#ifndef DEV_MOTOR_H_
#define DEV_MOTOR_H_

#include "user_main.h"

void PWM_init();
uint8_t Read_HallSum();
void Set_Phases(int U, int V, int W);
void PWM_Off(int ch);
void PWM_On(int ch);
void Move_Motor_HALL(int dir);
void CalculateRPM_ring_buffer();
void CalculateRPM_OnePulse();
uint8_t Read_BEMFSum();
void Move_Motor_BEMF(int dir);
void Move_Motor_Nextstep(int dir, int step);
void BEMF_Start();



#endif /* DEV_MOTOR_H_ */
