EESchema Schematic File Version 2  date 01-09-2014 0:11:34
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:CustomComponents
LIBS:CameraShutterTimer-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title "Camera Shutter Timer Circuit"
Date "31 aug 2014"
Rev "1.0"
Comp "Creation Factory"
Comment1 "by Luis Teixeira - 2012"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5100 4000 5000 4000
Wire Wire Line
	5000 3250 5000 4000
Wire Wire Line
	4400 3250 5000 3250
Wire Wire Line
	4600 4350 4600 3300
Wire Wire Line
	4600 3300 5100 3300
Wire Wire Line
	5100 3700 4900 3700
Wire Wire Line
	4500 3250 4500 2800
Wire Wire Line
	3700 2750 3700 3450
Wire Wire Line
	8550 3450 8550 3200
Wire Wire Line
	8550 3450 8100 3450
Wire Wire Line
	8100 3450 8100 3650
Wire Wire Line
	6550 3700 6550 3550
Connection ~ 7950 3550
Wire Wire Line
	8100 4150 7950 4150
Wire Wire Line
	7950 4150 7950 3550
Wire Wire Line
	8100 3650 8350 3650
Connection ~ 8350 4150
Connection ~ 6950 3100
Wire Wire Line
	7250 3100 6750 3100
Wire Wire Line
	6750 3100 6750 3000
Wire Wire Line
	6750 3000 6550 3000
Wire Wire Line
	7250 3000 7050 3000
Wire Wire Line
	7050 3000 7050 1850
Wire Wire Line
	7050 1850 10500 1850
Connection ~ 10500 4150
Wire Wire Line
	10500 1850 10500 4150
Wire Wire Line
	7250 2800 7250 2050
Wire Wire Line
	7250 2050 10000 2050
Connection ~ 10000 4150
Wire Wire Line
	10000 2050 10000 4150
Connection ~ 9500 4150
Wire Wire Line
	7950 2450 9500 2450
Wire Wire Line
	9500 2450 9500 4150
Connection ~ 9000 4150
Wire Wire Line
	8450 2900 9000 2900
Wire Wire Line
	9000 2900 9000 4150
Wire Wire Line
	10100 3650 10350 3650
Wire Wire Line
	9600 3650 9850 3650
Wire Wire Line
	9100 3650 9350 3650
Wire Wire Line
	8600 3650 8850 3650
Connection ~ 6950 4300
Wire Wire Line
	6950 4300 7150 4300
Wire Wire Line
	7150 4300 7150 4150
Connection ~ 5100 2250
Wire Wire Line
	5100 3000 5100 2250
Connection ~ 4200 2250
Connection ~ 1650 2250
Wire Wire Line
	1800 2250 1150 2250
Wire Wire Line
	1150 2250 1150 2650
Connection ~ 2200 2750
Wire Wire Line
	1650 2250 1650 2350
Wire Wire Line
	2200 2550 2200 2950
Wire Wire Line
	2700 2250 2700 2350
Wire Wire Line
	2700 2750 1650 2750
Connection ~ 2700 2250
Wire Wire Line
	3700 2350 3700 2250
Connection ~ 4500 2250
Wire Wire Line
	4500 2300 4500 2250
Wire Wire Line
	6550 3300 7250 3300
Wire Wire Line
	7150 3300 7150 3650
Connection ~ 7150 3300
Wire Wire Line
	8850 4150 9100 4150
Wire Wire Line
	9600 4150 9350 4150
Wire Wire Line
	9850 4150 10100 4150
Wire Wire Line
	10350 4150 10600 4150
Wire Wire Line
	8550 3200 8450 3200
Wire Wire Line
	8850 3650 8850 3000
Wire Wire Line
	8850 3000 8450 3000
Wire Wire Line
	9350 3650 9350 2800
Wire Wire Line
	9350 2800 8450 2800
Wire Wire Line
	9850 3650 9850 2150
Wire Wire Line
	9850 2150 7750 2150
Wire Wire Line
	7750 2150 7750 2450
Wire Wire Line
	10350 3650 10350 1950
Wire Wire Line
	10350 1950 7150 1950
Wire Wire Line
	7150 1950 7150 2900
Wire Wire Line
	7150 2900 7250 2900
Wire Wire Line
	10600 1750 6950 1750
Wire Wire Line
	10600 1750 10600 3650
Wire Wire Line
	6950 1750 6950 4450
Wire Wire Line
	8600 4150 8350 4150
Wire Wire Line
	8500 4150 8500 3550
Connection ~ 8500 4150
Wire Wire Line
	8500 3550 8650 3550
Wire Wire Line
	8650 3550 8650 3100
Wire Wire Line
	8650 3100 8450 3100
Wire Wire Line
	5100 2250 2600 2250
Wire Wire Line
	6550 3550 8450 3550
Wire Wire Line
	8450 3550 8450 3300
Connection ~ 4500 3250
Wire Wire Line
	3750 3250 3700 3250
Connection ~ 3700 3250
Wire Wire Line
	4900 3700 4900 4350
Wire Wire Line
	6550 4000 6550 5700
Wire Wire Line
	6550 5700 6650 5700
$Comp
L GND #PWR?
U 1 1 5403AA9A
P 7450 5900
F 0 "#PWR?" H 7450 5900 30  0001 C CNN
F 1 "GND" H 7450 5830 30  0001 C CNN
	1    7450 5900
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 5403AA5A
P 7450 4800
F 0 "D3" H 7450 4900 50  0000 C CNN
F 1 "IR DIODE" H 7450 4700 50  0000 C CNN
	1    7450 4800
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR?
U 1 1 5403AA09
P 7450 4600
F 0 "#PWR?" H 7450 4690 20  0001 C CNN
F 1 "+5V" H 7450 4690 30  0000 C CNN
	1    7450 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F540413
P 3700 3450
F 0 "#PWR?" H 3700 3450 30  0001 C CNN
F 1 "GND" H 3700 3380 30  0001 C CNN
	1    3700 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F54033E
P 4900 5250
F 0 "#PWR?" H 4900 5250 30  0001 C CNN
F 1 "GND" H 4900 5180 30  0001 C CNN
	1    4900 5250
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 4F54032C
P 4900 5050
F 0 "D2" H 4900 5150 50  0000 C CNN
F 1 "FOCUS_LED" H 4900 4950 50  0000 C CNN
	1    4900 5050
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 4F5402F0
P 4900 4600
F 0 "R8" V 4980 4600 50  0000 C CNN
F 1 "1K" V 4900 4600 50  0000 C CNN
	1    4900 4600
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 4F540158
P 7450 5250
F 0 "R5" V 7530 5250 50  0000 C CNN
F 1 "160R" V 7450 5250 50  0000 C CNN
	1    7450 5250
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 4F540110
P 6900 5700
F 0 "R4" V 6980 5700 50  0000 C CNN
F 1 "1K" V 6900 5700 50  0000 C CNN
	1    6900 5700
	0    -1   -1   0   
$EndComp
$Comp
L BC237 Q1
U 1 1 4F5400E1
P 7350 5700
F 0 "Q1" H 7550 5600 50  0000 C CNN
F 1 "2N2222" H 7600 5850 50  0000 C CNN
F 2 "TO92-EBC" H 7540 5700 30  0001 C CNN
	1    7350 5700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F540052
P 4600 5250
F 0 "#PWR?" H 4600 5250 30  0001 C CNN
F 1 "GND" H 4600 5180 30  0001 C CNN
	1    4600 5250
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 4F54003A
P 4600 5050
F 0 "D1" H 4600 5150 50  0000 C CNN
F 1 "ACTIVITY_LED" H 4600 4950 50  0000 C CNN
	1    4600 5050
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 4F53FF7C
P 4600 4600
F 0 "R3" V 4680 4600 50  0000 C CNN
F 1 "1K" V 4600 4600 50  0000 C CNN
	1    4600 4600
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 4F53FE69
P 8100 3900
F 0 "R9" V 8180 3900 50  0000 C CNN
F 1 "470R" V 8100 3900 50  0000 C CNN
	1    8100 3900
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 4F53FC2B
P 8350 3900
F 0 "R10" V 8430 3900 50  0000 C CNN
F 1 "470R" V 8350 3900 50  0000 C CNN
	1    8350 3900
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 4F53FC1C
P 8600 3900
F 0 "R11" V 8680 3900 50  0000 C CNN
F 1 "470R" V 8600 3900 50  0000 C CNN
	1    8600 3900
	1    0    0    -1  
$EndComp
$Comp
L R R19
U 1 1 4F53FC17
P 10600 3900
F 0 "R19" V 10680 3900 50  0000 C CNN
F 1 "470R" V 10600 3900 50  0000 C CNN
	1    10600 3900
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 4F53FC13
P 10350 3900
F 0 "R18" V 10430 3900 50  0000 C CNN
F 1 "470R" V 10350 3900 50  0000 C CNN
	1    10350 3900
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 4F53FC0F
P 10100 3900
F 0 "R17" V 10180 3900 50  0000 C CNN
F 1 "470R" V 10100 3900 50  0000 C CNN
	1    10100 3900
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 4F53FC0A
P 9850 3900
F 0 "R16" V 9930 3900 50  0000 C CNN
F 1 "470R" V 9850 3900 50  0000 C CNN
	1    9850 3900
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 4F53FC07
P 9600 3900
F 0 "R15" V 9680 3900 50  0000 C CNN
F 1 "470R" V 9600 3900 50  0000 C CNN
	1    9600 3900
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 4F53FC03
P 9350 3900
F 0 "R14" V 9430 3900 50  0000 C CNN
F 1 "470R" V 9350 3900 50  0000 C CNN
	1    9350 3900
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 4F53FC00
P 9100 3900
F 0 "R13" V 9180 3900 50  0000 C CNN
F 1 "470R" V 9100 3900 50  0000 C CNN
	1    9100 3900
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 4F53FBF9
P 8850 3900
F 0 "R12" V 8930 3900 50  0000 C CNN
F 1 "470R" V 8850 3900 50  0000 C CNN
	1    8850 3900
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 4F53FB96
P 7150 3900
F 0 "R2" V 7230 3900 50  0000 C CNN
F 1 "100K" V 7150 3900 50  0000 C CNN
	1    7150 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F53FB43
P 6950 4450
F 0 "#PWR?" H 6950 4450 30  0001 C CNN
F 1 "GND" H 6950 4380 30  0001 C CNN
	1    6950 4450
	1    0    0    -1  
$EndComp
$Comp
L 12POS_SWITCH SW3
U 1 1 4F53FACA
P 7850 3050
F 0 "SW3" H 7950 3400 60  0000 C CNN
F 1 "12POS_SWITCH" H 7850 2351 60  0000 C CNN
	1    7850 3050
	-1   0    0    1   
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 4F53F776
P 4100 3250
F 0 "SW2" H 4250 3360 50  0000 C CNN
F 1 "SHUTTER_START" H 4100 3170 50  0000 C CNN
	1    4100 3250
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 4F53F69C
P 4500 2550
F 0 "R1" V 4580 2550 50  0000 C CNN
F 1 "10K" V 4500 2550 50  0000 C CNN
	1    4500 2550
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 4F53F5E9
P 3700 2550
F 0 "C3" H 3750 2650 50  0000 L CNN
F 1 "0.1uF" H 3750 2450 50  0000 L CNN
	1    3700 2550
	1    0    0    -1  
$EndComp
$Comp
L PIC12F683 U2
U 1 1 4F53F5B6
P 5850 3500
F 0 "U2" H 5850 4200 60  0000 C CNN
F 1 "PIC12F683" H 5850 2850 60  0000 C CNN
	1    5850 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F53F594
P 1150 4300
F 0 "#PWR?" H 1150 4300 30  0001 C CNN
F 1 "GND" H 1150 4230 30  0001 C CNN
	1    1150 4300
	1    0    0    -1  
$EndComp
$Comp
L SPST SW1
U 1 1 4F53F56D
P 1150 3150
F 0 "SW1" H 1150 3250 70  0000 C CNN
F 1 "POWER" H 1150 3050 70  0000 C CNN
	1    1150 3150
	0    -1   -1   0   
$EndComp
$Comp
L BATTERY BT1
U 1 1 4F53F52B
P 1150 4000
F 0 "BT1" H 1150 4200 50  0000 C CNN
F 1 "9V BATTERY" H 1150 3810 50  0000 C CNN
	1    1150 4000
	0    1    1    0   
$EndComp
$Comp
L C C2
U 1 1 4F53F4B1
P 2700 2550
F 0 "C2" H 2750 2650 50  0000 L CNN
F 1 "10nF" H 2750 2450 50  0000 L CNN
	1    2700 2550
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 4F53F4AC
P 1650 2550
F 0 "C1" H 1700 2650 50  0000 L CNN
F 1 "330nF" H 1700 2450 50  0000 L CNN
	1    1650 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F53F496
P 2200 2950
F 0 "#PWR?" H 2200 2950 30  0001 C CNN
F 1 "GND" H 2200 2880 30  0001 C CNN
	1    2200 2950
	1    0    0    -1  
$EndComp
$Comp
L 78L05 U1
U 1 1 4F53F482
P 2200 2300
F 0 "U1" H 2350 2104 60  0000 C CNN
F 1 "78L05" H 2200 2500 60  0000 C CNN
	1    2200 2300
	1    0    0    -1  
$EndComp
$EndSCHEMATC
