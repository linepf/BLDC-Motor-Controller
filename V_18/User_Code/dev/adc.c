#include "adc.h"

float Read_adc_1(void)
{
    uint32_t adc_val = 0;
    float voltage = 0.0f;

    HAL_ADC_Start(&hadc1);

    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
        adc_val = HAL_ADC_GetValue(&hadc1);

        voltage = ((float)adc_val * 3.3f) / 4095.0f;
    }

    HAL_ADC_Stop(&hadc1);

    return voltage - data.adc_1offset;
}


float Calibrate_ADC_Offset(void)
{
    float sum = 0.0f;

    for(int i = 0; i < 10; i++)
    {
        sum += Read_adc_1();
        HAL_Delay(1);
    }

    return  sum / 10.0f;
}


