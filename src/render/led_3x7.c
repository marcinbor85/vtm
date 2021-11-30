#include "vtm_render.h"

static void print_item(struct vtm_menu *menu, const char *name, int index, bool selected, bool enabled)
{
        // TODO
}

struct vtm_render_iface vtm_render_led_3x7 = {
        .print_path = NULL,
        .print_separator = NULL,
        .print_item = print_item,
        .print_scrollbars = NULL,
};
