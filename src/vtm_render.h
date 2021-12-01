#ifndef VTM_RENDER_H
#define VTM_RENDER_H

#include "vtm_types.h"

extern const struct vtm_render_iface vtm_render_led_3x7;
extern const struct vtm_render_iface vtm_render_lcd_1x16;
extern const struct vtm_render_iface vtm_render_lcd_2x16;
extern const struct vtm_render_iface vtm_render_lcd_4x20;
extern const struct vtm_render_iface vtm_render_term_vt100;

#endif /* VTM_RENDER_H */
