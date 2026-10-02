#include "user_main.h"
#include "main.h"


    volatile Data data  = { 0 };
	Debug debug = { 0 };
	int a=0;



void user_main(){

	PWM_init();
	HAL_TIM_Base_Start(&htim2);
	data.duty = 0;
	data.Hall_Sum = Read_HallSum();
	LPF_init_Bilinear(80.0f, 0.001f);
	HAL_TIM_Base_Start_IT(&htim3);
	PID_Init();
	data.encoder_step = 500;
	Reset_RPM_RingBuffer();
	data.adc_1offset = Calibrate_ADC_Offset();
	data.current_delay = 40;

	lv_init();
	lv_port_disp_init();
	ui_init();
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, 1);
	lv_label_set_text_fmt(ui_Label4, "HSEN");
	lv_label_set_text_fmt(ui_Label6, "%dmA", 0);
	lv_bar_set_value(ui_Bar1, 0, 0);
	lv_bar_set_value(ui_Bar2, 0, 0);
	lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_HIDDEN);
	lv_label_set_text_fmt(ui_Label7, "CW");
	lv_label_set_text_fmt(ui_Label2, "PI");

	data.mode = 0;
	EXTI->IMR &= ~((1 << 12) | (1 << 14) | (1 << 15));
	EXTI->PR = (1 << 12) | (1 << 14) | (1 << 15);
	EXTI->IMR |= (1 << 0) | (1 << 1) | (1 << 3);


	uint32_t tick_now  = 0;
	uint32_t tick_1ms  = 0;
	uint32_t tick_10ms = 0;
	uint32_t tick_100ms = 0;
	uint32_t tick_500ms = 0;

	while(1){

			tick_now = HAL_GetTick();

			if (tick_now - tick_1ms >= 1){
				Task_1ms();
				tick_1ms = tick_now;
		    }
		    if (tick_now - tick_10ms >= 10){
		    	Task_10ms();
		    	tick_10ms = tick_now;
		    }
		    if (tick_now - tick_100ms >= 100){
		    	Task_100ms();
		        tick_100ms = tick_now;
		    }
		    if (tick_now - tick_500ms >= 500){
		    	Task_500ms();
		        tick_500ms = tick_now;
		    }
	}
}
