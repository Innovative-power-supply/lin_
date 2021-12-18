

#include "gui_guider.h"

extern TaskHandle_t ntConnectTaskHandler;
extern String ssidName, password;
extern void events_wifi_screen(void);
extern lv_obj_t *mbox;
extern lv_style_t style_modal;
extern bool wifi_has_config;

void printLocalTime()
{
  struct tm timeinfo;
  lv_label_set_text(ui->screen_ch2_runTime, "10h 33m");
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  lv_label_set_text_fmt(ui->screen_ch2_runTime, "%dh %dm",timeinfo.tm_hour,timeinfo.tm_min);  
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}
void mbox_event_handler(lv_obj_t * obj, lv_event_t event) {              
  if (event == LV_EVENT_VALUE_CHANGED) {

    if (strcmp(lv_msgbox_get_active_btn_text(obj), "Connect") == 0) {
      password = lv_textarea_get_text(ui->ta_password);
      password.trim();
      xTaskCreatePinnedToCore(
        wifiConnect_task     
        ,  "wifi connect Task"  
        ,  1024 * 4      
        ,  NULL         
        ,  1            
        ,  &ntConnectTaskHandler
        ,  0);         

    }
    else printf("user cancel\r\n");
    lv_obj_del(ui->kb);
    lv_obj_del(ui->ta_password);
    lv_obj_del(ui->mbox_connect);


     
            lv_obj_t *obj = lv_obj_create(lv_scr_act(), NULL);
            lv_obj_reset_style_list(obj, LV_OBJ_PART_MAIN);
            lv_obj_add_style(obj, LV_OBJ_PART_MAIN, &style_modal);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_HOR_RES, LV_VER_RES);
            static const char * btns2[] = {"Ok", "Cancel", ""};
            mbox = lv_msgbox_create(obj, NULL);
            lv_msgbox_add_btns(mbox, btns2);
            lv_msgbox_set_text(mbox, "Remember this Wifi ?");       
            lv_obj_align(mbox, NULL, LV_ALIGN_CENTER, 0, 0);
            lv_obj_set_event_cb(mbox, wifimbox_event_cb); 
    printf("selected wifi ap is %s , paswd is %s \r\n", ssidName.c_str(), password.c_str());
  }
}
static void wifimbox_event_cb(lv_obj_t *obj, lv_event_t evt)        
{
    if(evt == LV_EVENT_DELETE && obj == mbox) {
      
        lv_obj_del_async(lv_obj_get_parent(mbox));
        mbox = NULL; 
    } else if(evt == LV_EVENT_VALUE_CHANGED) {
      
        
      if(lv_msgbox_get_active_btn_text(obj) == "Ok")
      {  
        listDir(SPIFFS, "/", 0);
        writeFile(SPIFFS, "/ssidname.txt", &ssidName.c_str()[0]);
        writeFile(SPIFFS, "/password.txt", &password.c_str()[0]);
       printf("save completion\n");
      }else{
        printf("no save\n");
      }
        lv_msgbox_start_auto_close(mbox, 0);
    }
}
void popupPWMsgBox(void) {
  if (ssidName == NULL || ssidName.length() == 0) 
  {
    return;
  }
  ui->mbox_connect = lv_msgbox_create(lv_scr_act(), NULL);    
  // lv_obj_set_pos(ui->mbox_connect, 100, 50);                  
  lv_obj_set_width(ui->mbox_connect, 200);
  lv_obj_align(ui->mbox_connect, NULL, LV_ALIGN_CENTER, 0, -140);   
  lv_msgbox_set_text(ui->mbox_connect, ssidName.c_str());     

  //在这个弹出式信息框上增加text area
  ui->ta_password = lv_textarea_create(ui->mbox_connect, NULL);  
  lv_obj_set_size(ui->ta_password, 200, 40);                   
  lv_textarea_set_text(ui->ta_password, "");
  // 在这个弹出式信息框上增加"Connect"和 "Cancel"
  static const char * btns[] = {"Connect", "Cancel", ""};
  lv_msgbox_add_btns(ui->mbox_connect, btns);

  lv_obj_set_event_cb(ui->mbox_connect, mbox_event_handler);      

  ui->kb = lv_keyboard_create(lv_scr_act(), NULL);
  lv_obj_set_size(ui->kb,  LV_HOR_RES, LV_VER_RES / 2);       
  lv_keyboard_set_cursor_manage(ui->kb, true);

  lv_keyboard_set_textarea(ui->kb, ui->ta_password);            
}
extern String ssidName, password;
void list_event_handler(lv_obj_t * obj, lv_event_t event)
{
  if (event == LV_EVENT_CLICKED) {
    String customSelect(lv_list_get_btn_text(obj));
    //    printf("Clicked: %s\n", customSelect.c_str());
    for (int i = 0; i < customSelect.length() - 1; i++) {
      if (customSelect.substring(i, i + 2) == " (") {   
        ssidName = customSelect.substring(0, i);
        break;
      }
    }
    printf("selected AP: %s\n", ssidName.c_str());
    popupPWMsgBox();                                          
  }
}

static void wifi_config_scanevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
  case LV_EVENT_CLICKED:  
  {
  sprintf(stateInfo, "start scanning...");
  lv_label_set_text(ui->wifi_config_state, stateInfo);
  xTaskCreatePinnedToCore(
    wifiScan_task     
    ,  "wifi Scan Task"   
    ,  1024 * 2      
    ,  NULL         
    ,  1            
    ,  NULL
    ,  0);        
}
    break;
    default:
    break;
  }
}

static void wifi_config_confirmevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
  case LV_EVENT_CLICKED:
  {

        printLocalTime();
         
        lv_obj_t *obj = lv_obj_create(lv_scr_act(), NULL);
        lv_obj_reset_style_list(obj, LV_OBJ_PART_MAIN);
        lv_obj_add_style(obj, LV_OBJ_PART_MAIN, &style_modal);
        lv_obj_set_pos(obj, 0, 0);
        lv_obj_set_size(obj, LV_HOR_RES, LV_VER_RES);
        static const char * btns2[] = {"Ok", "Cancel", ""};
        mbox = lv_msgbox_create(obj, NULL);
        lv_msgbox_add_btns(mbox, btns2);
        lv_msgbox_set_text(mbox, "Select Wifi AP");        // 05.26
        lv_obj_align(mbox, NULL, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_event_cb(mbox, mbox_event_cb);
  }
    break;
  default:
    break;
  }
}
static void mbox_event_cb(lv_obj_t *obj, lv_event_t evt)        
{
    if(evt == LV_EVENT_DELETE && obj == mbox) {
        
        lv_obj_del_async(lv_obj_get_parent(mbox));
        mbox = NULL; 
    } else if(evt == LV_EVENT_VALUE_CHANGED) {
       
        
      if(lv_msgbox_get_active_btn_text(obj) == "Ok"){  
       printf("ok\n");
      }else{
        printf("cancel\n");
     
      }
        lv_msgbox_start_auto_close(mbox, 0);
    }
}

static void wifi_config_connectevent_handler(lv_obj_t * obj, lv_event_t event)
{
  String item;
  switch (event)
  {
  case LV_EVENT_CLICKED:
  {
   
          listDir(SPIFFS, "/", 0);
          readFileToStr(SPIFFS,"/ssidname.txt",&item);
          lv_obj_t * list_btn;   
          list_btn = lv_list_add_btn(ui->wifi_config_foundWifi, NULL, item.c_str());  
          lv_obj_set_event_cb(list_btn, list_wified_event_handler);    
  }
    break;
  default:
    break;
  }
}
void list_wified_event_handler(lv_obj_t * obj, lv_event_t event)
{
  if (event == LV_EVENT_CLICKED) {  
    String customSelect(lv_list_get_btn_text(obj));
    ssidName = customSelect;
    
    listDir(SPIFFS, "/", 0);
    password = "";
    readFileToStr(SPIFFS,"/password.txt",&password);
 
    printf("password = %s",password.c_str());
    
      xTaskCreatePinnedToCore(
        wifiConnect_task    
        ,  "wifi connect Task"   
        ,  1024 * 4     
        ,  NULL       
        ,  1            
        ,  &ntConnectTaskHandler
        ,  0);          
  
  }
}
static void wifi_config_home_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
  case LV_EVENT_CLICKED:
  {
        wifi_has_config=true;
        lv_obj_del(ui->wifi_config);   
  }
    break;
  default:
    break;
  }
}

void events_wifi_screen(void)
{
  lv_obj_set_event_cb(ui->wifi_config_scan, wifi_config_scanevent_handler);  
  lv_obj_set_event_cb(ui->wifi_config_confirm, wifi_config_confirmevent_handler); 
  lv_obj_set_event_cb(ui->wifi_config_connect, wifi_config_connectevent_handler); 
  lv_obj_set_event_cb(ui->wifi_config_home, wifi_config_home_handler); 
}
