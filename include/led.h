#ifndef __LED_H
#define __LED_H

#include	"config.h"

sbit light_pin   = P0^1;
sbit water_pin   = P0^0;
sbit mode_pin    = P3^3;

#define LIGHT_ON()      light_pin   = 0
#define LIGHT_OFF()     light_pin   = 1

#define WATER_ON()      water_pin   = 0
#define WATER_OFF()     water_pin   = 1
#endif