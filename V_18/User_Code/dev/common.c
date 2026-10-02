#include "common.h"

void Read_Rotary_Encoder(uint16_t idr) {
    uint8_t clk = (idr & (1 << 11)) ? 1 : 0;
    uint8_t dt  = (idr & (1 << 10)) ? 1 : 0;

    if (clk != dt) {
    		data.encoder += data.encoder_step;
    	} else {
    		data.encoder -= data.encoder_step;
    	}

    if(data.encoder < 0) data.encoder = 0;
    if(data.encoder > MAX_RPM) data.encoder = MAX_RPM;
    if(data.em_flag == 0) data.target_rpm = data.encoder;
}

void Read_Rotary_Encoder_angle(uint16_t idr) {
    uint8_t clk = (idr & (1 << 11)) ? 1 : 0;
    uint8_t dt  = (idr & (1 << 10)) ? 1 : 0;

    if (clk != dt) {
    		data.encoder += data.encoder_step;
    	} else {
    		data.encoder -= data.encoder_step;
    	}

    if(data.encoder < -1000) data.encoder = 10000;
    if(data.encoder > 1000) data.encoder = 1000;
    if(data.em_flag == 0) data.target_angle = data.encoder;

}


void Change_Encoder_Step(){
	data.encoder_step *= 10;
	if(data.encoder_step == 1000){
		data.encoder_step = 500;
	}else if(data.encoder_step >= 5000){
		data.encoder_step = 1;
	}
}

void direction_output(void){
	if (data.dir == 0) {
		lv_label_set_text_fmt(ui_Label7, "CW");
	} else {
		lv_label_set_text_fmt(ui_Label7, "CCW");
	}
}
