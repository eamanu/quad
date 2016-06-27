/*
 * complementaryFilter.c
 *
 *  Created on: 27 jun. 2016
 *      Author: eamanu
 */

#include "complementaryFilter.h"
#include "math.h"

//convert rad to deg 180/PI
#define RAD_TO_DEG 180/M_PI

// Get the angls roll and pitch using just the accelerometer
void calcAnglAccel(double accelX, double accelY, double accelZ, double* anglAccelRoll, double* anglAccelPitch){
	*anglAccelRoll = atan(-1*(accelX)/sqrt(pow((accelY),2) + pow((accelZ),2))) * RAD_TO_DEG;
	*anglAccelPitch = atan((accelY)/sqrt(pow((accelX),2) + pow((accelZ),2))) * RAD_TO_DEG;
}


// get the angles roll and pitch final
void getRollPitch(double anglAccelRoll, double anglAccelPitch, double anglGyroRoll, double anglGyroPitch, double* Roll, double* Pitch){
	*Roll = ((0.98 * ((*Roll)+ anglGyroRoll * 0.010)) + (0.02 * anglAccelRoll));
	*Pitch = ((0.98 * ((*Pitch) + anglGyroPitch * 0.010)) + (0.02 * anglAccelPitch));
}

