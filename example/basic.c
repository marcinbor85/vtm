
#include "vtm.h"

int g_main_action_callback(struct vtm_menu *menu, struct vtm_item *item)
{
        return 0;
}

int g_main_prop_getter(struct vtm_menu *menu, struct vtm_item *item, vtm_item_property_t prop, void *value)
{
        return 0;
}

VTM_MENU(g_menu, "Menu")
        VTM_ITEM_ACTION("Action1", 0x10000001, g_main_action_callback)
        VTM_ITEM_ACTION("Action2", 0x10000002, g_main_action_callback)

        VTM_ITEM_SUBMENU("Submenu3", 0x10000003)
                VTM_ITEM_ACTION("Action31", 0x10000013, g_main_action_callback)
        VTM_ITEM_SUBMENU_END()

        VTM_ITEM_SUBMENU("Submenu4", 0x10000004)
                VTM_ITEM_ACTION("Action41", 0x10000014, g_main_action_callback)
                VTM_ITEM_ACTION("Action42", 0x10000024, g_main_action_callback)

                VTM_ITEM_SUBMENU("Submenu43", 0x10000034)
                        VTM_ITEM_ACTION("Action431", 0x10000134, g_main_action_callback)
                        VTM_ITEM_ACTION("Action432", 0x10000234, g_main_action_callback)
                        VTM_ITEM_ACTION("Action433", 0x10000334, g_main_action_callback)
                VTM_ITEM_SUBMENU_END()
        VTM_ITEM_SUBMENU_END()

        VTM_ITEM_ACTION("Action5", 0x10000005, g_main_action_callback)
VTM_MENU_END();

int main(int argc, char *argv[])
{
        vtm_init(&g_menu);

        while (1) {
                vtm_service(&g_menu);
        }
        
        return 0;
}