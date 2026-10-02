

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


#define Alpa 		60.0f * 56000000.0f		//앞의 60은 RPS에서 RPM으로 변한 하기 위한 상수이고 뒤에 값은 rpm을 측정 할때 사용할 타이머의 주파수이다.
#define dlta_count 	6						//링버퍼 크기
#define MAX_DUTY	2800-10					//PID에서 최대 듀티값 2790
#define MIN_DUTY	80
#define MAX_I_ERROR 1500					//윈드업 방지 실험으로 구한값
#define SHUNT_RESISTOR    0.02f  			// 0.02 Ohm 션트저항 값
#define AMP_GAIN          33.0f  			// OP-AMP Gain 이득곱한값
#define MAX_RPM			  15000

typedef enum {
    STATE_IDLE = 0,				//모터가 멈춰있을때
    STATE_ALIGN,				//모터 구동전 정렬
    STATE_RAMP_UP,				//모터 강제구동
    STATE_CLOSED_LOOP			//모터 강제구동 후 pid제어 상태
} MotorState;

typedef struct {
	int mode;					//모드전환 0 : 홀센서 상요   1: 센서리스
	int dir;					//회전 방방 0: CW 시계 방향 1: CCW 반시계
	int Error_code;				//에러종류 반환 코드
    int duty;					//스피드
    uint8_t Hall_Sum;			//현재 홀센서 합
    uint8_t last_Hall_Sum;		//이전 홀센서 합
    int is_running;				//모터가 상태 표시 1이면 도는중
    int target_rpm;				//목표 RPM

    uint8_t BEMF_Sum;			//현제 BEMF 합
    uint8_t last_BEMF_Sum;		//이전 BEMF 합
    uint8_t last_bemf;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //전류값 배터리 전압을 저장하는 변수
    int DC_Current;						//adc_1값을 가지고 계산한 전류를 저장 할 변수
    float adc_1;						//adc_1값을 저장할 변수
    float adc_1offset; 					//adc_1의 초기 오차를 저장할 변수
    float adc_2;						//adc_2값을 저장할 변수


    //센서리즈 제어 변수
    uint32_t current_delay; 			//시작 지연 40ms
    MotorState motor_state;				//센서리스 강제구동시 사용하는 모터의 상태를 저장하는 변수
    uint8_t step;        				//센서리스 강제구동시 사용하는 모터의 스텝을 저장하는 변수
    uint8_t bemf_valid_cnt;				//센서리스 강제구동시 초기에 비교기 인터럽트 개수를 세는 변수

    //엔코더 제어 변수
    uint16_t encoder_flag;
    int change_dir_cnt;					//방향을 변경할때 사용하는 변수, 정지상태에서 일정 시간 이상 누르면 방향이 바뀐다.
    int SW_3_flag;						//엔코드의 스위치 상태를 저장하는 변수
    int encoder;						//엔코더 값을 저장하는 변수
    int encoder_step;					//엔코더 값을 얼마나 더하거나 뺄지 정하는 변수
    int last_encoder_interrupt_time;	//엔코더의 노이즈방지를 위해서 이전 시간을 저장하는 변수

    int buzzer_flag;					//버저 제어 변수
    int em_flag;						//비상정지 플레그

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int rpm_orig;						//RPM의 오리지널값
    int rpm_lpf;						//RPM이 LPF를 거친값
    uint32_t last_tick_time;			//RPM계산시 이전 타이머값
    uint32_t delta_buffer[dlta_count];	//델타 값을 저장 할 링버퍼
    uint32_t delta_sum;					//RPM계산시 6 스텝 동안의 시간
    uint32_t delta_index;				//링버퍼 위치값
    int stop_counter;

    double Kp;							//비례이득
    double Ki;							//적분이득
	double Kd;							//미분이득
	double p_error;						//비례오차
	double i_error;						//적분오차
	double d_error;						//미분오차
	double dt;							//미적분시 시간
	double last_error;	  				// 이전의 오차를 저장하기 위한 변수


	int temp;
	int temp2;

}Data;

//디버깅용 구조체
typedef struct {
	int test_int;
	double error;
	float test_float;

}Debug;

///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////

extern volatile Data data;
extern Debug debug;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart1;
//extern ADC_HandleTypeDef hadc3;

void user_main();


#endif /* USER_MAIN_USER_MAIN_H_ */
