/*
 * main.c
 *
 *  Created on: Nov 28, 2019
 *      Author: izzat
 */
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#define F_CPU 16000000UL

unsigned char num_variable;
void USART_Init(void);

int main(void)
{
	USART_Init();
	num_variable=100;
	while(1){
		while(!(UCSR0A&(1<<UDRE0))); //wait until UDRE register empty
		UDR0 = num_variable;
		if(++num_variable>250){
			num_variable=0;
		}
		_delay_ms(50);
	}

}

void USART_Init(void)
{
	UCSR0C = (2<<UPM00)|(3<<UCSZ00);
	UBRR0L =103;
	UCSR0B = (1<<TXEN0);
}

