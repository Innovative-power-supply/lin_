
#include <lvgl.h>
#include <TFT_eSPI.h>

#include "FS.h"
#include "SPIFFS.h"
#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <scpi-parser.h>
#include "Scpi-def.h"
#include "gui_guider.h"      
#define FORMAT_SPIFFS_IF_FAILED true
extern void lv_tft_setup(void);                
extern void rotaryEncoder_setup(void);         
extern void mcp4xx_setup(void);                 
extern void adcTimer_setup(void);               
extern void rotaryEncoderTimer_setup(void);     

extern void GUI_task( void *pvParameters );    
void setup() {

  Serial.begin(115200); 

      delay(10);
  if(!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)){  
      Serial.println("SPIFFS Mount Failed");
      return;
  }
  #if USE_LV_LOG != 0
    lv_log_register_print_cb(my_print); 
  #endif

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer); 
  lv_tft_setup();                       
  rotaryEncoder_setup();               
  mcp4xx_setup();                      
  adcTimer_setup();                    
  rotaryEncoderTimer_setup();          
    pinMode(22, OUTPUT);
    digitalWrite(22, LOW);
    delay(500);
    digitalWrite(22, HIGH);
  xTaskCreatePinnedToCore(
    GUI_task     
    ,  "GUI Task"   
    ,  1024*4     
    ,  NULL         
    ,  1            
    ,  NULL 
    ,  1);          
}
