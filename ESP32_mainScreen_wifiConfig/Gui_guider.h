

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H

#define ON  1                                 
#define OFF 0                                 
#define channel1_I 0                        
#define channel1_V 1                       
#define channel2_I 3                       
#define channel2_V 4                    
#define DAC1 25                                 
#define DAC2 26                                    
String ssidName, password;                    
bool ch2OnOff = OFF;
bool ch1OnOff = OFF;
bool wifi_on = false;
bool wifi_has_config = false;          
unsigned ch_VIset_choose;
TaskHandle_t ntConnectTaskHandler;
static lv_obj_t *mbox;
static lv_style_t style_modal;

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 8*3600; 
const int   daylightOffset_sec = 4*3600;
void printLocalTime();
struct lv_ui{
  
  
  lv_obj_t *screen;
  lv_obj_t* bgk;
  lv_obj_t *screen_power;
  lv_obj_t *screen_power_label;
  lv_obj_t *screen_ch1_onOff;
  lv_obj_t *screen_ch2_onOff;
  lv_obj_t *screen_ch1_onOff_label;
  lv_obj_t *screen_ch2_onOff_label;
  lv_obj_t *screen_system_setup;
  lv_obj_t *screen_system_setup_label;
  lv_obj_t *screen_system_config;
  lv_obj_t *screen_system_config_label;
  lv_obj_t *screen_system_info;
  lv_obj_t *screen_system_info_label;
  lv_obj_t *screen_system_help;
  lv_obj_t *screen_system_help_label;
  lv_obj_t *screen_system_events;
  lv_obj_t *screen_system_events_label;
  lv_obj_t *screen_system_usb;
  lv_obj_t *screen_system_usb_label;
  lv_obj_t *screen_system_wifi;
  lv_obj_t *screen_system_wifi_label;
  lv_obj_t *screen_ch1_runTime;
  lv_obj_t *screen_ch2_runTime;
  lv_obj_t *screen_ch1_Vset;
  lv_obj_t *screen_ch1_Vset_label;
  lv_obj_t *screen_ch1_Iset;
  lv_obj_t *screen_ch1_Iset_label;
  lv_obj_t *screen_ch2_Vset;
  lv_obj_t *screen_ch2_Vset_label;
  lv_obj_t *screen_ch2_Iset;
  lv_obj_t *screen_ch2_Iset_label;
  lv_obj_t *screen_lineUp;
  lv_obj_t *screen_ch1_OVP;
  lv_obj_t *screen_ch1_OVP_label;
  lv_obj_t *screen_ch1_OCP;
  lv_obj_t *screen_ch1_OCP_label;
  lv_obj_t *screen_ch1_OPP;
  lv_obj_t *screen_ch1_OPP_label;
  lv_obj_t *screen_ch1_setup;
  lv_obj_t *screen_ch1_setup_label;
  lv_obj_t *screen_ch2_OVP;
  lv_obj_t *screen_ch2_OVP_label;
  lv_obj_t *screen_ch2_OCP;
  lv_obj_t *screen_ch2_OCP_label;
  lv_obj_t *screen_ch2_OPP;
  lv_obj_t *screen_ch2_OPP_label;
  lv_obj_t *screen_ch2_setup;
  lv_obj_t *screen_ch2_setup_label;
  lv_obj_t *screen_lab_CV;
  lv_obj_t *screen_lab_CV_label;
  lv_obj_t *screen_CH1_CV_LED;
  lv_obj_t *screen_CH2_CV_LED;
  lv_obj_t *screen_lab_CC;
  lv_obj_t *screen_lab_CC_label;
  lv_obj_t *screen_CH1_CC_LED;
  lv_obj_t *screen_CH2_CC_LED;
  lv_obj_t *screen_system_clock;
  lv_obj_t *screen_system_clock_label;

  lv_obj_t *wifi_config;
  lv_obj_t *wifi_config_wifi_config_title;
  lv_obj_t *wifi_config_wifiIcon;
  lv_obj_t *wifi_config_label_status;
  lv_obj_t *wifi_config_wifi_list;
  lv_obj_t *wifi_config_home;
  lv_obj_t *wifi_config_home_label;
  lv_obj_t *wifi_config_findWifi;
  lv_obj_t *wifi_config_findWifi_label;
  lv_obj_t *wifi_config_updateWifi;
  lv_obj_t *wifi_config_updateWifi_label;
  lv_obj_t *wifi_config_title;
  lv_obj_t *wifi_config_foundWifi;
  lv_obj_t *wifi_config_state;
  lv_obj_t *wifi_config_scan;
  lv_obj_t *wifi_config_scan_label;
  lv_obj_t *wifi_config_confirm;
  lv_obj_t *wifi_config_confirm_label;
  lv_obj_t *wifi_config_connect;
  lv_obj_t *wifi_config_connect_label;
  lv_obj_t *numKB;          
  lv_obj_t *ta;            
 lv_obj_t * ta_password;
 lv_obj_t * kb;
 lv_obj_t * mbox_connect;
} g_ui;

struct lv_ui *ui = &g_ui;
enum focused_button {
  ch1Vset = 0,
  ch1Iset,
  ch2Vset,
  ch2Iset
} channelVIset;

enum channel_State {
  cv = 0,
  cc,
}channel1CVCC = cv;
LV_IMG_DECLARE(_info1_alpha_50x50);
LV_IMG_DECLARE(_onOff5_alpha_70x70);
LV_IMG_DECLARE(_usb0_alpha_40x40);
LV_IMG_DECLARE(_onOff2_alpha_70x70);
LV_IMG_DECLARE(_onOff3_alpha_70x70);
LV_IMG_DECLARE(_usb3_alpha_40x40);
LV_IMG_DECLARE(_event0_alpha_40x40);
LV_IMG_DECLARE(_wifi0_alpha_50x50);
LV_IMG_DECLARE(_onOff4_alpha_70x70);
LV_IMG_DECLARE(_find_wifi1_alpha_50x50);
LV_IMG_DECLARE(_home0_alpha_50x50);
LV_IMG_DECLARE(_update0_alpha_50x50);
LV_IMG_DECLARE(_config0_alpha_50x50);
LV_IMG_DECLARE(_wifi1_alpha_40x40);
LV_IMG_DECLARE(_help0_alpha_50x50);
LV_IMG_DECLARE(_setup0_alpha_50x50);
LV_IMG_DECLARE(_unlock0_alpha_50x50);
LV_IMG_DECLARE(_wifi0_alpha_40x40);
LV_IMG_DECLARE(_lock0_alpha_50x50);

#endif
