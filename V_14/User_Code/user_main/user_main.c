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

/////////////////////////////////////////////////////////////////////////////////////////////
	data.adc_1offset = Calibrate_ADC_Offset();	//초기에 adc오차를 측정해서 변수에 저장


	data.current_delay = 40;					//

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
