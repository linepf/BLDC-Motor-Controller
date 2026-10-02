/*
 * PID.h
 *
 *  Created on: Jan 29, 2026
 *      Author: JJH
 */

#ifndef DEV_PID_H_
#define DEV_PID_H_

#include "user_main.h"

void PID_Init();
void PID_update_HALL();
void PID_update_BEMF();
void Position_Control_Update();
void Set_Target_Angle(double angle);



#endif /* DEV_PID_H_ */
