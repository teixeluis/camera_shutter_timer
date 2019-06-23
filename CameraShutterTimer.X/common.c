/**
 * common.h
 *
 * Common definitions used in the project
 *
 * Author: Luis Teixeira (teixeluis@gmail.com)
 *
 * February 2012
 *
 **/

#include "common.h"

unsigned short readADC(void) {
    ADCON0 |= 0b10;

    //GO_nDONE = 1;
    while(ADCON0 & 0b10)
        ;
    
    return (((unsigned short) ADRESH) << 8) | ADRESL;
}