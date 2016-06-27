/*
 * sensor_reader.h
 *
 *  Created on: Apr 6, 2016
 *      Author: eamanu
 */

#ifndef ADCS_SENSOR_READER_H_
#define ADCS_SENSOR_READER_H_

#include <avr/io.h>

// get convert data for calculate attitude datas
void getConvData(double *acelX, double *acelY, double *acelZ, double *rateX, double *rateY, double *rateZ);

// get temperature data
void getTemperature(double *temp);

//get attitude data
void getAttitudeData(double *anglX, double *anglY, double *anglZ, double *Roll, double *Pitch);

// read bytes from MPU6050 register
int8_t readBytesFromMPU6050(uint8_t regAddr, uint8_t length, uint8_t *data);

#endif /* ADCS_SENSOR_READER_H_ */
