
#include "gui_guider.h"

TFT_eSPI tft = TFT_eSPI(); 

lv_disp_buf_t disp_buf;
lv_color_t buf[LV_HOR_RES_MAX * 32];


#if USE_LV_LOG != 0

void my_print(lv_log_level_t level, const char * file, uint32_t line, const char * dsc)
{

  Serial.printf("%s@%d->%s\r\n", file, line, dsc);
  delay(100);
}
#endif


void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint16_t c;

  tft.startWrite(); 
  tft.setAddrWindow(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1));
  for (int y = area->y1; y <= area->y2; y++) {
    for (int x = area->x1; x <= area->x2; x++) {
      c = color_p->full;
      tft.writeColor(c, 1);
      color_p++;
    }
  }
  tft.endWrite(); 
  lv_disp_flush_ready(disp);
}

bool my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
    uint16_t touchX, touchY;

    bool touched = tft.getTouch(&touchX, &touchY, 100);

    if(!touched)
    {
      return false;
    }

    if(touchX>LV_HOR_RES_MAX || touchY > LV_VER_RES_MAX)
    {
      Serial.println("Y or y outside of expected parameters..");
      Serial.print("y:");
      Serial.print(touchX);
      Serial.print(" x:");
      Serial.print(touchY);
    }
    else
    {

      data->state = touched ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL; 
  
    
      //if(data->state == LV_INDEV_STATE_PR) touchpad_get_xy(&last_x, &last_y);
     
     
      data->point.x = touchX;
      data->point.y = touchY;
  
   }

    return false; 
}


void lv_tft_setup(void){
  
//  ledcSetup(10, 5000/*freq*/, 10 /*resolution*/);   
//  ledcAttachPin(22, 10);
//  analogReadResolution(10);
//  ledcWrite(10,768);                               

  lv_init();                           
  
  tft.begin(); 
  tft.setRotation(3);                             

  uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
  tft.setTouch(calData);


  lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * 10);

  
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = LV_HOR_RES_MAX;
  disp_drv.ver_res = LV_VER_RES_MAX;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.buffer = &disp_buf;
  lv_disp_drv_register(&disp_drv);

  
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);             
  indev_drv.type = LV_INDEV_TYPE_POINTER;    
  indev_drv.read_cb = my_touchpad_read;     
  lv_indev_drv_register(&indev_drv);         

}


#include "AiEsp32RotaryEncoder.h"
#define ROTARY_ENCODER_A_PIN 32
#define ROTARY_ENCODER_B_PIN 33
#define ROTARY_ENCODER_BUTTON_PIN 0
#define ROTARY_ENCODER_VCC_PIN -1 


#define ROTARY_ENCODER_STEPS 4
AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN, ROTARY_ENCODER_STEPS);

void rotaryEncoder_setup(void)
{
  //we must initialize rotary encoder
  rotaryEncoder.begin();

  rotaryEncoder.setup(
    [] { rotaryEncoder.readEncoder_ISR(); },
    [] { rotary_onButtonClick(); });


  bool circleValues = false;
  rotaryEncoder.setBoundaries(0, 255, circleValues); //minValue, maxValue, circleValues true|false (when max go to min and vice versa)



  rotaryEncoder.setAcceleration(250);     //or set the value - larger number = more accelearation; 0 or 1 means disabled acceleration
  rotaryEncoder.disable();                // 开始的时候，旋转编码器无效     
}



extern bool ch1OnOff;
extern bool ch2OnOff;
#define ON  1
#define OFF 0

void onRotaryEncoderTimerCb(void *argv) {
  char    dispStr[16];
  uint8_t encoderValue;
  float   outputValue;
  bool    larger_mV = false;
  if (rotaryEncoder.encoderChanged()) {
    encoderValue = rotaryEncoder.readEncoder();
    outputValue  = (float)encoderValue * 36000.0 / 256;             // mv 单位
    if (outputValue > 1000) {
      larger_mV = true;
      outputValue /= 1000;
      dtostrf(outputValue, 3, 2, dispStr);
    }
    else
    {
      dtostrf(outputValue, 3, 0, dispStr);
      larger_mV = false;
    }

    String dispStrWithUnit(dispStr);                          

    
    if (channelVIset == ch1Vset)    {
      if (larger_mV) {
        dispStrWithUnit += "V";
      }
      else dispStrWithUnit += "mV";

      lv_label_set_text(ui->screen_ch1_Vset_label, dispStrWithUnit.c_str());
      if (ch1OnOff == ON) dacWrite(DAC1, rotaryEncoder.readEncoder());
    }
    else
    {
       if (larger_mV) {
        dispStrWithUnit += "V";
      }
      else dispStrWithUnit += "mV";

      lv_label_set_text(ui->screen_ch2_Vset_label, dispStrWithUnit.c_str());
      if (ch2OnOff == ON) dacWrite(DAC2, rotaryEncoder.readEncoder());
      }
    if (channelVIset == ch1Iset)    lv_label_set_text(ui->screen_ch1_Iset_label, dispStr);
    else lv_label_set_text(ui->screen_ch2_Iset_label, dispStr);
  }
}

void rotary_onButtonClick(void)
{
 
  static unsigned long lastTimePressed = 0;
  if (millis() - lastTimePressed < 500)
  {
    return;
  }
  lastTimePressed = millis();
  
  lv_event_send(ui->screen_ch1_onOff, LV_EVENT_CLICKED, NULL);       
  lv_event_send(ui->screen_ch2_onOff, LV_EVENT_CLICKED, NULL);       
}





 #include <SPI.h>
SPIClass *hspi = NULL;
#define HSPI_SCLK 16
#define HSPI_MOSI 13
#define HSPI_MISO 12
// #define HSPI_CS1  26
#define MCP_CS    26
static const int spiClk = 1000000;

 
void mcp4xx_setup(void) {
  pinMode(MCP_CS, OUTPUT);
  digitalWrite(MCP_CS, HIGH);
  
  hspi = new SPIClass(HSPI);
  hspi->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI);           
}


void writePotmeter(int value)
{   
    hspi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
    //CS goes low,enable
    digitalWrite(MCP_CS, LOW);   
 
    hspi->transfer(0x11);  //command 00010001 [00][01][00][01]    
    hspi->transfer(value);  
    
    //CS goes high, disable spi
    digitalWrite(MCP_CS, HIGH);
    hspi->endTransaction();
  
}


 TimerHandle_t adcHandle           = nullptr;    
 #define   VIMEASCYCLE         500                
 

void adcTimer_setup(void){
    if (!adcHandle) {
    adcHandle = xTimerCreate(           
                  "VIMeasureBack",
                  pdMS_TO_TICKS(VIMEASCYCLE),
                  pdTRUE,
                  NULL, 
                  onVIMeasureBackTimerCb);    

    assert(adcHandle);
  }
}


void onVIMeasureBackTimerCb(void *argv) {
  char      dispStr[16];
  uint16_t  adcValue = analogRead(34);           
  float     inputValue;                          
  bool      larger_m = false;
  inputValue = adcValue * 3300 / 1024;        
  if ( inputValue > 999) {
    larger_m = true;
    inputValue /= 1000;                      
    dtostrf(inputValue, 3, 2, dispStr);
  }
  else {
    larger_m = false;

    dtostrf(inputValue, 3, 0, dispStr);      
  }
  String dispStrWithUnit(dispStr);
  if(channel1CVCC == cv)  {
    if (larger_m) dispStrWithUnit += "A";     
    else          dispStrWithUnit += "mA";
  }
  else {                                          
    if (larger_m) dispStrWithUnit += "V";     
    else          dispStrWithUnit += "mV";
  }
  if (ch1OnOff == ON)
   {
      lv_label_set_text(ui->screen_ch1_onOff_label, dispStrWithUnit.c_str());
      lv_led_toggle(ui->screen_CH1_CV_LED);  lv_led_set_bright(ui->screen_CH1_CC_LED, 0);
   }
   if (ch2OnOff == ON)
   {
      lv_label_set_text(ui->screen_ch2_onOff_label, dispStrWithUnit.c_str());
      lv_led_toggle(ui->screen_CH2_CV_LED);  lv_led_set_bright(ui->screen_CH2_CC_LED, 0);
   }
}



TimerHandle_t rotaryEncoderHandle = nullptr;    
#define   rotaryEncoderCycle  50                


 void rotaryEncoderTimer_setup(void){
    if (!rotaryEncoderHandle) {
    rotaryEncoderHandle = xTimerCreate( 
                            "rotaryEncoderTimer",
                            pdMS_TO_TICKS(rotaryEncoderCycle),
                            pdTRUE,
                            NULL,
                            onRotaryEncoderTimerCb);

    assert(rotaryEncoderHandle);
  }
 }
