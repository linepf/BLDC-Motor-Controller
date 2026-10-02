#include "adc.h"

float Read_adc_1(void)
{
    uint32_t adc_val = 0;
    float voltage = 0.0f;

    // 1. ADC 시작
    HAL_ADC_Start(&hadc1);

    // 2. 변환 완료 대기 (Timeout 10ms)
    // 딜레이 대신 하드웨어가 변환을 마칠 때까지 아주 짧게 대기합니다.
    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
        // 3. 변환된 디지털 값 읽기 (12-bit: 0 ~ 4095)
        adc_val = HAL_ADC_GetValue(&hadc1);

        // 4. 전압 계산 (Reference 전압 3.3V 기준)
        voltage = ((float)adc_val * 3.3f) / 4095.0f;
    }

    // 5. ADC 중지 (다음 호출을 위해 리셋)
    HAL_ADC_Stop(&hadc1);

    return voltage - data.adc_1offset;
}


float Calibrate_ADC_Offset(void)
{
    float sum = 0.0f;

    // 10번 반복 측정하여 평균 계산
    for(int i = 0; i < 10; i++)
    {
        sum += Read_adc_1();
        HAL_Delay(1); // 샘플링 간격 (필요시 조절)
    }

    return  sum / 10.0f;
}


