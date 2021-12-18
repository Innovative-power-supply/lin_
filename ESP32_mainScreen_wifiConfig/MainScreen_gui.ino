

#include "gui_guider.h"                       

extern void events_mainScreen(void);                



void mainScreen_gui(void){

	ui->screen = lv_obj_create(NULL, NULL);
  lv_disp_load_scr(ui->screen);                      


  ui->bgk = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_clean_style_list(ui->bgk, LV_OBJ_PART_MAIN);
  lv_obj_set_style_local_bg_opa(ui->bgk, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);
  lv_obj_set_style_local_bg_color(ui->bgk, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_size(ui->bgk, 480, 320);
   

  ui->screen_power = lv_imgbtn_create(ui->screen, NULL);

  static lv_style_t style_screen_power_main;
  lv_style_init(&style_screen_power_main);

  lv_style_set_text_color(&style_screen_power_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_image_recolor(&style_screen_power_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_image_recolor_opa(&style_screen_power_main, LV_STATE_DEFAULT, 0);
  lv_style_set_image_opa(&style_screen_power_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_power, LV_IMGBTN_PART_MAIN, &style_screen_power_main);
  lv_obj_set_pos(ui->screen_power, 400, 248);
  lv_obj_set_size(ui->screen_power, 70, 70);
  lv_imgbtn_set_src(ui->screen_power,LV_BTN_STATE_RELEASED,&_onOff4_alpha_70x70);
  lv_imgbtn_set_src(ui->screen_power,LV_BTN_STATE_PRESSED,&_onOff2_alpha_70x70);
  lv_imgbtn_set_src(ui->screen_power,LV_BTN_STATE_CHECKED_RELEASED,&_onOff3_alpha_70x70);
  lv_imgbtn_set_src(ui->screen_power,LV_BTN_STATE_CHECKED_PRESSED,&_onOff5_alpha_70x70);
  lv_imgbtn_set_checkable(ui->screen_power, true);

  ui->screen_ch1_onOff = lv_btn_create(ui->screen, NULL);

  static lv_style_t style_screen_ch1_onOff_main;
  lv_style_init(&style_screen_ch1_onOff_main);

  lv_style_set_radius(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, 50);
  lv_style_set_bg_color(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, 255);
  lv_style_set_border_color(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, 2);
  lv_style_set_border_opa(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, 255);
  lv_style_set_outline_color(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch1_onOff_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_ch1_onOff, LV_BTN_PART_MAIN, &style_screen_ch1_onOff_main);
  lv_obj_set_pos(ui->screen_ch1_onOff, 10, 70);
  lv_obj_set_size(ui->screen_ch1_onOff, 213, 45);
  ui->screen_ch1_onOff_label = lv_label_create(ui->screen_ch1_onOff, NULL);
  lv_label_set_text(ui->screen_ch1_onOff_label, "OFF");
  lv_obj_set_style_local_text_color(ui->screen_ch1_onOff_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch1_onOff_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_24);

 
  ui->screen_ch2_onOff = lv_btn_create(ui->screen, NULL);

  static lv_style_t style_screen_ch2_onOff_main;
  lv_style_init(&style_screen_ch2_onOff_main);

  //Write style state: LV_STATE_DEFAULT for style_screen_ch1_onOff_main
  lv_style_set_radius(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, 50);
  lv_style_set_bg_color(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, 255);
  lv_style_set_border_color(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, 2);
  lv_style_set_border_opa(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, 255);
  lv_style_set_outline_color(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch2_onOff_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_ch2_onOff, LV_BTN_PART_MAIN, &style_screen_ch1_onOff_main);
  lv_obj_set_pos(ui->screen_ch2_onOff, 250, 70);
  lv_obj_set_size(ui->screen_ch2_onOff, 213, 45);
  ui->screen_ch2_onOff_label = lv_label_create(ui->screen_ch2_onOff, NULL);
  lv_label_set_text(ui->screen_ch2_onOff_label, "OFF");
  lv_obj_set_style_local_text_color(ui->screen_ch2_onOff_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch2_onOff_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_24);
  ui->screen_system_setup = lv_imgbtn_create(ui->screen, NULL);

  static lv_style_t style_screen_system_setup_main;
  lv_style_init(&style_screen_system_setup_main);
  lv_style_set_text_color(&style_screen_system_setup_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_image_recolor(&style_screen_system_setup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_image_recolor_opa(&style_screen_system_setup_main, LV_STATE_DEFAULT, 0);
  lv_style_set_image_opa(&style_screen_system_setup_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_system_setup, LV_IMGBTN_PART_MAIN, &style_screen_system_setup_main);
  lv_obj_set_pos(ui->screen_system_setup, 10, 260);
  lv_obj_set_size(ui->screen_system_setup, 50, 50);
  lv_imgbtn_set_src(ui->screen_system_setup,LV_BTN_STATE_RELEASED,&_setup0_alpha_50x50);
  lv_imgbtn_set_checkable(ui->screen_system_setup, true);

  ui->screen_system_config = lv_imgbtn_create(ui->screen, NULL);

  static lv_style_t style_screen_system_config_main;
  lv_style_init(&style_screen_system_config_main);

  lv_style_set_text_color(&style_screen_system_config_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_image_recolor(&style_screen_system_config_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_image_recolor_opa(&style_screen_system_config_main, LV_STATE_DEFAULT, 0);
  lv_style_set_image_opa(&style_screen_system_config_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_system_config, LV_IMGBTN_PART_MAIN, &style_screen_system_config_main);
  lv_obj_set_pos(ui->screen_system_config, 81, 260);
  lv_obj_set_size(ui->screen_system_config, 50, 50);
  lv_imgbtn_set_src(ui->screen_system_config,LV_BTN_STATE_RELEASED,&_config0_alpha_50x50);
  lv_imgbtn_set_checkable(ui->screen_system_config, true);

  ui->screen_system_info = lv_imgbtn_create(ui->screen, NULL);

  static lv_style_t style_screen_system_info_main;
  lv_style_init(&style_screen_system_info_main);

  lv_style_set_text_color(&style_screen_system_info_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_image_recolor(&style_screen_system_info_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_image_recolor_opa(&style_screen_system_info_main, LV_STATE_DEFAULT, 0);
  lv_style_set_image_opa(&style_screen_system_info_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_system_info, LV_IMGBTN_PART_MAIN, &style_screen_system_info_main);
  lv_obj_set_pos(ui->screen_system_info, 154, 260);
  lv_obj_set_size(ui->screen_system_info, 50, 50);
  lv_imgbtn_set_src(ui->screen_system_info,LV_BTN_STATE_RELEASED,&_info1_alpha_50x50);
  lv_imgbtn_set_checkable(ui->screen_system_info, true);

  ui->screen_system_help = lv_imgbtn_create(ui->screen, NULL);

  static lv_style_t style_screen_system_help_main;
  lv_style_init(&style_screen_system_help_main);

  lv_style_set_text_color(&style_screen_system_help_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_image_recolor(&style_screen_system_help_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_image_recolor_opa(&style_screen_system_help_main, LV_STATE_DEFAULT, 0);
  lv_style_set_image_opa(&style_screen_system_help_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_system_help, LV_IMGBTN_PART_MAIN, &style_screen_system_help_main);
  lv_obj_set_pos(ui->screen_system_help, 224, 260);
  lv_obj_set_size(ui->screen_system_help, 50, 50);
  lv_imgbtn_set_src(ui->screen_system_help,LV_BTN_STATE_RELEASED,&_help0_alpha_50x50);
  lv_imgbtn_set_checkable(ui->screen_system_help, true);

  ui->screen_system_events = lv_imgbtn_create(ui->screen, NULL);

  static lv_style_t style_screen_system_events_main;
  lv_style_init(&style_screen_system_events_main);

  lv_style_set_text_color(&style_screen_system_events_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_image_recolor(&style_screen_system_events_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_image_recolor_opa(&style_screen_system_events_main, LV_STATE_DEFAULT, 0);
  lv_style_set_image_opa(&style_screen_system_events_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_system_events, LV_IMGBTN_PART_MAIN, &style_screen_system_events_main);
  lv_obj_set_pos(ui->screen_system_events, 10, 10);
  lv_obj_set_size(ui->screen_system_events, 40, 40);
  lv_imgbtn_set_src(ui->screen_system_events,LV_BTN_STATE_RELEASED,&_event0_alpha_40x40);
  lv_imgbtn_set_checkable(ui->screen_system_events, true);

  ui->screen_system_usb = lv_imgbtn_create(ui->screen, NULL);

  static lv_style_t style_screen_system_usb_main;
  lv_style_init(&style_screen_system_usb_main);

  lv_style_set_text_color(&style_screen_system_usb_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_image_recolor(&style_screen_system_usb_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_image_recolor_opa(&style_screen_system_usb_main, LV_STATE_DEFAULT, 0);
  lv_style_set_image_opa(&style_screen_system_usb_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_system_usb, LV_IMGBTN_PART_MAIN, &style_screen_system_usb_main);
  lv_obj_set_pos(ui->screen_system_usb, 90, 10);
  lv_obj_set_size(ui->screen_system_usb, 40, 40);
  lv_imgbtn_set_src(ui->screen_system_usb,LV_BTN_STATE_RELEASED,&_usb0_alpha_40x40);
  lv_imgbtn_set_src(ui->screen_system_usb,LV_BTN_STATE_CHECKED_RELEASED,&_usb3_alpha_40x40);
  lv_imgbtn_set_checkable(ui->screen_system_usb, true);

  
  ui->screen_system_wifi = lv_imgbtn_create(ui->screen, NULL);
  static lv_style_t style_screen_system_wifi_main;
  lv_style_init(&style_screen_system_wifi_main);
  lv_style_set_text_color(&style_screen_system_wifi_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_image_recolor(&style_screen_system_wifi_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_image_recolor_opa(&style_screen_system_wifi_main, LV_STATE_DEFAULT, 0);
  lv_style_set_image_opa(&style_screen_system_wifi_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_system_wifi, LV_IMGBTN_PART_MAIN, &style_screen_system_wifi_main);
  lv_obj_set_pos(ui->screen_system_wifi, 170, 10);
  lv_obj_set_size(ui->screen_system_wifi, 40, 40);
  lv_imgbtn_set_src(ui->screen_system_wifi,LV_BTN_STATE_RELEASED,&_wifi0_alpha_40x40);
  lv_imgbtn_set_src(ui->screen_system_wifi,LV_BTN_STATE_CHECKED_RELEASED,&_wifi1_alpha_40x40);
  lv_imgbtn_set_checkable(ui->screen_system_wifi, true);
  ui->screen_ch1_runTime = lv_label_create(ui->screen, NULL);
  lv_label_set_text(ui->screen_ch1_runTime, "10h 33m");
  lv_label_set_long_mode(ui->screen_ch1_runTime, LV_LABEL_LONG_BREAK);
  lv_label_set_align(ui->screen_ch1_runTime, LV_LABEL_ALIGN_CENTER);

  static lv_style_t style_screen_ch1_runTime_main;
  lv_style_init(&style_screen_ch1_runTime_main);

  lv_style_set_radius(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, 255);
  lv_style_set_text_color(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_text_font(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  lv_style_set_text_letter_space(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, 2);
  lv_style_set_pad_left(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_right(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_top(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_bottom(&style_screen_ch1_runTime_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch1_runTime, LV_LABEL_PART_MAIN, &style_screen_ch1_runTime_main);
  lv_obj_set_pos(ui->screen_ch1_runTime, 230, 20);
  lv_obj_set_size(ui->screen_ch1_runTime, 100, 0);

  ui->screen_ch2_runTime = lv_label_create(ui->screen, NULL);
  lv_label_set_text(ui->screen_ch2_runTime, "10h 33m");
  lv_label_set_long_mode(ui->screen_ch2_runTime, LV_LABEL_LONG_BREAK);
  lv_label_set_align(ui->screen_ch2_runTime, LV_LABEL_ALIGN_CENTER);

 
  static lv_style_t style_screen_ch2_runTime_main;
  lv_style_init(&style_screen_ch2_runTime_main);

  lv_style_set_radius(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, 255);
  lv_style_set_text_color(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_text_font(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  lv_style_set_text_letter_space(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, 2);
  lv_style_set_pad_left(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_right(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_top(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_bottom(&style_screen_ch2_runTime_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch2_runTime, LV_LABEL_PART_MAIN, &style_screen_ch2_runTime_main);
  lv_obj_set_pos(ui->screen_ch2_runTime, 340, 20);
  lv_obj_set_size(ui->screen_ch2_runTime, 100, 0);

 
  ui->screen_ch1_Vset = lv_btn_create(ui->screen, NULL);

 
  static lv_style_t style_screen_ch1_Vset_main;
  lv_style_init(&style_screen_ch1_Vset_main);


  lv_style_set_radius(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, 128);
  lv_style_set_border_color(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_border_width(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch1_Vset_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch1_Vset, LV_BTN_PART_MAIN, &style_screen_ch1_Vset_main);
  lv_obj_set_pos(ui->screen_ch1_Vset, 70, 125);
  lv_obj_set_size(ui->screen_ch1_Vset, 80, 30);
  ui->screen_ch1_Vset_label = lv_label_create(ui->screen_ch1_Vset, NULL);
  lv_label_set_text(ui->screen_ch1_Vset_label, "15 V");
  lv_obj_set_style_local_text_color(ui->screen_ch1_Vset_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch1_Vset_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_22);


  ui->screen_ch1_Iset = lv_btn_create(ui->screen, NULL);

  
  static lv_style_t style_screen_ch1_Iset_main;
  lv_style_init(&style_screen_ch1_Iset_main);
  lv_style_set_radius(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, 128);
  lv_style_set_border_color(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch1_Iset_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch1_Iset, LV_BTN_PART_MAIN, &style_screen_ch1_Iset_main);
  lv_obj_set_pos(ui->screen_ch1_Iset, 70, 170);
  lv_obj_set_size(ui->screen_ch1_Iset, 80, 30);
  ui->screen_ch1_Iset_label = lv_label_create(ui->screen_ch1_Iset, NULL);
  lv_label_set_text(ui->screen_ch1_Iset_label, "1.5 A");
  lv_obj_set_style_local_text_color(ui->screen_ch1_Iset_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch1_Iset_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_22);

 
  ui->screen_lineUp = lv_line_create(ui->screen, NULL);
  static lv_style_t style_screen_lineUp_main;
  lv_style_init(&style_screen_lineUp_main);

  lv_style_set_line_color(&style_screen_lineUp_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_line_width(&style_screen_lineUp_main, LV_STATE_DEFAULT, 5);
  lv_obj_add_style(ui->screen_lineUp, LV_LINE_PART_MAIN, &style_screen_lineUp_main);
  lv_obj_set_pos(ui->screen_lineUp, 10, 55);
  lv_obj_set_size(ui->screen_lineUp, 460, 5);
  static lv_point_t screen_lineUp[] ={{0,0},{460,0}};
  lv_line_set_points(ui->screen_lineUp,screen_lineUp,2);

  ui->screen_ch1_OVP = lv_btn_create(ui->screen, NULL);
  static lv_style_t style_screen_ch1_OVP_main;
  lv_style_init(&style_screen_ch1_OVP_main);

  lv_style_set_radius(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch1_OVP_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch1_OVP, LV_BTN_PART_MAIN, &style_screen_ch1_OVP_main);
  lv_obj_set_pos(ui->screen_ch1_OVP, 0, 125);
  lv_obj_set_size(ui->screen_ch1_OVP, 50, 30);
  ui->screen_ch1_OVP_label = lv_label_create(ui->screen_ch1_OVP, NULL);
  lv_label_set_text(ui->screen_ch1_OVP_label, "OVP");
  lv_obj_set_style_local_text_color(ui->screen_ch1_OVP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch1_OVP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);

  ui->screen_ch1_OCP = lv_btn_create(ui->screen, NULL);

  static lv_style_t style_screen_ch1_OCP_main;
  lv_style_init(&style_screen_ch1_OCP_main);

  lv_style_set_radius(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch1_OCP_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch1_OCP, LV_BTN_PART_MAIN, &style_screen_ch1_OCP_main);
  lv_obj_set_pos(ui->screen_ch1_OCP, 0, 170);
  lv_obj_set_size(ui->screen_ch1_OCP, 50, 30);
  ui->screen_ch1_OCP_label = lv_label_create(ui->screen_ch1_OCP, NULL);
  lv_label_set_text(ui->screen_ch1_OCP_label, "OCP");
  lv_obj_set_style_local_text_color(ui->screen_ch1_OCP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch1_OCP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  ui->screen_ch1_OPP = lv_btn_create(ui->screen, NULL);
  static lv_style_t style_screen_ch1_OPP_main;
  lv_style_init(&style_screen_ch1_OPP_main);
  lv_style_set_radius(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch1_OPP_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch1_OPP, LV_BTN_PART_MAIN, &style_screen_ch1_OPP_main);
  lv_obj_set_pos(ui->screen_ch1_OPP, 0, 215);
  lv_obj_set_size(ui->screen_ch1_OPP, 50, 30);
  ui->screen_ch1_OPP_label = lv_label_create(ui->screen_ch1_OPP, NULL);
  lv_label_set_text(ui->screen_ch1_OPP_label, "OPP");
  lv_obj_set_style_local_text_color(ui->screen_ch1_OPP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch1_OPP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);

  ui->screen_ch1_setup = lv_btn_create(ui->screen, NULL);
  static lv_style_t style_screen_ch1_setup_main;
  lv_style_init(&style_screen_ch1_setup_main);
  lv_style_set_radius(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch1_setup_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch1_setup, LV_BTN_PART_MAIN, &style_screen_ch1_setup_main);
  lv_obj_set_pos(ui->screen_ch1_setup, 70, 215);
  lv_obj_set_size(ui->screen_ch1_setup, 80, 30);
  ui->screen_ch1_setup_label = lv_label_create(ui->screen_ch1_setup, NULL);
  lv_label_set_text(ui->screen_ch1_setup_label, "SETUP");
  lv_obj_set_style_local_text_color(ui->screen_ch1_setup_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch1_setup_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  ui->screen_lab_CV = lv_btn_create(ui->screen, NULL);
  static lv_style_t style_screen_lab_CV_main;
  lv_style_init(&style_screen_lab_CV_main);

  lv_style_set_radius(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_lab_CV_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_lab_CV_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_lab_CV_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_lab_CV_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_lab_CV_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_lab_CV, LV_BTN_PART_MAIN, &style_screen_lab_CV_main);
  lv_obj_set_pos(ui->screen_lab_CV, 155, 125);
  lv_obj_set_size(ui->screen_lab_CV, 30, 30);
  ui->screen_lab_CV_label = lv_label_create(ui->screen_lab_CV, NULL);
  lv_label_set_text(ui->screen_lab_CV_label, "CV");
  lv_obj_set_style_local_text_color(ui->screen_lab_CV_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_lab_CV_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);

 
  ui->screen_CH1_CV_LED = lv_led_create(ui->screen, NULL);

  static lv_style_t style_screen_CH1_CV_LED_main;
  lv_style_init(&style_screen_CH1_CV_LED_main);

 
  lv_style_set_radius(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, 20);
  lv_style_set_bg_color(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
  lv_style_set_bg_grad_color(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, lv_color_make(0x8e, 0xbc, 0xc2));
  lv_style_set_bg_grad_dir(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, LV_GRAD_DIR_HOR);
  lv_style_set_bg_opa(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, 255);
  lv_style_set_shadow_color(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
  lv_style_set_shadow_width(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_border_width(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_CH1_CV_LED_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_CH1_CV_LED, LV_LED_PART_MAIN, &style_screen_CH1_CV_LED_main);
  lv_obj_set_pos(ui->screen_CH1_CV_LED, 185, 125);
  lv_obj_set_size(ui->screen_CH1_CV_LED, 30, 30);
  lv_led_set_bright(ui->screen_CH1_CV_LED, 200);


  ui->screen_lab_CC = lv_btn_create(ui->screen, NULL);


  static lv_style_t style_screen_lab_CC_main;
  lv_style_init(&style_screen_lab_CC_main);

  lv_style_set_radius(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_lab_CC_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_lab_CC_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_lab_CC_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_lab_CC_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_lab_CC_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_lab_CC, LV_BTN_PART_MAIN, &style_screen_lab_CC_main);
  lv_obj_set_pos(ui->screen_lab_CC, 155, 170);
  lv_obj_set_size(ui->screen_lab_CC, 30, 30);
  ui->screen_lab_CC_label = lv_label_create(ui->screen_lab_CC, NULL);
  lv_label_set_text(ui->screen_lab_CC_label, "CC");
  lv_obj_set_style_local_text_color(ui->screen_lab_CC_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_lab_CC_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);


  ui->screen_CH1_CC_LED = lv_led_create(ui->screen, NULL);

  static lv_style_t style_screen_CH1_CC_LED_main;
  lv_style_init(&style_screen_CH1_CC_LED_main);

  lv_style_set_radius(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, 20);
  lv_style_set_bg_color(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, lv_color_make(0xb3, 0x24, 0x00));
  lv_style_set_bg_grad_color(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, lv_color_make(0xb3, 0x00, 0xad));
  lv_style_set_bg_grad_dir(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, LV_GRAD_DIR_HOR);
  lv_style_set_bg_opa(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, 255);
  lv_style_set_shadow_color(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
  lv_style_set_shadow_width(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_border_width(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_CH1_CC_LED_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_CH1_CC_LED, LV_LED_PART_MAIN, &style_screen_CH1_CC_LED_main);
  lv_obj_set_pos(ui->screen_CH1_CC_LED, 185, 170);
  lv_obj_set_size(ui->screen_CH1_CC_LED, 30, 30);
  lv_led_set_bright(ui->screen_CH1_CC_LED, 200);


  ui->screen_ch2_Vset = lv_btn_create(ui->screen, NULL);
  static lv_style_t style_screen_ch2_Vset_main;
  lv_style_init(&style_screen_ch2_Vset_main);
  lv_style_set_radius(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, 128);
  lv_style_set_border_color(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_border_width(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch2_Vset_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch2_Vset, LV_BTN_PART_MAIN, &style_screen_ch1_Vset_main);
  lv_obj_set_pos(ui->screen_ch2_Vset, 310, 125);
  lv_obj_set_size(ui->screen_ch2_Vset, 80, 30);
  ui->screen_ch2_Vset_label = lv_label_create(ui->screen_ch2_Vset, NULL);
  lv_label_set_text(ui->screen_ch2_Vset_label, "15 V");
  lv_obj_set_style_local_text_color(ui->screen_ch2_Vset_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch2_Vset_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_22);
  ui->screen_ch2_Iset = lv_btn_create(ui->screen, NULL);

  static lv_style_t style_screen_ch2_Iset_main;
  lv_style_init(&style_screen_ch2_Iset_main);
  lv_style_set_radius(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, 128);
  lv_style_set_border_color(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch2_Iset_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch2_Iset, LV_BTN_PART_MAIN, &style_screen_ch2_Iset_main);
  lv_obj_set_pos(ui->screen_ch2_Iset, 310, 170);
  lv_obj_set_size(ui->screen_ch2_Iset, 80, 30);
  ui->screen_ch2_Iset_label = lv_label_create(ui->screen_ch2_Iset, NULL);
  lv_label_set_text(ui->screen_ch2_Iset_label, "1.5 A");
  lv_obj_set_style_local_text_color(ui->screen_ch2_Iset_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch2_Iset_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_22);


  ui->screen_ch2_OVP = lv_btn_create(ui->screen, NULL);

  static lv_style_t style_screen_ch2_OVP_main;
  lv_style_init(&style_screen_ch2_OVP_main);

  lv_style_set_radius(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch2_OVP_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch2_OVP, LV_BTN_PART_MAIN, &style_screen_ch2_OVP_main);
  lv_obj_set_pos(ui->screen_ch2_OVP, 240, 125);
  lv_obj_set_size(ui->screen_ch2_OVP, 50, 30);
  ui->screen_ch2_OVP_label = lv_label_create(ui->screen_ch2_OVP, NULL);
  lv_label_set_text(ui->screen_ch2_OVP_label, "OVP");
  lv_obj_set_style_local_text_color(ui->screen_ch2_OVP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch2_OVP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  ui->screen_ch2_OCP = lv_btn_create(ui->screen, NULL);

  static lv_style_t style_screen_ch2_OCP_main;
  lv_style_init(&style_screen_ch2_OCP_main);

  lv_style_set_radius(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch2_OCP_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch2_OCP, LV_BTN_PART_MAIN, &style_screen_ch1_OCP_main);
  lv_obj_set_pos(ui->screen_ch2_OCP, 240, 170);
  lv_obj_set_size(ui->screen_ch2_OCP, 50, 30);
  ui->screen_ch2_OCP_label = lv_label_create(ui->screen_ch2_OCP, NULL);
  lv_label_set_text(ui->screen_ch2_OCP_label, "OCP");
  lv_obj_set_style_local_text_color(ui->screen_ch2_OCP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch2_OCP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);

  ui->screen_ch2_OPP = lv_btn_create(ui->screen, NULL);

  static lv_style_t style_screen_ch2_OPP_main;
  lv_style_init(&style_screen_ch2_OPP_main);

  lv_style_set_radius(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch2_OPP_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch2_OPP, LV_BTN_PART_MAIN, &style_screen_ch2_OPP_main);
  lv_obj_set_pos(ui->screen_ch2_OPP, 240, 215);
  lv_obj_set_size(ui->screen_ch2_OPP, 50, 30);
  ui->screen_ch2_OPP_label = lv_label_create(ui->screen_ch2_OPP, NULL);
  lv_label_set_text(ui->screen_ch2_OPP_label, "OPP");
  lv_obj_set_style_local_text_color(ui->screen_ch2_OPP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch2_OPP_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);

  ui->screen_ch2_setup = lv_btn_create(ui->screen, NULL);

  static lv_style_t style_screen_ch2_setup_main;
  lv_style_init(&style_screen_ch2_setup_main);

  lv_style_set_radius(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_ch2_setup_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_ch2_setup, LV_BTN_PART_MAIN, &style_screen_ch2_setup_main);
  lv_obj_set_pos(ui->screen_ch2_setup, 310, 215);
  lv_obj_set_size(ui->screen_ch2_setup, 80, 30);
  ui->screen_ch2_setup_label = lv_label_create(ui->screen_ch2_setup, NULL);
  lv_label_set_text(ui->screen_ch2_setup_label, "SETUP");
  lv_obj_set_style_local_text_color(ui->screen_ch2_setup_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_ch2_setup_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);

  ui->screen_lab_CV = lv_btn_create(ui->screen, NULL);

  lv_style_init(&style_screen_lab_CV_main);
  lv_style_set_radius(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_lab_CV_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_lab_CV_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_lab_CV_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_lab_CV_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_lab_CV_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_lab_CV_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_lab_CV, LV_BTN_PART_MAIN, &style_screen_lab_CV_main);
  lv_obj_set_pos(ui->screen_lab_CV, 395, 125);
  lv_obj_set_size(ui->screen_lab_CV, 30, 30);
  ui->screen_lab_CV_label = lv_label_create(ui->screen_lab_CV, NULL);
  lv_label_set_text(ui->screen_lab_CV_label, "CV");
  lv_obj_set_style_local_text_color(ui->screen_lab_CV_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_lab_CV_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);

  ui->screen_CH2_CV_LED = lv_led_create(ui->screen, NULL);
  static lv_style_t style_screen_CH2_CV_LED_main;
  lv_style_init(&style_screen_CH2_CV_LED_main);

  lv_style_set_radius(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, 20);
  lv_style_set_bg_color(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
  lv_style_set_bg_grad_color(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, lv_color_make(0x8e, 0xbc, 0xc2));
  lv_style_set_bg_grad_dir(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, LV_GRAD_DIR_HOR);
  lv_style_set_bg_opa(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, 255);
  lv_style_set_shadow_color(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
  lv_style_set_shadow_width(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_border_width(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_CH2_CV_LED_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_CH2_CV_LED, LV_LED_PART_MAIN, &style_screen_CH2_CV_LED_main);
  lv_obj_set_pos(ui->screen_CH2_CV_LED, 425, 125);
  lv_obj_set_size(ui->screen_CH2_CV_LED, 30, 30);
  lv_led_set_bright(ui->screen_CH2_CV_LED, 200);

  ui->screen_lab_CC = lv_btn_create(ui->screen, NULL);

  lv_style_init(&style_screen_lab_CC_main);

  lv_style_set_radius(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(&style_screen_lab_CC_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_screen_lab_CC_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_screen_lab_CC_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
  lv_style_set_bg_opa(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_lab_CC_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
  lv_style_set_border_width(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_style_set_outline_color(&style_screen_lab_CC_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
  lv_style_set_outline_opa(&style_screen_lab_CC_main, LV_STATE_DEFAULT, 0);
  lv_obj_add_style(ui->screen_lab_CC, LV_BTN_PART_MAIN, &style_screen_lab_CC_main);
  lv_obj_set_pos(ui->screen_lab_CC, 395, 170);
  lv_obj_set_size(ui->screen_lab_CC, 30, 30);
  ui->screen_lab_CC_label = lv_label_create(ui->screen_lab_CC, NULL);
  lv_label_set_text(ui->screen_lab_CC_label, "CC");
  lv_obj_set_style_local_text_color(ui->screen_lab_CC_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_obj_set_style_local_text_font(ui->screen_lab_CC_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_16);
  ui->screen_CH2_CC_LED = lv_led_create(ui->screen, NULL);
  static lv_style_t style_screen_CH2_CC_LED_main;
  lv_style_init(&style_screen_CH2_CC_LED_main);

  lv_style_set_radius(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, 20);
  lv_style_set_bg_color(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, lv_color_make(0xb3, 0x24, 0x00));
  lv_style_set_bg_grad_color(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, lv_color_make(0xb3, 0x00, 0xad));
  lv_style_set_bg_grad_dir(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, LV_GRAD_DIR_HOR);
  lv_style_set_bg_opa(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, 255);
  lv_style_set_shadow_color(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
  lv_style_set_shadow_width(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_color(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_border_width(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&style_screen_CH2_CC_LED_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_CH2_CC_LED, LV_LED_PART_MAIN, &style_screen_CH2_CC_LED_main);
  lv_obj_set_pos(ui->screen_CH2_CC_LED, 425, 170);
  lv_obj_set_size(ui->screen_CH2_CC_LED, 30, 30);
  lv_led_set_bright(ui->screen_CH2_CC_LED, 200);
  ui->screen_system_clock = lv_imgbtn_create(ui->screen, NULL);

  static lv_style_t style_screen_system_clock_main;
  lv_style_init(&style_screen_system_clock_main);

  lv_style_set_text_color(&style_screen_system_clock_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
  lv_style_set_image_recolor(&style_screen_system_clock_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_image_recolor_opa(&style_screen_system_clock_main, LV_STATE_DEFAULT, 0);
  lv_style_set_image_opa(&style_screen_system_clock_main, LV_STATE_DEFAULT, 255);
  lv_obj_add_style(ui->screen_system_clock, LV_IMGBTN_PART_MAIN, &style_screen_system_clock_main);
  lv_obj_set_pos(ui->screen_system_clock, 330, 260);
  lv_obj_set_size(ui->screen_system_clock, 50, 50);
  lv_imgbtn_set_src(ui->screen_system_clock,LV_BTN_STATE_RELEASED,&_unlock0_alpha_50x50);
  lv_imgbtn_set_src(ui->screen_system_clock,LV_BTN_STATE_CHECKED_RELEASED,&_lock0_alpha_50x50);
  lv_imgbtn_set_checkable(ui->screen_system_clock, true);


	events_mainScreen();

}

void GUI_task( void *pvParameters ) {


  mainScreen_gui();                 // defined in setup_scr_screen.ino file

  for (;;) {
  }

}
