#include "user_main.h"
#include "main.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	//비상정지 인터럽트
	if (GPIO_Pin == GPIO_PIN_4) // PB10(CLK)에서 신호 변화 발생
	{
		data.target_rpm = 0;
		data.encoder = 0;
		data.duty = 0;
		PWM_Off(1);
		PWM_Off(2);
		PWM_Off(3);
		data.em_flag  = 1;

	}


	//엔코더 인터럽트
	if (GPIO_Pin == GPIO_PIN_10) // PB10(DT)에서 신호 변화 발생 왼쪽 +
	{
		//Read_Rotary_Encoder(-1);
		data.encoder_flag = GPIOB->IDR;
		data.buzzer_flag = 1;
	}


	//Hall센서 인터럽트
	if (GPIO_Pin == GPIO_PIN_0 || GPIO_Pin == GPIO_PIN_1 || GPIO_Pin == GPIO_PIN_3) {
		//Hall센서 모드일때
		if (data.mode == 0) {
			Move_Motor_HALL(data.dir);
			CalculateRPM_ring_buffer();
			/*if(GPIO_Pin == GPIO_PIN_3)
				CalculateRPM_OnePulse();*/
			}

		//HALL센서 위치 제어 모드일때
		if(data.mode == 2){
			Move_Motor_HALL(data.dir);
			CalculateRPM_ring_buffer();
			data.current_position++;
		}
	}


	//BEMF 인터럽트
	if (GPIO_Pin == GPIO_PIN_12 || GPIO_Pin == GPIO_PIN_14 || GPIO_Pin == GPIO_PIN_15) {
		//센서리스 모드일때
		if (data.mode == 1) {
			// 1. 강제 가속 구간일 때
			if (data.motor_state == STATE_RAMP_UP) {
				// 강제 구동 스텝 전환 직후에만 들어오는 신호를 '유효'하다고 판단하거나
				// 단순히 횟수를 세어 신호가 나오기 시작했음을 인지
				data.bemf_valid_cnt++;

				if (data.bemf_valid_cnt > 10) { // 10번 정도 연속으로 들어오면
					data.bemf_valid_cnt = 11;	//오버플로 방지
					data.motor_state = STATE_CLOSED_LOOP;
				}
			}

			// 2. 센서리스 구간일 때 (이제 여기서 모터를 돌림)
			if (data.motor_state == STATE_CLOSED_LOOP) {
				Move_Motor_BEMF(data.dir);
			}
			CalculateRPM_ring_buffer();
		}
	}

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	if (htim->Instance == TIM3) {

		//Hall센서 모드일때
		if (data.mode == 0) {
			PID_update_HALL();
			return;
		}

		//센서리스 모드일때
		if (data.mode == 1) {
			PID_update_BEMF();
			return;
		}

		//Hall센서 모드이고 위지 제어모드일때
		if (data.mode == 2) {
			Position_Control_Update();
			PID_update_HALL();
			return;
		}











	}
}

