/**
 * user_interface.h
 *
 * Driver for the timer device push buttons and rotary selector
 * switch. Check main.c for information about the pin mappings.
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
 *
 */

#ifndef _USER_INTERFACE_H
#define _USER_INTERFACE_H

#include <pic12f683.h>
#include "pic.h"

#include "common.h"

#define START_BTN       GP3     // GPIO bit 3 (pin 4)
#define ENGAGED_LED     GP5     // GPIO bit 2 (pin 5)
#define TRIGGER_LED     GP4     // GPIO bit 4 (pin 3)
#define KNOB_BIAS       GP1     // GPIO bit 1 (pin 6) voltage supplied to the knob resistive divider during a reading

#define KNOB_VAL_STEP   85
#define EDGE_CAL_FACTOR 50

/**
 * This function tells if the start button is pressed. it actively waits a few milliseconds
 * before assuming a valid read (debounce) of the switch.
 *
 * @return 1 if the button is pressed. 0 otherwise.
 */
unsigned char isStartBtnPressed(void);

/**
 * Determines the knob position taking into account the expected range of analog
 * values for a particular knob position, and the calibration values that are
 * defined.
 *
 * @return a number in the range 0-11 representing the position of the knob.
 */
unsigned char getKnobPosition(void);

/**
 * Sets the green "engaged" LED.
 */
void setEngagedLed(void);

/**
 * Clears the green "engaged" LED.
 */
void clearEngagedLed(void);

/**
 * Sets the red "trigger" LED.
 */
void setTriggerLed(void);

/**
 * Clears the red "trigger" LED.
 */
void clearTriggerLed(void);

#endif