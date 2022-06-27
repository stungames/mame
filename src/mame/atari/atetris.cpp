// license:BSD-3-Clause
// copyright-holders:Zsolt Vasvari, Aaron Giles
/***************************************************************************

    Atari Tetris hardware

    driver by Zsolt Vasvari

    Games supported:
        * Tetris

    Though of course none of the bootlegs have the actual SLAPSTIC, at
    least some appear to have simulated it using TTL and PLDs.

**********************************************************************************

Tetris (Atari, 1988)
Hardware info by Guru

PCB Layout
----------

TETRIS A044809
ATARI GAMES (C) 1988 MADE IN USA
|---------------------------------|
| VID                             |
|                                 |
|                     LED         |
|   P  P    65728                 |
|J  O  O                          |
|A  K  K                   ROM.A35|
|M  E  E   SLAPSTIC       6264    |
|M  Y  Y   ROM.F45              D |
|A           EMPTY              I |
|    TEST DSW4                  P |
|     LM324                     4 |
|   LED    X2804                0 |
|VOL                              |
|LA4465   6502         14.31818MHz|
|---------------------------------|
Notes:
      POKEY - Atari POKEY sound and I/O chip. Clock 1.7897725MHz [14.31818/8]
              Chip is marked '137430-001 ATARI GAMES, INC.'
              This is identical/compatible with the more common 'AMI C012294' POKEY chip
     LA4465 - Sanyo LA4465 Audio Power Amplifier
        VID - 11 pin connector for separate video output signals (R, G, B, HSync, VSync)
       6264 - Hyundai HY6264 8kBx8-bit SRAM
      65728 - Harris HM3-65728 2kBx8-bit SRAM (compatible with 6116/2018 etc)
  SLAPSTIC  - Atari custom protection SLAPSTIC  chip marked '137412-101 1984 ATARI GAMES'
      DIP40 - Atari custom DIP40 chip marked 'SOS-137550-001 TAIWAN (M)8822 YVAGZK'. (M) is the Motorola logo
    ROM.F45 - 27C512 EPROM with label '(C)1988 ATARI 8901 136066 1100'
    ROM.A35 - 27C512 EPROM with label '(C)1988 ATARI 8901 136066 1101'
      EMPTY - Empty DIP28 space (no socket or chip populated here)
       TEST - Toggle switch to enable test mode (test is also on the JAMMA connector)
       DSW4 - 4-position DIP switch at location H50
      X2804 - XICOR X2804 512 byte x8-bit EEPROM
      LM324 - Motorola LM324 Quad Operational Amplifier
       6502 - UM6502A CPU. Clock 1.7897725 [14.31818/8]
      HSync - 15.7014kHz
      VSync - 59.9290Hz

**********************************************************************************

****************************************************************************

    Memory map

****************************************************************************

    ========================================================================
    CPU #1
    ========================================================================
    0000-0FFF   R/W   xxxxxxxx    Program RAM
    1000-1FFF   R/W   xxxxxxxx    Playfield RAM
                      xxxxxxxx       (byte 0: LSB of character code)
                      -----xxx       (byte 1: MSB of character code)
                      xxxx----       (byte 1: palette index)
    2000-20FF   R/W   xxxxxxxx    Palette RAM
                      xxx----        (red component)
                      ---xxx--       (green component)
                      ------xx       (blue component)
    2400-25FF   R/W   xxxxxxxx    EEPROM
    2800-280F   R/W   xxxxxxxx    POKEY #1
    2810-281F   R/W   xxxxxxxx    POKEY #2
    3000          W   --------    Watchdog
    3400          W   --------    EEPROM write enable
    3800          W   --------    IRQ acknowledge
    3C00          W   --xx----    Coin counters
                  W   --x-----       (right coin counter)
                  W   ---x----       (left coin counter)
    4000-7FFF   R     xxxxxxxx    Banked program ROM
    8000-FFFF   R     xxxxxxxx    Program ROM
    ========================================================================
    Interrupts:
        IRQ generated by 32V
    ========================================================================

***************************************************************************/


#include "emu.h"

#include "slapstic.h"

#include "cpu/m6502/m6502.h"
#include "cpu/mcs48/mcs48.h"
#include "machine/eeprompar.h"
#include "machine/gen_latch.h"
#include "machine/watchdog.h"
#include "sound/pokey.h"
#include "sound/sn76496.h"

#include "emupal.h"
#include "screen.h"
#include "speaker.h"
#include "tilemap.h"


namespace {


class atetris_state : public driver_device
{
public:
	atetris_state(const machine_config &mconfig, device_type type, const char *tag) :
		driver_device(mconfig, type, tag),
		m_maincpu(*this, "maincpu"),
		m_gfxdecode(*this, "gfxdecode"),
		m_screen(*this, "screen"),
		m_slapstic(*this, "slapstic"),
		m_slapstic_bank(*this, "slapstic_bank"),
		m_slapstic_region(*this, "maincpu"),
		m_videoram(*this, "videoram")
	{
	}

	void atetris_base(machine_config &config);
	void atetris_pokey(machine_config &config);
	void atetris(machine_config &config);
	void atetrisb2(machine_config &config);
	void atetrisb5(machine_config &config);

	void init_atetris();

protected:
	virtual void machine_start() override;
	virtual void machine_reset() override;
	virtual void video_start() override;

	required_device<cpu_device> m_maincpu;
	required_device<gfxdecode_device> m_gfxdecode;
	required_device<screen_device> m_screen;
	optional_device<atari_slapstic_device> m_slapstic;
	optional_memory_bank m_slapstic_bank;
	required_region_ptr<uint8_t> m_slapstic_region;

	required_shared_ptr<uint8_t> m_videoram;

	emu_timer *m_interrupt_timer;
	tilemap_t *m_bg_tilemap;

	void irq_ack_w(uint8_t data);
	void coincount_w(uint8_t data);
	void videoram_w(offs_t offset, uint8_t data);
	TILE_GET_INFO_MEMBER(get_tile_info);
	uint32_t screen_update(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	TIMER_CALLBACK_MEMBER(interrupt_gen);
	void reset_bank();

	void atetrisb2_map(address_map &map);
	void atetrisb5_map(address_map &map);
	void main_map(address_map &map);
};

class atetris_bartop_state : public atetris_state
{
public:
	atetris_bartop_state(const machine_config &mconfig, device_type type, const char *tag) :
		atetris_state(mconfig, type, tag)
	{
	}

	void atetrisbp(machine_config &config);

private:
	void output_w(uint8_t data);

	void atetrisbp_map(address_map &map);
};

class atetris_mcu_state : public atetris_state
{
public:
	atetris_mcu_state(const machine_config &mconfig, device_type type, const char *tag) :
		atetris_state(mconfig, type, tag),
		m_mcu(*this, "mcu"),
		m_soundlatch(*this, "soundlatch%u", 1U),
		m_sn(*this, "sn%u", 1U)
	{
	}

	void atetrisb3(machine_config &config);

private:
	uint8_t mcu_bus_r();
	void mcu_p2_w(uint8_t data);
	void mcu_reg_w(offs_t offset, uint8_t data);

	void atetrisb3_map(address_map &map);

	required_device<i8749_device> m_mcu;
	required_device_array<generic_latch_8_device, 2> m_soundlatch;
	required_device_array<sn76496_base_device, 4> m_sn;
};



/*************************************
 *
 *  Tilemap callback
 *
 *************************************/

TILE_GET_INFO_MEMBER(atetris_state::get_tile_info)
{
	int code = m_videoram[tile_index * 2] | ((m_videoram[tile_index * 2 + 1] & 7) << 8);
	int color = (m_videoram[tile_index * 2 + 1] & 0xf0) >> 4;

	tileinfo.set(0, code, color, 0);
}



/*************************************
 *
 *  Video RAM write
 *
 *************************************/

void atetris_state::videoram_w(offs_t offset, uint8_t data)
{
	m_videoram[offset] = data;
	m_bg_tilemap->mark_tile_dirty(offset / 2);
}



/*************************************
 *
 *  Video system start
 *
 *************************************/

void atetris_state::video_start()
{
	m_bg_tilemap = &machine().tilemap().create(*m_gfxdecode, tilemap_get_info_delegate(*this, FUNC(atetris_state::get_tile_info)), TILEMAP_SCAN_ROWS, 8, 8, 64, 32);
}



/*************************************
 *
 *  Main refresh
 *
 *************************************/

uint32_t atetris_state::screen_update(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect)
{
	m_bg_tilemap->draw(screen, bitmap, cliprect, 0, 0);
	return 0;
}



/*************************************
 *
 *  Interrupt generation
 *
 *************************************/

TIMER_CALLBACK_MEMBER(atetris_state::interrupt_gen)
{
	int scanline = param;

	// assert/deassert the interrupt
	m_maincpu->set_input_line(0, (scanline & 32) ? ASSERT_LINE : CLEAR_LINE);

	// set the next timer
	scanline += 32;
	if (scanline >= 256)
		scanline -= 256;
	m_interrupt_timer->adjust(m_screen->time_until_pos(scanline), scanline);
}


void atetris_state::irq_ack_w(uint8_t data)
{
	m_maincpu->set_input_line(0, CLEAR_LINE);
}



/*************************************
 *
 *  Machine init
 *
 *************************************/

void atetris_state::machine_start()
{
	// Prepare the ROM bank
	if (m_slapstic_bank.found())
	{
		m_slapstic_bank->configure_entries(0, 2, m_slapstic_region, 0x4000);
		m_slapstic_bank->configure_entries(2, 2, m_slapstic_region, 0x4000);
	}

	// Allocate interrupt timer
	m_interrupt_timer = timer_alloc(FUNC(atetris_state::interrupt_gen), this);
}


void atetris_state::machine_reset()
{
	// start interrupts going (32V clocked by 16V)
	m_interrupt_timer->adjust(m_screen->time_until_pos(48), 48);
}



/*************************************
 *
 *  Coin counters
 *
 *************************************/

void atetris_state::coincount_w(uint8_t data)
{
	machine().bookkeeping().coin_counter_w(0, (data >> 5) & 1);
	machine().bookkeeping().coin_counter_w(1, (data >> 4) & 1);
}


void atetris_bartop_state::output_w(uint8_t data)
{
	coincount_w(data);

	// atetrisbp: $3c00 also handles ROM bank selection
	// game writes 0x4 to select bank 0, 0x5 to select bank 1
	if (data & 4)
		m_slapstic_bank->set_entry(data & 1);
}


/*************************************
 *
 *  Main CPU memory handlers
 *
 *************************************/

// full address map derived from schematics
void atetris_state::main_map(address_map &map)
{
	map(0x0000, 0x0fff).ram();
	map(0x1000, 0x1fff).ram().w(FUNC(atetris_state::videoram_w)).share(m_videoram);
	map(0x2000, 0x20ff).mirror(0x0300).ram().w("palette", FUNC(palette_device::write8)).share("palette");
	map(0x2400, 0x25ff).rw("eeprom", FUNC(eeprom_parallel_28xx_device::read), FUNC(eeprom_parallel_28xx_device::write));
	map(0x2800, 0x280f).mirror(0x03e0).rw("pokey1", FUNC(pokey_device::read), FUNC(pokey_device::write));
	map(0x2810, 0x281f).mirror(0x03e0).rw("pokey2", FUNC(pokey_device::read), FUNC(pokey_device::write));
	map(0x3000, 0x3000).mirror(0x03ff).w("watchdog", FUNC(watchdog_timer_device::reset_w));
	map(0x3400, 0x3400).mirror(0x03ff).w("eeprom", FUNC(eeprom_parallel_28xx_device::unlock_write8));
	map(0x3800, 0x3800).mirror(0x03ff).w(FUNC(atetris_state::irq_ack_w));
	map(0x3c00, 0x3c00).mirror(0x03ff).w(FUNC(atetris_state::coincount_w));
	map(0x4000, 0x7fff).bankr(m_slapstic_bank);
	map(0x8000, 0xffff).rom();
}


void atetris_state::atetrisb2_map(address_map &map)
{
	map(0x0000, 0x0fff).ram();
	map(0x1000, 0x1fff).ram().w(FUNC(atetris_state::videoram_w)).share(m_videoram);
	map(0x2000, 0x20ff).ram().w("palette", FUNC(palette_device::write8)).share("palette");
	map(0x2400, 0x25ff).rw("eeprom", FUNC(eeprom_parallel_28xx_device::read), FUNC(eeprom_parallel_28xx_device::write));
	map(0x2802, 0x2802).w("sn1", FUNC(sn76496_device::write));
	map(0x2804, 0x2804).w("sn2", FUNC(sn76496_device::write));
	map(0x2806, 0x2806).w("sn3", FUNC(sn76496_device::write));
	map(0x2808, 0x2808).portr("IN0");
	map(0x2808, 0x280f).nopw();
	map(0x2818, 0x2818).portr("IN1");
	map(0x2818, 0x281f).nopw();
	map(0x3000, 0x3000).w("watchdog", FUNC(watchdog_timer_device::reset_w));
	map(0x3400, 0x3400).w("eeprom", FUNC(eeprom_parallel_28xx_device::unlock_write8));
	map(0x3800, 0x3800).w(FUNC(atetris_state::irq_ack_w));
	map(0x3c00, 0x3c00).w(FUNC(atetris_state::coincount_w));
	map(0x4000, 0x7fff).bankr(m_slapstic_bank);
	map(0x8000, 0xffff).rom();
}


void atetris_mcu_state::atetrisb3_map(address_map &map)
{
	map(0x0000, 0x0fff).ram();
	map(0x1000, 0x1fff).ram().w(FUNC(atetris_mcu_state::videoram_w)).share(m_videoram);
	map(0x2000, 0x20ff).ram().w("palette", FUNC(palette_device::write8)).share("palette");
	map(0x2400, 0x27ff).rw("eeprom", FUNC(eeprom_parallel_28xx_device::read), FUNC(eeprom_parallel_28xx_device::write));
	map(0x2800, 0x281f).nopr().w(FUNC(atetris_mcu_state::mcu_reg_w));
	map(0x2808, 0x2808).portr("IN0");
	map(0x2818, 0x2818).portr("IN1");
	map(0x3000, 0x3000).w("watchdog", FUNC(watchdog_timer_device::reset_w));
	map(0x3400, 0x3400).w("eeprom", FUNC(eeprom_parallel_28xx_device::unlock_write8));
	map(0x3800, 0x3800).w(FUNC(atetris_mcu_state::irq_ack_w));
	map(0x3c00, 0x3c00).w(FUNC(atetris_mcu_state::coincount_w));
	map(0x4000, 0x7fff).bankr(m_slapstic_bank);
	map(0x8000, 0xffff).rom();
}


void atetris_state::atetrisb5_map(address_map &map) // TODO: Pokeys and Slapstic are substituted by a big TTL board and an additional 2716 EPROM
{
	map(0x0000, 0x0fff).ram();
	map(0x1000, 0x1fff).ram().w(FUNC(atetris_state::videoram_w)).share(m_videoram);
	map(0x2000, 0x20ff).mirror(0x0300).ram().w("palette", FUNC(palette_device::write8)).share("palette");
	// map(0x2400, 0x25ff).rw("eeprom", FUNC(eeprom_parallel_28xx_device::read), FUNC(eeprom_parallel_28xx_device::write));
	// map(0x2800, 0x280f).mirror(0x03e0).rw("pokey1", FUNC(pokey_device::read), FUNC(pokey_device::write));
	// map(0x2810, 0x281f).mirror(0x03e0).rw("pokey2", FUNC(pokey_device::read), FUNC(pokey_device::write));
	map(0x3000, 0x3000).mirror(0x03ff).w("watchdog", FUNC(watchdog_timer_device::reset_w));
	// map(0x3400, 0x3400).mirror(0x03ff).w("eeprom", FUNC(eeprom_parallel_28xx_device::unlock_write8));
	map(0x3800, 0x3800).mirror(0x03ff).w(FUNC(atetris_state::irq_ack_w));
	map(0x3c00, 0x3c00).mirror(0x03ff).w(FUNC(atetris_state::coincount_w));
	// map(0x4000, 0x7fff).bankr(m_slapstic_bank);
	map(0x8000, 0xffff).rom();
}


void atetris_bartop_state::atetrisbp_map(address_map &map)
{
	map(0x0000, 0x0fff).ram();
	map(0x1000, 0x1fff).ram().w(FUNC(atetris_bartop_state::videoram_w)).share(m_videoram);
	map(0x2000, 0x20ff).mirror(0x0300).ram().w("palette", FUNC(palette_device::write8)).share("palette");
	map(0x2400, 0x25ff).rw("eeprom", FUNC(eeprom_parallel_28xx_device::read), FUNC(eeprom_parallel_28xx_device::write));
	map(0x2800, 0x280f).mirror(0x03e0).rw("pokey1", FUNC(pokey_device::read), FUNC(pokey_device::write));
	map(0x2810, 0x281f).mirror(0x03e0).rw("pokey2", FUNC(pokey_device::read), FUNC(pokey_device::write));
	map(0x3000, 0x3000).mirror(0x03ff).w("watchdog", FUNC(watchdog_timer_device::reset_w));
	map(0x3400, 0x3400).mirror(0x03ff).w("eeprom", FUNC(eeprom_parallel_28xx_device::unlock_write8));
	map(0x3800, 0x3800).mirror(0x03ff).w(FUNC(atetris_bartop_state::irq_ack_w));
	map(0x3c00, 0x3c00).mirror(0x03ff).w(FUNC(atetris_bartop_state::output_w));
	map(0x4000, 0x7fff).bankr(m_slapstic_bank);
	map(0x8000, 0xffff).rom();
}


/*************************************
 *
 *  Bootleg MCU handlers
 *
 *************************************/

uint8_t atetris_mcu_state::mcu_bus_r()
{
	switch (m_mcu->p2_r() & 0xf0)
	{
	case 0x40:
		return m_soundlatch[1]->read();

	case 0xf0:
		return m_soundlatch[0]->read();

	default:
		return 0xff;
	}
}

void atetris_mcu_state::mcu_p2_w(uint8_t data)
{
	if ((data & 0xc0) == 0x80)
		m_sn[(data >> 4) & 3]->write(m_mcu->p1_r());
}

void atetris_mcu_state::mcu_reg_w(offs_t offset, uint8_t data)
{
	// FIXME: a lot of sound writes seem to get lost this way; why doesn't that hurt?
	m_soundlatch[0]->write(offset | 0x20);
	m_soundlatch[1]->write(data);
}


/*************************************
 *
 *  Port definitions
 *
 *************************************/

static INPUT_PORTS_START( atetris )
	// These ports are read via the Pokeys
	PORT_START("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_COIN2 )
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_DIPNAME( 0x04, 0x00, "Freeze" )            PORT_DIPLOCATION("50H:!4")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x04, DEF_STR( On ) )
	PORT_DIPNAME( 0x08, 0x00, "Freeze Step" )       PORT_DIPLOCATION("50H:!3")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x08, DEF_STR( On ) )
	PORT_DIPUNUSED_DIPLOC( 0x10, 0x00, "50H:!2" )   // Listed As "SPARE2 (Unused)"
	PORT_DIPUNUSED_DIPLOC( 0x20, 0x00, "50H:!1" )   // Listed As "SPARE1 (Unused)"
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_CUSTOM ) PORT_VBLANK("screen")
	PORT_SERVICE( 0x80, IP_ACTIVE_HIGH )

	// The control panel has a start and an action button for both players. The board has them connected together on the JAMMA connector.
	// So bit 0x01 actually is used by both player 1 start and action buttons and bit 0x10 is used by both player 2 start and action buttons
	PORT_START("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_BUTTON1) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_PLAYER(1)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_BUTTON1) PORT_PLAYER(2)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_JOYSTICK_DOWN ) PORT_4WAY PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_JOYSTICK_RIGHT ) PORT_4WAY PORT_PLAYER(2)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_JOYSTICK_LEFT ) PORT_4WAY PORT_PLAYER(2)
INPUT_PORTS_END


// Same as the regular one except they added a Flip Controls switch
static INPUT_PORTS_START( atetrisc )
	PORT_INCLUDE( atetris )

	PORT_MODIFY("IN0")
	PORT_DIPNAME( 0x20, 0x00, "Flip Controls" )     PORT_DIPLOCATION("50H:!1")
	PORT_DIPSETTING(    0x00, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x20, DEF_STR( On ) )
INPUT_PORTS_END



/*************************************
 *
 *  Graphics layouts
 *
 *************************************/

static GFXDECODE_START( gfx_atetris )
	GFXDECODE_ENTRY( "tiles", 0, gfx_8x8x4_packed_msb, 0, 16 )
GFXDECODE_END


/*************************************
 *
 *  Machine driver
 *
 *************************************/

constexpr XTAL MASTER_CLOCK = XTAL(14'318'181);
constexpr XTAL BOOTLEG_CLOCK = XTAL(14'745'600);

void atetris_state::atetris_base(machine_config &config)
{
	// basic machine hardware
	M6502(config, m_maincpu, MASTER_CLOCK / 8);
	m_maincpu->set_addrmap(AS_PROGRAM, &atetris_state::main_map);

	WATCHDOG_TIMER(config, "watchdog");

	// video hardware
	GFXDECODE(config, m_gfxdecode, "palette", gfx_atetris);

	PALETTE(config, "palette").set_format(palette_device::RGB_332, 256);

	SCREEN(config, m_screen, SCREEN_TYPE_RASTER);
	// note: these parameters are from published specs, not derived
	// the board uses an SOS-2 chip to generate video signals
	m_screen->set_raw(MASTER_CLOCK / 2, 456, 0, 336, 262, 0, 240);
	m_screen->set_screen_update(FUNC(atetris_state::screen_update));
	m_screen->set_palette("palette");

	// sound hardware
	SPEAKER(config, "mono").front_center();
}

void atetris_state::atetris_pokey(machine_config &config)
{
	atetris_base(config);

	EEPROM_2804(config, "eeprom").lock_after_write(true);

	pokey_device &pokey1(POKEY(config, "pokey1", MASTER_CLOCK / 8));
	pokey1.allpot_r().set_ioport("IN0");
	pokey1.add_route(ALL_OUTPUTS, "mono", 0.50);

	pokey_device &pokey2(POKEY(config, "pokey2", MASTER_CLOCK / 8));
	pokey2.allpot_r().set_ioport("IN1");
	pokey2.add_route(ALL_OUTPUTS, "mono", 0.50);
}

void atetris_state::atetris(machine_config &config)
{
	atetris_pokey(config);

	SLAPSTIC(config, m_slapstic, 101);
	m_slapstic->set_range(m_maincpu, AS_PROGRAM, 0x6000, 0x7fff, 0);
	m_slapstic->set_bank(m_slapstic_bank);
}

void atetris_state::atetrisb2(machine_config &config)
{
	atetris(config);
	config.device_remove("pokey1");
	config.device_remove("pokey2");

	// basic machine hardware
	m_maincpu->set_clock(BOOTLEG_CLOCK / 8);
	m_maincpu->set_addrmap(AS_PROGRAM, &atetris_state::atetrisb2_map);

	SN76489A(config, "sn1", BOOTLEG_CLOCK / 8).add_route(ALL_OUTPUTS, "mono", 0.50);
	SN76489A(config, "sn2", BOOTLEG_CLOCK / 8).add_route(ALL_OUTPUTS, "mono", 0.50);
	SN76489(config, "sn3", BOOTLEG_CLOCK / 8).add_route(ALL_OUTPUTS, "mono", 0.50);
}


void atetris_state::atetrisb5(machine_config &config)
{
	atetris_base(config);

	m_maincpu->set_addrmap(AS_PROGRAM, &atetris_bartop_state::atetrisb5_map);
}


void atetris_mcu_state::atetrisb3(machine_config &config)
{
	atetris(config);
	config.device_remove("pokey1");
	config.device_remove("pokey2");

	m_maincpu->set_addrmap(AS_PROGRAM, &atetris_mcu_state::atetrisb3_map);

	I8749(config, m_mcu, 10_MHz_XTAL);
	m_mcu->bus_in_cb().set(FUNC(atetris_mcu_state::mcu_bus_r));
	m_mcu->bus_out_cb().set(m_soundlatch[0], FUNC(generic_latch_8_device::acknowledge_w));
	m_mcu->p2_out_cb().set(FUNC(atetris_mcu_state::mcu_p2_w));

	GENERIC_LATCH_8(config, m_soundlatch[0]);
	m_soundlatch[0]->data_pending_callback().set_inputline(m_mcu, MCS48_INPUT_IRQ);
	m_soundlatch[0]->set_separate_acknowledge(true);

	GENERIC_LATCH_8(config, m_soundlatch[1]);

	for (int i = 0; i < 4; i++)
	{
		SN76489A(config, m_sn[i], 4_MHz_XTAL).add_route(ALL_OUTPUTS, "mono", 0.50);
	}
}


void atetris_bartop_state::atetrisbp(machine_config &config)
{
	atetris_pokey(config);

	m_maincpu->set_addrmap(AS_PROGRAM, &atetris_bartop_state::atetrisbp_map);
}


/*************************************
 *
 *  ROM definitions
 *
 *************************************/

ROM_START( atetris )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "136066-1100.45f", 0x0000, 0x10000, CRC(2acbdb09) SHA1(5e1189227f26563fd3e5372121ea5c915620f892) )

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "136066-1101.35a", 0x0000, 0x10000, CRC(84a1939f) SHA1(d8577985fc8ed4e74f74c68b7c00c4855b7c3270) )
ROM_END


ROM_START( atetrisa )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "d1",           0x0000, 0x10000, CRC(2bcab107) SHA1(3cfb8df8cd3782f3ff7f6b32ff15c461352061ee) )

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "136066-1101.35a",     0x0000, 0x10000, CRC(84a1939f) SHA1(d8577985fc8ed4e74f74c68b7c00c4855b7c3270) )
ROM_END


ROM_START( atetrisb )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "tetris.01",    0x0000, 0x10000, CRC(944d15f6) SHA1(926fa5cb26b6e6a50bea455eec1f6d3fb92aa95c) )

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "tetris.02",    0x0000, 0x10000, CRC(5c4e7258) SHA1(58060681a728e74d69b2b6f5d02faa597ca6c226) )

	// there's an extra EEPROM, maybe used for protection crack, which however doesn't seem to be required to run the game in this driver.
	ROM_REGION( 0x0800, "user1", 0 )
	ROM_LOAD( "tetris.03",    0x0000, 0x0800, CRC(26618c0b) SHA1(4d6470bf3a79be3b0766e246abe00582d4c85a97) )
ROM_END


ROM_START( atetrisb2 )
	ROM_REGION( 0x10000, "maincpu", 0 ) // Some bootleg PCBs use unmodified Atari ROMs
	ROM_LOAD( "k1-01",    0x0000, 0x10000, CRC(fa056809) SHA1(e4ccccdf9b04b68127c7b03ae263519cf00f94cb) ) // 27512

	ROM_REGION( 0x10000, "tiles", 0 ) // Some bootleg PCBs use unmodified Atari ROMs
	ROM_LOAD( "136066-1101.35a", 0x0000, 0x10000, CRC(84a1939f) SHA1(d8577985fc8ed4e74f74c68b7c00c4855b7c3270) ) // 27512

	ROM_REGION( 0x0020, "proms", 0 ) // currently unused
	ROM_LOAD( "m3-7603-5.prom1", 0x00000, 0x0020, CRC(79656af3) SHA1(bf55f100806520b291157c03999606367dd14ecc) ) // 82s123 or TBP18S030

	// Unused. It's usual to find PLDs with different hashes, but defining equivalent equations
	ROM_REGION( 0x859, "plds", 0 )
	ROM_LOAD( "a-gal16v8-b.bin", 0x000, 0x117, CRC(b1dfab0f) SHA1(e9e4db5459617a35a13df4b7a4586dd1b7be04ac) ) // sub PCB - Same content as "b"
	ROM_LOAD( "b-gal16v8-b.bin", 0x117, 0x117, CRC(b1dfab0f) SHA1(e9e4db5459617a35a13df4b7a4586dd1b7be04ac) ) // sub PCB - Same content as "a"
	ROM_LOAD( "c-gal16v8-b.bin", 0x22e, 0x117, CRC(e1a9db0b) SHA1(5bbac24e37a4d9b8a1387054722fa35478ca7941) ) // sub PCB
	ROM_LOAD( "1-pal16l8-a.3g" , 0x345, 0x104, CRC(dcf0d2fe) SHA1(0496acaa605ec5008b110c387136bbc714441384) ) // main PCB - Found also as GAL16v8 on some PCBs
	ROM_LOAD( "2-pal16r4-a.3r" , 0x449, 0x104, CRC(d71bdf27) SHA1(cc3503cb037de344fc353886f3492601638c9d45) ) // main PCB
	ROM_LOAD( "3-pal16r4-a.8p" , 0x54D, 0x104, CRC(e007edf2) SHA1(4f1bc31abd64e402edb4c900ddb21f258d6782c8) ) // main PCB - Found also as GAL16v8 on some PCBs
	ROM_LOAD( "4-pal16l8-a.9n" , 0x651, 0x104, CRC(3630e734) SHA1(a29dc202ffc75ac48815115b85e984fc0c9d5b59) ) // main PCB - Found also as GAL16v8 on some PCBs
	ROM_LOAD( "5-pal16l8-a.9m" , 0x755, 0x104, CRC(53b64be1) SHA1(2bf712b766541c90c38c0810ee16848e448c5205) ) // main PCB - Found also as GAL16v8 on some PCBs
ROM_END


/*
Tetris (Korean bootleg of atetrisa set)
Hardware info by Guru

PCB Layout
----------

RC-1108
|---------------------------------------------------|
|                                        14.31818MHz|
| PAL                                               |
|                                                   |
|     P8749H   6116                                 |
|J                                                  |
|A          10MHz                     27512         |
|M              PAL                                 |
|M                                62256             |
|A                                                  |
|                27512                              |
|                28C16                         PAL  |
|                                      PAL     PAL  |
|76489 76489  4MHz                  82S123          |
|76489              6502                            |
|VOL MB3713    PAL                                  |
|---------------------------------------------------|

A second PCB has been found with identical code, but with 1x additional SN76489AN, 1x additional DIP switch, a few more TTLs, and 6 PAL18l8ACN.
The MCU XTAL is 10.73835 MHz rather than 10 MHz on this PCB.
*/

ROM_START( atetrisb3 )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "prg.bin",           0x0000, 0x10000, CRC(2bcab107) SHA1(3cfb8df8cd3782f3ff7f6b32ff15c461352061ee) )

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "gfx.bin",     0x0000, 0x10000, CRC(84a1939f) SHA1(d8577985fc8ed4e74f74c68b7c00c4855b7c3270) )

	// 8749 (10 MHz OSC) emulates POKEYs
	ROM_REGION( 0x0800, "mcu", 0 )
	ROM_LOAD( "8749h.bin",    0x0000, 0x0800, CRC(a66a9c47) SHA1(fbebd755a5e826c7d94ebcafdff2f9a01c9fd1a5) ) // dumped via normal methods and confirmed good via decap
	ROM_FILL( 0x06e2, 1, 0x96 ) // patch illegal opcode

	// currently unused
	ROM_REGION( 0x0020, "proms", 0 )
	ROM_LOAD( "82s123.bin", 0x00000, 0x0020, CRC(79656af3) SHA1(bf55f100806520b291157c03999606367dd14ecc) )

	ROM_REGION( 0xc00, "plds", 0 ) // all protected
	ROM_LOAD( "gal18v8a-25lp.1",   0x000, 0x117, NO_DUMP )
	ROM_LOAD( "gal18v8a-25lp.2",   0x200, 0x117, NO_DUMP )
	ROM_LOAD( "palce18v8h-25pc.3", 0x400, 0x117, NO_DUMP )
	ROM_LOAD( "palce18v8h-25pc.4", 0x600, 0x117, NO_DUMP )
	ROM_LOAD( "pal16r4b-2cn.5",    0x800, 0x104, NO_DUMP )
	ROM_LOAD( "pal16r4b-2cn.6",    0xa00, 0x104, NO_DUMP )
ROM_END

ROM_START( atetrisb4 ) // bootleg on an unusually big PCB for this game
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "1.bin",    0x0000, 0x10000, CRC(56589096) SHA1(df0ff776f3e3506c86d703d2283db59a576abea6) ) // only difference is the credits for 'video graphics' where changed

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "2.bin", 0x0000, 0x10000, CRC(70859030) SHA1(bb6bf88b75be3a81672e0aa30a8cbd7181bc87d0) ) // unique, but extremely similar to the one of the original
ROM_END

ROM_START( atetrisb5 ) // this bootleg has a big sub board filled with TTL, presumably used for substituting the Slapstic and the Pokeys. If the sub board is disconnected the game doesn't boot.
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "tt1", 0x0000, 0x10000, CRC(2acbdb09) SHA1(5e1189227f26563fd3e5372121ea5c915620f892) ) // same data as the original

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "tt2", 0x0000, 0x10000, CRC(84a1939f) SHA1(d8577985fc8ed4e74f74c68b7c00c4855b7c3270) ) // same data as the original

	ROM_REGION( 0x800, "extra_rom", 0 ) // possibly involved in the Slapstic circumvention? It's positioned at the side of the main CPU ROM.
	ROM_LOAD( "2716", 0x000, 0x800, CRC(4a71c947) SHA1(873d7b63b2e59ccd9bb2519efd6d104969967e01) ) // BADADDR --xxxxxxxxx, but it has been redumped many times. 2716 is the chip type, it has no label.
ROM_END


/*
atetb3482: Atari Tetris bootleg with additional UM3482 and Z80 (with its ROM)
  __________________________________________________________________
  |                                                                 |
A | ?????             74LS06   74LS197  74LS374             74LS04  |
  |                                                                 |
B |                   74LS08    74LS74  74LS374    74LS374          |
  |                                                                 |
C |                   74LS32    74LS27  74LS357    74LS374 XTAL     |
  |                                                          74LS10 |
D |                   74LS04   74LS273   74LS74    74LS374          |
  | ?? ??  74LS393   UM6116K    74LS74  74LS257      ______  74LS27 |
E |                                                  | D2  |        |
  |                   74LS245      74LS245 _______   |     | 74LS74 |
F |UM3482  74LS139    PAL16L8              |      |  |27PC |74LS161 |
  |______           __________     74LS245 | MS   |  | 512 |        |
G ||DIPS | PAL16R4  |UNPOPULAT|            | 6264 |  |_____|74LS161 |
  ||_____|          |_________|    74LS245 | L-10 |  _______        |
H |74LS04  PAL16R8  ___________            |      |  | UN  |74LS161 |
  |                 |D1 27PC512|   74LS00  |______|  | PO  |        |
I |74LS32  74LS373  |__________|   74LS32            | PU  |PAL16L8 |
  |                  __________              74LS04  | LA  |        |
J |74LS374 74LS357   | X2804AP |   74LS257   74LS138 | TED |PAL16?? |
  |____________      |_________|   74LS257   74LS257 |     |        |
K ||D3 27PC256 |                                     |_____|74LS161 |
  ||___________|     74LS245   74LS245                              |
L |________________  _______________         74LS257 74LS74 74LS161 |
  ||SHARP LH0080B  | |   UM6502A    |                               |
M ||_______________| |______________|      74LS00    74LS74 74LS161 |
  |                                                                 |
N |PAL16R4 74LS??? 4017 74LS08 74LS32 74LS04 PAL16R4 82S123 74LS32  |
  |_________________________________________________________________|
    1      2      3       4       5       6       7      8      9
*/
ROM_START( atetb3482 )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "i4-d1.bin", 0x0000, 0x10000, CRC(2acbdb09) SHA1(5e1189227f26563fd3e5372121ea5c915620f892) )

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "f8-d2.bin", 0x0000, 0x10000, CRC(84a1939f) SHA1(d8577985fc8ed4e74f74c68b7c00c4855b7c3270) )

	ROM_REGION( 0x8000, "soundcpu", 0 ) // Not hooked up
	ROM_LOAD( "k1-d3.bin", 0x0000, 0x8000, CRC(ce51c82b) SHA1(f90ed16f817e6b2a22b69db20348386b9c1ecb67) ) // Same 8K repeated four times

	// See http://www.seanriddle.com/um348x/ for notes about the UM3482
	ROM_REGION( 0x01f0, "um3482", 0 ) // Not hooked up

	/* Notes (3584 bits, which matches the datasheet's 512 7-bit notes).
	   Raw dump from visual decap, needs further analysis. */
	ROM_LOAD( "um3482araw.bin", 0x0000, 0x01c0, BAD_DUMP CRC(5871d564) SHA1(4203b6513ad08ece26177778e5defeb862d1a81d) )

	/* 16 entry by 9-bit ROM
	   Song starting locations?  Chip has 16 songs max, 512 total notes.
	   All 16 entries have data, but only 12 songs on chip.
	   Dump from visual decap with values padded to 16 bits, needs further analysis. */
	ROM_LOAD( "offsets.bin",    0x0000, 0x0020, BAD_DUMP CRC(f39aff3c) SHA1(255dcea154ed04c6d1968b09e188ca5fc8821721) )

	/* 16 entry by 7-bit ROM.
	   Tempo for each song?
	   All 16 entries have data, but only 12 songs on chip.
	   Dump from visual decap with values padded to 8 bits, needs further analysis. */
	ROM_LOAD( "tempos.bin",     0x0000, 0x0010, BAD_DUMP CRC(c3a37f74) SHA1(67eac8c6530c202760d492f3e52c44f9cd183b46) )

	// Not dumped, unused
	ROM_REGION( 0x71c, "plds", 0 )
	ROM_LOAD( "pal16r4.1n" , 0x000, 0x104, NO_DUMP )
	ROM_LOAD( "pal16r4.7n" , 0x104, 0x104, NO_DUMP )
	ROM_LOAD( "pal16l8.9j" , 0x208, 0x104, NO_DUMP )
	ROM_LOAD( "pal16l8.9i" , 0x30c, 0x104, NO_DUMP )
	ROM_LOAD( "pal16r8.2h" , 0x410, 0x104, NO_DUMP )
	ROM_LOAD( "pal16r4.2g" , 0x514, 0x104, NO_DUMP )
	ROM_LOAD( "pal16l8.4f" , 0x618, 0x104, NO_DUMP )
ROM_END

/*

 This ROM came from a prototype bartop field-test machine from an
ex-Atari Employee.

PCB is screened : A044809

The PCB does not draw its power from the JAMMA connector, instead a
small AC voltage is taken onboard and regulated down as this PCB has
only a small power requirement!

The label on the rom says :

Tet_Rom_Rev1
NO SLAPSTIC
B4FF
20-Apr-89

The cabinet is completely custom made by Atari, and this PCB differs
greatly from the production PCB that we know of. The machine was operated
on location at a local bar but did not perform well so they decided it
wasn't a viable game to make, it's the only known example.

*/

ROM_START( atetrisbp )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "tet_rom_rev1.40f", 0x0000, 0x10000, CRC(b6224e6c) SHA1(6b549317499e91a2f19ec282d927fba08f217488) )

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "8901-136066-1101.40p", 0x0000, 0x10000, CRC(84a1939f) SHA1(d8577985fc8ed4e74f74c68b7c00c4855b7c3270) BAD_DUMP ) // "© 1988 ATARI"; not dumped from this set
ROM_END

ROM_START( atetrisc )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "tetcktl1.rom", 0x0000, 0x10000, CRC(9afd1f4a) SHA1(323d1576d92c905e8e95108b39cabf6fa0c10db6) )

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "136066-1103.35a", 0x0000, 0x10000, CRC(ec2a7f93) SHA1(cb850141ffd1504f940fa156a39e71a4146d7fea) )
ROM_END


ROM_START( atetrisc2 )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "136066-1102.45f", 0x0000, 0x10000, CRC(1bd28902) SHA1(ae8c34f082bce1f827bf60830f207c46cb282421) )

	ROM_REGION( 0x10000, "tiles", 0 )
	ROM_LOAD( "136066-1103.35a", 0x0000, 0x10000, CRC(ec2a7f93) SHA1(cb850141ffd1504f940fa156a39e71a4146d7fea) )
ROM_END

} // Anonymous namespace



/*************************************
 *
 *  Game drivers
 *
 *************************************/

GAME( 1988, atetris,   0,       atetris,   atetris,  atetris_state,        empty_init, ROT0,   "Atari Games", "Tetris (set 1)", MACHINE_SUPPORTS_SAVE )
GAME( 1988, atetrisa,  atetris, atetris,   atetris,  atetris_state,        empty_init, ROT0,   "Atari Games", "Tetris (set 2)", MACHINE_SUPPORTS_SAVE )
GAME( 1988, atetrisb,  atetris, atetris,   atetris,  atetris_state,        empty_init, ROT0,   "bootleg",     "Tetris (bootleg set 1)", MACHINE_SUPPORTS_SAVE )
GAME( 1988, atetrisb2, atetris, atetrisb2, atetris,  atetris_state,        empty_init, ROT0,   "bootleg",     "Tetris (bootleg set 2)", MACHINE_SUPPORTS_SAVE )
GAME( 1988, atetrisb3, atetris, atetrisb3, atetris,  atetris_mcu_state,    empty_init, ROT0,   "bootleg",     "Tetris (bootleg set 3)", MACHINE_SUPPORTS_SAVE )
GAME( 1988, atetrisb4, atetris, atetris,   atetris,  atetris_state,        empty_init, ROT0,   "bootleg",     "Tetris (bootleg set 4)", MACHINE_SUPPORTS_SAVE )
GAME( 1988, atetrisb5, atetris, atetrisb5, atetris,  atetris_state,        empty_init, ROT0,   "bootleg",     "Tetris (bootleg set 5)", MACHINE_NOT_WORKING | MACHINE_SUPPORTS_SAVE )
GAME( 1988, atetb3482, atetris, atetris,   atetris,  atetris_state,        empty_init, ROT0,   "bootleg",     "Tetris (bootleg set 6, with UM3482)", MACHINE_SUPPORTS_SAVE | MACHINE_IMPERFECT_SOUND )
GAME( 1989, atetrisbp, atetris, atetrisbp, atetris,  atetris_bartop_state, empty_init, ROT0,   "Atari Games", "Tetris (bartop, prototype)", MACHINE_SUPPORTS_SAVE )
GAME( 1989, atetrisc,  atetris, atetris,   atetrisc, atetris_state,        empty_init, ROT270, "Atari Games", "Tetris (cocktail set 1)", MACHINE_SUPPORTS_SAVE )
GAME( 1989, atetrisc2, atetris, atetris,   atetrisc, atetris_state,        empty_init, ROT270, "Atari Games", "Tetris (cocktail set 2)", MACHINE_SUPPORTS_SAVE )
