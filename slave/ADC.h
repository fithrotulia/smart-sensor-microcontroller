/*
 * ADC.h
 *
 *  Created on: Nov 28, 2019
 *      Author: Piko Prasetyo
 */

#ifndef ADC_H_
#define ADC_H_

#include "stdio.h"

void READ_ADC(uint8_t channel);
uint8_t HasilADCH(uint8_t channel);
uint8_t HasilADCL(uint8_t channel);


#endif /* ADC_H_ */
