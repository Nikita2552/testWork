
#include "stm32f4xx_hal.h"

void ADCgetvalue(ADC_HandleTypeDef *hadc, uint8_t *channelNumber, uint32_t *value)
{
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;

	switch(*channelNumber)
	{
	case (14):
		sConfig.Channel = ADC_CHANNEL_14;
		break;
	case (15):
		sConfig.Channel = ADC_CHANNEL_15;
		break;
	}

	if (HAL_ADC_ConfigChannel(hadc, &sConfig) == HAL_OK)
	{
		HAL_ADC_Start(hadc); // запускаем преобразование сигнала АЦП
		HAL_ADC_PollForConversion(hadc, 100); // ожидаем окончания преобразования
		*value = HAL_ADC_GetValue(hadc); // читаем полученное значение в переменную adc
		HAL_ADC_Stop(hadc); // останавливаем АЦП (не обязательно)
	 }
	else
	{
		*value = -1;
	}
}
