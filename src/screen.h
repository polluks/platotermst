/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * screen.h - Display output functions
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <stdbool.h>
#include "protocol.h"
#include "screen_queue.h"
#include "palette_queue.h"

#define FGBG_FOREGROUND 0
#define FGBG_BACKGROUND 1

/**
 * screen_init() - Set up the screen
 */
void screen_init(void);

/**
 * screen_x() - Get screen X coordinates
 */
short screen_x(short x);

/**
 * screen_y() - Get screen Y coordinates
 */
short screen_y(short y);

/**
 * screen_strndup(ch, count) - duplicate character data.
 */
char* screen_strndup(unsigned char* ch, unsigned char count);

/**
 * screen_load_driver()
 * Load the TGI driver
 */
void screen_load_driver(void);

/**
 * screen_init_hook()
 * Called after tgi_init to set any special features, e.g. nmi trampolines.
 */
void screen_init_hook(void);

/**
 * screen_cycle_foreground()
 * Go to the next foreground color in palette
 */
void screen_cycle_foreground(void);

/**
 * screen_cycle_background()
 * Go to the next background color in palette
 */
void screen_cycle_background(void);

/**
 * screen_cycle_border()
 * Go to the next border color in palette
 */
void screen_cycle_border(void);

/**
 * screen_update_colors() - Set the terminal colors
 */
void screen_update_colors(void);

/**
 * screen_wait(void) - Sleep for approx 16.67ms
 */
void screen_wait(void);

/**
 * screen_beep(void) - Beep the terminal
 */
void screen_beep(void);

/**
 * screen_clear - Clear the screen
 */
void screen_clear(void);

/**
 * screen_block_draw(Coord1, Coord2) - Perform a block fill from Coord1 to Coord2
 */
void screen_block_draw(padPt* Coord1, padPt* Coord2, bool queue);

/**
 * screen_dot_draw(Coord) - Plot a mode 0 pixel
 */
void screen_dot_draw(padPt* Coord, bool queue);

/**
 * screen_line_draw(Coord1, Coord2) - Draw a mode 1 line
 */
void screen_line_draw(padPt* Coord1, padPt* Coord2, bool queue);

/**
 * screen_char_draw(Coord, ch, count) - Output buffer from ch* of length count as PLATO characters
 */
void screen_char_draw(padPt* Coord, unsigned char* ch, unsigned char count, bool queue);

/**
 * screen_tty_char - Called to plot chars when in tty mode
 */
void screen_tty_char(padByte theChar);

/**
 * screen_done()
 * Close down TGI
 */
void screen_done(void);

/**
 * Do next redraw
 */
void screen_next_redraw(DrawElement* element);

/**
 * screen_redraw()
 */
void screen_redraw(void);

/**
 * Set selected screen color (fg/bg)
 */
void screen_color(unsigned char fgbg, padRGB* theColor);

/**
 * Set foreground color
 */
void screen_foreground(padRGB* theColor);

/**
 * Set background color
 */
void screen_background(padRGB* theColor);

/**
 * Paint
 */
void screen_paint(padPt* Coord, bool queue);

#endif /* SCREEN_H */
