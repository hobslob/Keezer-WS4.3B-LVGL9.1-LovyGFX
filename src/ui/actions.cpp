#include <Arduino.h>
#include "ui.h"
#include "ui_helpers.h"
#include "screens.h"
#include "animations.h"
#include "includes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
    loadScreen(SCREEN_ID_SCN_SPLASH);
    //lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0, false); 
    lv_scr_load(screen);
*/

void action_keg1_home_click_cb(lv_event_t * e)
{ 

    // Set Active Tab
    lv_tabview_set_act(objects.tab_view1, 0, LV_ANIM_OFF);

	lv_label_set_text(objects.lbl_keg_data_title, "Keg 1 Settings");		
    
    // Update Kegname shown in textbox
    lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name1));

    // Update Kegtype Dropdown
    lv_dropdown_set_selected(objects.keg_type_dropdown, (uint32_t)KegData[0].KegType );

    // Update Keg Full Capacity Label
    Update_pnl_keg_capacity (0);

    // Update Keg Empty & Full textboxes
    char str[8];
    dtostrf(KegData[0].EmptyWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_empty, str );
    dtostrf(KegData[0].FullWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_full, str );

    // Update Scale Connectivitiy Status		
    if(MyKeezer.isScale1Installed)
        {
        // if weight > 2 lbs
        lv_label_set_text(objects.lbl_keg_status, "Scale: Connected");
        }
    else
        {
        lv_label_set_text(objects.lbl_keg_status, "Scale: Connected-No Keg On Scale");                
        }

    loadScreen(SCREEN_ID_SCN_KEG_DATA);
}

void action_keg2_home_click_cb(lv_event_t * e)
{ 
    lv_tabview_set_act(objects.tab_view1, 1, LV_ANIM_OFF);
	lv_label_set_text(objects.lbl_keg_data_title, "Keg 2 Settings");		
    lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name2));		

    // Update Kegtype Dropdown
    lv_dropdown_set_selected(objects.keg_type_dropdown, (uint32_t)KegData[1].KegType );

    // Update Keg Full Capacity Label
    Update_pnl_keg_capacity (1);

    // Update Keg Empty & Full textboxes
    char str[8];
    dtostrf(KegData[1].EmptyWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_empty, str );
    dtostrf(KegData[1].FullWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_full, str );

    // Update Scale Connectivitiy Status		
    if(MyKeezer.isScale1Installed)
        {
        // if weight > 2 lbs
        lv_label_set_text(objects.lbl_keg_status, "Scale: Connected");
        }
    else
        {
        lv_label_set_text(objects.lbl_keg_status, "Scale: Connected-No Keg On Scale");                
        }

    loadScreen(SCREEN_ID_SCN_KEG_DATA);
}

void action_keg3_home_click_cb(lv_event_t * e)
{ 
    lv_tabview_set_act(objects.tab_view1, 2, LV_ANIM_OFF);
	lv_label_set_text(objects.lbl_keg_data_title, "Keg 3 Settings");		
    lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name3));		

    // Update Kegtype Dropdown
    lv_dropdown_set_selected(objects.keg_type_dropdown, (uint32_t)KegData[2].KegType );

    // Update Keg Full Capacity Label
    Update_pnl_keg_capacity (2);

    // Update Keg Empty & Full textboxes
    char str[8];
    dtostrf(KegData[2].EmptyWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_empty, str );
    dtostrf(KegData[2].FullWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_full, str );

    // Update Scale Connectivitiy Status		
    if(MyKeezer.isScale1Installed)
        {
        // if weight > 2 lbs
        lv_label_set_text(objects.lbl_keg_status, "Scale: Connected");
        }
    else
        {
        lv_label_set_text(objects.lbl_keg_status, "Scale: Connected-No Keg On Scale");                
        }

    loadScreen(SCREEN_ID_SCN_KEG_DATA);
}

void action_keg4_home_click_cb(lv_event_t * e)
{ 
    lv_tabview_set_act(objects.tab_view1, 3, LV_ANIM_OFF);
	lv_label_set_text(objects.lbl_keg_data_title, "Keg 4 Settings");		
    lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name4));		

    // Update Kegtype Dropdown
    lv_dropdown_set_selected(objects.keg_type_dropdown, (uint32_t)KegData[3].KegType );

     // Update Keg Full Capacity Label
    Update_pnl_keg_capacity (3);

   // Update Keg Empty & Full textboxes
    char str[8];
    dtostrf(KegData[3].EmptyWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_empty, str );
    dtostrf(KegData[3].FullWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_full, str );

    // Update Scale Connectivitiy Status		
    if(MyKeezer.isScale1Installed)
        {
        // if weight > 2 lbs
        lv_label_set_text(objects.lbl_keg_status, "Scale: Connected");
        }
    else
        {
        lv_label_set_text(objects.lbl_keg_status, "Scale: Connected-No Keg On Scale");                
        }

    loadScreen(SCREEN_ID_SCN_KEG_DATA);
}


void action_pass_visible_click_cb(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target_obj(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
	    lv_textarea_set_password_mode(objects.txt_wifi_password, false);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
	    lv_textarea_set_password_mode(objects.txt_wifi_password, true);
    }

}

void action_wifi_connect_click_cb(lv_event_t * e)
{ 
    // Disconnect from current WiFi and update screen
    MyKeezer.isWiFiConnected = false;
    WiFi.disconnect();
    lv_label_set_text(objects.lbl_connected,"Not Connected");
    lv_led_set_color(objects.led_connected,lv_color_hex(0xFF0000));
    delay(1000);
    
    // Reconnect
    WiFi_Setup();

}

void action_wifi_back_click_cb(lv_event_t * e)
{
    loadScreen(SCREEN_ID_SCN_HOME);
}


void action_keg_save_data_click_cb(lv_event_t * e)
{ 
    // Get the currently selected Keg Tab
    uint16_t kegnum = lv_tabview_get_tab_act(objects.tab_view1);

    // Save the data
    KegData[kegnum].KegType = (uint8_t)lv_dropdown_get_selected(objects.keg_type_dropdown );
    KegData[kegnum].EmptyWeight = strtof (lv_textarea_get_text(objects.txt_weight_empty), NULL);
    KegData[kegnum].FullWeight = strtof (lv_textarea_get_text(objects.txt_weight_full), NULL);
    Save_Scale_Settings_To_NV_Storage(kegnum);
    
    // Update Keg Full Capacity Label
    Update_pnl_keg_capacity (kegnum);
}

void action_keg_set_empty_click_cb(lv_event_t * e)
{ 
char str[8];

    // Get the currently selected Keg Tab
    uint16_t kegnum = lv_tabview_get_tab_act(objects.tab_view1);

    //KegData[kegnum].EmptyWeight = KegData[kegnum].CurrentWeight;
    dtostrf(KegData[kegnum].CurrentWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_empty, str );
}


void action_keg_set_full_click_cb(lv_event_t * e)
{ 
char str[8];

    // Get the currently selected Keg Tab
    uint16_t kegnum = lv_tabview_get_tab_act(objects.tab_view1);

    //KegData[kegnum].FullWeight = KegData[kegnum].CurrentWeight;
    dtostrf(KegData[0].CurrentWeight, 5, 1, str);
    lv_textarea_set_text(objects.txt_weight_full, str );
}


void action_tab_click_cb(lv_event_t * e)
{
uint16_t kegpage = lv_tabview_get_tab_act(objects.tab_view1);
char str[8];

	switch (kegpage)
	{
		case 0:
            lv_label_set_text(objects.lbl_keg_data_title, "Keg 1 Settings");		
            lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name1));		

            // Update Scale Connectivitiy Status		
            if(MyKeezer.isScale1Installed)
                {
                if ( KegData[kegpage].CurrentWeight > 2 )
                    lv_label_set_text(objects.lbl_keg_status, "Scale: Connected");
                else
                    lv_label_set_text(objects.lbl_keg_status, "Scale: Connected-No Keg On Scale");                
                }
            else
                {
                lv_label_set_text(objects.lbl_keg_status, "Scale: Not Connected");                
                }

            // Update Kegtype Dropdown
            lv_dropdown_set_selected(objects.keg_type_dropdown, (uint32_t)KegData[0].KegType );

            // Update Keg Full Capacity Label
            Update_pnl_keg_capacity (0);

            // Update Keg Empty & Full textboxes
            dtostrf(KegData[0].EmptyWeight, 5, 1, str);
            lv_textarea_set_text(objects.txt_weight_empty, str );
            dtostrf(KegData[0].FullWeight, 5, 1, str);
            lv_textarea_set_text(objects.txt_weight_full, str );

			break;

		case 1:
            lv_label_set_text(objects.lbl_keg_data_title, "Keg 2 Settings");		
            lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name2));		

            // Update Scale Connectivitiy Status		
            if(MyKeezer.isScale2Installed)
                {
                if ( KegData[kegpage].CurrentWeight > 2 )
                    lv_label_set_text(objects.lbl_keg_status, "Scale: Connected");
                else
                    lv_label_set_text(objects.lbl_keg_status, "Scale: Connected-No Keg On Scale");                
                }
            else
                {
                lv_label_set_text(objects.lbl_keg_status, "Scale: Not Connected");                
                }

            // Update Kegtype Dropdown
            lv_dropdown_set_selected(objects.keg_type_dropdown, (uint32_t)KegData[1].KegType );

            // Update Keg Full Capacity Label
            Update_pnl_keg_capacity (1);

            // Update Keg Empty & Full textboxes
            dtostrf(KegData[1].EmptyWeight, 5, 1, str);
            lv_textarea_set_text(objects.txt_weight_empty, str );
            dtostrf(KegData[1].FullWeight, 5, 1, str);
            lv_textarea_set_text(objects.txt_weight_full, str );

			break;

		case 2:
            lv_label_set_text(objects.lbl_keg_data_title, "Keg 3 Settings");		
            lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name3));		

            // Update Scale Connectivitiy Status		
            if(MyKeezer.isScale3Installed)
                {
                if ( KegData[kegpage].CurrentWeight > 2 )
                    lv_label_set_text(objects.lbl_keg_status, "Scale: Connected");
                else
                    lv_label_set_text(objects.lbl_keg_status, "Scale: Connected-No Keg On Scale");                
                }
            else
                {
                lv_label_set_text(objects.lbl_keg_status, "Scale: Not Connected");                
                }

            // Update Kegtype Dropdown
            lv_dropdown_set_selected(objects.keg_type_dropdown, (uint32_t)KegData[2].KegType );

            // Update Keg Full Capacity Label
            Update_pnl_keg_capacity (2);

            // Update Keg Empty & Full textboxes
            dtostrf(KegData[2].EmptyWeight, 5, 1, str);
            lv_textarea_set_text(objects.txt_weight_empty, str );
            dtostrf(KegData[2].FullWeight, 5, 1, str);
            lv_textarea_set_text(objects.txt_weight_full, str );

			break;

		case 3:
            lv_label_set_text(objects.lbl_keg_data_title, "Keg 4 Settings");		
            lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name4));

            // Update Scale Connectivitiy Status		
            if(MyKeezer.isScale4Installed)
                {
                if ( KegData[kegpage].CurrentWeight > 2 )
                    lv_label_set_text(objects.lbl_keg_status, "Scale: Connected");
                else
                    lv_label_set_text(objects.lbl_keg_status, "Scale: Connected-No Keg On Scale");                
                }
            else
                {
                lv_label_set_text(objects.lbl_keg_status, "Scale: Not Connected");                
                }

            // Update Kegtype Dropdown
            lv_dropdown_set_selected(objects.keg_type_dropdown, (uint32_t)KegData[3].KegType );

            // Update Keg Full Capacity Label
            Update_pnl_keg_capacity (3);

            // Update Keg Empty & Full textboxes
            dtostrf(KegData[3].EmptyWeight, 5, 1, str);
            lv_textarea_set_text(objects.txt_weight_empty, str );
            dtostrf(KegData[3].FullWeight, 5, 1, str);
            lv_textarea_set_text(objects.txt_weight_full, str );

			break;

		default:
			break;
	}

}


void action_tab1_click_cb(lv_event_t * e)
{ 
	lv_label_set_text(objects.lbl_keg_data_title, "Keg 1 Settings");		
    lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name1));		

}

void action_tab2_click_cb(lv_event_t * e)
{ 
	lv_label_set_text(objects.lbl_keg_data_title, "Keg 2 Settings");		
    lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name2));		

}

void action_tab3_click_cb(lv_event_t * e)
{ 
	lv_label_set_text(objects.lbl_keg_data_title, "Keg 3 Settings");		
    lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name3));		

}

void action_tab4_click_cb(lv_event_t * e)
{ 
	lv_label_set_text(objects.lbl_keg_data_title, "Keg 4 Settings");		
    lv_textarea_set_text(objects.txt_keg_name, lv_label_get_text(objects.lbl_keg_name4));		

}


void action_wifi_pwd_click_cb(lv_event_t * e)
{ 
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target_obj(e);
    if(event_code == LV_EVENT_FOCUSED) {
        // Move the panel up
        //animate_obj_Up200pix(objects.pnl_wifi_main, 0);
        lv_obj_set_y(objects.pnl_wifi_main, -50);

		// Set keyboard parent back to Wifi
		lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);
        _ui_keyboard_set_target(objects.kbd_normal, objects.txt_wifi_password);

        _ui_flag_modify(objects.txt_wifi_ssid, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.chk_visible, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);

		// Display the keyboard. Will need to condition this
		_ui_flag_modify(objects.kbd_normal, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

    }

    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(objects.txt_wifi_ssid, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.chk_visible, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
    }

    if(event_code == LV_EVENT_READY) {
        // Hide the keyboard
		_ui_flag_modify(objects.kbd_normal, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.txt_wifi_ssid, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.chk_visible, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        
        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_y(objects.pnl_wifi_main, 0);

        // Save the SSID Name
        const char* wifiname = lv_textarea_get_text(target);
        MyKeezer.WiFiPWD = String(wifiname);
        Save_WiFi_To_NVStorage();

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

    if(event_code == LV_EVENT_CANCEL) {
		_ui_flag_modify(objects.kbd_normal, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.txt_wifi_ssid, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.chk_visible, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);

        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_y(objects.pnl_wifi_main, 30);

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

}



void action_wifi_ssid_click_cb(lv_event_t * e)
{ 
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target_obj(e);
    if(event_code == LV_EVENT_FOCUSED) {
        // Move the panel up
        //animate_obj_Up200pix(objects.pnl_wifi_main, 0);
        lv_obj_set_y(objects.pnl_wifi_main, -50);

		// Set keyboard parent back to Wifi
		lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);
        _ui_keyboard_set_target(objects.kbd_normal, objects.txt_wifi_ssid);

        _ui_flag_modify(objects.txt_wifi_password, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.chk_visible, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);

		// Display the keyboard. Will need to condition this
		_ui_flag_modify(objects.kbd_normal, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

    }

    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(objects.txt_wifi_password, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.chk_visible, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
    }

    if(event_code == LV_EVENT_READY) {
        // Hide the keyboard
		_ui_flag_modify(objects.kbd_normal, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.txt_wifi_password, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.chk_visible, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        
        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_y(objects.pnl_wifi_main, 0);

        // Save the SSID Name
        const char* wifiname = lv_textarea_get_text(target);
        MyKeezer.WiFiSSID = String(wifiname);
        Save_WiFi_To_NVStorage();

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

    if(event_code == LV_EVENT_CANCEL) {
		_ui_flag_modify(objects.kbd_normal, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.txt_wifi_password, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.chk_visible, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);

        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_y(objects.pnl_wifi_main, 0);

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

}



void action_keg_name_click_cb(lv_event_t * e)
{ 
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target_obj(e);
    if(event_code == LV_EVENT_FOCUSED) {
        // Move the panel up
        //animate_obj_Up200pix(objects.pnl_keg, 0);
        lv_obj_set_y(objects.pnl_keg, -150);

		// Set parent of wifi screen keyboard to this screen
		lv_obj_set_parent(objects.kbd_normal, objects.scn_keg_data);
        _ui_keyboard_set_target(objects.kbd_normal, objects.txt_keg_name);

        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_REMOVE);

		// Display the keyboard. Will need to condition this
		_ui_flag_modify(objects.kbd_normal, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

    }

    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
    }

    if(event_code == LV_EVENT_READY) {
        // Hide the keyboard
		_ui_flag_modify(objects.kbd_normal, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        
        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_y(objects.pnl_keg, 60);

        // Save the Keg name and update the main screen
	    uint16_t kegpage = lv_tabview_get_tab_act(objects.tab_view1);
        const char* kegname = lv_textarea_get_text(target);

        switch (kegpage)
            {
            case 0:
                lv_label_set_text(objects.lbl_keg_name1, kegname );
                KegData[0].ContentName = String (kegname);
                Save_Kegname_To_NVStorage(0);		
                break;

            case 1:
                lv_label_set_text(objects.lbl_keg_name2, kegname);		
                KegData[1].ContentName = String (kegname);
                Save_Kegname_To_NVStorage(1);		
                break;

            case 2:
                lv_label_set_text(objects.lbl_keg_name3, kegname);		
                KegData[2].ContentName = String (kegname);
                Save_Kegname_To_NVStorage(2);		
                break;

            case 3:
                lv_label_set_text(objects.lbl_keg_name4, kegname);		
                KegData[3].ContentName = String (kegname);
                Save_Kegname_To_NVStorage(3);		
                break;

            default:
                break;
            }

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

    if(event_code == LV_EVENT_CANCEL) {
		_ui_flag_modify(objects.kbd_normal, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);

        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_y(objects.pnl_keg, 60);

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

}



void action_keg_check_modify_click_cb(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target_obj(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        // Set panel opacity to normal
        //_ui_flag_modify(objects.pnl_keg_items, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        //_ui_state_modify(objects.pnl_keg_items, LV_Sta)
        //lv_obj_remove_state(objects.pnl_keg_items, LV_STATE_DISABLED);

        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.keg_type_dropdown, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);

    }

    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        //_ui_flag_modify(objects.pnl_keg_items, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        //lv_obj_add_state(objects.pnl_keg_items, LV_STATE_DISABLED);

        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.keg_type_dropdown, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);

    }


}


void action_keg_option_click_cb(lv_event_t * e)
{
uint16_t kegnum = lv_tabview_get_tab_act(objects.tab_view1);

    // Update Keg Full Capacity Label
    Update_pnl_keg_capacity (kegnum);

    // Update the kegimage
}


void action_keg_empty_click_cb(lv_event_t * e)
{ 
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target_obj(e);
    if(event_code == LV_EVENT_FOCUSED) {
        // Move the panel up
        //animate_obj_Right50pix(objects.pnl_wifi_main, 0);
        lv_obj_set_x(objects.pnl_keg_data, 50);

		// Set keyboard parent to Keg data
		lv_obj_set_parent(objects.kbd_numeric, objects.scn_keg_data);
        _ui_keyboard_set_target(objects.kbd_numeric, objects.txt_weight_empty);

        _ui_flag_modify(objects.chk_modify_kegdata, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.keg_type_dropdown, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_back, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);

		// Display the keyboard.
		_ui_flag_modify(objects.kbd_numeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

    }

    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(objects.chk_modify_kegdata, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.keg_type_dropdown, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_back, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
    }

    if(event_code == LV_EVENT_READY) {
        // Hide the keyboard
		_ui_flag_modify(objects.kbd_numeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.chk_modify_kegdata, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.keg_type_dropdown, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_back, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        
        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_x(objects.pnl_keg_data, -20);

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

    if(event_code == LV_EVENT_CANCEL) {
		_ui_flag_modify(objects.kbd_numeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.chk_modify_kegdata, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.txt_weight_full, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_back, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);

        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_x(objects.pnl_keg_data, -20);

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

}


void action_keg_full_click_cb(lv_event_t * e)
{ 
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target_obj(e);
    if(event_code == LV_EVENT_FOCUSED) {
        // Move the panel up
        //animate_obj_Right50pix(objects.pnl_wifi_main, 0);
        lv_obj_set_x(objects.pnl_keg_data, 50);

		// Set keyboard parent to Keg data
		lv_obj_set_parent(objects.kbd_numeric, objects.scn_keg_data);
        _ui_keyboard_set_target(objects.kbd_numeric, objects.txt_weight_full);

        _ui_flag_modify(objects.chk_modify_kegdata, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.keg_type_dropdown, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_back, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_REMOVE);

		// Display the keyboard.
		_ui_flag_modify(objects.kbd_numeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

    }

    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(objects.chk_modify_kegdata, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.keg_type_dropdown, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_back, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
    }

    if(event_code == LV_EVENT_READY) {
        // Hide the keyboard
		_ui_flag_modify(objects.kbd_numeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.chk_modify_kegdata, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.keg_type_dropdown, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_back, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        
        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_x(objects.pnl_keg_data, -20);

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

    if(event_code == LV_EVENT_CANCEL) {
		_ui_flag_modify(objects.kbd_numeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        _ui_flag_modify(objects.chk_modify_kegdata, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.txt_weight_empty, LV_OBJ_FLAG_CLICK_FOCUSABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_back, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_recalibrate, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_reset, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_save, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_empty, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_kegdata_set_full, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_ADD);

        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_x(objects.pnl_keg_data, -20);

		// Set keyboard parent back to Wifi
		//lv_obj_set_parent(objects.kbd_normal, objects.scn_wifi);

    }

}


void action_keg_default_click_cb(lv_event_t * e){ }



void action_keg_calibrate_scale_click_cb(lv_event_t * e)
{
 	    uint16_t kegpage = lv_tabview_get_tab_act(objects.tab_view1);

        switch (kegpage)
            {
            case 0:
                lv_label_set_text(objects.lbl_scale_num, "Scale 1 Calibration" );
                
                // Save existing calibration data in temporary vars
                tempCalibrationFactor = ScaleData[kegpage].CalibrationFactor;
                tempZeroOffset = ScaleData[kegpage].ZeroOffset;
                break;

            case 1:
                lv_label_set_text(objects.lbl_scale_num, "Scale 2 Calibration" );		
                
                // Save existing calibration data in temporary vars
                tempCalibrationFactor = ScaleData[kegpage].CalibrationFactor;
                tempZeroOffset = ScaleData[kegpage].ZeroOffset;
                break;

            case 2:
                lv_label_set_text(objects.lbl_scale_num, "Scale 3 Calibration" );		
                
                // Save existing calibration data in temporary vars
                tempCalibrationFactor = ScaleData[kegpage].CalibrationFactor;
                tempZeroOffset = ScaleData[kegpage].ZeroOffset;
                break;

            case 3:
                lv_label_set_text(objects.lbl_scale_num, "Scale 4 Calibration" );		
                
                // Save existing calibration data in temporary vars
                tempCalibrationFactor = ScaleData[kegpage].CalibrationFactor;
                tempZeroOffset = ScaleData[kegpage].ZeroOffset;
                break;

            default:
                break;
            }

   loadScreen(SCREEN_ID_SCN_CALIBRATE);

}

void action_keg_data_back_click_cb(lv_event_t * e)
{
    loadScreen(SCREEN_ID_SCN_HOME);
}

void action_home_wifi_icon_click_cb(lv_event_t * e)
{
    loadScreen(SCREEN_ID_SCN_WIFI);
}


void action_home_temp_panel_click_cb(lv_event_t * e)
{
	// Your code here
    lv_event_code_t event_code = lv_event_get_code(e);
    //lv_obj_t * target = lv_event_get_target(e);
    //lv_obj_t *obj = lv_obj_create(0);
    //objects.lbl_temp_units = obj;
    if(event_code == LV_EVENT_CLICKED) {
        // Change panel color to blue
		//lv_obj_set_style_bg_color(ui_scnHomePanel_pnlTemperature, lv_color_hex(0xff0000), 0);
        // Change temperature units
        if (MyKeezer.Temp_Display_Units == TEMPERATURE_UNITS_C)
            {
            lv_label_set_text(objects.lbl_temp_units, "F");
            MyKeezer.Temp_Display_Units = TEMPERATURE_UNITS_F;
            }
        else
            {
            lv_label_set_text(objects.lbl_temp_units, "C");
            MyKeezer.Temp_Display_Units = TEMPERATURE_UNITS_C;
            }
        
        // Update temperature display now
        update_temperature_info();

    }
    if(event_code == LV_EVENT_LONG_PRESSED) {
        // Change panel color to blue
		//lv_obj_set_style_bg_color(ui_scnHomePanel_pnlTemperature, lv_color_hex(0x0000ff), 0);
    }

}

void action_cal_step1_click_cb(lv_event_t * e)
{
    // Step 1: wait for removal of everything on scale OK click. This allows us to get the Zero Offset
   	uint16_t scalenum = lv_tabview_get_tab_act(objects.tab_view1);

    Calculate_New_Zero_Offset(scalenum);


    // Show Next Step on screen
    _ui_flag_modify(objects.lbl_step2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    _ui_flag_modify(objects.btn_step2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

}

void action_cal_step2_click_cb(lv_event_t * e)
{
    // Step 2: wait for user to place known weight on scale and click OK.

    // Show Next Step on screen
    _ui_flag_modify(objects.lbl_step3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    _ui_flag_modify(objects.txt_cal_known_weight, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

}

void action_cal_step3_click_cb(lv_event_t * e)
{
    // Step 3: Take the user input in textbox and use it to calculate the calibration factor
   	uint16_t scalenum = lv_tabview_get_tab_act(objects.tab_view1);

	//Read user input
	float weightOnScale = strtof (lv_textarea_get_text(objects.txt_cal_known_weight), NULL);
	//float weightOnScale = 10;

    Calculate_New_Cal_Factor(scalenum, weightOnScale);


    // Update the label showing current weight
    //lv_label_set_text_fmt();

    // Show Next Step on screen - show the save button
    _ui_flag_modify(objects.btn_cal_save, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

}

void action_cal_txt_click_cb(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_current_target_obj(e);
    if(event_code == LV_EVENT_FOCUSED) {
        // Move the panel right
        //animate_obj_Right50pix(objects.pnl_wifi_main, 0);
        lv_obj_set_x(objects.txt_cal_known_weight, 30);

		// Set keyboard parent to Keg data
		lv_obj_set_parent(objects.kbd_numeric, objects.scn_calibrate);
        _ui_keyboard_set_target(objects.kbd_numeric, objects.txt_cal_known_weight);

		// Display the keyboard.
		_ui_flag_modify(objects.kbd_numeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

    }

    if(event_code == LV_EVENT_DEFOCUSED) {
    }

    if(event_code == LV_EVENT_READY) {
        // Hide the keyboard
		_ui_flag_modify(objects.kbd_numeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(objects.btn_step3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

        //Restore Panel to original position
        //animate_obj_Down200pix(objects.pnl_keg, 0);
        lv_obj_set_x(objects.txt_cal_known_weight, 0);

    }

    if(event_code == LV_EVENT_CANCEL) {
		_ui_flag_modify(objects.kbd_numeric, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

        //Restore Panel to original position
        //animate_obj_Down200pix(objects.txt_cal_known_weight, 0);
        lv_obj_set_x(objects.txt_cal_known_weight, 0);


    }

}

void action_cal_cancel_click_cb(lv_event_t * e)
{
    _ui_flag_modify(objects.lbl_step2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.btn_step2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.lbl_step3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.btn_step3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.btn_cal_save, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.txt_cal_known_weight, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

                
    // Restore previous calibration data from temporary vars
 	uint16_t scalenum = lv_tabview_get_tab_act(objects.tab_view1);
    ScaleData[scalenum].CalibrationFactor = tempCalibrationFactor;
    ScaleData[scalenum].ZeroOffset = tempZeroOffset;
    ReCalibrate_Scale_AFE (scalenum);

    loadScreen(SCREEN_ID_SCN_KEG_DATA);

}


void action_cal_save_click_cb(lv_event_t * e)
{
    // Last Step: Save the new data
   	uint16_t scalenum = lv_tabview_get_tab_act(objects.tab_view1);

    Read_Calibration_Settings_from_Scale (scalenum);

	//Commit these values to NV Storage
    Save_Scale_Settings_To_NV_Storage( scalenum );

    _ui_flag_modify(objects.lbl_step2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.btn_step2, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.lbl_step3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.btn_step3, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.btn_cal_save, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(objects.txt_cal_known_weight, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);

    loadScreen(SCREEN_ID_SCN_KEG_DATA);
}



#ifdef __cplusplus
}
#endif
