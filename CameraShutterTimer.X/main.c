/*
 * main.h
 *
 * Main module of the "CameraShutterTimer" firmware.
 *
 * This source code implements an hardware intervalometer for Nikon cameras.
 * It interfaces the camera the same way as an ML-L3 infrared remote control
 * but instead of having the single functionality of triggering the camera
 * upon the press of the button, it also provides timed shooting for timelapse
 * photography.
 *
 * This source code is accompanied with an application schematic diagram to
 * help in the construction of a complete unit using the PIC12F683 microcontroller
 * and this firmware.
 *
 * The diagram below shows the pin mappings of the microntroller to this concrete
 * application:
 *
 *                       +---------------+
 *     +5V         -   --|(VDD)|   |(VSS)|--   - GND
 *                       |     \---/     |
 *     ENGAGED_LED <   --|(GP5)     (AN0)|--   < KNOB_POS
 *                       |               |
 *     N/A         -   --|(GP4)     (GP1)|--   > KNOB_BIAS
 *                       |               |
 *     START_BTN   >   --|(GP3)    (CCP1)|--   > IR_DIODE
 *                       +---------------+
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

#include "main.h"

void initSys(void) {
    TRISIO = 0b001101;          // enables GP0 (pin 7) as input (for ADC) and GP3 (pin 4) for
                                // the push button. GP2 is also set for preparing the PWM mode
                                // for this pin.

    ANSEL = 0b0010001;          // selected Fosc/8 (smallest value allowed for 4 MHz clock)
    ADCON0 = 0b10000001;        // selected right shifted conversion output,
                                // ADC channel 0 and enables ADC converter
    GPIO = 0;                   // reset GPIO bits

    // configure timer1:

    TMR1CS = 0; // select internal Fosc/4 clock source
    T1CONbits.T1CKPS = 0b11; // enable 1:8 prescale

    initIrCarrier();
}

void initIntervalometerTimer(int timeLimit) {
    TMR1ON = 0;
    TMR1IE = 0;
    TMR1IF = 0;

    PEIE = 1;
    GIE = 1;

    TMR1 = TMR1_OFFSET;
    
    timerCount = 1;
    shutterTimeLimit = timeLimit;

    TMR1IE = 1;

    // Enable timer1:

    TMR1ON = 1;
}



void initTimerFromKnobPos(unsigned char knobPosition) {
    switch(knobPosition) {
        case 1: // 1 hour period
            initIntervalometerTimer(_1_HOUR);
            break;
        case 2: // 30' period
            initIntervalometerTimer(_30_MINS);
            break;
        case 3: // 10' period
            initIntervalometerTimer(_10_MINS);
            break;
        case 4: // 3' period
            initIntervalometerTimer(_3_MINS);
            break;
        case 5: // 1' period
            initIntervalometerTimer(_1_MIN);
            break;
        case 6: // 30" period
            initIntervalometerTimer(_30_SECS);
            break;
        case 7: // 20" period
            initIntervalometerTimer(_20_SECS);
            break;
        case 8: // 10" period
            initIntervalometerTimer(_10_SECS);
            break;
        case 9: // 5" period
            initIntervalometerTimer(_5_SECS);
            break;
        case 10: // 2" period
            initIntervalometerTimer(_2_SECS);
            break;
        case 11: // 1" period
            initIntervalometerTimer(_1_SEC);
            break;
        default:
            break;
    }
}

void stopIntervalometerTimer(void) {
    TMR1ON = 0;
    TMR1IF = 0;
    TMR1IE = 0;
}

#pragma interrupt isr            // declare function as high priority isr

void interrupt isr(void) {
    TMR1IE = 0; // disable timer1 interrupts

    if(TMR1IF) {
        TMR1 = TMR1_OFFSET;

        if(timerCount < shutterTimeLimit)
            timerCount++;
        else {
            fireShutter();
            timerCount = 1;
        }

        TMR1IF = 0; // reset interrupt flag
        TMR1IE = 1; // re-enable timer0 interrupts
    }
}

void setGpioLeds(unsigned char value) {
    unsigned char gpio_shadow;

    gpio_shadow = GPIO;
    GPIO = (gpio_shadow & 0b11001001) | (((value & 0b1100) << 2) | ((value & 0b11) << 1));
}

int main(void) {
    unsigned char knobPosition;
    unsigned char isStarted;
    unsigned char ledBlinkTrack;
    int i;

    initSys();

    isStarted = 0;
    ledBlinkTrack = 0;

    for(i = 0; i < 3; i++) {
        setEngagedLed();
        __delay_ms(200);
        setTriggerLed();
        clearEngagedLed();
        __delay_ms(200);
        clearTriggerLed();
    }

    for(;;) {
        knobPosition = getKnobPosition();

        //setGpioLeds(knobPosition); // only for the test configuration

        if(knobPosition == 0) {
            stopIntervalometerTimer(); // disable the timer as we won't be using it in single shot mode
            isStarted = 0;

            if(isStartBtnPressed()) {
                fireShutter();
                setTriggerLed();
            }
            else {
                clearTriggerLed();
            }
        }
        else {
            if(isStarted) {
                if(ledBlinkTrack >= 5) {
                    setTriggerLed();
                    __delay_ms(5);
                    clearTriggerLed();
                }
            }

            if(isStartBtnPressed()) {
                if(isStarted) {
                    stopIntervalometerTimer();
                    isStarted = 0;
                    clearTriggerLed();
                }
                else {
                    initTimerFromKnobPos(knobPosition);
                    isStarted = 1;
                    setTriggerLed();
                }
            }
        }

        if(ledBlinkTrack >= 5) {
            setEngagedLed();
            __delay_ms(5);
            clearEngagedLed();
            ledBlinkTrack = 0;
        }
        else {
            ledBlinkTrack++;
            __delay_ms(5);
        }
        
        __delay_ms(195);
    }

    return 0;
}
