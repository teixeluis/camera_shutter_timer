/**
 * main.h
 *
 * Main module definition file
 *
 * Author: Luis Teixeira (teixeluis@gmail.com)
 *
 *
 *
 * Licence and copyright notice:
 *
 * Copyright 2014 Luis Teixeira
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, softwar
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


#ifndef _MAIN_H
#define _MAIN_H

#include <pic12f683.h>
#include "pic.h"

#include "common.h"
#include "user_interface.h"
#include "camera_interface_nikon_ir.h"

#define TMR0_OFFSET     0x3C    // initializes to 60, so that the timer overflows after 195 ticks

#define TMR1_OFFSET     0x0BDC  // initializes to 3036, so that at T/8 = 125 KHz it will overflow after 0.5 secs

// definition of number of interrupts for each time interval

#define _1_HOUR         7200
#define _30_MINS        3500
#define _10_MINS        1200
#define _3_MINS          360
#define _1_MIN           120
#define _30_SECS          60
#define _20_SECS          40
#define _10_SECS          20
#define _5_SECS           10
#define _2_SECS            4
#define _1_SEC             2
#define _HALF_SEC          1

#define SHUTTER_DLY        15
#define SHUTTER_LENGTH      1
#define DEFAULT_TIME_LIMIT  _5_SECS

unsigned int timerCount;
unsigned int shutterTimeLimit;

/**
 * Procedure for initialization of features within the PIC such as the AD
 * converters and timers.
 *
 */
void initSys(void);

/**
 * Return a readout from the ADC.
 *
 * @return
 */
unsigned short readADC(void);

/**
 * Initializes and starts the intervalometer timer (Timer1).
 *
 * @param timeLimit the timer after which the shutter should be released.
 */
void initIntervalometerTimer(int timeLimit);

/**
 * Calls the initialization of the intervalometer timer according to the
 * obtained position of the knob.
 * 
 * @param knobPosition the known knob position.
 */
void initTimerFromKnobPos(unsigned char knobPosition);

/**
 * Stops the intervalometer timer.
 */
void stopIntervalometerTimer(void);

/**
 * The interrupt service routine for handling the interrupt caused by the shutter
 * timer (once every 0.5 seconds).
 */
void interrupt isr(void);

/**
 * Test function for generically turning on leds based on a value).
 *
 * @param value
 */
void setGpioLeds(unsigned char value);

#endif