

#include "gui_guider.h"

extern TaskHandle_t ntConnectTaskHandler;
extern String ssidName, password;
extern bool wifi_has_config;
void events_wifi_screen(void);
void wifi_screen(void) {
   
   wifi_has_config=false;
  
  ui->wifi_config_title = lv_label_create(ui->wifi_config, NULL);
  lv_label_set_text(ui->wifi_config_title, "wifi config");
  lv_label_set_long_mode(ui->wifi_config_title, LV_LABEL_LONG_BREAK);
  lv_label_set_align(ui->wifi_config_title, LV_LABEL_ALIGN_CENTER);
  static lv_style_t style_wifi_config_title_main;
  lv_style_init(&style_wifi_config_title_main);
  lv_style_set_radius(&style_wifi_config_title_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_wifi_config_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_wifi_config_title_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_wifi_config_title_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_wifi_config_title_main, LV_STATE_DEFAULT, 255);
  lv_style_set_text_color(&style_wifi_config_title_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_text_font(&style_wifi_config_title_main, LV_STATE_DEFAULT, &lv_font_montserrat_22);
  lv_style_set_text_letter_space(&style_wifi_config_title_main, LV_STATE_DEFAULT, 1);
  lv_style_set_pad_left(&style_wifi_config_title_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_right(&style_wifi_config_title_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_top(&style_wifi_config_title_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_bottom(&style_wifi_config_title_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->wifi_config_title, LV_LABEL_PART_MAIN, &style_wifi_config_title_main);
  lv_obj_set_pos(ui->wifi_config_title, 77, 29);
  lv_obj_set_size(ui->wifi_config_title, 328, 0);
  ui->wifi_config_foundWifi = lv_list_create(ui->wifi_config, NULL);
  lv_list_set_edge_flash(ui->wifi_config_foundWifi, true);
  lv_list_set_anim_time(ui->wifi_config_foundWifi, 255);
  static lv_style_t style_wifi_config_foundWifi_bg;
  lv_style_init(&style_wifi_config_foundWifi_bg);
  lv_style_set_radius(&style_wifi_config_foundWifi_bg, LV_STATE_DEFAULT, 3);
  lv_style_set_border_color(&style_wifi_config_foundWifi_bg, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
  lv_style_set_border_width(&style_wifi_config_foundWifi_bg, LV_STATE_DEFAULT, 1);
  lv_obj_add_style(ui->wifi_config_foundWifi, LV_LIST_PART_BG, &style_wifi_config_foundWifi_bg);
  static lv_style_t style_wifi_config_foundWifi_scrollable;
  lv_style_init(&style_wifi_config_foundWifi_scrollable);
  lv_style_set_radius(&style_wifi_config_foundWifi_scrollable, LV_STATE_DEFAULT, 3);
  lv_style_set_bg_color(&style_wifi_config_foundWifi_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_wifi_config_foundWifi_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_wifi_config_foundWifi_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_wifi_config_foundWifi_scrollable, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->wifi_config_foundWifi, LV_LIST_PART_SCROLLABLE, &style_wifi_config_foundWifi_scrollable);
  static lv_style_t style_wifi_config_foundWifi_main_child;
  lv_style_init(&style_wifi_config_foundWifi_main_child);
  lv_style_set_radius(&style_wifi_config_foundWifi_main_child, LV_STATE_DEFAULT, 3);
  lv_style_set_bg_color(&style_wifi_config_foundWifi_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_wifi_config_foundWifi_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_wifi_config_foundWifi_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_wifi_config_foundWifi_main_child, LV_STATE_DEFAULT, 255);
  lv_style_set_text_color(&style_wifi_config_foundWifi_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
  lv_obj_set_pos(ui->wifi_config_foundWifi, 15, 58);          
  lv_obj_set_size(ui->wifi_config_foundWifi, 394, 210);      
  lv_obj_t *wifi_config_foundWifi_btn;
  ui->wifi_config_state = lv_label_create(ui->wifi_config, NULL);
  lv_label_set_text(ui->wifi_config_state, "standby, push scan to start...");
  lv_label_set_long_mode(ui->wifi_config_state, LV_LABEL_LONG_BREAK);
  lv_label_set_align(ui->wifi_config_state, LV_LABEL_ALIGN_CENTER);
  static lv_style_t style_wifi_config_state_main;
  lv_style_init(&style_wifi_config_state_main);
  lv_style_set_radius(&style_wifi_config_state_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_wifi_config_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_wifi_config_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_wifi_config_state_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_wifi_config_state_main, LV_STATE_DEFAULT, 255);
  lv_style_set_text_color(&style_wifi_config_state_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_text_font(&style_wifi_config_state_main, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  lv_style_set_text_letter_space(&style_wifi_config_state_main, LV_STATE_DEFAULT, 1);
  lv_style_set_pad_left(&style_wifi_config_state_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_right(&style_wifi_config_state_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_top(&style_wifi_config_state_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_bottom(&style_wifi_config_state_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->wifi_config_state, LV_LABEL_PART_MAIN, &style_wifi_config_state_main);
  lv_obj_set_pos(ui->wifi_config_state, 10, 280);
  lv_obj_set_size(ui->wifi_config_state, 420, 0);
  ui->wifi_config_scan = lv_btn_create(ui->wifi_config, NULL);
  static lv_style_t style_wifi_config_scan_main;
  lv_style_init(&style_wifi_config_scan_main);
  lv_style_set_radius(&style_wifi_config_scan_main, LV_STATE_DEFAULT, 50);
  lv_style_set_bg_color(&style_wifi_config_scan_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_wifi_config_scan_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_wifi_config_scan_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_wifi_config_scan_main, LV_STATE_DEFAULT, 255);
  lv_style_set_border_color(&style_wifi_config_scan_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_wifi_config_scan_main, LV_STATE_DEFAULT, 2);
  lv_style_set_border_opa(&style_wifi_config_scan_main, LV_STATE_DEFAULT, 255);
  lv_style_set_outline_color(&style_wifi_config_scan_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_wifi_config_scan_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->wifi_config_scan, LV_BTN_PART_MAIN, &style_wifi_config_scan_main);
  lv_obj_set_pos(ui->wifi_config_scan, 423, 62);
  lv_obj_set_size(ui->wifi_config_scan, 50, 50);
  ui->wifi_config_scan_label = lv_label_create(ui->wifi_config_scan, NULL);
  lv_label_set_text(ui->wifi_config_scan_label, "scan");
  lv_obj_set_style_local_text_color(ui->wifi_config_scan_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->wifi_config_scan_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  ui->wifi_config_confirm = lv_btn_create(ui->wifi_config, NULL);
  static lv_style_t style_wifi_config_confirm_main;
  lv_style_init(&style_wifi_config_confirm_main);
  lv_style_set_radius(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, 50);
  lv_style_set_bg_color(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, 255);
  lv_style_set_border_color(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, 2);
  lv_style_set_border_opa(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, 255);
  lv_style_set_outline_color(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_wifi_config_confirm_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->wifi_config_confirm, LV_BTN_PART_MAIN, &style_wifi_config_confirm_main);
  lv_obj_set_pos(ui->wifi_config_confirm, 422, 121);
  lv_obj_set_size(ui->wifi_config_confirm, 50, 50);
  ui->wifi_config_confirm_label = lv_label_create(ui->wifi_config_confirm, NULL);
  lv_label_set_text(ui->wifi_config_confirm_label, "confirm");
  lv_obj_set_style_local_text_color(ui->wifi_config_confirm_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->wifi_config_confirm_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  ui->wifi_config_connect = lv_btn_create(ui->wifi_config, NULL);
  static lv_style_t style_wifi_config_connect_main;
  lv_style_init(&style_wifi_config_connect_main);
  lv_style_set_radius(&style_wifi_config_connect_main, LV_STATE_DEFAULT, 50);
  lv_style_set_bg_color(&style_wifi_config_connect_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_wifi_config_connect_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_wifi_config_connect_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_wifi_config_connect_main, LV_STATE_DEFAULT, 255);
  lv_style_set_border_color(&style_wifi_config_connect_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_wifi_config_connect_main, LV_STATE_DEFAULT, 2);
  lv_style_set_border_opa(&style_wifi_config_connect_main, LV_STATE_DEFAULT, 255);
  lv_style_set_outline_color(&style_wifi_config_connect_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_wifi_config_connect_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->wifi_config_connect, LV_BTN_PART_MAIN, &style_wifi_config_connect_main);
  lv_obj_set_pos(ui->wifi_config_connect, 424, 182);
  lv_obj_set_size(ui->wifi_config_connect, 50, 50);
  ui->wifi_config_connect_label = lv_label_create(ui->wifi_config_connect, NULL);
  lv_label_set_text(ui->wifi_config_connect_label, "connet");
  lv_obj_set_style_local_text_color(ui->wifi_config_connect_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->wifi_config_connect_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  ui->wifi_config_home = lv_btn_create(ui->wifi_config, NULL);
  static lv_style_t style_wifi_config_home_main;
  lv_style_init(&style_wifi_config_home_main);
  lv_style_set_radius(&style_wifi_config_home_main, LV_STATE_DEFAULT, 50);
  lv_style_set_bg_color(&style_wifi_config_home_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_wifi_config_home_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_wifi_config_home_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_wifi_config_home_main, LV_STATE_DEFAULT, 255);
  lv_style_set_border_color(&style_wifi_config_home_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_wifi_config_home_main, LV_STATE_DEFAULT, 2);
  lv_style_set_border_opa(&style_wifi_config_home_main, LV_STATE_DEFAULT, 255);
  lv_style_set_outline_color(&style_wifi_config_home_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_wifi_config_home_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->wifi_config_home, LV_BTN_PART_MAIN, &style_wifi_config_home_main);
  lv_obj_set_pos(ui->wifi_config_home, 422, 238);
  lv_obj_set_size(ui->wifi_config_home, 50, 50);
  ui->wifi_config_home_label = lv_label_create(ui->wifi_config_home, NULL);
  lv_label_set_text(ui->wifi_config_home_label, "home");
  lv_obj_set_style_local_text_color(ui->wifi_config_home_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->wifi_config_home_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  events_wifi_screen();
}



extern void list_event_handler(lv_obj_t * obj, lv_event_t event);
char stateInfo[64];

void wifiScan_task( void *pvParameters ) {
  int n = WiFi.scanNetworks();
  vTaskDelay(10);
  for (int i = 0; i < n; ++i) {
    String item = WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ") " + ((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
    lv_obj_t * list_btn;
    list_btn = lv_list_add_btn(ui->wifi_config_foundWifi, NULL, item.c_str());
    lv_obj_set_event_cb(list_btn, list_event_handler);
  }
  sprintf(stateInfo, "%d wifi AP Found!", n);
  lv_label_set_text(ui->wifi_config_state, stateInfo);
  vTaskDelete(NULL);
}


const int serverPort = 5023;           
#define BUFFER_SIZE 1024

WiFiServer server(serverPort);          
WiFiClient client;                     

byte client_buff[BUFFER_SIZE];          
char scpi_input_buff[BUFFER_SIZE];      
#define BUFFER_SIZE 1024

#define CONF_SERIAL_BUFFER_SIZE 64

scpi_t g_scpiContext;                 

size_t SCPI_Write(scpi_t *context, const char * data, size_t len) {
  size_t written = 0;

  for (size_t i = 0; i < len; i += CONF_SERIAL_BUFFER_SIZE) {
      size_t size = min((size_t)CONF_SERIAL_BUFFER_SIZE, len - i);
      Serial.write(data + i, size);                               
      written += size;
      }
  for (size_t i = 0; i < len; i++) client_buff[i] = (uint8_t) data[i];
  client.write(client_buff, len);
  client_buff[0] = '\0';
  return written;
}

scpi_result_t SCPI_Flush(scpi_t *context) {
    return SCPI_RES_OK;
}


int SCPI_Error(scpi_t * context, int_fast16_t err) {
    (void) context;

    fprintf(stderr, "**ERROR: %d, \"%s\"\r\n", (int16_t) err, SCPI_ErrorTranslate(err));
    return 0;
}

scpi_result_t SCPI_Control(scpi_t * context, scpi_ctrl_name_t ctrl, scpi_reg_val_t val) {
    (void) context;

    if (SCPI_CTRL_SRQ == ctrl) {
        fprintf(stderr, "**SRQ: 0x%X (%d)\r\n", val, val);
    } else {
        fprintf(stderr, "**CTRL %02x: 0x%X (%d)\r\n", ctrl, val, val);
    }
    return SCPI_RES_OK;
}

scpi_result_t SCPI_Reset(scpi_t * context) {
    (void) context;

    fprintf(stderr, "**Reset\r\n");
    return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommTcpipControlQ(scpi_t * context) {
    (void) context;

    return SCPI_RES_ERR;
}

void wifiConnect_task( void *pvParameters ) {
  SCPI_Init(&scpi_context,
            scpi_commands,
            &scpi_interface,
            scpi_units_def,
            SCPI_IDN1, SCPI_IDN2, SCPI_IDN3, SCPI_IDN4,
            scpi_input_buffer, SCPI_INPUT_BUFFER_LENGTH,
            scpi_error_queue_data, SCPI_ERROR_QUEUE_SIZE);
   if(wifi_has_config == true)
    {
          listDir(SPIFFS, "/", 0);
          ssidName = "";
          readFileToStr(SPIFFS,"/ssidname.txt",&ssidName);
          listDir(SPIFFS, "/", 0);
          password = ""; 
          readFileToStr(SPIFFS,"/password.txt",&password);
     }
  WiFi.begin(ssidName.c_str(), password.c_str());

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP().toString());
  server.begin();
  Serial.println("WiFi server started.");

  for (;;) {
    vTaskDelay(5);
    client = server.available();
    while (client.connected()) {
      vTaskDelay(5);
      int size = 0;
      while ((size = client.available())) {
        vTaskDelay(5);
        size = (size >= BUFFER_SIZE ? BUFFER_SIZE : size);
        client.read(client_buff, size);                            

        for (int i = 0; i < size; i++) scpi_input_buff[i] = (char)client_buff[i]; 
        scpi_input_buff[size] = '\r';                                    
        scpi_input_buff[size + 1] = '\n';
        Serial.println(scpi_input_buff);                                  

        SCPI_Input(&scpi_context, scpi_input_buff, size + 2);             
        client_buff[0]     = '\0';                                        
        scpi_input_buff[0] = '\0';                                        
      }
    }
    client.stop();
  }
}


void wifiConfig_screen(void) {
  Serial.println("enter wifiConfig_screen funciton\r\n");
  ui->wifi_config = lv_obj_create(lv_scr_act(), NULL);                       
  //
  lv_obj_set_style_local_bg_opa(ui->wifi_config, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);  
  lv_obj_set_style_local_bg_color(ui->wifi_config, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_pos(ui->wifi_config, 0, 0);
  lv_obj_set_size(ui->wifi_config, LV_HOR_RES, LV_VER_RES);

  wifi_screen();
}
