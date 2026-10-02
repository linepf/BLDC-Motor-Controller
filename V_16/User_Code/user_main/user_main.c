#include "user_main.h"
#include "main.h"


    volatile Data data  = { 0 };
	Debug debug = { 0 };
	int a=0;
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////


void user_main(){

	PWM_init();								//모터에 인가되는 pwm 초기화
	HAL_TIM_Base_Start(&htim2);				//RPM계산시 사용되는 타이머
	data.duty = 0;							//초기 오작동 방지
	data.Hall_Sum = Read_HallSum();			//처음에 읽지 않으면 쓰레기 값이 들어감
	LPF_init_Bilinear(80.0f, 0.001f);		//컷오프 주파수, 샘플링 주기
	HAL_TIM_Base_Start_IT(&htim3);			//1kHz , PID제어및 LPF사용시 사용되는 타이머
	PID_Init();								//PID제어 초기화
	data.encoder_step = 500; 				//초기에 엔코드 스텝크기 정하기 100이면 RPM이 100씩증가
	Reset_RPM_RingBuffer();					//초기에 링버퍼 초기화 하기

/////////////////////////////////////////////////////////////////////////////////////////////
	data.adc_1offset = Calibrate_ADC_Offset();		//초기에 adc오차를 측정해서 변수에 저장
	data.current_delay = 40;						//

	/*lv_init(); 										//Initialise LVGL UI library
	lv_port_disp_init();  							// intializse the display drivers
	ui_init();

	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, 1);
	lv_label_set_text_fmt(ui_Label4, "HSEN");		//초기에 홀센서 모드로 시작
	lv_label_set_text_fmt(ui_Label6, "%dmA", 0);	//초기 0A 로 시작
	lv_bar_set_value(ui_Bar1, 0, 0);				//게이지 0으로 초기화
	lv_bar_set_value(ui_Bar2, 0, 0);				//게이지 0으로 초기화
	lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_HIDDEN); //비상 사진 숨기기
	lv_label_set_text_fmt(ui_Label7, "CW");			//기본 방향 시계방향
	lv_label_set_text_fmt(ui_Label2, "PI");*/


	//초기에 홀센서 모드로 시작
	data.mode = 0;
	EXTI->IMR &= ~((1 << 12) | (1 << 14) | (1 << 15));//BEMF off
	EXTI->PR = (1 << 12) | (1 << 14) | (1 << 15);
	EXTI->IMR |= (1 << 0) | (1 << 1) | (1 << 3);// hall센서 활성화

/////////////////////////////////////////////////////////////////////////////////////////////
	uint32_t tick_now  = 0;
	uint32_t tick_1ms  = 0;
	uint32_t tick_10ms = 0;
	uint32_t tick_100ms = 0;
	uint32_t tick_500ms = 0;

	while(1){

			tick_now = HAL_GetTick();

			if (tick_now - tick_1ms >= 1){			//1ms Task
				Task_1ms();
				tick_1ms = tick_now;
		    }
		    if (tick_now - tick_10ms >= 10){		//10ms Task
		    	Task_10ms();
		    	tick_10ms = tick_now;
		    }
		    if (tick_now - tick_100ms >= 100){		//100ms Task
		    	Task_100ms();
		        tick_100ms = tick_now;
		    }
		    if (tick_now - tick_500ms >= 500){		//500ms Task
		    	Task_500ms();
		        tick_500ms = tick_now;
		    }





	}
}
