
#include "PID.h"

void PID_Init(){
	data.Kp = 0.2f;
	data.Ki = 1.5f;
	data.Kd = 0.03f;
	data.dt = 0.001f;
	data.d_error = 0.0f;

	data.Kp_pos = 1.0f;

}


void PI_update_HALL() {

	    if (data.last_Hall_Sum == Read_HallSum()) {
	        data.stop_counter++;
	    } else {
	        data.stop_counter = 0;
	        data.last_Hall_Sum = Read_HallSum();
	        data.is_running = 1;
	    }

	    if (data.stop_counter > 200) {
	    	if(data.target_rpm > 0){
	    		Move_Motor_HALL(data.dir);
	    	}else{
	    		data.rpm_orig = 0;
	    		data.rpm_lpf = 0;
	    		data.i_error = 0;
	    		data.stop_counter = 201;
	    		data.is_running = 0;
	    		data.last_error = 0;
	    		Reset_RPM_RingBuffer();
	    		return;
	    	}
	    }


	//data.rpm_lpf = LPF_read_Bilinear(data.rpm_orig);
	data.rpm_lpf = data.rpm_orig;

	double error = data.target_rpm - data.rpm_lpf;

	data.Kp = (data.target_rpm) * KP_PER_RPM;
	data.p_error = data.Kp * error;

	data.i_error += (data.Ki * error * data.dt);
	if (data.i_error > MAX_I_ERROR) data.i_error = MAX_I_ERROR;
	else if (data.i_error < 0) data.i_error = 0;

	double output = data.p_error + data.i_error;

	if (data.target_rpm > 0 && (int)output < MIN_DUTY)
	    output = MIN_DUTY;

	if((int)output > MAX_DUTY) output = MAX_DUTY;


	if(data.target_rpm <= 0){
		data.duty = 0;
		data.last_error = 0;
		PWM_Off(1);
		PWM_Off(2);
		PWM_Off(3);
	}
	else data.duty = (int)output;

	data.last_error = error;


}

void PI_update_BEMF() {
	data.rpm_lpf = data.rpm_orig;

	if (data.last_BEMF_Sum == Read_BEMFSum()) {
		data.stop_counter++;
	} else {
		data.stop_counter = 0;
		data.last_BEMF_Sum = Read_BEMFSum();
		data.is_running = 1;
	}

	if (data.stop_counter > 200) {
		data.stop_counter = 201;
		Reset_RPM_RingBuffer();
		data.last_error = 0;

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

		data.p_error = data.Kp * error;
		double feed_forward = data.target_rpm * 0.1;
		data.p_error += feed_forward;

		data.i_error += (data.Ki * error * data.dt);
		if (data.i_error > MAX_I_ERROR)
			data.i_error = MAX_I_ERROR;
		else if (data.i_error < 0)
			data.i_error = 0;

		double output = data.p_error + data.i_error + data.d_error;

		if (data.target_rpm > 0 && output < MIN_DUTY)
			output = MIN_DUTY;

		if (output > MAX_DUTY)
			output = MAX_DUTY;

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

		data.last_error = error;

	}
}


void Position_Control_Update(void) {
	int32_t pos_error = data.target_position - data.current_position;

	if (pos_error == 0) {
		data.target_rpm = 0.0;
		data.i_error = 0.0;
		return;
	}

	double calculated_target_rpm = data.Kp_pos * (double) pos_error;

	if (calculated_target_rpm > 5000.0)  calculated_target_rpm = 5000.0;
	if (calculated_target_rpm < 200) calculated_target_rpm = 200;

	data.target_rpm = (int)calculated_target_rpm;
}

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

    double base_pulses = angle / 12.0;

    int32_t target_pulses = (int32_t)round(base_pulses + 1.0);

    data.target_position = data.current_position + target_pulses;
}
