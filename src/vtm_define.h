#ifndef VTM_DEFINE_H
#define VTM_DEFINE_H

#include "vtm_types.h"

#define VTM_MENU(p_menu, p_name, p_property_getter) \
\
static struct vtm_manager p_menu##_manager = {\
        .selected_item_index = 0,\
};\
\
static struct vtm_render p_menu##_render = {\
        .ctx = NULL,\
        .iface = NULL,\
};\
\
static const struct vtm_menu p_menu = {\
        .name = p_name,\
        .manager = &p_menu##_manager,\
        .render = &p_menu##_render,\
        .get_property = p_property_getter,\
        .items = {\

#define VTM_ITEM_ACTION(p_name, p_id, p_action_callback) {\
        .type = VTM_ITEM_TYPE_ACTION,\
        .name = p_name,\
        .action = p_action_callback,\
        .id = p_id,\
},\

#define VTM_ITEM_SUBMENU(p_name, p_id) {\
        .type = VTM_ITEM_TYPE_SUBMENU,\
        .name = p_name,\
        .action = NULL,\
        .id = p_id,\
},\

#define VTM_ITEM_SUBMENU_END() {\
        .type = VTM_ITEM_TYPE_SUBMENU_END,\
},\

#define VTM_MENU_END() }};

#endif /* VTM_DEFINE_H */
