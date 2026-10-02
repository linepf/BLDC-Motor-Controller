#ifndef DEV_COMMON_H_
#define DEV_COMMON_H_

#include "user_main.h"

void Read_Rotary_Encoder(uint16_t idr);
void Read_Rotary_Encoder_angle(uint16_t idr);
void Change_Encoder_Step();
void direction_output(void);


#endif /* DEV_COMMON_H_ */
