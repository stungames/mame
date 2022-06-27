// license:BSD-3-Clause
// copyright-holders:Stefan Jokisch
/***************************************************************************

    Atari Drag Race Driver

***************************************************************************/

#include "emu.h"
#include "dragrace.h"

#include "cpu/m6800/m6800.h"
#include "machine/74259.h"
#include "sound/discrete.h"
#include "speaker.h"

#include "dragrace.lh"


TIMER_DEVICE_CALLBACK_MEMBER(dragrace_state::frame_callback)
{
	for (int i = 0; i < 2; i++)
	{
		switch (m_p[i]->read())
		{
			case 0x01: m_gear[i] = 1; break;
			case 0x02: m_gear[i] = 2; break;
			case 0x04: m_gear[i] = 3; break;
			case 0x08: m_gear[i] = 4; break;
			case 0x10: m_gear[i] = 0; break;
		}
	}

	m_gear_sel[0] = m_gear[0];
	m_gear_sel[1] =  m_gear[1];

	// watchdog is disabled during service mode
	m_watchdog->watchdog_enable(m_in[0]->read() & 0x20);
}


void dragrace_state::speed1_w(uint8_t data)
{
	unsigned freq = ~data & 0x1f;
	m_discrete->write(DRAGRACE_MOTOR1_DATA, freq);

	// the tachometers are driven from the same frequency generator that creates the engine sound
	m_tacho_sel[0] = freq;
}

void dragrace_state::speed2_w(uint8_t data)
{
	unsigned freq = ~data & 0x1f;
	m_discrete->write(DRAGRACE_MOTOR2_DATA, freq);

	// the tachometers are driven from the same frequency generator that creates the engine sound
	m_tacho_sel[1] = freq;
}

uint8_t dragrace_state::input_r(offs_t offset)
{
	int val = m_in[2]->read();

	uint8_t maskA = 1 << (offset % 8);
	uint8_t maskB = 1 << (offset / 8);

	for (int i = 0; i < 2; i++)
	{
		int in = m_in[i]->read();

		if (m_gear[i] != 0)
			in &= ~(1 << m_gear[i]);

		if (in & maskA)
			val |= 1 << i;
	}

	return (val & maskB) ? 0xff : 0x7f;
}


uint8_t dragrace_state::steering_r()
{
	int bitA[2];
	int bitB[2];

	for (int i = 0; i < 2; i++)
	{
		int dial = m_dial[i]->read();

		bitA[i] = ((dial + 1) / 2) & 1;
		bitB[i] = ((dial + 0) / 2) & 1;
	}

	return
		(bitA[0] << 0) | (bitB[0] << 1) |
		(bitA[1] << 2) | (bitB[1] << 3);
}


uint8_t dragrace_state::scanline_r()
{
	return (m_screen->vpos() ^ 0xf0) | 0x0f;
}


void dragrace_state::main_map(address_map &map)
{
	map(0x0080, 0x00ff).ram();
	map(0x0800, 0x083f).r(FUNC(dragrace_state::input_r));
	map(0x0900, 0x0907).w("latch_f5", FUNC(addressable_latch_device::write_d0));
	map(0x0908, 0x090f).w("latch_a5", FUNC(addressable_latch_device::write_d0));
	map(0x0910, 0x0917).w("latch_h5", FUNC(addressable_latch_device::write_d0));
	map(0x0918, 0x091f).w("latch_e5", FUNC(addressable_latch_device::write_d0));
	map(0x0920, 0x0927).w("latch_f5", FUNC(addressable_latch_device::clear));
	map(0x0928, 0x092f).w("latch_a5", FUNC(addressable_latch_device::clear));
	map(0x0930, 0x0937).w("latch_h5", FUNC(addressable_latch_device::clear));
	map(0x0938, 0x093f).w("latch_e5", FUNC(addressable_latch_device::clear));
	map(0x0a00, 0x0aff).writeonly().share(m_playfield_ram);
	map(0x0b00, 0x0bff).writeonly().share(m_position_ram);
	map(0x0c00, 0x0c00).r(FUNC(dragrace_state::steering_r));
	map(0x0d00, 0x0d00).r(FUNC(dragrace_state::scanline_r));
	map(0x0e00, 0x0eff).w(m_watchdog, FUNC(watchdog_timer_device::reset_w));
	map(0x1000, 0x1fff).rom(); // program
	map(0xf800, 0xffff).rom(); // program mirror
}


static INPUT_PORTS_START( dragrace )
	PORT_START("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_NAME("Player 1 Gas") PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED ) // player 1 gear 1
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED ) // player 1 gear 2
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED ) // player 1 gear 3
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNUSED ) // player 1 gear 4
	PORT_SERVICE( 0x20, IP_ACTIVE_LOW )
	PORT_DIPNAME( 0xc0, 0x80, "Extended Play" )         PORT_DIPLOCATION("SW1:1,2")
	PORT_DIPSETTING( 0x00, "6.9 seconds" )
	PORT_DIPSETTING( 0x80, "5.9 seconds" )
	PORT_DIPSETTING( 0x40, "4.9 seconds" )
	PORT_DIPSETTING( 0xc0, "Never" )

	PORT_START("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON1 ) PORT_NAME("Player 2 Gas") PORT_PLAYER(2)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNUSED ) // player 2 gear 1
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNUSED ) // player 2 gear 2
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNUSED ) // player 2 gear 3
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNUSED ) // player 2 gear 4
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_DIPNAME( 0xc0, 0x80, "Number Of Heats" )       PORT_DIPLOCATION("SW1:3,4")
	PORT_DIPSETTING( 0xc0, "3" )
	PORT_DIPSETTING( 0x80, "4" )
	PORT_DIPSETTING( 0x00, "5" )

	PORT_START("IN2")
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_UNUSED ) // IN0 connects here
	PORT_BIT( 0x02, IP_ACTIVE_HIGH, IPT_UNUSED ) // IN1 connects here
	PORT_BIT( 0x04, IP_ACTIVE_HIGH, IPT_COIN1 )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_COIN2 )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_START1 )
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_START2 )
	PORT_DIPNAME( 0xc0, 0x40, DEF_STR( Coinage ) )      PORT_DIPLOCATION("SW1:5,6")
	PORT_DIPSETTING( 0xc0, DEF_STR( 2C_1C ) )
	PORT_DIPSETTING( 0x40, DEF_STR( 1C_1C ) )
	PORT_DIPSETTING( 0x80, DEF_STR( 1C_2C ) )
	PORT_DIPSETTING( 0x00, DEF_STR( Free_Play ) )

	PORT_START("DIAL1")
	PORT_BIT( 0xff, 0x00, IPT_DIAL_V ) PORT_SENSITIVITY(25) PORT_KEYDELTA(10) PORT_PLAYER(1)

	PORT_START("DIAL2")
	PORT_BIT( 0xff, 0x00, IPT_DIAL_V ) PORT_SENSITIVITY(25) PORT_KEYDELTA(10) PORT_PLAYER(2)

	PORT_START("P1")
	PORT_BIT(0x01, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_NAME("Player 1 Gear 1") PORT_PLAYER(1)
	PORT_BIT(0x02, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_NAME("Player 1 Gear 2") PORT_PLAYER(1)
	PORT_BIT(0x04, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_NAME("Player 1 Gear 3") PORT_PLAYER(1)
	PORT_BIT(0x08, IP_ACTIVE_HIGH, IPT_BUTTON5 ) PORT_NAME("Player 1 Gear 4") PORT_PLAYER(1)
	PORT_BIT(0x10, IP_ACTIVE_HIGH, IPT_BUTTON6 ) PORT_NAME("Player 1 Neutral") PORT_PLAYER(1)

	PORT_START("P2")
	PORT_BIT(0x01, IP_ACTIVE_HIGH, IPT_BUTTON2 ) PORT_NAME("Player 2 Gear 1") PORT_PLAYER(2)
	PORT_BIT(0x02, IP_ACTIVE_HIGH, IPT_BUTTON3 ) PORT_NAME("Player 2 Gear 2") PORT_PLAYER(2)
	PORT_BIT(0x04, IP_ACTIVE_HIGH, IPT_BUTTON4 ) PORT_NAME("Player 2 Gear 3") PORT_PLAYER(2)
	PORT_BIT(0x08, IP_ACTIVE_HIGH, IPT_BUTTON5 ) PORT_NAME("Player 2 Gear 4") PORT_PLAYER(2)
	PORT_BIT(0x10, IP_ACTIVE_HIGH, IPT_BUTTON6 ) PORT_NAME("Player 2 Neutral") PORT_PLAYER(2)

	PORT_START("MOTOR1")
	PORT_ADJUSTER( 81, "Motor 1 RPM" )

	PORT_START("MOTOR2")
	PORT_ADJUSTER( 85, "Motor 2 RPM" )
INPUT_PORTS_END


static const gfx_layout dragrace_tile_layout1 =
{
	16, 16,   // width, height
	0x40,     // total
	1,        // planes
	{ 0 },    // plane offsets
	{
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87
	},
	{
		0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38,
		0x40, 0x48, 0x50, 0x58, 0x60, 0x68, 0x70, 0x78
	},
	0x100      // increment
};


static const gfx_layout dragrace_tile_layout2 =
{
	16, 16,   // width, height
	0x20,     // total
	2,        // planes
	{         // plane offsets
		0x0000, 0x2000
	},
	{
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87
	},
	{
		0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38,
		0x40, 0x48, 0x50, 0x58, 0x60, 0x68, 0x70, 0x78
	},
	0x100      // increment
};


static GFXDECODE_START( gfx_dragrace )
	GFXDECODE_ENTRY( "gfx1", 0, dragrace_tile_layout1, 0, 4 )
	GFXDECODE_ENTRY( "gfx2", 0, dragrace_tile_layout2, 8, 2 )
GFXDECODE_END


void dragrace_state::palette(palette_device &palette) const
{
	palette.set_pen_color(0, rgb_t(0xff, 0xff, 0xff));   // 2 color tiles
	palette.set_pen_color(1, rgb_t(0x00, 0x00, 0x00));
	palette.set_pen_color(2, rgb_t(0x00, 0x00, 0x00));
	palette.set_pen_color(3, rgb_t(0xff, 0xff, 0xff));
	palette.set_pen_color(4, rgb_t(0x00, 0x00, 0x00));
	palette.set_pen_color(5, rgb_t(0x00, 0x00, 0x00));
	palette.set_pen_color(6, rgb_t(0xff, 0xff, 0xff));
	palette.set_pen_color(7, rgb_t(0xff, 0xff, 0xff));
	palette.set_pen_color(8, rgb_t(0xff, 0xff, 0xff));   // 4 color tiles
	palette.set_pen_color(9, rgb_t(0xb0, 0xb0, 0xb0));
	palette.set_pen_color(10,rgb_t(0x5f, 0x5f, 0x5f));
	palette.set_pen_color(11,rgb_t(0x00, 0x00, 0x00));
	palette.set_pen_color(12,rgb_t(0xff, 0xff, 0xff));
	palette.set_pen_color(13,rgb_t(0x5f, 0x5f, 0x5f));
	palette.set_pen_color(14,rgb_t(0xb0, 0xb0, 0xb0));
	palette.set_pen_color(15,rgb_t(0x00, 0x00, 0x00));
}


void dragrace_state::machine_start()
{
	m_gear_sel.resolve();
	m_tacho_sel.resolve();

	save_item(NAME(m_gear));
}

void dragrace_state::machine_reset()
{
	m_gear[0] = 0;
	m_gear[1] = 0;
}

void dragrace_state::dragrace(machine_config &config)
{
	// basic machine hardware
	M6800(config, m_maincpu, 12.096_MHz_XTAL / 12);
	m_maincpu->set_addrmap(AS_PROGRAM, &dragrace_state::main_map);
	m_maincpu->set_periodic_int(FUNC(dragrace_state::irq0_line_hold), attotime::from_hz(4*60));

	WATCHDOG_TIMER(config, m_watchdog).set_vblank_count("screen", 8);

	TIMER(config, "frame_timer").configure_periodic(FUNC(dragrace_state::frame_callback), attotime::from_hz(60));

	// video hardware
	SCREEN(config, m_screen, SCREEN_TYPE_RASTER);
	m_screen->set_refresh_hz(60);
	m_screen->set_size(256, 262);
	m_screen->set_visarea(0, 255, 0, 239);
	m_screen->set_screen_update(FUNC(dragrace_state::screen_update));
	m_screen->set_palette("palette");

	GFXDECODE(config, m_gfxdecode, "palette", gfx_dragrace);
	PALETTE(config, "palette", FUNC(dragrace_state::palette), 16);

	// sound hardware
	SPEAKER(config, "lspeaker").front_left();
	SPEAKER(config, "rspeaker").front_right();

	DISCRETE(config, m_discrete, dragrace_discrete);
	m_discrete->add_route(0, "lspeaker", 1.0);
	m_discrete->add_route(1, "rspeaker", 1.0);

	f9334_device &latch_f5(F9334(config, "latch_f5")); // F5
	latch_f5.parallel_out_cb().set(FUNC(dragrace_state::speed1_w)).mask(0x1f); // set 3SPEED1-7SPEED1
	latch_f5.q_out_cb<5>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_EXPLODE1_EN>)); // Explosion1 enable
	latch_f5.q_out_cb<6>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_SCREECH1_EN>)); // Screech1 enable

	f9334_device &latch_a5(F9334(config, "latch_a5")); // A5
	latch_a5.q_out_cb<1>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_KLEXPL1_EN>)); // KLEXPL1 enable
	latch_a5.q_out_cb<3>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_MOTOR1_EN>)); // Motor1 enable
	latch_a5.q_out_cb<4>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_ATTRACT_EN>)); // Attract enable
	latch_a5.q_out_cb<5>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_LOTONE_EN>)); // LoTone enable
	latch_a5.q_out_cb<7>().set_output("led0"); // Player 1 Start Lamp

	f9334_device &latch_h5(F9334(config, "latch_h5")); // H5
	latch_h5.parallel_out_cb().set(FUNC(dragrace_state::speed2_w)).mask(0x1f); // set 3SPEED2-7SPEED2
	latch_h5.q_out_cb<5>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_EXPLODE2_EN>)); // Explosion2 enable
	latch_h5.q_out_cb<6>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_SCREECH2_EN>)); // Screech2 enable

	f9334_device &latch_e5(F9334(config, "latch_e5")); // E5
	latch_e5.q_out_cb<1>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_KLEXPL2_EN>)); // KLEXPL2 enable
	latch_e5.q_out_cb<3>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_MOTOR2_EN>)); // Motor2 enable
	latch_e5.q_out_cb<5>().set(m_discrete, FUNC(discrete_device::write_line<DRAGRACE_HITONE_EN>)); // HiTone enable
	latch_e5.q_out_cb<7>().set_output("led1"); // Player 2 Start Lamp
}


ROM_START( dragrace )
	ROM_REGION( 0x10000, "maincpu", 0 )
	ROM_LOAD( "8513.c1", 0x1000, 0x0800, CRC(543bbb30) SHA1(646a41d1124c8365f07a93de38af007895d7d263) )
	ROM_LOAD( "8514.a1", 0x1800, 0x0800, CRC(ad218690) SHA1(08ba5f4fa4c75d8dad1a7162888d44b3349cbbe4) )
	ROM_RELOAD(          0xf800, 0x0800 )

	ROM_REGION( 0x800, "gfx1", 0 )   // 2 color tiles
	ROM_LOAD( "8519dr.j0", 0x000, 0x200, CRC(aa221ba0) SHA1(450acbf349d77a790a25f3e303c31b38cc426a38) )
	ROM_LOAD( "8521dr.k0", 0x200, 0x200, CRC(0cb33f12) SHA1(d50cb55391aec03e064eecad1624d50d4c30ccab) )
	ROM_LOAD( "8520dr.r0", 0x400, 0x200, CRC(ee1ae6a7) SHA1(83491095260c8b7c616ff17ec1e888d05620f166) )

	ROM_REGION( 0x800, "gfx2", 0 )   // 4 color tiles
	ROM_LOAD( "8515dr.e0", 0x000, 0x200, CRC(9510a59e) SHA1(aea0782b919279efe55a07007bd55a16f7f59239) )
	ROM_LOAD( "8517dr.h0", 0x200, 0x200, CRC(8b5bff1f) SHA1(fdcd719c66bff7c4b9f3d56d1e635259dd8add61) )
	ROM_LOAD( "8516dr.l0", 0x400, 0x200, CRC(d1e74af1) SHA1(f55a3bfd7d152ac9af128697f55c9a0c417779f5) )
	ROM_LOAD( "8518dr.n0", 0x600, 0x200, CRC(b1369028) SHA1(598a8779982d532c9f34345e793a79fcb29cac62) )

	ROM_REGION( 0x100, "sync", 0 )  // sync prom located at L8, it's a 82s129
	ROM_LOAD( "l8.bin", 0x000, 0x100, CRC(3610b453) SHA1(9e33ee04f22a9174c29fafb8e71781fa330a7a08) )
ROM_END


GAMEL( 1977, dragrace, 0, dragrace, dragrace, dragrace_state, empty_init, 0, "Atari (Kee Games)", "Drag Race", MACHINE_SUPPORTS_SAVE, layout_dragrace )
