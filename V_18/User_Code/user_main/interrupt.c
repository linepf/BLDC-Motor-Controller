#include "user_main.h"
#include "main.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	if (GPIO_Pin == GPIO_PIN_4)
	{
		data.target_rpm = 0;
		data.encoder = 0;
		data.target_position = 0;
		data.current_position = 0;
		data.target_angle = 0;
		data.duty = 0;
		PWM_Off(1);
		PWM_Off(2);
		PWM_Off(3);
		data.em_flag  = 1;

	}

	if (GPIO_Pin == GPIO_PIN_10)
	{
		data.encoder_flag = GPIOB->IDR;
		data.buzzer_flag = 1;
	}

	if (GPIO_Pin == GPIO_PIN_0 || GPIO_Pin == GPIO_PIN_1 || GPIO_Pin == GPIO_PIN_3) {

		if (data.mode == 0) {
			Move_Motor_HALL(data.dir);
			CalculateRPM_ring_buffer();

			}

		if(data.mode == 2){
			Move_Motor_HALL(data.dir);
			CalculateRPM_ring_buffer();
			data.current_position++;
		}
	}



	if (GPIO_Pin == GPIO_PIN_12 || GPIO_Pin == GPIO_PIN_14 || GPIO_Pin == GPIO_PIN_15) {

		if (data.mode == 1) {
			if (data.motor_state == STATE_RAMP_UP) {
				data.bemf_valid_cnt++;

				if (data.bemf_valid_cnt > 10) {
					data.bemf_valid_cnt = 11;
					data.motor_state = STATE_CLOSED_LOOP;
				}
			}

			if (data.motor_state == STATE_CLOSED_LOOP) {
				Move_Motor_BEMF(data.dir);
			}
			CalculateRPM_ring_buffer();
		}
	}

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	if (htim->Instance == TIM3) {

		if (data.mode == 0) {
			PI_update_HALL();
			return;
		}

		if (data.mode == 1) {
			PI_update_BEMF();
			return;
		}

		if (data.mode == 2){
			if(data.em_flag == 0){
				Position_Control_Update();
			}else{
				data.target_rpm = 0;
				data.encoder = 0;
				data.target_position = 0;
				data.current_position = 0;
				data.target_angle = 0;
			}
			PI_update_HALL();

			return;
		}
	}
}

