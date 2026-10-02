#ifndef DEV_DSP_H_
#define DEV_DSP_H_

#include "user_main.h"
#include "math.h"


typedef struct {
	float input;
	float input_n_1;
	float output_n;
	float output_n_1;
	float a, b;
	float wp;
}LPF;

extern LPF LPF_data;


void LPF_init_Euler(float Fc, float sample_T);
float LPF_read_Euler(float inp);

void LPF_init_Bilinear(float Fc, float sample_T);
float LPF_read_Bilinear(float inp_n);



#endif /* DEV_DSP_H_ */
