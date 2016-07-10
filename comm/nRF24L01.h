/*
 * nRF24L01.h
 *
 *  Created on: Jul 9, 2016
 *      Author: root
 */

#ifndef COMM_NRF24L01_H_
#define COMM_NRF24L01_H_

#include "nRF24L01_RegisterMap.h"
#include <avr/io.h>

#define CE PL0 /*Digital pin 49*/
#define CSN PL1 /*Digital pin 48*/

/*init RF module*/
void rf_int(void);

/*configure the rf*/
void rf_config();

/*write config register*/
void rf_w_config_register(uint8_t reg, uint8_t data);

/*config RF*/
void rf_config(void);

/*write register*/
void rf_write_register(uint8_t reg, uint8_t * data, uint8_t len);

/*read register*/
void rf_read_register(uint8_t reg, uint8_t * data, uint8_t len);

/*if data is ready for reading*/
uint8_t rf_data_ready();

/*get data*/
void rf_get_data(uint8_t * data);

/*Set addr receive*/
void set_RADDR(uint8_t *add);

/*Set addr transmiser*/
void set_TADDR(uint8_t *add);

/*Send Data*/
void rf_send(uint8_t * data, uint8_t len);

#endif /* COMM_NRF24L01_H_ */

