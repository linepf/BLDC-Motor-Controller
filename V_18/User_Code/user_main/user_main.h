#ifndef USER_MAIN_USER_MAIN_H_
#define USER_MAIN_USER_MAIN_H_

#include "main.h"
#include "motor.h"
#include "task.h"
#include "adc.h"
#include "DSP.h"
#include "UART.h"
#include "PID.h"
#include "common.h"
#include <stdbool.h>
#include "lvgl.h"
#include "LCDController.h"
#include "ui.h"

#define Alpa 			60.0f * 56000000.0f
#define dlta_count 		6
#define MAX_DUTY		2800-10
#define MIN_DUTY		80
#define MAX_I_ERROR 	3000
#define SHUNT_RESISTOR  0.02f
#define AMP_GAIN        33.0f
#define MAX_RPM			15000
#define KP_PER_RPM 		(1.3f / 14500.0f)

typedef enum {
    STATE_IDLE = 0,
    STATE_ALIGN,
    STATE_RAMP_UP,
    STATE_CLOSED_LOOP
} MotorState;

typedef struct {
	int mode;
	int dir;
	int Error_code;
    int duty;
    uint8_t Hall_Sum;
    uint8_t last_Hall_Sum;
    int is_running;
    int target_rpm;

    uint8_t BEMF_Sum;
    uint8_t last_BEMF_Sum;
    uint8_t last_bemf;

    int DC_Current;
    float adc_1;
    float adc_1offset;
    float adc_2;

    uint32_t current_delay;
    MotorState motor_state;
    uint8_t step;
    uint8_t bemf_valid_cnt;


    uint16_t encoder_flag;
    int change_dir_cnt;
    int SW_3_flag;
    int encoder;
    int encoder_step;
    int last_encoder_interrupt_time;

    int buzzer_flag;
    int em_flag;

    int rpm_orig;
    int rpm_lpf;
    uint32_t last_tick_time;
    uint32_t delta_buffer[dlta_count];
    uint32_t delta_sum;
    uint32_t delta_index;
    int stop_counter;


    double Kp;
    double Ki;
	double Kd;
	double p_error;
	double i_error;
	double d_error;
	double dt;
	double last_error;

	int32_t current_position;
	int32_t target_position;
	int32_t target_angle;
	double Kp_pos;

	int temp;
	int temp2;

}Data;


typedef struct {
	int test_int;
	double error;
	float test_float;

}Debug;

extern volatile Data data;
extern Debug debug;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart1;

void user_main();


#endif /* USER_MAIN_USER_MAIN_H_ */
