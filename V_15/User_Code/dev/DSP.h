/*
 * DSP.h
 *
 *  Created on: Jan 27, 2026
 *      Author: JJH
 */

#ifndef DEV_DSP_H_
#define DEV_DSP_H_

#include "user_main.h"
#include "math.h"


typedef struct {
	float input;
	float input_n_1;	//과거 입력
	float output_n;		//현재 출력
	float output_n_1;	//과거 출력
	float a, b;
	//float Fc;			//컷오프 주파수
	float wp;			//보정된 컷오프 주파수
}LPF;

extern LPF LPF_data;


void LPF_init_Euler(float Fc, float sample_T);
float LPF_read_Euler(float inp);

void LPF_init_Bilinear(float Fc, float sample_T);
float LPF_read_Bilinear(float inp_n);



#endif /* DEV_DSP_H_ */
