// license:BSD-3-Clause
// copyright-holders:Aaron Giles
/***************************************************************************

    Incredible Technologies/Strata system
    (32-bit blitter variant)

***************************************************************************/

#include "emu.h"
#include "cpu/m68000/m68000.h"
#include "itech32.h"
#include "render.h"
#include <algorithm>


/*************************************
 *
 *  Debugging
 *
 *************************************/

#define BLIT_LOGGING            0



/*************************************
 *
 *  Blitter constants
 *
 *************************************/

#define VIDEO_UNKNOWN00         m_video[0x00/2] /* $0087 at startup */
#define VIDEO_STATUS            m_video[0x00/2]
#define VIDEO_INTSTATE          m_video[0x02/2]
#define VIDEO_INTACK            m_video[0x02/2]
#define VIDEO_TRANSFER          m_video[0x04/2]
#define VIDEO_TRANSFER_FLAGS    m_video[0x06/2] /* $5080 at startup (kept at $1512) */
#define VIDEO_COMMAND           m_video[0x08/2] /* $0005 at startup */
#define VIDEO_INTENABLE         m_video[0x0a/2] /* $0144 at startup (kept at $1514) */
#define VIDEO_TRANSFER_HEIGHT   m_video[0x0c/2]
#define VIDEO_TRANSFER_WIDTH    m_video[0x0e/2]
#define VIDEO_TRANSFER_ADDRLO   m_video[0x10/2]
#define VIDEO_TRANSFER_X        m_video[0x12/2]
#define VIDEO_TRANSFER_Y        m_video[0x14/2]
#define VIDEO_SRC_YSTEP         m_video[0x16/2] /* $0011 at startup */
#define VIDEO_SRC_XSTEP         m_video[0x18/2]
#define VIDEO_DST_XSTEP         m_video[0x1a/2]
#define VIDEO_DST_YSTEP         m_video[0x1c/2]
#define VIDEO_YSTEP_PER_X       m_video[0x1e/2]
#define VIDEO_XSTEP_PER_Y       m_video[0x20/2]
#define VIDEO_UNKNOWN22         m_video[0x22/2] /* $0033 at startup */
#define VIDEO_LEFTCLIP          m_video[0x24/2]
#define VIDEO_RIGHTCLIP         m_video[0x26/2]
#define VIDEO_TOPCLIP           m_video[0x28/2]
#define VIDEO_BOTTOMCLIP        m_video[0x2a/2]
#define VIDEO_INTSCANLINE       m_video[0x2c/2] /* $00ef at startup */
#define VIDEO_TRANSFER_ADDRHI   m_video[0x2e/2] /* $0000 at startup */

#define VIDEO_UNKNOWN30         m_video[0x30/2] /* $0040 at startup */
#define VIDEO_VTOTAL            m_video[0x32/2] /* $0106 at startup */
#define VIDEO_VSYNC             m_video[0x34/2] /* $0101 at startup */
#define VIDEO_VBLANK_START      m_video[0x36/2] /* $00f3 at startup */
#define VIDEO_VBLANK_END        m_video[0x38/2] /* $0003 at startup */
#define VIDEO_HTOTAL            m_video[0x3a/2] /* $01fc at startup */
#define VIDEO_HSYNC             m_video[0x3c/2] /* $01e4 at startup */
#define VIDEO_HBLANK_START      m_video[0x3e/2] /* $01b2 at startup */
#define VIDEO_HBLANK_END        m_video[0x40/2] /* $0032 at startup */
#define VIDEO_UNKNOWN42         m_video[0x42/2] /* $0015 at startup */
#define VIDEO_DISPLAY_YORIGIN1  m_video[0x44/2] /* $0000 at startup */
#define VIDEO_DISPLAY_YORIGIN2  m_video[0x46/2] /* $0000 at startup */
#define VIDEO_DISPLAY_YSCROLL2  m_video[0x48/2] /* $0000 at startup */
#define VIDEO_UNKNOWN4a         m_video[0x4a/2] /* $0000 at startup */
#define VIDEO_DISPLAY_XORIGIN1  m_video[0x4c/2] /* $0000 at startup */
#define VIDEO_DISPLAY_XORIGIN2  m_video[0x4e/2] /* $0000 at startup */
#define VIDEO_DISPLAY_XSCROLL2  m_video[0x50/2] /* $0000 at startup */
#define VIDEO_UNKNOWN52         m_video[0x52/2] /* $0000 at startup */
#define VIDEO_UNKNOWN54         m_video[0x54/2] /* $0080 at startup */
#define VIDEO_UNKNOWN56         m_video[0x56/2] /* $00c0 at startup */
#define VIDEO_UNKNOWN58         m_video[0x58/2] /* $01c0 at startup */
#define VIDEO_UNKNOWN5a         m_video[0x5a/2] /* $01c0 at startup */
#define VIDEO_UNKNOWN5c         m_video[0x5c/2] /* $01cf at startup */
#define VIDEO_UNKNOWN5e         m_video[0x5e/2] /* $01cf at startup, kept $01bf in running game, $01c3 at testing */
#define VIDEO_UNKNOWN60         m_video[0x60/2] /* $01e3 at startup */
#define VIDEO_UNKNOWN62         m_video[0x62/2] /* $01cf at startup */
#define VIDEO_UNKNOWN64         m_video[0x64/2] /* $01ff at startup */
#define VIDEO_UNKNOWN66         m_video[0x66/2] /* $0183 at startup, kept $01bf in running game, $1ff at testing */
#define VIDEO_UNKNOWN68         m_video[0x68/2] /* $01ff at startup */
#define VIDEO_UNKNOWN6a         m_video[0x6a/2] /* $000f at startup */
#define VIDEO_UNKNOWN6c         m_video[0x6c/2] /* $018f at startup */
#define VIDEO_UNKNOWN6e         m_video[0x6e/2] /* $01ff at startup, kept $01ff in running game, $01c3 at testing */
#define VIDEO_UNKNOWN70         m_video[0x70/2] /* $000f at startup */
#define VIDEO_UNKNOWN72         m_video[0x72/2] /* $000f at startup */
#define VIDEO_UNKNOWN74         m_video[0x74/2] /* $01ff at startup */
#define VIDEO_UNKNOWN76         m_video[0x76/2] /* $01ff at startup */
#define VIDEO_UNKNOWN78         m_video[0x78/2] /* $01ff at startup */
#define VIDEO_UNKNOWN7a         m_video[0x7a/2] /* $01ff at startup */
#define VIDEO_UNKNOWN7c         m_video[0x7c/2] /* $0820 at startup */
#define VIDEO_UNKNOWN7e         m_video[0x7e/2] /* $0100 at startup */

#define VIDEO_STARTSTEP         m_video[0x80/2] /* drivedge only? */
#define VIDEO_LEFTSTEPLO        m_video[0x82/2] /* drivedge only? */
#define VIDEO_LEFTSTEPHI        m_video[0x84/2] /* drivedge only? */
#define VIDEO_RIGHTSTEPLO       m_video[0x86/2] /* drivedge only? */
#define VIDEO_RIGHTSTEPHI       m_video[0x88/2] /* drivedge only? */

#define VIDEOINT_SCANLINE       0x0004
#define VIDEOINT_BLITTER        0x0040

#define XFERFLAG_TRANSPARENT    0x0001
#define XFERFLAG_XFLIP          0x0002
#define XFERFLAG_YFLIP          0x0004
#define XFERFLAG_DSTXSCALE      0x0008
#define XFERFLAG_DYDXSIGN       0x0010
#define XFERFLAG_DXDYSIGN       0x0020
#define XFERFLAG_UNKNOWN8       0x0100
#define XFERFLAG_CLIP           0x0400
#define XFERFLAG_WIDTHPIX       0x8000

#define XFERFLAG_KNOWNFLAGS     (XFERFLAG_TRANSPARENT | XFERFLAG_XFLIP | XFERFLAG_YFLIP | XFERFLAG_DSTXSCALE | XFERFLAG_DYDXSIGN | XFERFLAG_DXDYSIGN | XFERFLAG_CLIP | XFERFLAG_WIDTHPIX)

#define VRAM_WIDTH              512







/*************************************
 *
 *  Macros and inlines
 *
 *************************************/

#define ADJUSTED_HEIGHT(x) ((((x) >> 1) & 0x100) | ((x) & 0xff))

inline offs_t itech32_state::compute_safe_address(int x, int y)
{
	return ((y & m_vram_ymask) * 512) + (x & m_vram_xmask);
}

inline void itech32_state::disable_clipping()
{
	m_clip_save = m_clip_rect;
	m_clip_rect.set(0, 0xfff, 0, 0xfff);
	m_scaled_clip_rect.set(0, 0xfff << 8, 0, 0xfff << 8);
}

inline void itech32_state::enable_clipping()
{
	m_clip_rect = m_clip_save;

	m_scaled_clip_rect.min_x = m_clip_rect.min_x << 8;
	m_scaled_clip_rect.max_x = m_clip_rect.max_x << 8;
	m_scaled_clip_rect.min_y = m_clip_rect.min_y << 8;
	m_scaled_clip_rect.max_y = m_clip_rect.max_y << 8;
}



/*************************************
 *
 *  Video start
 *
 *************************************/

void itech32_state::video_start()
{
	int i;

	/* allocate memory */
	m_videoram = std::make_unique<u16[]>(VRAM_WIDTH * (m_vram_height + 16) * 2);
	std::fill_n(&m_videoram[0], VRAM_WIDTH * (m_vram_height + 16) * 2, 0xff);

	/* videoplane[0] is the foreground; videoplane[1] is the background */
	m_videoplane[0] = &m_videoram[0 * VRAM_WIDTH * (m_vram_height + 16) + 8 * VRAM_WIDTH];
	m_videoplane[1] = &m_videoram[1 * VRAM_WIDTH * (m_vram_height + 16) + 8 * VRAM_WIDTH];

	/* set the masks */
	m_vram_mask = VRAM_WIDTH * m_vram_height - 1;
	m_vram_xmask = VRAM_WIDTH - 1;
	m_vram_ymask = m_vram_height - 1;

	/* clear the planes initially */
	for (i = 0; i < VRAM_WIDTH * m_vram_height; i++)
		m_videoplane[0][i] = m_videoplane[1][i] = 0xff;

	/* fetch the GROM base */
	m_grom_bank = 0;
	m_grom_bank_mask = m_grom.length() >> 24;
	if (m_grom_bank_mask == 2)
		m_grom_bank_mask = 3;

	/* reset statics */
	std::fill_n(&m_video[0], m_video.bytes() >> 1, 0);

	m_scanline_timer = timer_alloc(FUNC(itech32_state::scanline_interrupt), this);
	m_enable_latch[0] = 1;
	m_enable_latch[1] = (m_planes > 1) ? 1 : 0;

	save_item(NAME(m_xfer_xcount));
	save_item(NAME(m_xfer_ycount));
	save_item(NAME(m_xfer_xcur));
	save_item(NAME(m_xfer_ycur));
	save_item(NAME(m_grom_bank));
	save_item(NAME(m_color_latch));
	save_item(NAME(m_enable_latch));
	save_pointer(NAME(m_videoram), VRAM_WIDTH * (m_vram_height + 16) * 2);
}

void shoottv_state::video_start()
{
	itech32_state::video_start();
	m_gun_timer = timer_alloc(FUNC(shoottv_state::gun_interrupt), this);
	m_gun_timer->adjust(m_screen->time_until_pos(0));
}



/*************************************
 *
 *  Latches
 *
 *************************************/

void itech32_state::timekill_colora_w(u8 data)
{
	m_enable_latch[0] = (~data >> 5) & 1;
	m_enable_latch[1] = (~data >> 7) & 1;
	m_color_latch[0] = (data & 0x0f) << 8;
}


void itech32_state::timekill_colorbc_w(u8 data)
{
	m_color_latch[1] = ((data & 0xf0) << 4) | 0x1000;
}


void itech32_state::timekill_intensity_w(u8 data)
{
	double intensity = (double)(data & 0xff) / (double)0x60;
	for (int i = 0; i < 8192; i++)
		m_palette->set_pen_contrast(i, intensity);
}


void itech32_state::bloodstm_plane_w(u8 data)
{
	m_enable_latch[0] = (~data >> 1) & 1;
	m_enable_latch[1] = (~data >> 2) & 1;
}


void itech32_state::itech020_plane_w(u8 data)
{
	m_enable_latch[0] = (~data >> 1) & 1;
	m_enable_latch[1] = (~data >> 2) & 1;
	m_grom_bank = ((data >> 6) & m_grom_bank_mask) << 24;
}



/*************************************
 *
 *  Palette I/O
 *
 *************************************/

void itech32_state::bloodstm_paletteram_w(offs_t offset, u16 data, u16 mem_mask)
{
	/* in test mode, the LSB is used; in game mode, the MSB is used */
	if (!ACCESSING_BITS_0_7 && (offset & 1))
	{
		data >>= 8;
		mem_mask >>= 8;
	}

	m_palette->write16(offset, data, mem_mask);
}



/*************************************
 *
 *  Debugging
 *
 *************************************/

void drivedge_state::logblit(const char *tag)
{
	if (!machine().input().code_pressed(KEYCODE_L))
		return;

	if (VIDEO_TRANSFER_FLAGS == 0x5490)
	{
		/* polygon drawing */
		logerror("%s: e=%d%d f=%04x s=(%03x-%03x,%03x) w=%03x h=%03x b=%02x%04x c=%02x%02x ss=%04x,%04x ds=%04x,%04x ls=%04x%04x rs=%04x%04x u80=%04x", tag,
			m_enable_latch[0], m_enable_latch[1],
			VIDEO_TRANSFER_FLAGS,
			VIDEO_TRANSFER_X, VIDEO_RIGHTCLIP, VIDEO_TRANSFER_Y, VIDEO_TRANSFER_WIDTH, VIDEO_TRANSFER_HEIGHT,
			VIDEO_TRANSFER_ADDRHI, VIDEO_TRANSFER_ADDRLO,
			m_color_latch[0] >> 8, m_color_latch[1] >> 8,
			VIDEO_SRC_XSTEP, VIDEO_SRC_YSTEP,
			VIDEO_DST_XSTEP, VIDEO_DST_YSTEP,
			VIDEO_LEFTSTEPHI, VIDEO_LEFTSTEPLO, VIDEO_RIGHTSTEPHI, VIDEO_RIGHTSTEPLO,
			VIDEO_STARTSTEP);
		logerror(" v0=%08x v1=%08x v2=%08x v3=%08x\n", m_zbuf_control[0], m_zbuf_control[1], m_zbuf_control[2], m_zbuf_control[3]);
	}
	else
	{
		itech32_state::logblit(tag);
	}
}

void itech32_state::logblit(const char *tag)
{
	if (!machine().input().code_pressed(KEYCODE_L))
		return;

	if (m_video[0x16/2] == 0x100 && m_video[0x18/2] == 0x100 &&
		m_video[0x1a/2] == 0x000 && m_video[0x1c/2] == 0x100 &&
		m_video[0x1e/2] == 0x000 && m_video[0x20/2] == 0x000)
	{
		logerror("%s: e=%d%d f=%04x c=%02x%02x %02x%04x -> (%03x,%03x) %3dx%3dc=(%03x,%03x)-(%03x,%03x)", tag,
				m_enable_latch[0], m_enable_latch[1],
				VIDEO_TRANSFER_FLAGS,
				m_color_latch[0] >> 8, m_color_latch[1] >> 8,
				VIDEO_TRANSFER_ADDRHI, VIDEO_TRANSFER_ADDRLO,
				VIDEO_TRANSFER_X, VIDEO_TRANSFER_Y,
				VIDEO_TRANSFER_WIDTH, ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT),
				VIDEO_LEFTCLIP, VIDEO_TOPCLIP, VIDEO_RIGHTCLIP, VIDEO_BOTTOMCLIP);
	}
	else
	{
		logerror("%s: e=%d%d f=%04x c=%02x%02x %02x%04x -> (%03x,%03x) %3dx%d c=(%03x,%03x)-(%03x,%03x) s=%04x %04x %04x %04x %04x %04x", tag,
				m_enable_latch[0], m_enable_latch[1],
				VIDEO_TRANSFER_FLAGS,
				m_color_latch[0] >> 8, m_color_latch[1] >> 8,
				VIDEO_TRANSFER_ADDRHI, VIDEO_TRANSFER_ADDRLO,
				VIDEO_TRANSFER_X, VIDEO_TRANSFER_Y,
				VIDEO_TRANSFER_WIDTH, ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT),
				VIDEO_LEFTCLIP, VIDEO_TOPCLIP, VIDEO_RIGHTCLIP, VIDEO_BOTTOMCLIP,
				m_video[0x16/2], m_video[0x18/2], m_video[0x1a/2],
				m_video[0x1c/2], m_video[0x1e/2], m_video[0x20/2]);
	}
	logerror("\n");
}



/*************************************
 *
 *  Video interrupts
 *
 *************************************/

void itech32_state::update_interrupts(int fast)
{
	int scanline_state = 0, blitter_state = 0;

	if (VIDEO_INTSTATE & VIDEO_INTENABLE & VIDEOINT_SCANLINE)
		scanline_state = 1;
	if (VIDEO_INTSTATE & VIDEO_INTENABLE & VIDEOINT_BLITTER)
		blitter_state = 1;

	update_interrupts(-1, blitter_state, scanline_state);
}


TIMER_CALLBACK_MEMBER(itech32_state::scanline_interrupt)
{
	/* set timer for next frame */
	m_scanline_timer->adjust(m_screen->time_until_pos(VIDEO_INTSCANLINE));

	/* set the interrupt bit in the status reg */
	//logerror("-------------- (DISPLAY INT @ %d) ----------------\n", m_screen->vpos());
	VIDEO_INTSTATE |= VIDEOINT_SCANLINE;

	/* update the interrupt state */
	update_interrupts(0);
}


TIMER_CALLBACK_MEMBER(shoottv_state::gun_interrupt)
{
	s32 vpos = m_screen->vpos();
	if ((vpos & 0x1f) == 0)
		m_maincpu->set_input_line(5, ASSERT_LINE);
	if ((vpos & 0x1f) == 16)
		m_maincpu->set_input_line(6, ASSERT_LINE);
	m_gun_timer->adjust(m_screen->time_until_pos((vpos + 1) % m_screen->height()));
}

/*************************************
 *
 *  Uncompressed blitter functions
 *
 *************************************/

void itech32_state::draw_raw(u16 *base, u16 color)
{
	u8* src = &m_grom[0];// m_grom[(m_grom_bank | ((VIDEO_TRANSFER_ADDRHI & 0xff) << 16) | VIDEO_TRANSFER_ADDRLO) % m_grom.length()];
	const u32 grom_length = m_grom.length();
	const u32 grom_base = m_grom_bank | ((VIDEO_TRANSFER_ADDRHI & 0xff) << 16) | VIDEO_TRANSFER_ADDRLO;
	int transparent_pen = (VIDEO_TRANSFER_FLAGS & XFERFLAG_TRANSPARENT) ? 0xff : -1;
	int width = VIDEO_TRANSFER_WIDTH << 8;
	int height = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT) << 8;
	int xsrcstep = VIDEO_SRC_XSTEP;
	int ysrcstep = VIDEO_SRC_YSTEP;
	int sx, sy = (VIDEO_TRANSFER_Y & 0xfff) << 8;
	int startx = (VIDEO_TRANSFER_X & 0xfff) << 8;
	int xdststep = 0x100;
	int ydststep = VIDEO_DST_YSTEP;
	int x, y;

	/* adjust for (lack of) clipping */
	if (!(VIDEO_TRANSFER_FLAGS & XFERFLAG_CLIP))
		disable_clipping();

	/* adjust for scaling */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_DSTXSCALE)
		xdststep = VIDEO_DST_XSTEP;

	/* adjust for flipping */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_XFLIP)
		xdststep = -xdststep;
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_YFLIP)
		ydststep = -ydststep;

	/* loop over Y in src pixels */
	for (y = 0; y < height; y += ysrcstep, sy += ydststep)
	{
		const u32 row_base = (y >> 8) * (width >> 8);

		/* simpler case: VIDEO_YSTEP_PER_X is zero */
		if (VIDEO_YSTEP_PER_X == 0)
		{
			/* clip in the Y direction */
			if (sy >= m_scaled_clip_rect.min_y && sy < m_scaled_clip_rect.max_y)
			{
				u32 dstoffs;

				/* direction matters here */
				sx = startx;
				if (xdststep > 0)
				{
					/* skip left pixels */
					for (x = 0; x < width && sx < m_scaled_clip_rect.min_x; x += xsrcstep, sx += xdststep) ;

					/* compute the address */
					dstoffs = compute_safe_address(sx >> 8, sy >> 8) - (sx >> 8);

					/* render middle pixels */
					for ( ; x < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep)
					{
						int pixel = src[(grom_base + row_base + (x >> 8)) % grom_length];
						if (pixel != transparent_pen)
							base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
					}
				}
				else
				{
					/* skip right pixels */
					for (x = 0; x < width && sx >= m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep) ;

					/* compute the address */
					dstoffs = compute_safe_address(sx >> 8, sy >> 8) - (sx >> 8);

					/* render middle pixels */
					for ( ; x < width && sx >= m_scaled_clip_rect.min_x; x += xsrcstep, sx += xdststep)
					{
						int pixel = src[(grom_base + row_base + (x >> 8)) % grom_length];
						if (pixel != transparent_pen)
							base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
					}
				}
			}
		}

		/* slow case: VIDEO_YSTEP_PER_X is non-zero */
		else
		{
			int ystep = (VIDEO_TRANSFER_FLAGS & XFERFLAG_DYDXSIGN) ? -VIDEO_YSTEP_PER_X : VIDEO_YSTEP_PER_X;
			int ty = sy;

			/* render all pixels */
			sx = startx;
			for (x = 0; x < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep, ty += ystep)
				if (m_scaled_clip_rect.contains(sx, ty))
				{
					int pixel = src[(grom_base + row_base + (x >> 8)) % grom_length];
					if (pixel != transparent_pen)
						base[compute_safe_address(sx >> 8, ty >> 8)] = pixel | color;
				}
		}

		/* apply skew */
		if (VIDEO_TRANSFER_FLAGS & XFERFLAG_DXDYSIGN)
			startx += VIDEO_XSTEP_PER_Y;
		else
			startx -= VIDEO_XSTEP_PER_Y;
	}

	/* restore cliprects */
	if (!(VIDEO_TRANSFER_FLAGS & XFERFLAG_CLIP))
		enable_clipping();
}

/* draw a scaled primitive such that the specified width is in pixel, not scaled, coordinates */
void itech32_state::draw_raw_widthpix(u16 *base, u16 color)
{
	u8* src = &m_grom[0];// m_grom[(m_grom_bank | ((VIDEO_TRANSFER_ADDRHI & 0xff) << 16) | VIDEO_TRANSFER_ADDRLO) % m_grom.length()];
	const u32 grom_length = m_grom.length();
	const u32 grom_base = m_grom_bank | ((VIDEO_TRANSFER_ADDRHI & 0xff) << 16) | VIDEO_TRANSFER_ADDRLO;
	int transparent_pen = (VIDEO_TRANSFER_FLAGS & XFERFLAG_TRANSPARENT) ? 0xff : -1;
	int width = VIDEO_TRANSFER_WIDTH << 8;
	int height = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT) << 8;
	int xsrcstep = VIDEO_SRC_XSTEP;
	int ysrcstep = VIDEO_SRC_YSTEP;
	int sx, sy = (VIDEO_TRANSFER_Y & 0xfff) << 8;
	int startx = (VIDEO_TRANSFER_X & 0xfff) << 8;
	int xdststep = 0x100;
	int ydststep = VIDEO_DST_YSTEP;
	int x, y, px;

	/* adjust for (lack of) clipping */
	if (!(VIDEO_TRANSFER_FLAGS & XFERFLAG_CLIP))
		disable_clipping();

	/* adjust for scaling */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_DSTXSCALE)
		xdststep = VIDEO_DST_XSTEP;

	/* adjust for flipping */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_XFLIP)
		xdststep = -xdststep;
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_YFLIP)
		ydststep = -ydststep;

	/* loop over Y in src pixels */
	for (y = 0; y < height; y += ysrcstep, sy += ydststep)
	{
		const u32 row_base = (y >> 8) * (width >> 8);

		x = 0;
		px = 0;

		/* simpler case: VIDEO_YSTEP_PER_X is zero */
		if (VIDEO_YSTEP_PER_X == 0)
		{
			/* clip in the Y direction */
			if (sy >= m_scaled_clip_rect.min_y && sy < m_scaled_clip_rect.max_y)
			{
				u32 dstoffs;

				/* direction matters here */
				sx = startx;
				if (xdststep > 0)
				{
					/* skip left pixels */
					for ( ; px < width && sx < m_scaled_clip_rect.min_x; x += xsrcstep, px += 0x100, sx += xdststep) ;

					/* compute the address */
					dstoffs = compute_safe_address(sx >> 8, sy >> 8) - (sx >> 8);

					/* render middle pixels */
					for ( ; px < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, px += 0x100, sx += xdststep)
					{
						int pixel = src[(grom_base + row_base + (x >> 8)) % grom_length];
						if (pixel != transparent_pen)
							base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
					}
				}
				else
				{
					/* skip right pixels */
					for ( ; px < width && sx >= m_scaled_clip_rect.max_x; x += xsrcstep, px += 0x100, sx += xdststep) ;

					/* compute the address */
					dstoffs = compute_safe_address(sx >> 8, sy >> 8) - (sx >> 8);

					/* render middle pixels */
					for ( ; px < width && sx >= m_scaled_clip_rect.min_x; x += xsrcstep, px += 0x100, sx += xdststep)
					{
						int pixel = src[(grom_base + row_base + (x >> 8)) % grom_length];
						if (pixel != transparent_pen)
							base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
					}
				}
			}
		}

		/* slow case: VIDEO_YSTEP_PER_X is non-zero */
		else
		{
			int ystep = (VIDEO_TRANSFER_FLAGS & XFERFLAG_DYDXSIGN) ? -VIDEO_YSTEP_PER_X : VIDEO_YSTEP_PER_X;
			int ty = sy;

			/* render all pixels */
			sx = startx;
			for ( ; px < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, px += 0x100, sx += xdststep, ty += ystep)
				if (m_scaled_clip_rect.contains(sx, ty))
				{
					int pixel = src[(grom_base + row_base + (x >> 8)) % grom_length];
					if (pixel != transparent_pen)
						base[compute_safe_address(sx >> 8, ty >> 8)] = pixel | color;
				}
		}

		/* apply skew */
		if (VIDEO_TRANSFER_FLAGS & XFERFLAG_DXDYSIGN)
			startx += VIDEO_XSTEP_PER_Y;
		else
			startx -= VIDEO_XSTEP_PER_Y;
	}

	/* restore cliprects */
	if (!(VIDEO_TRANSFER_FLAGS & XFERFLAG_CLIP))
		enable_clipping();
}

void drivedge_state::draw_raw(u16 *base, u16 *zbase, u16 color)
{
	u8 *src = &m_grom[(m_grom_bank | ((VIDEO_TRANSFER_ADDRHI & 0xff) << 16) | VIDEO_TRANSFER_ADDRLO) % m_grom.length()];
	int transparent_pen = (VIDEO_TRANSFER_FLAGS & XFERFLAG_TRANSPARENT) ? 0xff : -1;
	int width = VIDEO_TRANSFER_WIDTH << 8;
	int height = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT) << 8;
	int xsrcstep = VIDEO_SRC_XSTEP;
	int ysrcstep = VIDEO_SRC_YSTEP;
	int sx, sy = ((VIDEO_TRANSFER_Y & 0xfff) << 8) + 0x80;
	int startx = ((VIDEO_TRANSFER_X & 0xfff) << 8) + 0x80;
	int xdststep = 0x100;
	int ydststep = VIDEO_DST_YSTEP;
	int32_t z0 = m_zbuf_control[2] & 0x7ff00;
	int32_t zmatch = (m_zbuf_control[2] & 0x1f) << 11;
	int32_t srcdelta = 0;
	int x, y;

	/* adjust for (lack of) clipping */
	if (!(VIDEO_TRANSFER_FLAGS & XFERFLAG_CLIP))
		disable_clipping();

	/* adjust for scaling */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_DSTXSCALE)
		xdststep = VIDEO_DST_XSTEP;

	/* adjust for flipping */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_XFLIP)
		xdststep = -xdststep;
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_YFLIP)
		ydststep = -ydststep;

	/* loop over Y in src pixels */
	for (y = 0; y < height; y += ysrcstep, sy += ydststep)
	{
		u8 *rowsrc = src + (srcdelta >> 8);

		/* in the polygon case, we don't factor in the Y */
		if (VIDEO_TRANSFER_FLAGS != 0x5490)
			rowsrc += (y >> 8) * (width >> 8);
		else
			width = 1000 << 8;

		/* simpler case: VIDEO_YSTEP_PER_X is zero */
		if (VIDEO_YSTEP_PER_X == 0)
		{
			/* clip in the Y direction */
			if (sy >= m_scaled_clip_rect.min_y && sy < m_scaled_clip_rect.max_y)
			{
				u32 dstoffs, zbufoffs;
				int32_t z = z0;

				/* direction matters here */
				sx = startx;
				if (xdststep > 0)
				{
					/* skip left pixels */
					for (x = 0; x < width && sx < m_scaled_clip_rect.min_x; x += xsrcstep, sx += xdststep)
						z += (int32_t)m_zbuf_control[0];

					/* compute the address */
					dstoffs = compute_safe_address(sx >> 8, sy >> 8) - (sx >> 8);
					zbufoffs = compute_safe_address(sx >> 8, sy >> 8) - (sx >> 8);

					/* render middle pixels */
					if (m_zbuf_control[3] & 0x8000)
					{
						for ( ; x < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep)
						{
							int pixel = rowsrc[x >> 8];
							if (pixel != transparent_pen)
							{
								base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
								zbase[(zbufoffs + (sx >> 8)) & m_vram_mask] = (z >> 8) | zmatch;
							}
							z += (int32_t)m_zbuf_control[0];
						}
					}
					else if (m_zbuf_control[3] & 0x4000)
					{
						for ( ; x < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep)
						{
							int pixel = rowsrc[x >> 8];
							if (pixel != transparent_pen && zmatch == (zbase[(zbufoffs + (sx >> 8)) & m_vram_mask] & (0x1f << 11)))
								base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
							z += (int32_t)m_zbuf_control[0];
						}
					}
					else
					{
						for ( ; x < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep)
						{
							int pixel = rowsrc[x >> 8];
							if (pixel != transparent_pen && ((z >> 8) <= (zbase[(zbufoffs + (sx >> 8)) & m_vram_mask] & 0x7ff)))
							{
								base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
								zbase[(zbufoffs + (sx >> 8)) & m_vram_mask] = (z >> 8) | zmatch;
							}
							z += (int32_t)m_zbuf_control[0];
						}
					}
				}
				else
				{
					/* skip right pixels */
					for (x = 0; x < width && sx >= m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep)
						z += (int32_t)m_zbuf_control[0];

					/* compute the address */
					dstoffs = compute_safe_address(sx >> 8, sy >> 8) - (sx >> 8);
					zbufoffs = compute_safe_address(sx >> 8, sy >> 8) - (sx >> 8);

					/* render middle pixels */
					if (m_zbuf_control[3] & 0x8000)
					{
						for ( ; x < width && sx >= m_scaled_clip_rect.min_x; x += xsrcstep, sx += xdststep)
						{
							int pixel = rowsrc[x >> 8];
							if (pixel != transparent_pen)
							{
								base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
								zbase[(zbufoffs + (sx >> 8)) & m_vram_mask] = (z >> 8) | zmatch;
							}
							z += (int32_t)m_zbuf_control[0];
						}
					}
					else if (m_zbuf_control[3] & 0x4000)
					{
						for ( ; x < width && sx >= m_scaled_clip_rect.min_x; x += xsrcstep, sx += xdststep)
						{
							int pixel = rowsrc[x >> 8];
							if (pixel != transparent_pen && zmatch == (zbase[(zbufoffs + (sx >> 8)) & m_vram_mask] & (0x1f << 11)))
								base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
							z += (int32_t)m_zbuf_control[0];
						}
					}
					else
					{
						for ( ; x < width && sx >= m_scaled_clip_rect.min_x; x += xsrcstep, sx += xdststep)
						{
							int pixel = rowsrc[x >> 8];
							if (pixel != transparent_pen && ((z >> 8) <= (zbase[(zbufoffs + (sx >> 8)) & m_vram_mask] & 0x7ff)))
							{
								base[(dstoffs + (sx >> 8)) & m_vram_mask] = pixel | color;
								zbase[(zbufoffs + (sx >> 8)) & m_vram_mask] = (z >> 8) | zmatch;
							}
							z += (int32_t)m_zbuf_control[0];
						}
					}
				}
			}
		}

		/* slow case: VIDEO_YSTEP_PER_X is non-zero */
		else
		{
			int ystep = (VIDEO_TRANSFER_FLAGS & XFERFLAG_DYDXSIGN) ? -VIDEO_YSTEP_PER_X : VIDEO_YSTEP_PER_X;
			int ty = sy;
			int32_t z = z0;

			/* render all pixels */
			sx = startx;
			if (m_zbuf_control[3] & 0x8000)
			{
				for (x = 0; x < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep, ty += ystep)
					if (m_scaled_clip_rect.contains(sx, ty))
					{
						int pixel = rowsrc[x >> 8];
						if (pixel != transparent_pen)
						{
							base[compute_safe_address(sx >> 8, ty >> 8)] = pixel | color;
							zbase[compute_safe_address(sx >> 8, ty >> 8)] = (z >> 8) | zmatch;
						}
						z += (int32_t)m_zbuf_control[0];
					}
			}
			else if (m_zbuf_control[3] & 0x4000)
			{
				for (x = 0; x < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep, ty += ystep)
					if (m_scaled_clip_rect.contains(sx, ty))
					{
						int pixel = rowsrc[x >> 8];
						u16 *zbuf = &zbase[compute_safe_address(sx >> 8, ty >> 8)];
						if (pixel != transparent_pen && zmatch == (*zbuf & (0x1f << 11)))
						{
							base[compute_safe_address(sx >> 8, ty >> 8)] = pixel | color;
							*zbuf = (z >> 8) | zmatch;
						}
						z += (int32_t)m_zbuf_control[0];
					}
			}
			else
			{
				for (x = 0; x < width && sx < m_scaled_clip_rect.max_x; x += xsrcstep, sx += xdststep, ty += ystep)
					if (m_scaled_clip_rect.contains(sx, ty))
					{
						int pixel = rowsrc[x >> 8];
						u16 *zbuf = &zbase[compute_safe_address(sx >> 8, ty >> 8)];
						if (pixel != transparent_pen && ((z >> 8) <= (*zbuf & 0x7ff)))
						{
							base[compute_safe_address(sx >> 8, ty >> 8)] = pixel | color;
							*zbuf = (z >> 8) | zmatch;
						}
						z += (int32_t)m_zbuf_control[0];
					}
			}
		}

		/* apply skew */
		if (VIDEO_TRANSFER_FLAGS & XFERFLAG_DXDYSIGN)
			startx += VIDEO_XSTEP_PER_Y;
		else
			startx -= VIDEO_XSTEP_PER_Y;

		/* update the per-scanline parameters */
		if (VIDEO_TRANSFER_FLAGS == 0x5490)
		{
			startx += (int32_t)((VIDEO_LEFTSTEPHI << 16) | VIDEO_LEFTSTEPLO);
			m_scaled_clip_rect.max_x += (int32_t)((VIDEO_RIGHTSTEPHI << 16) | VIDEO_RIGHTSTEPLO);
			srcdelta += (int16_t)VIDEO_STARTSTEP;
		}
		z0 += (int32_t)m_zbuf_control[1];
	}

	/* restore cliprects */
	if (!(VIDEO_TRANSFER_FLAGS & XFERFLAG_CLIP))
		enable_clipping();

	/* reflect the final values into registers */
	VIDEO_TRANSFER_X = (VIDEO_TRANSFER_X & ~0xfff) | (startx >> 8);
	VIDEO_RIGHTCLIP = (VIDEO_RIGHTCLIP & ~0xfff) | (m_scaled_clip_rect.max_x >> 8);
	VIDEO_TRANSFER_Y = (VIDEO_TRANSFER_Y & ~0xfff) | ((VIDEO_TRANSFER_Y + (y >> 8)) & 0xfff);
	VIDEO_TRANSFER_ADDRLO += srcdelta >> 8;

	m_zbuf_control[2] = (m_zbuf_control[2] & ~0x7ff00) | (z0 & 0x7ff00);
}



/*************************************
 *
 *  Compressed blitter macros
 *
 *************************************/

#define GET_NEXT_RUN(xleft, count, innercount, src) \
do {                                                \
	/* load next RLE chunk if needed */             \
	if (!count)                                     \
	{                                               \
		count = *src++;                             \
		val = (count & 0x80) ? -1 : *src++;         \
		count &= 0x7f;                              \
	}                                               \
													\
	/* determine how much to bite off */            \
	innercount = (xleft > count) ? count : xleft;   \
	count -= innercount;                            \
	xleft -= innercount;                            \
} while (0)


#define SKIP_RLE(skip, xleft, count, innercount, src)\
do {                                                \
	/* scan RLE until done */                       \
	for (xleft = skip; xleft > 0; )                 \
	{                                               \
		/* load next RLE chunk if needed */         \
		GET_NEXT_RUN(xleft, count, innercount, src);\
													\
		/* skip past the data */                    \
		if (val == -1) src += innercount;           \
	}                                               \
} while (0)

void Save8BitBmp(const char* filename, const u8* src, const void* inpal, int palCount, int w, int h, bool pal16)
{
	static u8 palette[256 * 4];
	FILE* f;

	int padsize = (4 - (w % 4)) % 4;
	int filesize = 54 + palCount * 4 + (w + padsize) * h;  //w is your image width, h is image height, both int

	unsigned char bmpfileheader[14] = { 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 8,0 };
	unsigned char bmppad[3] = { 0,0,0 };

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	int soffset = 54 + palCount * 4;

	bmpfileheader[10] = (unsigned char)(soffset);
	bmpfileheader[11] = (unsigned char)(soffset >> 8);
	bmpfileheader[12] = (unsigned char)(soffset >> 16);
	bmpfileheader[13] = (unsigned char)(soffset >> 24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w >> 8);
	bmpinfoheader[6] = (unsigned char)(w >> 16);
	bmpinfoheader[7] = (unsigned char)(w >> 24);
	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);
	bmpinfoheader[32] = palCount == 256 ? 0 : palCount;

	if (pal16)
	{
		u8* pal = palette;
		u16* Palette555 = (u16*)inpal;

		for (int i = 0; i < palCount; i++)
		{
			u16 pdata = Palette555[i];
			*pal++ = ((pdata >> 10) & 0x1f) << 3;
			*pal++ = ((pdata >> 5) & 0x1f) << 3;
			*pal++ = ((pdata >> 0) & 0x1f) << 3;
			*pal++ = 0;
		}
	}
	else
	{
		u8* pal = palette;
		u32* Palette8888 = (u32*)inpal;

		for (int i = 0; i < palCount; i++)
		{
			u32 pdata = Palette8888[i];

			*pal++ = ((pdata >> 0) & 0xff);
			*pal++ = ((pdata >> 8) & 0xff);
			*pal++ = ((pdata >> 16) & 0xff);
			*pal++ = 0;
		}
	}


	f = fopen(filename, "wb");
	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);
	fwrite(palette, 1, 4 * palCount, f);

	for (int i = 0; i < h; i++)
	{
		fwrite(src + (w * (h - i - 1)), 1, w, f);
		if (padsize) fwrite(bmppad, 1, padsize, f);
	}
	fclose(f);

}

#define ITECH32_4X_MODE 0
#define MAX_SAVEOBJ_COUNT 4096
#define MAX_4X_TEXTURES 1024

u32 grom_saved_objects[MAX_SAVEOBJ_COUNT] = { 0 };
u32 grom_saved_object_count = 0;

u8 grom_save_buffer[512 * 512];

int CheckBitmap(u32 adr)
{
	if (adr < 0x0080000 || adr > 0x00a00000) return -1;

	for (size_t i = 0; i < grom_saved_object_count; i++)
	{
		if (adr == grom_saved_objects[i]) {
			return i+1;
		}
	}

	return 0;
}

void Save8BitBmpAdr(u32 adr, const void* inpal, int palCount, int w, int h, bool pal16)
{
	char filename[128];
	sprintf(filename, "output/%08x.bmp", adr);
	Save8BitBmp(filename, grom_save_buffer, inpal, palCount, w, h, pal16);
	if (grom_saved_object_count < MAX_SAVEOBJ_COUNT) {
		grom_saved_objects[grom_saved_object_count++] = adr;
	}	
}

typedef struct
{
	uint8_t Header[12];         // File Header To Determine File Type
} TGAHeader;

typedef struct
{
	uint8_t header[6];          // Holds The First 6 Useful Bytes Of The File
	uint32_t bytesPerPixel;           // Number Of BYTES Per Pixel (3 Or 4)
	uint32_t imageSize;           // Amount Of Memory Needed To Hold The Image
	uint32_t type;                // The Type Of Image, GL_RGB Or GL_RGBA
	uint32_t Height;              // Height Of Image                 
	uint32_t Width;               // Width Of Image              
	uint32_t Bpp;             // Number Of BITS Per Pixel (24 Or 32)
} TGA;

static render_texture* tga_textures[MAX_4X_TEXTURES] = { 0 };
static bitmap_argb32* tga_bitmaps[MAX_4X_TEXTURES] = { 0 };

render_texture* itech32_state::map_gfx_texture(u32 adr, bitmap_argb32** bmp)
{
	int bmpresult = CheckBitmap(adr);

	if (bmpresult < 0) return NULL;

	if (bmpresult > 0) {
		*bmp = tga_bitmaps[bmpresult-1];
		return tga_textures[bmpresult-1];
	}

	FILE* f = 0;
	char filename[128];
	sprintf(filename, "C:/Projects/Mame/output/images4x/%08x.tga", adr);
	f = fopen(filename, "rb");

	if (f == 0) {
		return NULL;
	}

	TGAHeader tgaheader;
	TGA tga;

	// Attempt To Read The File Header
	if (fread(&tgaheader, sizeof(TGAHeader), 1, f) == 0)
	{
		return false;               // Return False If It Fails
	}

	// Attempt To Read Next 6 Bytes
	if (fread(tga.header, sizeof(tga.header), 1, f) == 0)
	{
		return false;               // Return False
	}

	int ww = tga.header[1] * 256 + tga.header[0];   // Calculate Height
	int hh = tga.header[3] * 256 + tga.header[2];   // Calculate The Width

	int bits = tga.header[4];                // Calculate Bits Per Pixel
	tga.Width = ww;              // Copy Width Into Local Structure
	tga.Height = hh;                // Copy Height Into Local Structure
	tga.Bpp = bits;
	tga.bytesPerPixel = (tga.Bpp / 8);      // Calculate The BYTES Per Pixel
	// Calculate Memory Needed To Store Image
	tga.imageSize = (tga.bytesPerPixel * tga.Width * tga.Height);

	uint8_t* pixels = new uint8_t[tga.Width * tga.Height * tga.bytesPerPixel];

	if (bits == 32)
	{
		int pitch = tga.Width * tga.bytesPerPixel;

		if (tga.header[5] & 0x20)
		{
			fread(pixels, 1, tga.Height * pitch, f);
		}
		else
		{
			// Attempt To Read All The Image Data			
			int row = (tga.Height - 1) * pitch;

			for (size_t i = 0; i < tga.Height; i++, row -= pitch)
			{
				fread(pixels + row, 1, pitch, f);
			}
		}

	}
	/*
	for (int cswap = 0; cswap < (int)tga.imageSize; cswap += tga.bytesPerPixel)
	{
		// 1st Byte XOR 3rd Byte XOR 1st Byte XOR 3rd Byte
		pixels[cswap] ^= pixels[cswap + 2] ^=
			pixels[cswap] ^= pixels[cswap + 2];
	}
	*/

	bitmap_argb32* bitmap = new bitmap_argb32((uint32_t*)pixels, ww, hh, ww);

	render_texture* tex = machine().render().texture_alloc();

	tex->set_bitmap(*bitmap, bitmap->cliprect(), TEXFORMAT_ARGB32);
	fclose(f);
	// Close The File

	tga_bitmaps[grom_saved_object_count] = bitmap;
	tga_textures[grom_saved_object_count] = tex;
	grom_saved_objects[grom_saved_object_count++] = adr;

	return tex;
}

int itech32_state::map_draw_4x(u32 adr, u16 flipx)
{
	bitmap_argb32* bmp = 0;
	render_texture* tex = map_gfx_texture(adr, &bmp);

	if (tex)
	{
		running_machine::dma_item item;
		int width = VIDEO_TRANSFER_WIDTH;
		int height = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT);
		int sx = VIDEO_TRANSFER_X & m_vram_xmask;
		int sy = ((VIDEO_TRANSFER_Y & 0xfff) << 8) & m_vram_ymask;

		const bool is_shadow = false;

		item.x = sx;
		item.x1 = item.x + (flipx ? -width : width);
		item.tex = tex;
		item.flags = (flipx ? 0x01 : 0x00);
		item.color = is_shadow ? 0xff000000 : 0xffffffff;//Font shadows

		item.y = sy - 512;
		item.y1 = item.y + height;

		machine().add_dma_item(item);
		return 1;
	}

	return 0;
}



/*************************************
 *
 *  Fast compressed blitter functions
 *
 *************************************/

inline void itech32_state::draw_rle_fast(u16 *base, u16 color)
{
	u32 adr = (m_grom_bank | ((VIDEO_TRANSFER_ADDRHI & 0xff) << 16) | VIDEO_TRANSFER_ADDRLO) % m_grom.length();
	u8 *src = &m_grom[adr];
	int transparent_pen = (VIDEO_TRANSFER_FLAGS & XFERFLAG_TRANSPARENT) ? 0xff : -1;
	int width = VIDEO_TRANSFER_WIDTH;
	int height = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT);
	int sx = VIDEO_TRANSFER_X & 0xfff;
	int sy = (VIDEO_TRANSFER_Y & 0xfff) << 8;
	int xleft, y, count = 0, val = 0, innercount;
	int ydststep = VIDEO_DST_YSTEP;
	int lclip, rclip;

#if ITECH32_4X_MODE == 0
	if (CheckBitmap(adr) == 0)
	{
		memset(grom_save_buffer, 0, width * height);

		for (y = 0; y < height; y++)
		{
			u32 sp = y * width;
			
			/* loop until gone */
			for (xleft = width; xleft > 0; )
			{
				/* load next RLE chunk if needed */
				GET_NEXT_RUN(xleft, count, innercount, src);

				/* run of literals */
				if (val == -1)
					while (innercount--)
					{
						int pixel = *src++;
						if (pixel != transparent_pen) {
							grom_save_buffer[sp] = pixel;
						}
						sp++;
					}

				/* run of non-transparent repeats */
				else if (val != transparent_pen)
				{
					u8 pix8 = val;
					while (innercount--) {
						grom_save_buffer[sp++] = pix8;
					}
				}

				/* run of transparent repeats */
				else {
					sp += innercount;
				}

			}
		}

		const rgb_t* PalData = m_palette->palette()->entry_list_raw() + color;
		Save8BitBmpAdr(adr, PalData, 256, width, height, false);
	}
#elif ITECH32_4X_MODE == 1
	if (map_draw_4x(adr, 0)) return;	
#endif

	/* determine clipping */
	lclip = m_clip_rect.min_x - sx;
	if (lclip < 0) lclip = 0;
	rclip = sx + width - m_clip_rect.max_x;
	if (rclip < 0) rclip = 0;
	width -= lclip + rclip;
	sx += lclip;

	/* adjust for flipping */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_YFLIP)
		ydststep = -ydststep;

	/* loop over Y in src pixels */
	for (y = 0; y < height; y++, sy += ydststep)
	{
		u32 dstoffs;

		/* clip in the Y direction */
		if (sy < m_scaled_clip_rect.min_y || sy >= m_scaled_clip_rect.max_y)
		{
			SKIP_RLE(width + lclip + rclip, xleft, count, innercount, src);
			continue;
		}

		/* compute the address */
		dstoffs = compute_safe_address(sx, sy >> 8);

		/* left clip */
		SKIP_RLE(lclip, xleft, count, innercount, src);

		/* loop until gone */
		for (xleft = width; xleft > 0; )
		{
			/* load next RLE chunk if needed */
			GET_NEXT_RUN(xleft, count, innercount, src);

			/* run of literals */
			if (val == -1)
				while (innercount--)
				{
					int pixel = *src++;
					if (pixel != transparent_pen) {
						base[dstoffs & m_vram_mask] = color | pixel;
					}
					dstoffs++;					
				}

			/* run of non-transparent repeats */
			else if (val != transparent_pen)
			{
				val |= color;
				while (innercount--) {
					base[dstoffs++ & m_vram_mask] = val;
				}
			}

			/* run of transparent repeats */
			else {
				dstoffs += innercount;
			}
				
		}

		/* right clip */
		SKIP_RLE(rclip, xleft, count, innercount, src);
	}
}


inline void itech32_state::draw_rle_fast_xflip(u16 *base, u16 color)
{
	u32 adr = (m_grom_bank | ((VIDEO_TRANSFER_ADDRHI & 0xff) << 16) | VIDEO_TRANSFER_ADDRLO) % m_grom.length();

#if ITECH32_4X_MODE == 1
	if (map_draw_4x(adr, 1)) return;
#endif

	u8 *src = &m_grom[adr];
	int transparent_pen = (VIDEO_TRANSFER_FLAGS & XFERFLAG_TRANSPARENT) ? 0xff : -1;
	int width = VIDEO_TRANSFER_WIDTH;
	int height = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT);
	int sx = VIDEO_TRANSFER_X & 0xfff;
	int sy = (VIDEO_TRANSFER_Y & 0xfff) << 8;
	int xleft, y, count = 0, val = 0, innercount;
	int ydststep = VIDEO_DST_YSTEP;
	int lclip, rclip;

	/* determine clipping */
	lclip = sx - m_clip_rect.max_x;
	if (lclip < 0) lclip = 0;
	rclip = m_clip_rect.min_x - (sx - width);
	if (rclip < 0) rclip = 0;
	width -= lclip + rclip;
	sx -= lclip;

	/* adjust for flipping */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_YFLIP)
		ydststep = -ydststep;

	/* loop over Y in src pixels */
	for (y = 0; y < height; y++, sy += ydststep)
	{
		u32 dstoffs;

		/* clip in the Y direction */
		if (sy < m_scaled_clip_rect.min_y || sy >= m_scaled_clip_rect.max_y)
		{
			SKIP_RLE(width + lclip + rclip, xleft, count, innercount, src);
			continue;
		}

		/* compute the address */
		dstoffs = compute_safe_address(sx, sy >> 8);

		/* left clip */
		SKIP_RLE(lclip, xleft, count, innercount, src);

		/* loop until gone */
		for (xleft = width; xleft > 0; )
		{
			/* load next RLE chunk if needed */
			GET_NEXT_RUN(xleft, count, innercount, src);

			/* run of literals */
			if (val == -1)
				while (innercount--)
				{
					int pixel = *src++;
					if (pixel != transparent_pen)
						base[dstoffs & m_vram_mask] = color | pixel;
					dstoffs--;
				}

			/* run of non-transparent repeats */
			else if (val != transparent_pen)
			{
				val |= color;
				while (innercount--)
					base[dstoffs-- & m_vram_mask] = val;
			}

			/* run of transparent repeats */
			else
				dstoffs -= innercount;
		}

		/* right clip */
		SKIP_RLE(rclip, xleft, count, innercount, src);
	}
}



/*************************************
 *
 *  Slow compressed blitter functions
 *
 *************************************/

inline void itech32_state::draw_rle_slow(u16 *base, u16 color)
{
	u8 *src = &m_grom[(m_grom_bank | ((VIDEO_TRANSFER_ADDRHI & 0xff) << 16) | VIDEO_TRANSFER_ADDRLO) % m_grom.length()];
	int transparent_pen = (VIDEO_TRANSFER_FLAGS & XFERFLAG_TRANSPARENT) ? 0xff : -1;
	int width = VIDEO_TRANSFER_WIDTH;
	int height = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT);
	int sx, sy = (VIDEO_TRANSFER_Y & 0xfff) << 8;
	int xleft, y, count = 0, val = 0, innercount;
	int xdststep = 0x100;
	int ydststep = VIDEO_DST_YSTEP;
	int startx = (VIDEO_TRANSFER_X & 0xfff) << 8;

	/* adjust for scaling */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_DSTXSCALE)
		xdststep = VIDEO_DST_XSTEP;

	/* adjust for flipping */
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_XFLIP)
		xdststep = -xdststep;
	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_YFLIP)
		ydststep = -ydststep;

	/* loop over Y in src pixels */
	for (y = 0; y < height; y++, sy += ydststep)
	{
		u32 dstoffs;

		/* clip in the Y direction */
		if (sy < m_scaled_clip_rect.min_y || sy >= m_scaled_clip_rect.max_y)
		{
			SKIP_RLE(width, xleft, count, innercount, src);
			continue;
		}

		/* compute the address */
		sx = startx;
		dstoffs = compute_safe_address(m_clip_rect.min_x, sy >> 8) - m_clip_rect.min_x;

		/* loop until gone */
		for (xleft = width; xleft > 0; )
		{
			/* load next RLE chunk if needed */
			GET_NEXT_RUN(xleft, count, innercount, src);

			/* run of literals */
			if (val == -1)
				for ( ; innercount--; sx += xdststep)
				{
					int pixel = *src++;
					if (pixel != transparent_pen)
						if (sx >= m_scaled_clip_rect.min_x && sx < m_scaled_clip_rect.max_x)
							base[(dstoffs + (sx >> 8)) & m_vram_mask] = color | pixel;
				}

			/* run of non-transparent repeats */
			else if (val != transparent_pen)
			{
				val |= color;
				for ( ; innercount--; sx += xdststep)
					if (sx >= m_scaled_clip_rect.min_x && sx < m_scaled_clip_rect.max_x)
						base[(dstoffs + (sx >> 8)) & m_vram_mask] = val;
			}

			/* run of transparent repeats */
			else
				sx += xdststep * innercount;
		}

		/* apply skew */
		if (VIDEO_TRANSFER_FLAGS & XFERFLAG_DXDYSIGN)
			startx += VIDEO_XSTEP_PER_Y;
		else
			startx -= VIDEO_XSTEP_PER_Y;
	}
}



void itech32_state::draw_rle(u16 *base, u16 color)
{
	/* adjust for (lack of) clipping */
	if (!(VIDEO_TRANSFER_FLAGS & XFERFLAG_CLIP))
		disable_clipping();

	/* if we have an X scale, draw it slow */
	if (((VIDEO_TRANSFER_FLAGS & XFERFLAG_DSTXSCALE) && VIDEO_DST_XSTEP != 0x100) || VIDEO_XSTEP_PER_Y)
		draw_rle_slow(base, color);

	/* else draw it fast */
	else if (VIDEO_TRANSFER_FLAGS & XFERFLAG_XFLIP)
		draw_rle_fast_xflip(base, color);
	else
		draw_rle_fast(base, color);

	/* restore cliprects */
	if (!(VIDEO_TRANSFER_FLAGS & XFERFLAG_CLIP))
		enable_clipping();
}



/*************************************
 *
 *  Shift register manipulation
 *
 *************************************/

void itech32_state::shiftreg_clear(u16 *base, u16 *zbase)
{
	const int ydir = (VIDEO_TRANSFER_FLAGS & XFERFLAG_YFLIP) ? -1 : 1;
	const int height = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT);
	const int sx = VIDEO_TRANSFER_X & 0xfff;
	int sy = VIDEO_TRANSFER_Y & 0xfff;

	/* first line is the source */
	u16 *src = &base[compute_safe_address(sx, sy)];
	sy += ydir;

	/* loop over height */
	for (int y = 1; y < height; y++)
	{
		memcpy(&base[compute_safe_address(sx, sy)], src, 512*2);
		sy += ydir;
	}
}

void drivedge_state::shiftreg_clear(u16 *base, u16 *zbase)
{
	int ydir = (VIDEO_TRANSFER_FLAGS & XFERFLAG_YFLIP) ? -1 : 1;
	int height = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT);
	int sx = VIDEO_TRANSFER_X & 0xfff;
	int sy = VIDEO_TRANSFER_Y & 0xfff;

	/* first line is the source */
	u16 *src = &base[compute_safe_address(sx, sy)];
	sy += ydir;

	/* loop over height */
	for (int y = 1; y < height; y++)
	{
		memcpy(&base[compute_safe_address(sx, sy)], src, 512*2);
		if (zbase)
		{
			u16 zval = ((m_zbuf_control[2] >> 8) & 0x7ff) | ((m_zbuf_control[2] & 0x1f) << 11);
			u16 *dst = &zbase[compute_safe_address(sx, sy)];
			int x;
			for (x = 0; x < 512; x++)
				*dst++ = zval;
		}
		sy += ydir;
	}
}



/*************************************
 *
 *  Video commands
 *
 *************************************/

void itech32_state::handle_video_command()
{
	/* only 6 known commands */
	switch (VIDEO_COMMAND)
	{
		/* command 1: blit raw data */
		case 1:
			command_blit_raw();
			break;

		/* command 2: blit RLE-compressed data */
		case 2:
			g_profiler.start(PROFILER_USER2);
			if (BLIT_LOGGING) logblit("Blit RLE");

			if (m_enable_latch[0]) draw_rle(m_videoplane[0], m_color_latch[0]);
			if (m_enable_latch[1]) draw_rle(m_videoplane[1], m_color_latch[1]);

			g_profiler.stop();
			break;

		/* command 3: set up raw data transfer */
		case 3:
			if (BLIT_LOGGING) logblit("Raw Xfer");
			m_xfer_xcount = VIDEO_TRANSFER_WIDTH;
			m_xfer_ycount = ADJUSTED_HEIGHT(VIDEO_TRANSFER_HEIGHT);
			m_xfer_xcur = VIDEO_TRANSFER_X & 0xfff;
			m_xfer_ycur = VIDEO_TRANSFER_Y & 0xfff;
			break;

		/* command 4: flush? */
		case 4:
			break;

		/* command 5: reset? */
		case 5:
			break;

		/* command 6: perform shift register copy */
		case 6:
			command_shift_reg();
			break;

		default:
			if (BLIT_LOGGING) logerror("Unknown blit command %d\n", VIDEO_COMMAND);
			break;
	}

	/* tell the processor we're done */
	VIDEO_INTSTATE |= VIDEOINT_BLITTER;
	update_interrupts(1);
}

void itech32_state::command_blit_raw()
{
	g_profiler.start(PROFILER_USER1);
	if (BLIT_LOGGING) logblit("Blit Raw");

	if (VIDEO_TRANSFER_FLAGS & XFERFLAG_WIDTHPIX)
	{
		if (m_enable_latch[0]) draw_raw_widthpix(m_videoplane[0], m_color_latch[0]);
		if (m_enable_latch[1]) draw_raw_widthpix(m_videoplane[1], m_color_latch[1]);
	}
	else
	{
		if (m_enable_latch[0]) draw_raw(m_videoplane[0], m_color_latch[0]);
		if (m_enable_latch[1]) draw_raw(m_videoplane[1], m_color_latch[1]);
	}

	g_profiler.stop();
}

void drivedge_state::command_blit_raw()
{
	g_profiler.start(PROFILER_USER1);
	if (BLIT_LOGGING) logblit("Blit Raw");

	if (m_enable_latch[0]) draw_raw(m_videoplane[0], m_videoplane[1], m_color_latch[0]);

	g_profiler.stop();
}

void itech32_state::command_shift_reg()
{
	g_profiler.start(PROFILER_USER3);
	if (BLIT_LOGGING) logblit("ShiftReg");

	if (m_enable_latch[0]) shiftreg_clear(m_videoplane[0], nullptr);
	if (m_enable_latch[1]) shiftreg_clear(m_videoplane[1], nullptr);

	g_profiler.stop();
}

void drivedge_state::command_shift_reg()
{
	g_profiler.start(PROFILER_USER3);
	if (BLIT_LOGGING) logblit("ShiftReg");

	if (m_enable_latch[0]) shiftreg_clear(m_videoplane[0], m_videoplane[1]);

	g_profiler.stop();
}


/*************************************
 *
 *  Video I/O
 *
 *************************************/

void itech32_state::video_w(offs_t offset, u16 data, u16 mem_mask)
{
	rectangle visarea;

	int old = m_video[offset];
	COMBINE_DATA(&m_video[offset]);

	switch (offset)
	{
		case 0x02/2:    /* VIDEO_INTACK */
			VIDEO_INTSTATE = old & ~data;
			update_interrupts(1);
			break;

		case 0x04/2:    /* VIDEO_TRANSFER */
			if (VIDEO_COMMAND == 3 && m_xfer_ycount)
			{
				offs_t addr = compute_safe_address(m_xfer_xcur, m_xfer_ycur);
				if (m_enable_latch[0])
				{
					VIDEO_TRANSFER = m_videoplane[0][addr];
					m_videoplane[0][addr] = (data & 0xff) | m_color_latch[0];
				}
				if (m_enable_latch[1])
				{
					VIDEO_TRANSFER = m_videoplane[1][addr];
					m_videoplane[1][addr] = (data & 0xff) | m_color_latch[1];
				}
				if (--m_xfer_xcount)
					m_xfer_xcur++;
				else if (--m_xfer_ycount)
					m_xfer_xcur = VIDEO_TRANSFER_X, m_xfer_xcount = VIDEO_TRANSFER_WIDTH, m_xfer_ycur++;
			}
			break;

		case 0x08/2:    /* VIDEO_COMMAND */
			handle_video_command();
			break;

		case 0x0a/2:    /* VIDEO_INTENABLE */
			update_interrupts(1);
			break;

		case 0x24/2:    /* VIDEO_LEFTCLIP */
			m_clip_rect.min_x = VIDEO_LEFTCLIP;
			m_scaled_clip_rect.min_x = VIDEO_LEFTCLIP << 8;
			break;

		case 0x26/2:    /* VIDEO_RIGHTCLIP */
			m_clip_rect.max_x = VIDEO_RIGHTCLIP;
			m_scaled_clip_rect.max_x = VIDEO_RIGHTCLIP << 8;
			break;

		case 0x28/2:    /* VIDEO_TOPCLIP */
			m_clip_rect.min_y = VIDEO_TOPCLIP;
			m_scaled_clip_rect.min_y = VIDEO_TOPCLIP << 8;
			break;

		case 0x2a/2:    /* VIDEO_BOTTOMCLIP */
			m_clip_rect.max_y = VIDEO_BOTTOMCLIP;
			m_scaled_clip_rect.max_y = VIDEO_BOTTOMCLIP << 8;
			break;

		case 0x2c/2:    /* VIDEO_INTSCANLINE */
			m_scanline_timer->adjust(m_screen->time_until_pos(VIDEO_INTSCANLINE));
			break;

		case 0x32/2:    /* VIDEO_VTOTAL */
		case 0x36/2:    /* VIDEO_VBLANK_START */
		case 0x38/2:    /* VIDEO_VBLANK_END */
		case 0x3a/2:    /* VIDEO_HTOTAL */
		case 0x3e/2:    /* VIDEO_HBLANK_START */
		case 0x40/2:    /* VIDEO_HBLANK_END */
			/* do some sanity checks first */
			if ((VIDEO_HTOTAL > 0) && (VIDEO_VTOTAL > 0) &&
				(VIDEO_VBLANK_START != VIDEO_VBLANK_END) &&
				(VIDEO_HBLANK_START != VIDEO_HBLANK_END) &&
				(VIDEO_HBLANK_START < VIDEO_HTOTAL) &&
				(VIDEO_HBLANK_END < VIDEO_HTOTAL) &&
				(VIDEO_VBLANK_START < VIDEO_VTOTAL) &&
				(VIDEO_VBLANK_END < VIDEO_VTOTAL))
			{
				visarea.min_x = visarea.min_y = 0;

				if (VIDEO_HBLANK_START > VIDEO_HBLANK_END)
					visarea.max_x = VIDEO_HBLANK_START - VIDEO_HBLANK_END - 1;
				else
					visarea.max_x = VIDEO_HTOTAL - VIDEO_HBLANK_END + VIDEO_HBLANK_START - 1;

				if (VIDEO_VBLANK_START > VIDEO_VBLANK_END)
					visarea.max_y = VIDEO_VBLANK_START - VIDEO_VBLANK_END - 1;
				else
					visarea.max_y = VIDEO_VTOTAL - VIDEO_VBLANK_END + VIDEO_VBLANK_START - 1;

				logerror("Configure Screen: HTOTAL: %x  HBSTART: %x  HBEND: %x  VTOTAL: %x  VBSTART: %x  VBEND: %x\n",
					VIDEO_HTOTAL, VIDEO_HBLANK_START, VIDEO_HBLANK_END, VIDEO_VTOTAL, VIDEO_VBLANK_START, VIDEO_VBLANK_END);
				m_screen->configure(VIDEO_HTOTAL, VIDEO_VTOTAL, visarea, HZ_TO_ATTOSECONDS(VIDEO_CLOCK) * VIDEO_HTOTAL * VIDEO_VTOTAL);
			}
			break;
	}
}


u16 itech32_state::video_r(offs_t offset)
{
	if (offset == 0)
	{
		return (m_video[offset] & ~0x08) | 0x04 | 0x01;
	}
	else if (offset == 3)
	{
		return 0xef;/*m_screen->vpos() - 1;*/
	}

	return m_video[offset];
}



/*************************************
 *
 *  Alternate video I/O
 *
 *************************************/

void itech32_state::bloodstm_video_w(offs_t offset, u16 data, u16 mem_mask)
{
	video_w(offset / 2, data, mem_mask);
}


u16 itech32_state::bloodstm_video_r(offs_t offset)
{
	return video_r(offset / 2);
}


void drivedge_state::zbuf_control_w(offs_t offset, u32 data, u32 mem_mask)
{
	COMBINE_DATA(&m_zbuf_control[offset]);
}


/*************************************
 *
 *  Main refresh
 *
 *************************************/

u32 itech32_state::screen_update(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect)
{
	int y;

	/* loop over height */
	for (y = cliprect.min_y; y <= cliprect.max_y; y++)
	{
		u16 *src1 = &m_videoplane[0][compute_safe_address(VIDEO_DISPLAY_XORIGIN1, VIDEO_DISPLAY_YORIGIN1 + y)];

		/* handle multi-plane case */
		if (m_planes > 1)
		{
			u16 *src2 = &m_videoplane[1][compute_safe_address(VIDEO_DISPLAY_XORIGIN2 + VIDEO_DISPLAY_XSCROLL2, VIDEO_DISPLAY_YORIGIN2 + VIDEO_DISPLAY_YSCROLL2 + y)];
			u16 scanline[384];
			int x;

			/* blend the pixels in the scanline; color xxFF is transparent */
			for (x = cliprect.min_x; x <= cliprect.max_x; x++)
			{
				u16 pixel = src1[x];
				if ((pixel & 0xff) == 0xff)
					pixel = src2[x];
				scanline[x] = pixel;
			}

			/* draw from the buffer */
			draw_scanline16(bitmap, cliprect.min_x, y, cliprect.width(), &scanline[cliprect.min_x], nullptr);
		}

		/* otherwise, draw directly from VRAM */
		else
			draw_scanline16(bitmap, cliprect.min_x, y, cliprect.width(), &src1[cliprect.min_x], nullptr);
	}
	return 0;
}
