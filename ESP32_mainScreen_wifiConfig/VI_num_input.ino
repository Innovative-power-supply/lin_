
lv_obj_t * kb;
lv_obj_t * ta;
lv_obj_t * unitVI;
lv_obj_t *mobj;

extern unsigned ch_VIset_choose; 
static void ta_event_cb(lv_obj_t * ta, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        const char * txt = lv_textarea_get_text(ta);
//        if(txt[3] == ':') {
//            lv_textarea_del_char(ta);
//        }
//        else if(txt[0] >= '0' && txt[0] <= '9' &&
//            txt[1] >= '0' && txt[1] <= '9' &&
//            txt[2] != ':')
//        {
//            lv_textarea_set_cursor_pos(ta, 2);
//            lv_textarea_add_char(ta, ':');
//        }
    }

}

static void kb_event_cb(lv_obj_t * keyboard, lv_event_t e)
{
    lv_keyboard_def_event_cb(kb, e);
    if(e == LV_EVENT_APPLY) {
     if(ch_VIset_choose==channel1_V)
      lv_label_set_text(ui->screen_ch1_Vset_label, lv_textarea_get_text(ta));
     else if(ch_VIset_choose==channel2_V)
      lv_label_set_text(ui->screen_ch2_Vset_label, lv_textarea_get_text(ta));
     else if(ch_VIset_choose==channel1_I)
      lv_label_set_text(ui->screen_ch1_Iset_label, lv_textarea_get_text(ta));
     else if(ch_VIset_choose==channel2_I)
      lv_label_set_text(ui->screen_ch2_Iset_label, lv_textarea_get_text(ta));
     lv_obj_del(mobj);                  
    }
    if(e == LV_EVENT_CANCEL) {
      lv_obj_del(mobj);                 
    }
}

 void num_input_taKB(void){


    mobj = lv_obj_create(lv_scr_act(), NULL);                   
    lv_obj_set_style_local_bg_opa(mobj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);  
    lv_obj_set_style_local_bg_color(mobj, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_pos(mobj, 0, 0);
    lv_obj_set_size(mobj, LV_HOR_RES, LV_VER_RES);


    ta = lv_textarea_create(mobj, NULL);
    lv_obj_set_style_local_text_font(ta, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_28);
    lv_obj_set_y(ta, LV_VER_RES*2/8);    
    lv_obj_set_size(ta, LV_HOR_RES,LV_VER_RES/8);
    lv_obj_set_event_cb(ta, ta_event_cb);                             
    lv_textarea_set_accepted_chars(ta, "0123456789.m");                
    lv_textarea_set_max_length(ta, 7);
    lv_textarea_set_text(ta, "");

//    unitVI = lv_label_create(mobj, NULL);
//    lv_obj_set_style_local_text_font(unitVI, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_28);
//    lv_obj_set_pos(unitVI, LV_HOR_RES*7/8, 0);
//    lv_obj_set_size(unitVI, LV_HOR_RES/8,LV_VER_RES/8);
//    lv_label_set_text(unitVI, "V");
//    lv_label_set_align(unitVI, LV_LABEL_ALIGN_RIGHT);
//    lv_obj_set_style_local_bg_color( unitVI, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE );

    static const char * kb_map[] = {
              "1","2", "3", LV_SYMBOL_BACKSPACE,"\n",
              "4", "5", "6", LV_SYMBOL_CLOSE, "\n",
              "7", "8", "9", LV_SYMBOL_OK ,"\n",
              "0",".","m"," ",""
    };

    static const lv_btnmatrix_ctrl_t kb_ctrl[] = {
           LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT,
           LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT,
           LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT,
           LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_NO_REPEAT, LV_BTNMATRIX_CTRL_HIDDEN,
    };

    
    kb = lv_keyboard_create(mobj, NULL);
    lv_obj_set_y(kb, LV_VER_RES*3/8);
    lv_obj_set_size(kb,  LV_HOR_RES, LV_VER_RES*5/8);
    lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_NUM);
    lv_keyboard_set_map(kb, LV_KEYBOARD_MODE_NUM, kb_map);
    lv_keyboard_set_ctrl_map(kb, LV_KEYBOARD_MODE_NUM,kb_ctrl);

    lv_obj_set_event_cb(kb, kb_event_cb);         
    
    lv_keyboard_set_textarea(kb, ta);            
    
 }
