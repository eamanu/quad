/*
 * nRF24L01.c
 *
 *  Created on: Jul 9, 2016
 *      Author: root
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "nRF24L01.h"
#include "../SPI/spi.h"

// Flag which denotes transmitting mode
volatile uint8_t PTX;

void rf_int(void){
	//set output pin
	DDRL |= (1<<CE)|(1<<CSN);

	PORTL |= (1<<CSN);
	PORTL &= ~(1<<CE);

	//set interrupt in pin PWM 10
	PORTB &= ~(1<<PB4);
	PCICR  |= (1<<PCIE0);
	PCMSK0 |= (1<<PCINT4);

	//inizialize spi
	init_spi();
}

void rf_w_config_register(uint8_t reg, uint8_t data){
	PORTL &= ~(1<<CSN);
	spi_tranceiver(W_REGISTER | (REGISTER_MASK & reg));
	spi_tranceiver(data);
	PORTL |= (1<<CSN);
}

void rf_config(){
	// set rf channel
	rf_w_config_register(RF_CH, 2);

	//set payload lenght data
	rf_w_config_register(RX_PW_P0, 16);

	PTX = 0;
	rf_w_config_register(CONFIG_NRF24L01, ( (1<<MASK_RX_DR) | (1<<EN_CRC) | (0<<CRCO) ) | (1<<PRIM_RX | 1<<PWR_UP));
	PORTL |= (1<<CE);
}

//write register
void rf_write_register(uint8_t reg, uint8_t * data, uint8_t len){
	PORTL &= ~(1<<CSN);
	spi_tranceiver(W_REGISTER | (REGISTER_MASK & reg));
	spi_send(data, len);
	PORTL |= (1<<CSN);
}

//read a register
void rf_read_register(uint8_t reg, uint8_t * data, uint8_t len){
	PORTL &= ~(1<<CSN);
	spi_tranceiver(R_REGISTER | (REGISTER_MASK & reg));
	spi_transfer(data,data,len);
	PORTL |= (1<<CSN);
}

//set address receiver
void set_RADDR(uint8_t *add){
	PORTL &= ~(1<<CE);
	rf_write_register(RX_ADDR_P0, add, 5);
	PORTL |= (1<<CE);
}

//set address transmisser
void set_TADDR(uint8_t *add){
	rf_write_register(TX_ADDR, add, 5);
}

uint8_t rf_data_ready(){
	if (PTX) return 0;
	uint8_t status;
	PORTL &= ~(1<<CSN);
	status = spi_tranceiver(NOP);
	PORTL |= (1<<CSN);
	return status & (1<<RX_DR);
}

void rf_get_data(uint8_t * data){
	PORTL &= ~(1<<CSN);
	spi_tranceiver(R_RX_PAYLOAD); //send command to read payload data
	spi_transfer(data,data,16); //read data payload
	PORTL |= (1<<CSN);
	rf_w_config_register(STATUS,(1<<RX_DR));
}

void rf_send(uint8_t * data, uint8_t len){
	while (PTX) {} //wait until the last packet is sent

	PORTL &= ~(1<<CE);

	PTX = 1; // transmiting
	rf_w_config_register(CONFIG_NRF24L01, ( (1<<MASK_RX_DR) | (1<<EN_CRC) | (0<<CRCO) ) | (1<<PRIM_RX | 0<<PWR_UP));

	PORTL &= ~(1<<CSN);
	spi_tranceiver(FLUSH_TX); // Write cmd to flush tx fifo
	PORTL |= (1<<CSN);

	PORTL &= ~(1<<CSN);
	spi_tranceiver(W_TX_PAYLOAD); // Write cmd to write payload
	spi_transfer(data, len); //write data payload
	PORTL |= (1<<CSN);

	PORTL |= (1<<CE);

}


