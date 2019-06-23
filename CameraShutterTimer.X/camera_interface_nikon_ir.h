/*
 * File:   camera_interface_nikon_ir.c
 *
 * Driver for the camera control via IR. Check main.c for information about
 * the pin mappings and camera_interface_nikon_ir.c for details about the
 * implementation and the protocol.
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

#ifndef CAMERA_INTERFACE_NIKON_IR_H
#define	CAMERA_INTERFACE_NIKON_IR_H

#include <pic12f683.h>
#include "pic.h"

#include "common.h"

#define CARRIER_PERIOD      25
#define CARRIER_DUTY        52
#define NUM_BURSTS          15

unsigned short delays[NUM_BURSTS] = {69, 1008, 12, 54, 12, 123, 12, 2313, 69, 1008, 12, 54, 12, 123, 12};

/**
 * Produces the sequence of bursts of the 38 KHz carrier that correspond to the
 * shutter command.
 */
void fireShutter(void);

/**
 * Initializes the PWM module for generating the 38 KHz carrier.
 */
void initIrCarrier(void);

#endif	/* CAMERA_INTERFACE_NIKON_IR_H */

