// license:BSD-3-Clause
// copyright-holders:Carl, Brian Johnson
/***************************************************************************

    Epson QX-10 Keyboard Interface

***************************************************************************/

#include "emu.h"
#include "keyboard.h"

#include "matrix.h"

#include "cpu/mcs48/mcs48.h"

static const unsigned char layout_qx10hasci_data[] = {
	120, 156, 173, 213, 221, 110, 130,  48,  20,   7, 240, 251,  61,  69, 211,   7,  16,  10, 162,  94,   0, 198, 232, 146,  45,  49, 203,  50,  47, 118, 141, 112,
	208, 198,  82,  22,  90, 252, 120, 251, 149,  15,   1, 113, 196,  44, 245,  10,  78, 128, 223, 191, 112, 218, 226, 206, 207,   9,  67,  71, 200,   4,  77, 185,
	135, 201, 200, 196, 115, 223,  77, 130,   4,  88, 112,  73, 115, 217,  94, 178, 176, 239,   2, 131,   4, 184,  68,  92,  93, 247,  48, 131,   8, 163,   8,  98,
	 33,   3, 169,  74, 162, 110, 136, 168,  56, 160, 186,  54,  85,  29, 166,  44, 205,  80,   6, 145,  42,  71,  83,   7, 163,  93,   6, 192, 139, 194, 196, 104,
	203, 114, 168,  78,  13, 223,  53, 138,  71, 111,   1, 210,   7,  44, 243,  49,  96, 212,  99, 236,  15,  54,  12, 126,   4,  75, 195, 131,  50,  37, 156, 165,
	202, 200,  40, 223, 121, 120, 185, 248, 220, 220, 230,  20, 223, 224,  26,  67, 218,  24,  82, 199,  20,  79,  15, 199,  80,  46,  32, 147, 253, 144, 247, 143,
	103, 102, 136, 152, 220, 191, 197, 122, 249, 212,   4, 171, 159, 176,  89, 190, 189, 174, 158,  26,  97, 247,  35,  86,  95, 139, 111, 173, 132,  35, 133,  83,
	205, 175,  32,  14, 114,  38, 209, 186, 156, 197,  74,  21,  97, 193,  32, 202,  35,  56,  87, 115, 115, 155, 230,  60,  18, 168, 172, 208, 197, 195, 182,  58,
	156, 104,  36, 247,  30, 158, 140, 213, 249,  30, 232, 110,  47,  61,  60, 158,  85, 105, 149, 240, 199,  34, 176, 177,  26, 109,  92, 173, 135,  46, 107, 219,
	165,  75, 166, 141,  75,  58,  44, 169, 212, 129, 207, 163,  44, 107, 128, 117, 244, 216, 233,   0,  59, 211,  99,  39,   3,  44,  49, 245,  92, 103, 200, 181,
	116, 220,  96,  11, 140, 212, 114, 103, 103, 232, 244, 142, 148, 122,  59,  37, 136, 211, 193, 157, 135, 248, 181, 121, 205, 126, 208, 233, 159,  38, 125, 157,
	110, 213,  54, 208, 105, 160, 166,  59, 110,  92, 171, 215,  65,  77, 216, 105,  96, 187, 215, 194, 255, 192,  70, 177, 186, 213, 161, 253,  55, 249,  47, 191,
	 62,  87,  23, 191
};

const internal_layout layout_qx10hasci = {
	1726, sizeof(layout_qx10hasci_data), internal_layout::compression::ZLIB, layout_qx10hasci_data
};

static const unsigned char layout_qx10ascii_data[] = {
	120, 156, 173, 213, 221, 106, 131,  48,  24,   6, 224, 243,  93,  69, 200,   5,  84, 163, 177, 237, 129,  90, 198, 198,  96,  48, 198, 160,  87,  96, 245, 179,
	 13, 141, 113, 152, 216, 159, 187,  95, 252, 169,  58,  59,  41,  35,  30, 233, 135, 250, 188,  34, 111, 162, 191, 185, 100,  28, 157, 160, 144,  44,  23,   1,
	 38,  11,  27, 111,  66,  63, 139,  50, 224, 209,  53,  47,  85, 127, 201, 193, 161,  15,  28,  50,  16,  10,   9, 125,  61, 192,  28,  18, 140,  18,  72, 165,
	138, 148,  30, 137, 190,  33,  97, 242, 136, 218, 217, 214, 115, 156, 243, 188,  64,   5,  36, 122,  92, 172,  60, 140, 246,   5, 128, 168,   6,  27, 163,  29,
	 47, 161,  57, 181,  66, 223, 170,  30, 253,  13, 144,  49, 224, 216, 143,   1, 171, 125, 199, 241, 203, 198, 209, 183, 228, 121, 124, 212, 166, 130, 139, 210,
	 25,   5,  19, 251,   0, 191,  60, 127, 109, 127, 231,  84, 223, 224,  22,  67, 250,  24, 210, 198,  84,  79,  79, 199,  48,  33, 161,  80, 227, 144, 247, 207,
	 57,  51, 100,  74, 198,   1, 219,  55,  50, 107, 128, 115,  31, 224, 204,  26, 224, 222,   7, 184, 179,   6, 208, 251,   0, 106,  20, 112,  98, 112, 110, 245,
	 87,  72, 163, 146,  43, 244,  81,  47,  17, 173, 202, 184,  98,  16,  19,   9,  92, 154, 226, 239, 242,  82,  36,  18, 213,  19, 186,   6, 216, 213, 135,  51,
	 75, 212,  33, 192,  75, 170, 207,  15, 192, 246,   7,  21,  96, 186, 110, 210,  26, 225, 143,  21, 166, 239,  45,  32, 109,  22, 219, 144, 117, 221, 218,  37,
	171, 206,  37,   3, 150,  52, 234, 196, 215, 209, 150,  51, 193, 122, 102, 236, 106, 130,  93, 155, 177, 203,   9, 150, 216, 102, 174,  55, 229,  58, 102,  46,
	157, 114, 169, 137,  27, 237, 128, 147,  86,  30, 108, 103, 131,  78, 144,  90, 239, 171,  70, 188,   1, 238,  61, 196, 111, 165, 232,  54, 177,  65,  47,  12,
	105, 183, 165, 155, 189, 107,  80,  12,  67, 151, 118, 174,  51, 106, 134,  33, 236, 117, 176,  59, 170, 134,  33, 188, 236,  96,  58, 234, 198, 127,  96, 171,
	218, 142, 244, 161, 255,  83, 135,  79,  63, 147, 105, 106, 160
};

const internal_layout layout_qx10ascii = {
	1996, sizeof(layout_qx10ascii_data), internal_layout::compression::ZLIB, layout_qx10ascii_data
};



//**************************************************************************
//  DEVICE DEFINITIONS
//**************************************************************************

DEFINE_DEVICE_TYPE(EPSON_QX_KEYBOARD_PORT, bus::epson_qx::keyboard::keyboard_port_device, "epson_qx_kbd", "Epson QX-10 Keyboard Port")
DEFINE_DEVICE_TYPE(QX10_KEYBOARD_HASCI, bus::epson_qx::keyboard::qx10_keyboard_hasci, "qx10_keyboard_hasci", "Epson QX-10 Keyboard (HASCI)")
DEFINE_DEVICE_TYPE(QX10_KEYBOARD_ASCII, bus::epson_qx::keyboard::qx10_keyboard_ascii, "qx10_keyboard_ascii", "Epson QX-10 Keyboard (ASCII)")


namespace bus::epson_qx::keyboard {

//**************************************************************************
//  SLOT DEVICE
//**************************************************************************

//-------------------------------------------------
//  keyboard_port_device - constructor
//-------------------------------------------------

keyboard_port_device::keyboard_port_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock)
	: device_t(mconfig, EPSON_QX_KEYBOARD_PORT, tag, owner, clock)
	, device_single_card_slot_interface<keyboard_device>(mconfig, *this)
	, m_kbd(nullptr)
	, m_txd_handler(*this)
{
}

//-------------------------------------------------
//  device_start - device-specific startup
//-------------------------------------------------

void keyboard_port_device::device_start()
{
	// resolve callbacks
	m_txd_handler.resolve_safe();
}

//-------------------------------------------------
//  device_reset - device-specific reset
//-------------------------------------------------

void keyboard_port_device::device_reset()
{
	// get connected keyboard
	m_kbd = get_card_device();
}

WRITE_LINE_MEMBER( keyboard_port_device::txd_w )
{
	m_txd_handler(state);
}

//-------------------------------------------------
//
//  host to module interface
//-------------------------------------------------

WRITE_LINE_MEMBER( keyboard_port_device::rxd_w )
{
	if (m_kbd)
		m_kbd->rxd_w(state);
}

WRITE_LINE_MEMBER( keyboard_port_device::clk_w )
{
	if (m_kbd)
		m_kbd->clk_w(state);
}

ROM_START(qx10kbd)
	ROM_REGION(0x0800, "mcu", 0)
	ROM_LOAD("mbl8049h.5a", 0x0000, 0x0800, CRC(8615e159) SHA1(26b7f447acfe2c605dbe0fc98e6c777f0fa8a94d))
ROM_END

//**************************************************************************
//  KEYBOARD DEVICE
//**************************************************************************

//-------------------------------------------------
//  keyboard_device - constructor
//-------------------------------------------------

keyboard_device::keyboard_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, uint32_t clock)
	: device_t(mconfig, type, tag, owner, clock)
	, device_interface(*this, "epson_qx_kbd")
	, m_rows(*this, "LINE%X", 0U)
	, m_mcu(*this, "mcu")
	, m_leds(*this, "led%u", 0U)
{
	m_host = dynamic_cast<keyboard_port_device *>(this->owner());
}

tiny_rom_entry const *keyboard_device::device_rom_region() const
{
	return ROM_NAME(qx10kbd);
}

void keyboard_device::device_add_mconfig(machine_config &config)
{
	auto &mcu(I8049(config, "mcu", 11_MHz_XTAL));
	mcu.p1_out_cb().set(FUNC(keyboard_device::mcu_p1_w));
	mcu.p2_out_cb().set(FUNC(keyboard_device::mcu_p2_w));
	mcu.bus_in_cb().set([this]() { return m_rows[m_row]->read(); });
	mcu.t1_in_cb().set([this]() { return m_rxd; });
	mcu.t0_in_cb().set([this]() { return m_clk_state; });

	config.set_default_layout(layout());
}

void keyboard_device::device_start()
{
	m_leds.resolve();

	m_clk_state = 0;

	save_item(NAME(m_rxd));
	save_item(NAME(m_row));
	save_item(NAME(m_clk_state));
}

void keyboard_device::mcu_p1_w(uint8_t data)
{
	m_row = data & 0xf;
	m_host->txd_w(BIT(data, 7));
}

void keyboard_device::mcu_p2_w(uint8_t data)
{
	for (int i = 0; i < 8; ++i) {
		m_leds[i] = BIT(data, i);
	}
}

WRITE_LINE_MEMBER(keyboard_device::rxd_w)
{
	m_rxd = state;
}

WRITE_LINE_MEMBER(keyboard_device::clk_w)
{
	m_clk_state = !state;
}

//**************************************************************************
//  HASCI KEYBOARD DEVICE
//**************************************************************************

qx10_keyboard_hasci::qx10_keyboard_hasci(const machine_config& mconfig, const char* tag, device_t* owner, uint32_t clock)
	: keyboard_device(mconfig, QX10_KEYBOARD_HASCI, tag, owner, clock)
{
}

ioport_constructor qx10_keyboard_hasci::device_input_ports() const
{
	return INPUT_PORTS_NAME(qx10_keyboard_hasci);
}

const internal_layout &qx10_keyboard_hasci::layout() const
{
	return layout_qx10hasci;
}

//**************************************************************************
//  ASCII KEYBOARD DEVICE
//**************************************************************************

qx10_keyboard_ascii::qx10_keyboard_ascii(const machine_config& mconfig, const char* tag, device_t* owner, uint32_t clock)
	: keyboard_device(mconfig, QX10_KEYBOARD_ASCII, tag, owner, clock)
{
}

ioport_constructor qx10_keyboard_ascii::device_input_ports() const
{
	return INPUT_PORTS_NAME(qx10_keyboard_ascii);
}

const internal_layout &qx10_keyboard_ascii::layout() const
{
	return layout_qx10ascii;
}

void keyboard_devices(device_slot_interface &device)
{
	device.option_add("qx10_hasci", QX10_KEYBOARD_HASCI);
	device.option_add("qx10_ascii", QX10_KEYBOARD_ASCII);
}

}
