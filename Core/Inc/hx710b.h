/*
 * hx710b.h
 *
 *  Created on: 26 sty 2023
 *      Author: user
 */

#ifndef INC_HX710B_H_
#define INC_HX710B_H_

#include "main.h"

// mapping pressure into cmH2O
#define RAW_READING_1 1957000.0f
#define PREASSURE_READING_1 1.0f  // cmH20
#define RAW_READING_2 2614400.0f
#define PREASSURE_READING_2 13.5f  // cmH20

#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

float mapFloat(float x, float in_min, float in_max, float out_min,
		float out_max);
float convertcmH2OtokPa(float x_cmh2o);
uint64_t ConvertSPItoRawReading(uint8_t *RxData);
float ConvertRawReadingToSignedFloat(uint64_t raw_reading);
void Hx710b_Read_Raw_DMA(void);
float mapFloatToCmH2O(float measured_preassure_raw);

#endif /* INC_HX710B_H_ */
