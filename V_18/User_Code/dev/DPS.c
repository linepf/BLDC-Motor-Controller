#include "DSP.h"

LPF LPF_data = {0.0f};


void LPF_init_Euler(float Fc, float sample_T){

	float RC = 1.0f/(6.283185307f * Fc);

	LPF_data.a = sample_T / (sample_T + RC);
	LPF_data.b = RC / (sample_T + RC);
	LPF_data.output_n=0.0f;
	LPF_data.output_n_1=0.0f;
}

float LPF_read_Euler(float inp){
	LPF_data.output_n_1 = LPF_data.output_n;

	LPF_data.output_n = LPF_data.a * inp + LPF_data.b * LPF_data.output_n_1;

	return LPF_data.output_n;
}


void LPF_init_Bilinear(float Fc, float sample_T){

	LPF_data.wp = (2/sample_T) * tanf((2*3.141592*Fc*sample_T)/2);

	LPF_data.a = (LPF_data.wp*sample_T) / (LPF_data.wp*sample_T+2);
	LPF_data.b = -(LPF_data.wp*sample_T-2) / (LPF_data.wp*sample_T+2);

}

float LPF_read_Bilinear(float inp_n){
	LPF_data.output_n = LPF_data.a*(inp_n + LPF_data.input_n_1) + LPF_data.b*(LPF_data.output_n);
	LPF_data.input_n_1 = inp_n;
	return LPF_data.output_n;
}




