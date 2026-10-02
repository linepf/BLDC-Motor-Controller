#include "motor.h"


void PWM_init() {

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
	PWM_Off(0);
}


uint8_t Read_HallSum(){

	int Hall_A, Hall_B, Hall_C, HallSum;

	 Hall_A = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
	 Hall_B = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_0);
	 Hall_C = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1);

	 HallSum = Hall_A*4 + Hall_B*2 + Hall_C;

	 if (HallSum == 0 || HallSum == 7){
		 data.Error_code = 1;
	 }

	 return HallSum;
}


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

void Move_Motor_HALL(int dir){
	data.Hall_Sum = Read_HallSum();

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


	if (dir == 1) {
		switch (data.Hall_Sum) {
		case 4:
			Set_Phases(1, 0, -1);
			break;
		case 6:
			Set_Phases(0, 1, -1);
			break;
		case 2:
			Set_Phases(-1, 1, 0);
			break;
		case 3:
			Set_Phases(-1, 0, 1);
			break;
		case 1:
			Set_Phases(0, -1, 1);
			break;
		case 5:
			Set_Phases(1, -1, 0);
			break;
		default:
			break;
		}
		return ;
	}

}

void Move_Motor_BEMF(int dir){
	data.BEMF_Sum = Read_BEMFSum();

	if (dir == 1) {
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

void Move_Motor_Nextstep(int dir, int step){

	if(dir == 1){
		switch (step) {
			case 1: Set_Phases(1, -1, 0);  break;
			case 2: Set_Phases(1, 0, -1);  break;
			case 3: Set_Phases(0, 1, -1);  break;
			case 4: Set_Phases(-1, 1, 0);  break;
			case 5: Set_Phases(-1, 0, 1);  break;
			case 6: Set_Phases(0, -1, 1);  break;
			default: break;
			}
		return;
		}

	if(dir == 0){
		switch (step) {
		        case 1: Set_Phases(0, -1, 1);  break;
		        case 2: Set_Phases(-1, 0, 1);  break;
		        case 3: Set_Phases(-1, 1, 0);  break;
		        case 4: Set_Phases(0, 1, -1);  break;
		        case 5: Set_Phases(1, 0, -1);  break;
		        case 6: Set_Phases(1, -1, 0);  break;
		        default: break;
		    }
		return;
	}


}

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

	    data.delta_sum -= data.delta_buffer[data.delta_index];
		data.delta_buffer[data.delta_index] = delta_time;
		data.delta_sum += delta_time;

		data.delta_index = (data.delta_index + 1) % dlta_count;

		if (data.delta_sum > 0) {
			data.rpm_orig = (Alpa) / (float) data.delta_sum;
		}
}

void Reset_RPM_RingBuffer(void) {

    data.delta_sum = 0;
    for (int i = 0; i < dlta_count; i++) {
        data.delta_buffer[i] = 56000000;
        data.delta_sum += 56000000;
    }

}

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

uint8_t Read_BEMFSum(){

	int BEMF_A, BEMF_B, BEMF_C, BEMFSum;

	 BEMF_A = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_12);
	 BEMF_B = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_14);
	 BEMF_C = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_15);
	 BEMFSum = BEMF_A*4 + BEMF_B*2 + BEMF_C;
	 if (BEMFSum == 0 || BEMFSum == 7){
		 data.Error_code = 1;
		 return 0;
	 }

	 return BEMFSum;
}

void BEMF_Start() {
	if (data.mode == 1 && data.target_rpm > 0 && data.motor_state != STATE_CLOSED_LOOP) {

		static uint8_t step_timer = 0;
		static uint8_t current_delay = 1;

		if (data.motor_state == STATE_IDLE) {
			data.motor_state = STATE_ALIGN;
			current_delay = 1;
		}

	switch (data.motor_state) {
		case STATE_ALIGN:
			data.motor_state = STATE_RAMP_UP;
			step_timer = 0;
			data.step = 1;
			data.bemf_valid_cnt = 0;
			break;

		case STATE_RAMP_UP:
			step_timer++;
			if (step_timer >= current_delay) {
				step_timer = 0;

				data.step++;
				if (data.step > 6) data.step = 1;

				data.duty = 350;
				Move_Motor_Nextstep(data.dir, data.step);

				if (current_delay > 5) {
					current_delay--;
				}
			}
			break;

		case STATE_CLOSED_LOOP:

			break;

		default:
			break;
		}
	}
}
