#include "task.h"


void Task_1ms() {


	BEMF_Start();


	data.adc_1 = Read_adc_1();

	if(data.adc_1 <= 0) data.adc_1 = 0;

	float raw_current_A = data.adc_1 / (AMP_GAIN * SHUNT_RESISTOR);
	if (raw_current_A <= 0) raw_current_A = 0;
	data.DC_Current = raw_current_A * 1000.0f;




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






}

void Task_100ms(){





}

void Task_500ms(){

	//엔코더 스위치 누를시 엔코더 증가분 조절
	if (HAL_GPIO_ReadPin(SW_3_GPIO_Port, SW_3_Pin) == 0) {
		++data.change_dir_cnt;
		data.SW_3_flag = 1;
		data.buzzer_flag = 1;
	} else {
		if (data.change_dir_cnt > 4 && data.SW_3_flag == 1) {
			//방향 전환은 정지시에만 가능
			if (data.target_rpm == 0 && data.is_running == 0) {
				data.em_flag = 0; //정지 상태에서 비상상황 해제 가능

				if (data.dir == 0) {
					data.dir = 1;

				} else {
					data.dir = 0;

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

		}else{
			data.mode = 0;	//HALL센서 모드로 변경
			EXTI->IMR &= ~((1 << 12) | (1 << 14) | (1 << 15));//BEMF off
			EXTI->PR = (1 << 12) | (1 << 14) | (1 << 15);
			EXTI->IMR |= (1 << 0) | (1 << 1) | (1 << 3);// hall센서 활성화
		}
	}




}


