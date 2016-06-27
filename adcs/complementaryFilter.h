/*
 * complementaryFilter.h
 *
 *  Created on: 27 jun. 2016
 *      Author: eamanu
 */

#ifndef ADCS_COMPLEMENTARYFILTER_H_
#define ADCS_COMPLEMENTARYFILTER_H_

// Get the angls roll and pitch using just the accelerometer
void calcAnglAccel(double accelX, double accelY, double accelZ, double* anglAccelRoll, double* anglAccelPitch);

// Get the aangles roll and pitch usint just the gyros
void calcAnglGyro(double rateX, double rateY, double* anglGyroRoll, double* anglGyroPitch);

// get the angles roll and pitch final
void getRollPitch(double anglAccelRoll, double anglAccelPitch, double anglGyroRoll, double anglGyroPitch, double* Roll, double* Pitch);

#endif /* ADCS_COMPLEMENTARYFILTER_H_ */
