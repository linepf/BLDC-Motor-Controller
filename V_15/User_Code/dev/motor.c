#include "motor.h"

/*
 * 초기 pwm 시작하는 함수
 */
void PWM_init() {

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
	PWM_Off(0);
}

/*
 * 홀센서를 읽어서 홀센서 합을 반환하는 함수
 */
uint8_t Read_HallSum(){

	int Hall_A, Hall_B, Hall_C, HallSum;

	 Hall_A = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
	 Hall_B = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_0);
	 Hall_C = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1);

/*	 Hall_A = HAL_GPIO_ReadPin(GPIOC, HALL_A_Pin);
	 Hall_B = HAL_GPIO_ReadPin(GPIOD, HALL_B_Pin);
	 Hall_C = HAL_GPIO_ReadPin(GPIOD, HALL_C_Pin);   */

	 HallSum = Hall_A*4 + Hall_B*2 + Hall_C;

	 if (HallSum == 0 || HallSum == 7){
		 data.Error_code = 1;
	 }

	 return HallSum;
}

/*
 * 출력하 U V W의 값을 받아서 실제 PWM으로 출력
 * U V W상 출력
 */
void Set_Phases(int U, int V, int W){

	if (U == 0) {
		TIM1->CCR1 = 0;
		PWM_Off(1);
	} else if (U == 1) {
		TIM1->CCR1 = data.duty;
		TIM1->CCER |= (TIM_CCER_CC1E | TIM_CCER_CC1NE);
	} else if (U == -1) {
		TIM1->CCR1 = 0;
		TIM1->CCER |= (TIM_CCER_CC1E | TIM_CCER_CC1NE);
	}

	if (V == 0) {
		TIM1->CCR2 = 0;
		PWM_Off(2);
	} else if (V == 1) {
		TIM1->CCR2 = data.duty;
		TIM1->CCER |= (TIM_CCER_CC2E | TIM_CCER_CC2NE);
	} else if (V == -1) {
		TIM1->CCR2 = 0;
		TIM1->CCER |= (TIM_CCER_CC2E | TIM_CCER_CC2NE);
	}

	if (W == 0) {
		TIM1->CCR3 = 0;
		PWM_Off(3);
	} else if (W == 1) {
		TIM1->CCR3 = data.duty;
		TIM1->CCER |= (TIM_CCER_CC3E | TIM_CCER_CC3NE);
	} else if (W == -1) {
		TIM1->CCR3 = 0;
		TIM1->CCER |= (TIM_CCER_CC3E | TIM_CCER_CC3NE);
	}
}

/*
 * 0입력시 PWM 채널 1 2 3  전부 off
 * 1일때 U상 PWM 출력 off
 * 2일때 V상 PWM 출력 off
 * 3일때 W상 PWM 출력 off
 * 타이머자체를 끄는게 아니라 pwm 출력만 off
 */
void PWM_Off(int ch){

	if (ch == 0) {
		TIM1->CCER &= ~(TIM_CCER_CC1E | TIM_CCER_CC1NE);
		TIM1->CCER &= ~(TIM_CCER_CC2E | TIM_CCER_CC2NE);
		TIM1->CCER &= ~(TIM_CCER_CC3E | TIM_CCER_CC3NE);
	}

	if (ch == 1) 	TIM1->CCER &= ~(TIM_CCER_CC1E | TIM_CCER_CC1NE);
	if (ch == 2)	TIM1->CCER &= ~(TIM_CCER_CC2E | TIM_CCER_CC2NE);
	if (ch == 3)	TIM1->CCER &= ~(TIM_CCER_CC3E | TIM_CCER_CC3NE);

}

/*
 * 0입력시 PWM 채널 1 2 3  전부 on
 * 1일때 U상 PWM 출력 on
 * 2일때 V상 PWM 출력 on
 * 3일때 W상 PWM 출력 on
 * 타이머자체를 끄는게 아니라 pwm 출력만 on
 */
void PWM_On(int ch){

	if (ch == 0) {
		TIM1->CCER |= (TIM_CCER_CC1E | TIM_CCER_CC1NE);
		TIM1->CCER |= (TIM_CCER_CC2E | TIM_CCER_CC2NE);
		TIM1->CCER |= (TIM_CCER_CC3E | TIM_CCER_CC3NE);
	}

	if (ch == 1) 	TIM1->CCER |= (TIM_CCER_CC1E | TIM_CCER_CC1NE);
	if (ch == 2)	TIM1->CCER |= (TIM_CCER_CC2E | TIM_CCER_CC2NE);
	if (ch == 3)	TIM1->CCER |= (TIM_CCER_CC3E | TIM_CCER_CC3NE);

}

/*
 * Hall_Sum값을 읽어 모터를 움직이는 함수
 *
 */
void Move_Motor_HALL(int dir){
	data.Hall_Sum = Read_HallSum();
	//시계방향
	if (dir == 0) {
		switch (data.Hall_Sum) {
		case 4:
			Set_Phases(-1, 0, 1);
			break;
		case 6:
			Set_Phases(0, -1, 1);
			break;
		case 2:
			Set_Phases(1, -1, 0);
			break;
		case 3:
			Set_Phases(1, 0, -1);
			break;
		case 1:
			Set_Phases(0, 1, -1);
			break;
		case 5:
			Set_Phases(-1, 1, 0);
			break;
		default:
			break;
		}
		return ;
	}

	//반시계방향
	if (dir == 1) {
		switch (data.Hall_Sum) {
		case 4:
			Set_Phases(1, 0, -1);  // (-1, 0, 1)에서 반전
			break;
		case 6:
			Set_Phases(0, 1, -1);  // (0, -1, 1)에서 반전
			break;
		case 2:
			Set_Phases(-1, 1, 0);  // (1, -1, 0)에서 반전
			break;
		case 3:
			Set_Phases(-1, 0, 1);  // (1, 0, -1)에서 반전
			break;
		case 1:
			Set_Phases(0, -1, 1);  // (0, 1, -1)에서 반전
			break;
		case 5:
			Set_Phases(1, -1, 0);  // (-1, 1, 0)에서 반전
			break;
		default:
			break;
		}
		return ;
	}

}

/*
 * BEMF_Sum값을 읽어 모터를 움직이는 함수
 *
 */
void Move_Motor_BEMF(int dir){
	data.BEMF_Sum = Read_BEMFSum();

	//반시계방향
	if (dir == 1) { // CCW
	    switch (data.BEMF_Sum) {
	    case 1: Set_Phases( 1,  0, -1); break;
	    case 5: Set_Phases( 0,  1, -1); break;
	    case 4: Set_Phases(-1,  1,  0); break;
	    case 6: Set_Phases(-1,  0,  1); break;
	    case 2: Set_Phases( 0, -1,  1); break;
	    case 3: Set_Phases( 1, -1,  0); break;
	    default: break;
	    }
	    return;
	}

	//시계방향
	if (dir == 0) {
		switch (data.BEMF_Sum) {
		case 2:
			Set_Phases(-1, 0, 1);
			break;
		case 3:
			Set_Phases(0, -1, 1);
			break;
		case 1:
			Set_Phases(1, -1, 0);
			break;
		case 5:
			Set_Phases(1, 0, -1);
			break;
		case 4:
			Set_Phases(0, 1, -1);
			break;
		case 6:
			Set_Phases(-1, 1, 0);
			break;
		default:
			break;
		}
		return;
	}
}

/*
 * BEMF_Sum값을 읽어 모터를 움직이는 함수
 *
 */
void Move_Motor_Nextstep(int dir, int step){

	//아래 시퀀스는 step 순서에 따라서 반전한것을 유의!!

	//반시계방향
	if(dir == 1){
		switch (step) {
			case 1: Set_Phases(1, -1, 0);  break; // U -> V
			case 2: Set_Phases(1, 0, -1);  break; // U -> W
			case 3: Set_Phases(0, 1, -1);  break; // V -> W
			case 4: Set_Phases(-1, 1, 0);  break; // V -> U
			case 5: Set_Phases(-1, 0, 1);  break; // W -> U
			case 6: Set_Phases(0, -1, 1);  break; // W -> V
			default: break;
			}
		return;
		}

	//시계방향
	if(dir == 0){
		switch (step) {
		        case 1: Set_Phases(0, -1, 1);  break; // 기존의 step 6
		        case 2: Set_Phases(-1, 0, 1);  break; // 기존의 step 5
		        case 3: Set_Phases(-1, 1, 0);  break; // 기존의 step 4
		        case 4: Set_Phases(0, 1, -1);  break; // 기존의 step 3
		        case 5: Set_Phases(1, 0, -1);  break; // 기존의 step 2
		        case 6: Set_Phases(1, -1, 0);  break; // 기존의 step 1
		        default: break;
		    }
		return;
	}


}

//링버퍼를 가지고 RPM을 계산하는 함수
void CalculateRPM_ring_buffer(){

		volatile uint32_t current_time = TIM2->CNT;
		volatile uint32_t delta_time;

	    if (current_time >= data.last_tick_time){
	        delta_time = current_time - data.last_tick_time;
	    }
	    else{
	        delta_time = (TIM2->ARR - data.last_tick_time) + current_time + 1;
	    }

	    if (delta_time < 25000) return;

	    data.last_tick_time = current_time;

	    //링버퍼 사용
	    data.delta_sum -= data.delta_buffer[data.delta_index];
		data.delta_buffer[data.delta_index] = delta_time;
		data.delta_sum += delta_time;

		data.delta_index = (data.delta_index + 1) % dlta_count;

		if (data.delta_sum > 0) {
			data.rpm_orig = (Alpa) / (float) data.delta_sum;
		}
}

/*//링버퍼 초기화 함수
void Reset_RPM_RingBuffer(void) {

    data.delta_sum = 0;
    for (int i = 0; i < dlta_count; i++) { // dlta_count = 6
        data.delta_buffer[i] = 56000000;  // 버퍼 내부 값을 최대 카운트로 설정
        data.delta_sum += 56000000;
    }

}*/

void CalculateRPM_OnePulse(){
			volatile uint32_t current_time = TIM2->CNT;
			volatile uint32_t delta_time;

		    if (current_time >= data.last_tick_time){
		        delta_time = current_time - data.last_tick_time;
		    }
		    else{
		        delta_time = (TIM2->ARR - data.last_tick_time) + current_time + 1;
		    }

		    if (delta_time < 25000) return;

		    data.last_tick_time = current_time;

			data.rpm_orig = (Alpa/2) / (float) delta_time;
}

/*
 *
 */
uint8_t Read_BEMFSum(){

	int BEMF_A, BEMF_B, BEMF_C, BEMFSum;

	 BEMF_A = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_12);//V
	 BEMF_B = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_14);//W
	 BEMF_C = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_15);//U
	 BEMFSum = BEMF_A*4 + BEMF_B*2 + BEMF_C;
	 //
	 if (BEMFSum == 0 || BEMFSum == 7){
		 data.Error_code = 1;
		 return 0;
	 }

	 return BEMFSum;
}

void BEMF_Start() {
	if (data.mode == 1 && data.target_rpm > 0 && data.motor_state != STATE_CLOSED_LOOP) {

		static uint8_t step_timer = 0;
		static uint8_t current_delay = 1; // 시작 지연 설정

		if (data.motor_state == STATE_IDLE) {
			data.motor_state = STATE_ALIGN;
			current_delay = 1;  // 지연시간 초기화
		}

	switch (data.motor_state) {
		case STATE_ALIGN:
			// (Step 1 상태로 고정) 강제 가속전 준비, 원래는 로터 정렬 부분이었으나 지금은 사용안함
			data.motor_state = STATE_RAMP_UP;
			step_timer = 0;
			data.step = 1;
			data.bemf_valid_cnt = 0;
			break;

		case STATE_RAMP_UP:
			// 2. 강제 가속 (Open-loop)
			step_timer++;
			if (step_timer >= current_delay) {
				step_timer = 0;

				// 다음 스텝으로 전환
				data.step++;
				if (data.step > 6) data.step = 1;

				data.duty = 350;
				// 강제로 모터 구동
				Move_Motor_Nextstep(data.dir, data.step);

				// 가속: 주기를 1ms씩 줄임 (최소 5ms까지), 홀시 몰라서 남겨둔 코드 나중에 삭제 필요
				if (current_delay > 5) {
					current_delay--;
				}
			}
			break;

		case STATE_CLOSED_LOOP:
			// 센서리스 구동 중 (1ms task에서는 모니터링만 수행) 어차피 실행 안됨
			break;

		default:
			break;
		}
	}
}
