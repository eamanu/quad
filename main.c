////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////    main.c
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include <avr/io.h>
#include <avr/sleep.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

/* serial interface include file. */
//#include "serial.h"


/* system time include file. */
//#include "time.h"

#ifdef portHD44780_LCD
/* LCD (Freetronics 16x2) interface include file. */
#include "hd44780.h"
#endif

#include "uart/uart.h"

#include "adcs/mpu6050.h"
/*-----------------------------------------------------------*/
/* Create a handle for the serial port. */
//extern xComPortHandle xSerialPort;

static void LecturaMPU6050(void *pvParameters);
static void Led(void *pvParameters);

/*-----------------------------------------------------------*/

/*GLOBAL*/
int16_t ax = 0;
int16_t ay = 0;
int16_t az = 0;
int16_t gx = 0;
int16_t gy = 0;
int16_t gz = 0;
double axg = 0;
double ayg = 0;
double azg = 0;
double gxds = 0;
double gyds = 0;
double gzds = 0;
double temp = 0;


/* Main program loop */
int main(void) __attribute__((OS_main));

int main(void)
{
	usart_init();

    xTaskCreate(
    	LecturaMPU6050
		,  (const portCHAR *)"MPU6050" // Main Arduino Mega 2560, Freetronics EtherMega (Red) LED Blink
		,  256				// Tested 9 free @ 208
		,  NULL
		,  3
		,  NULL ); // */


	vTaskStartScheduler();


}

/*-----------------------------------------------------------*/
static void Led(void *pvParameters){
	(void) pvParameters;

    TickType_t xLastWakeTime;
	/* The xLastWakeTime variable needs to be initialised with the current tick
	count.  Note that this is the only time we access this variable.  From this
	point on xLastWakeTime is managed automatically by the vTaskDelayUntil()
	API function. */
	xLastWakeTime = xTaskGetTickCount();

	DDRB |= 0xF0;

    while(1)
    {
    	sei();

		DDRB |= _BV(DDB5);

		    while(1)
		    {
		    	PORTB |=  _BV(PORTB7);       // main (red PB5) LED on. Arduino LED on

				vTaskDelayUntil( &xLastWakeTime, ( 1000 / portTICK_PERIOD_MS ) );

				PORTB &= ~_BV(PORTB7);       // main (red PB5) LED off. Arduino LED off

				vTaskDelayUntil( &xLastWakeTime, ( 1000 / portTICK_PERIOD_MS ) );

				put_float(2.3);
		    }

    }
}

static void LecturaMPU6050(void *pvParameters) // Main Red LED Flash
{
    (void) pvParameters;

    TickType_t xLastWakeTime;
	/* The xLastWakeTime variable needs to be initialised with the current tick
	count.  Note that this is the only time we access this variable.  From this
	point on xLastWakeTime is managed automatically by the vTaskDelayUntil()
	API function. */
	xLastWakeTime = xTaskGetTickCount();

	DDRB |= 1<<7;
	PORTB |= 1<<7;

    while(1)
    {
    	//init interrupt
		sei();

		//init mpu6050

		mpu6050_init();
		//_delay_ms(50);
    	mpu6050_getRawData(&ax, &ay, &az, &gx, &gy, &gz);
    	mpu6050_getConvData(&axg, &ayg, &azg, &gxds, &gyds, &gzds);
    	getTemperature(&temp);

    	put_float(axg);
    	put_float(ayg);
    	put_float(azg);
    	put_float(temp);
    	put_string("\n");


    	if (axg < 0){
    		PORTB |=  _BV(PORTB7);
    	}else{
    		PORTB &= ~_BV(PORTB7);
    	}
    	/*if(axg < 0.1) PORTB &= 0x00;

    	if(axg >= 0.1 && axg < 0.4){
    		PORTB &= 0x00;
    		PORTB |= 0x10;
    	}

    	if(axg >= 0.4 && axg < 0.6){
    		PORTB &= 0x00;
    		PORTB |= 0x30;
    	}
    	if(axg >= 0.6 && axg < 0.9){
    		PORTB &= 0x00;
			PORTB |= 0x70;
    	}
    	if(axg >= 0.9){
    		PORTB &= 0x00;
			PORTB |= 0xF0;
		}*/

		vTaskDelayUntil( &xLastWakeTime, ( 10 ) );

    }
}







