# Camera Shutter Timer

## Description

This source code implements an hardware intervalometer for Nikon cameras.

It interfaces the camera the same way as an ML-L3 infrared remote control but instead of having the single functionality of triggering the camera upon the press of the button, it also provides timed shooting for timelapse photography.

This source code is accompanied with an application schematic diagram to help in the construction of a complete unit using the PIC12F683 microcontroller and this firmware.

## Features

* Timed shooting from 1 second to 1h between shots;
* Virtually illimited number of shots (only limited to power availability and camera power and space constraints);
* Normal shooting mode, in order to use like the ML-L3 adaptor;
* At least 3 meter range with a standard 5 mm IR diode;
* Simple interface with a convenient rotary knob to alternate between time settings;

## How to build

* Install the [MPLAB X IDE][1]
* Open the CameraShutterTimer.X project;
* Connect a PICKit, MPLAB ICE or similar device to the computer;
* Insert the PIC12F683 into the socket for programming, and click "Make and Program Device Main Project";
* Place the PIC back into the circuit board;
* Test the device.

## Schematic diagram

![Alt](/diagrams/CameraShutterTimer.PNG "Schematic Diagram")

## Sample board assembly and enclosure

![Alt](/photos/intervalometer_external_view.jpg "External View")
![Alt](/photos/intervalometer_internal_view_01.jpg "Internal View - PCB back")
![Alt](/photos/intervalometer_internal_view_02.jpg "Internal View - PCB top")

## Notes

1. The resistors should ideally be of low tolerance. Otherwise some tuning and calibration of the constants may be required (see the constants KNOB_VAL_STEP and EDGE_CAL_FACTOR in the user_interface.h file)

