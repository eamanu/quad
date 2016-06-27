/*
 * sensor_reader.c
 *
 *  Created on: Apr 6, 2016
 *      Author: eamanu
 */
//#include "sensor_reader.h"
/* Scheduler include files. */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Inlcude de lib for i2c comm
#include "../i2c/i2c_master.h"

// MPU6050 libs
#include "mpu6050.h"

// buffer for the temperature of the sensor
uint8_t temp_buff[2];

// Read datas from mpu6050 registers
int8_t readBytesFromMPU6050(uint8_t regAddr, uint8_t length, uint8_t *data){
	uint8_t i = 0;
	int8_t count = 0;
	if(length > 0) {
		// start comm
		i2c_start(MPU6050_ADDR | I2C_WRITE);
		i2c_write(regAddr);

		//read data
		i2c_start(MPU6050_ADDR | I2C_READ);
		for(i=0; i<length; i++) {
			count++;
			if(i==length-1)
				data[i] = i2c_readNak();
			else
				data[i] = i2c_readAck();
		}
		i2c_stop();
	}
	return count;
}

void getConvData(double *acelX, double *acelY, double *acelZ, double *rateX, double *rateY, double *rateZ){
	mpu6050_getConvData(acelX,acelY, acelZ, rateX, rateY, rateZ);
}

void getTemperature(double *temp){
	readBytesFromMPU6050(MPU6050_RA_TEMP_OUT_H, 2, (uint8_t*)temp_buff);
	// set temperature
	*temp = (((((int16_t)temp_buff[0]) << 8 )| temp_buff[1]) + 12412.0)/340.0;
}


