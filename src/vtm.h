#ifndef VTM_H
#define VTM_H

#include "vtm_types.h"

#define VTM_MENU(p_menu, p_name) \
\
static struct vtm_manager p_menu##_manager = {\
        .current_index = 0,\
};\
\
static const struct vtm_menu p_menu = {\
        .name = p_name,\
        .manager = &p_menu##_manager,\
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

void vtm_init(const struct vtm_menu *menu);
void vtm_service(const struct vtm_menu *menu);

#endif /* VTM_H */
