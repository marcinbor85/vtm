#include "vtm_render.h"

#include "stdio.h"

#define VT100_CLEAR_SCREEN              "\x1B[2J"
#define VT100_GO_HOME                   "\x1B[H"
#define VT100_SET_CURSOR                "\x1B[%d;%dH"
#define VT100_FONT_STYLE_RESET          "\x1B[0m"
#define VT100_FONT_STYLE_DIMM           "\x1B[2m"

static void init(const struct vtm_menu *menu)
{
        printf(VT100_CLEAR_SCREEN VT100_GO_HOME "\n");
}

static void print_path(const struct vtm_menu *menu, const char *path)
{
        printf(VT100_GO_HOME "%s\n", path);
}

static void print_separator(const struct vtm_menu *menu)
{
        printf(VT100_SET_CURSOR "================\n", 0, 1);
}

static void print_item(const struct vtm_menu *menu, const char *name, int index, bool selected, bool enabled)
{
        char *cursor = (selected != false) ? ">" : " ";
        char *name_prefix = (enabled == false) ? VT100_FONT_STYLE_DIMM : "";
        char *name_suffix = (enabled == false) ? VT100_FONT_STYLE_RESET : "";

        int row = 2 + index;

        printf(VT100_SET_CURSOR "%s %s%s%s\n", 1, row, cursor, name_prefix, name, name_suffix);
}

static void print_scrollbars(const struct vtm_menu *menu, bool prev, bool next)
{
        char *prev_symbol = (prev != false) ? "↑" : " ";
        char *next_symbol = (next != false) ? "↓" : " ";
        
        printf(VT100_SET_CURSOR "%s\n", 0, 2, prev_symbol);
        printf(VT100_SET_CURSOR "%s\n", 0, 3, next_symbol);
}

const struct vtm_render_iface vtm_render_term_vt100 = {
        .init = init,
        .print_path = print_path,
        .print_separator = print_separator,
        .print_item = print_item,
        .print_scrollbars = print_scrollbars,
};
