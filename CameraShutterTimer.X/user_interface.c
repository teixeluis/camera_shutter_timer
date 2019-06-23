/**
 * user_interface.c
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

#include "user_interface.h"


unsigned char isStartBtnPressed(void) {
    if(START_BTN == 0) {
        __delay_ms(50);                         // wait 50 ms for debounce.

        if(START_BTN == 0) {
            return 1;
        }
    }

    return 0;// if key is not pressed, return 0
}

unsigned char getKnobPosition(void) {
    unsigned short rawVal;

    KNOB_BIAS = 1;
    rawVal = readADC();
    KNOB_BIAS = 0;

    if(rawVal < KNOB_VAL_STEP)
        return 0;

    if(rawVal >= KNOB_VAL_STEP && rawVal < KNOB_VAL_STEP * 2)
        return 1;

    if(rawVal >= KNOB_VAL_STEP * 2 && rawVal < KNOB_VAL_STEP * 3)
        return 2;

    if(rawVal >= KNOB_VAL_STEP * 3 && rawVal < KNOB_VAL_STEP * 4)
        return 3;

    if(rawVal >= KNOB_VAL_STEP * 4 && rawVal < KNOB_VAL_STEP * 5)
        return 4;

    if(rawVal >= KNOB_VAL_STEP * 5 && rawVal < KNOB_VAL_STEP * 6)
        return 5;

    if(rawVal >= KNOB_VAL_STEP * 6 && rawVal < KNOB_VAL_STEP * 7)
        return 6;

    if(rawVal >= KNOB_VAL_STEP * 7 && rawVal < KNOB_VAL_STEP * 8)
        return 7;

    if(rawVal >= KNOB_VAL_STEP * 8 && rawVal < KNOB_VAL_STEP * 9)
        return 8;

    if(rawVal >= KNOB_VAL_STEP * 9 && rawVal < KNOB_VAL_STEP * 10)
        return 9;

    if(rawVal >= KNOB_VAL_STEP * 10 && rawVal < KNOB_VAL_STEP * 11 + EDGE_CAL_FACTOR)
        return 10;

    if(rawVal >= KNOB_VAL_STEP * 11 + EDGE_CAL_FACTOR && rawVal <= 1023)
        return 11;
}

void setEngagedLed(void) {
    ENGAGED_LED = 1;
}
void clearEngagedLed(void) {
    ENGAGED_LED = 0;
}

void setTriggerLed(void) {
    TRIGGER_LED = 1;
}

void clearTriggerLed(void) {
    TRIGGER_LED = 0;
}
