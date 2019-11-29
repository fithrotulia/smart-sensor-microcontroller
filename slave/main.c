/*
 * main.c
 *
 *  Created on: Nov 28, 2019
 *      Author: izzat
 */

// Piko Contributed
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "ADC.h"

int i;
uint16_t adc[100];
uint16_t threshold;

//bsmillah
int main(void){
	ADC_INISIALISASI();
	DDRA = 0xFF;
	while(1){
		for(i=0; i<=1; i++){
			READ_ADC(0);
			adc[i]=HasilADCH(1);
		}
		threshold=(adc[0]+adc[1])/2;
	}
}
