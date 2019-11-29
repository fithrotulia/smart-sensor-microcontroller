/*
 * ADC.c
 *
 *  Created on: Nov 28, 2019
 *      Author: Piko Prasetyo
 */

#include "ADC.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void ADC_INISIALISASI(void){
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1);
	ADMUX |= (1<<ADLAR) | (1<<REFS0);
	ADCSRA |= (1<<ADEN);
}

void READ_ADC(uint8_t channel){
	ADMUX &= ~(0x1F);
	ADMUX |= channel;
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA&(1<<ADIF)));
	ADCSRA |= (1<<ADIF);
}

uint8_t HasilADCH(uint8_t channel){
	return ADCH;
}

uint8_t HasilADCL(uint8_t channel){
	return ADCL;
}
