#ifndef DEV_PID_H_
#define DEV_PID_H_

#include "user_main.h"

void PID_Init();
void PI_update_HALL();
void PI_update_BEMF();
void Position_Control_Update();
void Set_Target_Angle(double angle);



#endif /* DEV_PID_H_ */
