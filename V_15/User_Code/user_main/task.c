#include "task.h"


void Task_1ms() {


	BEMF_Start();


	data.adc_1 = Read_adc_1();

	if(data.adc_1 <= 0) data.adc_1 = 0;

	float raw_current_A = data.adc_1 / (AMP_GAIN * SHUNT_RESISTOR);
	if (raw_current_A <= 0) raw_current_A = 0;
	data.DC_Current = raw_current_A * 1000.0f;

	if(data.encoder_flag != 0){
		Read_Rotary_Encoder(data.encoder_flag);
		data.encoder_flag = 0;
	}


	lv_tick_inc(1); //LCD 시간갱신

}

void Task_10ms(){
	if(data.buzzer_flag == 1){
		HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, 1);
		data.buzzer_flag = 0;
	}else{
		HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, 0);
	}



	UART_print(">target_rpm:");
	UART_print("%d\n", data.target_rpm);
	UART_print(">rpm_orig:");
	UART_print("%d\n", data.rpm_orig);


	lv_timer_handler();	//LCD갱신



}

void Task_100ms(){

	if (data.em_flag == 0) {

		static int last_rpm = -1;
		if (data.rpm_lpf != last_rpm) {
			int temp = data.rpm_lpf;
			if (temp > MAX_RPM) {
				temp = MAX_RPM;
			} else if (temp < 0) {
				temp = 0;
			}
			//현재 RPM게이지
			lv_bar_set_value(ui_Bar1, (int16_t) temp, 0);
			last_rpm = temp;
		}

		static int last_DC_Current= -1;
		if (data.DC_Current != last_DC_Current) {
			//전류 (게이지)
			if (data.DC_Current >= 0 || data.DC_Current <= 1000) {
				if (data.DC_Current < 40)
					lv_bar_set_value(ui_Bar2, 0, 0);
				else
					lv_bar_set_value(ui_Bar2, data.DC_Current, 0);
			}
			last_DC_Current = data.DC_Current;
		}

		static int last_target_rpm = -1;
		if (data.target_rpm != last_target_rpm) {
			//목표 RPM
			lv_label_set_text_fmt(ui_Label1, "%d", data.target_rpm);
			last_target_rpm = data.target_rpm;
		}

		//제어 방식
		//lv_label_set_text_fmt(ui_Label2, "PI");

		static int last_encoder_step = -1;
		if (data.encoder_step != last_encoder_step) {
			//엔코더 스텝
			lv_label_set_text_fmt(ui_Label3, "ES: %d", data.encoder_step);
			last_encoder_step = data.encoder_step;
		}




	}else if(data.em_flag == 1){
		lv_obj_add_flag(ui_base, LV_OBJ_FLAG_HIDDEN);	  //기본 배경 숨기기
		lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_HIDDEN); // 비상 사진 보이기
		data.em_flag = 2;
	}




}

void Task_500ms(){

	//엔코더 스위치 누를시 인코더 증가분 조절
	if (HAL_GPIO_ReadPin(SW_3_GPIO_Port, SW_3_Pin) == 0) {
		++data.change_dir_cnt;
		data.SW_3_flag = 1;
		data.buzzer_flag = 1;
	} else {
		if (data.change_dir_cnt > 4 && data.SW_3_flag == 1) {
			//방향 전환은 정지시에만 가능
			if (data.target_rpm == 0 && data.is_running == 0) {
				data.em_flag = 0; //정지 상태에서 비상상황 해제 가능
				lv_obj_clear_flag(ui_base, LV_OBJ_FLAG_HIDDEN);	  //기본 배경 보이기
				lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_HIDDEN);  // 비상 사진 숨기기
				if (data.dir == 0) {
					data.dir = 1;
					lv_label_set_text_fmt(ui_Label7, "CCW");			//제어모드 및 방향 CCW 반시계 방향
				} else {
					data.dir = 0;
					lv_label_set_text_fmt(ui_Label7, "CW");			//제어모드 및 방향 CW 시계 방향
				}
			}

		} else if (data.change_dir_cnt < 4 && data.SW_3_flag == 1) {
			Change_Encoder_Step();
		}
		data.SW_3_flag = 0;
		data.change_dir_cnt = 0;
	}



	//정지상태에서 모드 변경
	if(data.target_rpm == 0 && data.is_running == 0 && HAL_GPIO_ReadPin(SW_1_GPIO_Port, SW_1_Pin) == 0){
		data.buzzer_flag = 1;
		if(data.mode == 0){
			data.mode = 1;	//센서리스 모드로 변경
			EXTI->IMR &= ~((1 << 0) | (1 << 1) | (1 << 3)); //홀센서 off
			EXTI->PR = (1 << 0) | (1 << 1) | (1 << 3);
			EXTI->IMR |= (1 << 12) | (1 << 14) | (1 << 15);//BEMF on
			//모드
			lv_label_set_text_fmt(ui_Label4, "SL");
		}else{
			data.mode = 0;	//HALL센서 모드로 변경
			EXTI->IMR &= ~((1 << 12) | (1 << 14) | (1 << 15));//BEMF off
			EXTI->PR = (1 << 12) | (1 << 14) | (1 << 15);
			EXTI->IMR |= (1 << 0) | (1 << 1) | (1 << 3);// hall센서 활성화
			//모드
			lv_label_set_text_fmt(ui_Label4, "HSEN");
		}
	}

	//정지상태에서 LCD_clear
	if(data.target_rpm == 0 && data.is_running == 0 && HAL_GPIO_ReadPin(LCD_CLEAR_GPIO_Port, LCD_CLEAR_Pin) == 0){
			//disp_init();
			ILI9341_Init();
			lv_obj_invalidate(lv_scr_act());

			lv_refr_now(NULL);
		}

	if(data.em_flag == 0){
		//현재 RPM
		lv_label_set_text_fmt(ui_Label5, "%d", data.rpm_orig);

		//전류 글자
		if (data.DC_Current > 40)
			lv_label_set_text_fmt(ui_Label6, "%dmA", data.DC_Current);
		else
			lv_label_set_text_fmt(ui_Label6, "%dmA", 0);
	}





}


