/*
 * File:   camera_interface_nikon_ir.c
 *
 * Driver for the camera control via IR. Check main.c for information about
 * the pin mappings.
 *
 * The implementation of the IR interface relies on the on/off modulation of
 * a 38 KHz square wave generated using the timer2 in PWM mode. In order to
 * ensure consistent phase between the bursts, instead of turning off the PWM,
 * we toggle the tri-state of the output pin for the correct amount of time.
 * This way the timer keeps running in spite of the output being turned on and off.
 *
 * The firmware mimics the ML-L3 remote, which uses the following timings:
 *
 * MARK (2000us)|SPACE (28000us)|MARK (400us)|SPACE (1580us)|MARK (400us)|SPACE (3580us)|MARK (400us)
 * SPACE (63200us)
 * MARK (2000us)|SPACE (28000us)|MARK (400us)|SPACE (1580us)|MARK (400us)|SPACE (3580us)|MARK (400us)
 *
 * MARK represents the 38 KHz carrier turned on, and SPACE the absence of signal.
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

#include "camera_interface_nikon_ir.h"


void fireShutter(void) {
    unsigned char i;
    unsigned short j;

    T2CONbits.TMR2ON = 1;

    for(i = 0; i < NUM_BURSTS; i++) {
        TRISIObits.TRISIO2 = (i % 2 != 0);

        for(j = 0; j < delays[i]; j++) {
            NOP();
        }
    }
    
    T2CONbits.TMR2ON = 0;
    TRISIObits.TRISIO2 = 1;
}

void initIrCarrier(void) {
    // configure PWM:

    PR2 = CARRIER_PERIOD;
    CCP1CONbits.DC1B = CARRIER_DUTY & 0b11;
    CCPR1L = CARRIER_DUTY >> 2;
    CCP1CONbits.CCP1M = 0b1100; // PWM active high

    PIR1bits.TMR2IF = 0;
    T2CONbits.T2CKPS = 0;
    T2CONbits.TMR2ON = 1;
}

