/*
 * PID.c
 *
 *  Created on: Jan 29, 2026
 *      Author: JJH
 */

#include "PID.h"

void PID_Init(){
	data.Kp = 0.2f; 		//0.2
	data.Ki = 1.5f; 		//1.5~8
	data.Kd = 0.03f; 		// 0.01~0.03
	data.dt = 0.001f; 		//1ms
	data.d_error = 0.0f;

	data.Kp_pos = 1.0f; 		//

}


void PI_update_HALL() {

		//이전 Hall 값이랑 지금 Hall 값이 같으면 멈춰 있다고 판단 해서 stop카운터 증가
	    if (data.last_Hall_Sum == Read_HallSum()) {//멈췄을때....
	        data.stop_counter++;
	    } else {//안 멈췄을때....
	    	//값이 다르면 안멈췄다고 판단하고 stop카운터 초기화, Hall값 갱신
	        data.stop_counter = 0;
	        data.last_Hall_Sum = Read_HallSum();
	        data.is_running = 1;
	    }

	    //위 조건문에서 카운터를 여러번 해서 즉 200ms동안 Hall 값이 고정이면 완전히 멈췄다고 판단
	    if (data.stop_counter > 200) {
	    	if(data.target_rpm > 0){
	    		Move_Motor_HALL(data.dir);			//모터가 강제 또는 어떤한 이유로 멈췄어도 타겟 목표가 1이상이면 모터가돌아야 하므로 강제로 이동
	    	}else{
	    		//완전 정지상태
	    		data.rpm_orig = 0;
	    		data.rpm_lpf = 0;
	    		data.i_error = 0;
	    		data.stop_counter = 201;
	    		data.is_running = 0;
	    		data.last_error = 0;
	    		Reset_RPM_RingBuffer(); //완전히 정지일때는 링버퍼 초기화 하기
	    		return;
	    	}
	        //오버 플로 방지 위에서 멈췄을때 계속해서 stop를 증가 시키므로 오버플로 방지를 위해서 일정 값으로 고정 필요
	    }

	//LPF 필터 계산
	//data.rpm_lpf = LPF_read_Bilinear(data.rpm_orig);
	data.rpm_lpf = data.rpm_orig;


	//현재 에러 갱신
	double error = data.target_rpm - data.rpm_lpf;
	//debug.error = error;//디버깅

	//비례제어 계산_1 선형제어
	data.Kp = (data.target_rpm) * KP_PER_RPM;
	data.p_error = data.Kp * error;

	//비례제어 계산_2 피드포워드
	//data.p_error = data.Kp * error;
	//double feed_forward = data.target_rpm * 0.1; //피드포워드
	//data.p_error += feed_forward;

	//적분계산
	data.i_error += (data.Ki * error * data.dt);
	if (data.i_error > MAX_I_ERROR) data.i_error = MAX_I_ERROR;
	else if (data.i_error < 0) data.i_error = 0;


	//최종 에러 더하기 (에러가 듀티로 인가된다.)
	double output = data.p_error + data.i_error;

	//최소 듀티 제어
	//최소한의 구동되는 듀티 보장 없으면 구동자체가 안됨
	//왜냐하면 오차에 따라서 처음 출력으로 나가는 듀티는 보통 80이하부터 나가기 때문에 에초에 듀티 값이 너무 작아서
	//모터가 돌수가 없음 그렇기 때문에 최소한의 듀티를 보장해서 일단을 돌게 만듬
	if (data.target_rpm > 0 && (int)output < MIN_DUTY)
	    output = MIN_DUTY;


	//최대 듀티 제어........................
	if((int)output > MAX_DUTY) output = MAX_DUTY;


	if(data.target_rpm <= 0){
		data.duty = 0;
		data.last_error = 0;
		PWM_Off(1);
		PWM_Off(2);
		PWM_Off(3);
	}
	else data.duty = (int)output;

	//현재에러를 이전 에러로 저장
	data.last_error = error;


}

void PI_update_BEMF() {
	data.rpm_lpf = data.rpm_orig;

	//이전 BEMF_Sum 값이랑 지금 BEMF_Sum 값이 같으면 멈춰 있다고 판단 해서 stop카운터 증가
	if (data.last_BEMF_Sum == Read_BEMFSum()) { //멈췄을때....
		data.stop_counter++;
	} else { //안 멈췄을때....
		//값이 다르면 안멈췄다고 판단하고 stop카운터 초기화, BEMF_Sum값 갱신
		data.stop_counter = 0;
		data.last_BEMF_Sum = Read_BEMFSum();
		data.is_running = 1;
	}

	//위 조건문에서 카운터를 여러번 해서 즉 200ms동안 BEMF 값이 고정이면 완전히 멈췄다고 판단
	if (data.stop_counter > 200) {
		data.stop_counter = 201;//오버 플로 방지 위에서 멈췄을때 계속해서 stop를 증가 시키므로 오버플로 방지를 위해서 일정 값으로 고정 필요
		Reset_RPM_RingBuffer(); //완전히 정지일때는 링버퍼 초기화 하기
		data.last_error = 0;

		//초기 구동이 실패한 경우
		if(data.target_rpm > 0){
			data.stop_counter = 0;
			data.bemf_valid_cnt = 0;
			data.motor_state = STATE_RAMP_UP;
			return;
		}

		data.is_running = 0;
		data.rpm_orig = 0;
		data.rpm_lpf = 0;
		data.i_error = 0;

		data.bemf_valid_cnt = 0;

	}

	if (data.target_rpm <= 0) {
		data.duty = 0;
		data.last_error = 0;
		data.motor_state = STATE_IDLE;
		PWM_Off(1);
		PWM_Off(2);
		PWM_Off(3);
	}

	if (data.motor_state == STATE_CLOSED_LOOP) {
		double error = data.target_rpm - data.rpm_lpf;
		//debug.error = error;	//디버깅

		//비례제어 계산 센서리스에서는 이걸로 사용필요
		data.p_error = data.Kp * error;
		double feed_forward = data.target_rpm * 0.1; //피드포워드
		data.p_error += feed_forward;

		//적분계산
		data.i_error += (data.Ki * error * data.dt);
		if (data.i_error > MAX_I_ERROR)
			data.i_error = MAX_I_ERROR;
		else if (data.i_error < 0)
			data.i_error = 0;

		//최종 에러 더하기
		double output = data.p_error + data.i_error + data.d_error;

		//최소한의 구동되는 듀티 보장 없으면 구동자체가 안됨
		//왜냐하면 오차에 따라서 처음 출력으로 나가는 듀티는 보통 80이하부터 나가기 때문에 에초에 듀티 값이 너무 작아서
		//모터가 돌수가 없음 그렇기 때문에 최소한의 듀티를 보장해서 일단을 돌게 만듬
		if (data.target_rpm > 0 && output < MIN_DUTY)
			output = MIN_DUTY;


		//최대 듀티 제어
		if (output > MAX_DUTY)
			output = MAX_DUTY;
		//듀티가 음수가 안가게 제어
		if (output < 0)
			output = 0;

		if (data.target_rpm == 0) {
			data.duty = 0;
			data.last_error = 0;
			PWM_Off(1);
			PWM_Off(2);
			PWM_Off(3);
		} else
			data.duty = output;

		//현재에러를 이전 에러로 저장
		data.last_error = error;

	}
}

// 위치 제어 루틴
void Position_Control_Update(void) {
	int32_t pos_error = data.target_position - data.current_position;

	// 목표 위치에 완전히 도착(오차 0)했을 때만 0 RPM 및 I항 리셋
	if (pos_error == 0) {
		data.target_rpm = 0.0;
		data.i_error = 0.0;
		return;
	}

	// 위치 P 제어 계산 (Kp_pos = 0.5f 사용 중)
	double calculated_target_rpm = data.Kp_pos * (double) pos_error;

	// 최고 속도 제한만 수행
	if (calculated_target_rpm > 5000.0)  calculated_target_rpm = 5000.0;
	if (calculated_target_rpm < 200) calculated_target_rpm = 200;

	data.target_rpm = (int)calculated_target_rpm;
}

// 각도(angle)를 입력받아 정확한 target_position을 설정하는 함수
void Set_Target_Angle(double angle) {
	if(angle == 0){
		data.target_position = data.current_position = 0;
		return;
	}
	if(angle > 0) data.dir = 0;
	if(angle < 0){
		data.dir = 1;
		angle = angle * -1;
	}

	data.target_position = data.current_position = 0;

    // 1. 기본 필요 펄스 계산 (1/5 감속기 기준 1펄스 = 12도)
    double base_pulses = angle / 12.0;

    // 2. 백래시 및 관성 보정 펄스 추가 (약 +1 펄스 보정)
    // 반올림(round)을 사용하여 소수점 오차를 매끄럽게 처리
    int32_t target_pulses = (int32_t)round(base_pulses + 1.0);

    // 3. 현재 위치 기준 최종 목표 위치 설정
    data.target_position = data.current_position + target_pulses;
}
