/*
 * spi.h
 *
 *  Created on: Jul 9, 2016
 *      Author: root
 */

#ifndef SPI_SPI_H_
#define SPI_SPI_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define MOSI PB2 /*Digital Pin 51*/
#define MISO PB3 /*Digital pin 50*/
#define SCK PB1 /*Digital pin 52 (SCK)*/
#define SS PB0 /*Digital pin 53 (SS)*/

/*init spi*/
void init_spi(void);
/*spi send array with return data*/
void spi_transfer(uint8_t *out, uint8_t *in, uint8_t len);
/*spi send array with without return data*/
void spi_send(uint8_t *out, uint8_t len);
/*send a byte*/
uint8_t spi_tranceiver(uint8_t data);


#endif /* SPI_SPI_H_ */
