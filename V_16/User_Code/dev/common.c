#include "common.h"

/*
 * 엔코더 값을 변경해서 타겟RPM을 변견하는 함수
 */
/*void Read_Rotary_Encoder(int si) {
	uint32_t current_time = HAL_GetTick(); // 현재 밀리초(ms) 단위 시간 읽기

	// 마지막 인터럽트 발생 후 5ms 이내에 또 들어오면 노이즈로 판단하고 무시
	if (current_time - data.last_encoder_interrupt_time < 5) {
		return;
	}
	data.last_encoder_interrupt_time = current_time;

	// CLK와 DT의 현재 상태를 읽음
	uint8_t clk_now = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
	uint8_t dt_now = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11);

	// 엔코더 방향 판별 로직 (Quadrature Decoding)
	if (clk_now != dt_now) {
		data.encoder += data.encoder_step;
	} else {
		data.encoder -= data.encoder_step;
	}

	if(data.encoder < 0) data.encoder = 0;
	if(data.encoder > MAX_RPM) data.encoder = MAX_RPM;
	//안전한 상태에서만 목표 RPM업데이트
	if(data.em_flag == 0)
		data.target_rpm = data.encoder;
}*/

void Read_Rotary_Encoder(uint16_t idr) {
    uint8_t clk = (idr & (1 << 11)) ? 1 : 0;
    uint8_t dt  = (idr & (1 << 10)) ? 1 : 0;

    if (clk != dt) {
    		data.encoder += data.encoder_step;
    	} else {
    		data.encoder -= data.encoder_step;
    	}

    // 4. 범위 제한 및 타겟 RPM 반영 (기존 코드 유지)
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

    // 4. 범위 제한 및 타겟 RPM 반영 (기존 코드 유지)
   // if(data.encoder < 0) data.encoder = 0;
    //if(data.encoder > MAX_RPM) data.encoder = MAX_RPM;
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
