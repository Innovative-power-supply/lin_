
#include "gui_guider.h"
//#include "AiEsp32RotaryEncoder.h"

extern String ssidName, password;                  
extern TimerHandle_t adcHandle;
extern TaskHandle_t ntConnectTaskHandler;
extern TimerHandle_t rotaryEncoderHandle;
extern void writePotmeter(int value);          
extern void wifiConfig_screen(void);          
extern void wifiConnect_task( void *pvParameters );
extern bool wifi_has_config;
extern bool ch1OnOff ;
extern bool ch2OnOff ;
extern unsigned ch_VIset_choose;                   
#include <esp32-hal-dac.h>


static void screen_ch1_onOffevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {
        if (ch1OnOff == OFF) {                     
          xTimerStart(adcHandle, 0xFFFF);          
          char *VsetChar = lv_label_get_text(ui->screen_ch1_Vset_label);
          uint16_t Vset  = atoi(VsetChar);
          dacWrite(DAC1, Vset);                    
          ch1OnOff = ON;                          
        }
        else {                                     
          xTimerStop(adcHandle, 0xFFFF);            
          lv_label_set_text(ui->screen_ch1_onOff_label, "OFF");
          ch1OnOff = OFF;                           
          rotaryEncoder.disable();                 
          dacWrite(DAC1, 0);                      

        }
      }
      break;
    default:
      break;
  }
}
static void screen_ch2_onOffevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {
        if (ch2OnOff == OFF) {                  
          xTimerStart(adcHandle, 0xFFFF);          
          char *VsetChar = lv_label_get_text(ui->screen_ch2_Vset_label);
          uint16_t Vset  = atoi(VsetChar);

          dacWrite(DAC2, Vset);                    
          ch2OnOff = ON;                        
        }
        else {                                     
          xTimerStop(adcHandle, 0xFFFF);          
          lv_label_set_text(ui->screen_ch2_onOff_label, "OFF");
          ch2OnOff = OFF;                          
          rotaryEncoder.disable();                 
          dacWrite(DAC2, 0);                     

        }
      }
      break;
    default:
      break;
  }
}
extern bool wifi_on ;
static void screen_system_wifievent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_PRESSED:       
      {
        if(wifi_has_config == false)
        {
             wifiConfig_screen();
          }
        else
        {
        if(wifi_on == true)
        {
          Serial.println("wifi on\r\n");
          wifi_on = false;
      xTaskCreatePinnedToCore(
        wifiConnect_task     
        ,  "wifi connect Task"   
        ,  1024 * 4     
        ,  NULL         
        ,  1            
        ,  &ntConnectTaskHandler
        ,  0);         
        }
        else
        {
            Serial.println("off\r\n");
            vTaskDelete(ntConnectTaskHandler);
            wifi_on = true;
        }
       }
      }
      break;
    case LV_EVENT_LONG_PRESSED:
      {
      
        Serial.println("wifi btn long pressed\r\n");
        wifiConfig_screen();
      }
      break;
    default:
      break;
  }
}
extern AiEsp32RotaryEncoder rotaryEncoder;
extern  void num_input_taKB(void);

static void screen_ch1_Vsetevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_LONG_PRESSED:
      {
        ch_VIset_choose=channel1_V;
        num_input_taKB();
      }
      break;
    case LV_EVENT_FOCUSED:
      {
        channelVIset = ch1Vset;
        rotaryEncoder.enable();
        if (xTimerIsTimerActive(rotaryEncoderHandle) == pdFALSE) xTimerStart(rotaryEncoderHandle, 0xFFFF);
        lv_obj_set_style_local_bg_color(ui->screen_ch1_Vset, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xf7, 0x02, 0x02));
      }   break;

    case LV_EVENT_DEFOCUSED:
      {
        lv_obj_set_style_local_bg_color(ui->screen_ch1_Vset, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
      } break;
    default:
      break;
  }
}


static void screen_ch2_Vsetevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_LONG_PRESSED:
      {
        ch_VIset_choose=channel2_V;
        num_input_taKB();
      }
      break;
    case LV_EVENT_FOCUSED:
      {
        channelVIset = ch2Vset;
        rotaryEncoder.enable();
        if (xTimerIsTimerActive(rotaryEncoderHandle) == pdFALSE) xTimerStart(rotaryEncoderHandle, 0xFFFF);
        lv_obj_set_style_local_bg_color(ui->screen_ch2_Vset, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xf7, 0x02, 0x02));
      }   break;

    case LV_EVENT_DEFOCUSED:
      {
        lv_obj_set_style_local_bg_color(ui->screen_ch2_Vset, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
      } break;
    default:
      break;
  }
}

static void screen_ch1_Isetevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_LONG_PRESSED:
      {
        ch_VIset_choose=channel1_I;
        num_input_taKB();       
      }
      break;
    case LV_EVENT_FOCUSED:
      {
        channelVIset = ch1Iset;
        rotaryEncoder.enable();
        if (xTimerIsTimerActive(rotaryEncoderHandle) == pdFALSE) xTimerStart(rotaryEncoderHandle, 0xFFFF);
        lv_obj_set_style_local_bg_color(ui->screen_ch1_Iset, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xf7, 0x02, 0x02));
      }   break;

    case LV_EVENT_DEFOCUSED:
      {
        lv_obj_set_style_local_bg_color(ui->screen_ch1_Iset, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
      } break;
    default:
      break;
  }
}

static void screen_ch2_Isetevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_LONG_PRESSED:
      {
        ch_VIset_choose=channel2_I;
        num_input_taKB();        
      }
      break;
    case LV_EVENT_FOCUSED:
      {
        channelVIset = ch2Iset;
        rotaryEncoder.enable();
        if (xTimerIsTimerActive(rotaryEncoderHandle) == pdFALSE) xTimerStart(rotaryEncoderHandle, 0xFFFF);
        lv_obj_set_style_local_bg_color(ui->screen_ch2_Iset, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xf7, 0x02, 0x02));
      }   break;

    case LV_EVENT_DEFOCUSED:
      {
        lv_obj_set_style_local_bg_color(ui->screen_ch2_Iset, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
      } break;
    default:
      break;
  }
}
static void screen_ch1_OVPevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {

      }
      break;
    default:
      break;
  }
}

static void screen_ch2_OVPevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {

      }
      break;
    default:
      break;
  }
}

static void screen_ch1_OCPevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {

      }
      break;
    default:
      break;
  }
}

static void screen_ch2_OCPevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {

      }
      break;
    default:
      break;
  }
}
static void screen_ch1_OPPevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {

      }
      break;
    default:
      break;
  }
}

static void screen_ch2_OPPevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {

      }
      break;
    default:
      break;
  }
}

static void screen_ch1_setupevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {

      }
      break;
    default:
      break;
  }
}


static void screen_ch2_setupevent_handler(lv_obj_t * obj, lv_event_t event)
{
  switch (event)
  {
    case LV_EVENT_CLICKED:
      {

      }
      break;
    default:
      break;
  }
}

void events_mainScreen(void)
{
  lv_obj_set_event_cb(ui->screen_ch1_onOff, screen_ch1_onOffevent_handler);
  lv_obj_set_event_cb(ui->screen_ch1_Vset, screen_ch1_Vsetevent_handler);
  lv_obj_set_event_cb(ui->screen_ch1_Iset, screen_ch1_Isetevent_handler);
  lv_obj_set_event_cb(ui->screen_ch1_OVP, screen_ch1_OVPevent_handler);
  lv_obj_set_event_cb(ui->screen_ch1_OCP, screen_ch1_OCPevent_handler);
  lv_obj_set_event_cb(ui->screen_ch1_OPP, screen_ch1_OPPevent_handler);
  lv_obj_set_event_cb(ui->screen_ch1_setup, screen_ch1_setupevent_handler);

  lv_obj_set_event_cb(ui->screen_ch2_onOff, screen_ch2_onOffevent_handler);
  lv_obj_set_event_cb(ui->screen_ch2_Vset, screen_ch2_Vsetevent_handler);
  lv_obj_set_event_cb(ui->screen_ch2_Iset, screen_ch2_Isetevent_handler);
  lv_obj_set_event_cb(ui->screen_ch2_OVP, screen_ch2_OVPevent_handler);
  lv_obj_set_event_cb(ui->screen_ch2_OCP, screen_ch2_OCPevent_handler);
  lv_obj_set_event_cb(ui->screen_ch2_OPP, screen_ch2_OPPevent_handler);
  lv_obj_set_event_cb(ui->screen_ch2_setup, screen_ch2_setupevent_handler);

  lv_obj_set_event_cb(ui->screen_system_wifi, screen_system_wifievent_handler);  
}
