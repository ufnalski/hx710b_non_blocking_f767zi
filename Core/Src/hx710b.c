/*
 * hx710b.c
 *
 *  Created on: 26 sty 2023
 *      Author: user
 */
#include "hx710b.h"
#include "spi.h"

uint8_t TxData[8] =
{ 0b0000000, 0x00000001, 0b01010101, 0b01010101, 0b01010101, 0b01010101,
		0b01010101, 0b01010101 };  // clock, 25 ticks
uint8_t RxData[8];

typedef struct hx710bProtocol
{
	uint32_t ReadBits;
	uint32_t DummyBits; // 0
} hx710bProtocol_t; // 16 bits

union uint32int32
{
	uint32_t Raw32Bits;
	int32_t TwosComplement;
} SensorData;

uint8_t sensor_read_flag = 0;

float mapFloat(float x, float in_min, float in_max, float out_min,
		float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float convertcmH2OtokPa(float x_cmh2o)
{
	return x_cmh2o * 0.098f;
}

// weak
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if (hspi->Instance == SPI1)
	{
		sensor_read_flag = 1;
	}
}

uint64_t ConvertSPItoRawReading(uint8_t *RxData)
{
	return (((uint64_t) (RxData[7] & 0b00000010)) >> 1)
			| (((uint64_t) (RxData[7] & 0b00001000)) >> 2)
			| (((uint64_t) (RxData[7] & 0b00100000)) >> 3)
			| (((uint64_t) (RxData[7] & 0b10000000)) >> 4)
			| (((uint64_t) (RxData[6] & 0b00000010)) << 3)
			| (((uint64_t) (RxData[6] & 0b00001000)) << 2)
			| (((uint64_t) (RxData[6] & 0b00100000)) << 1)
			| (((uint64_t) (RxData[6] & 0b10000000)) << 0) |

			(((uint64_t) (RxData[5] & 0b00000010)) << 7)
			| (((uint64_t) (RxData[5] & 0b00001000)) << 6)
			| (((uint64_t) (RxData[5] & 0b00100000)) << 5)
			| (((uint64_t) (RxData[5] & 0b10000000)) << 4)
			| (((uint64_t) (RxData[4] & 0b00000010)) << 11)
			| (((uint64_t) (RxData[4] & 0b00001000)) << 10)
			| (((uint64_t) (RxData[4] & 0b00100000)) << 9)
			| (((uint64_t) (RxData[4] & 0b10000000)) << 8) |

			(((uint64_t) (RxData[3] & 0b00000010)) << 15)
			| (((uint64_t) (RxData[3] & 0b00001000)) << 14)
			| (((uint64_t) (RxData[3] & 0b00100000)) << 13)
			| (((uint64_t) (RxData[3] & 0b10000000)) << 12)
			| (((uint64_t) (RxData[2] & 0b00000010)) << 19)
			| (((uint64_t) (RxData[2] & 0b00001000)) << 18)
			| (((uint64_t) (RxData[2] & 0b00100000)) << 17)
			| (((uint64_t) (RxData[2] & 0b10000000)) << 16) |

			(((uint64_t) (RxData[1] & 0b00000010)) << 23)
			| (((uint64_t) (RxData[1] & 0b00001000)) << 22)
			| (((uint64_t) (RxData[1] & 0b00100000)) << 21)
			| (((uint64_t) (RxData[1] & 0b10000000)) << 20);
}

float ConvertRawReadingToSignedFloat(uint64_t raw_reading)
{
	SensorData.Raw32Bits = ((uint32_t) raw_reading) << 8;
	return (float) (SensorData.TwosComplement / 256);
}

float mapFloatToCmH2O(float measured_preassure_raw)
{
	return mapFloat(measured_preassure_raw,
	RAW_READING_1, RAW_READING_2,
	PREASSURE_READING_1, PREASSURE_READING_2);
}

void Hx710b_Read_Raw_DMA(void)
{
	HAL_SPI_TransmitReceive_DMA(&hspi1, (uint8_t*) (&TxData),
			(uint8_t*) (&RxData), sizeof(TxData));
}
