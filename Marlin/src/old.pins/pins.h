/*
 * Describes Taz 5 motherboard (301).
 * Jess Sullivan
 *
 **/
#pragma once
#include "../core/boards.h"
/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef PINS_H
#define PINS_H

#if MOTHERBOARD == 301
#define KNOWN_BOARD

/*****************************************************************
* Rambo Pin Assignments
******************************************************************/

#ifndef __AVR_ATmega2560__
#error Oops!  Make sure you have 'Arduino Mega 2560' selected from the 'Tools -> Boards' menu.
#endif

#define LARGE_FLASH true

#define X_STEP_PIN 37
#define X_DIR_PIN 48
#define X_MIN_PIN 12
#define X_MAX_PIN 24
#define X_ENABLE_PIN 29
#define X_MS1_PIN 40
#define X_MS2_PIN 41

#define Y_STEP_PIN 36
#define Y_DIR_PIN 49
#define Y_MIN_PIN 11
#define Y_MAX_PIN 23
#define Y_ENABLE_PIN 28
#define Y_MS1_PIN 69
#define Y_MS2_PIN 39

#define Z_STEP_PIN 35
#define Z_DIR_PIN 47
#define Z_MIN_PIN 10
#define Z_MAX_PIN 30
#define Z_ENABLE_PIN 27
#define Z_MS1_PIN 68
#define Z_MS2_PIN 67

#define HEATER_BED_PIN 3
#define TEMP_BED_PIN 2

#define HEATER_0_PIN  9
#define TEMP_0_PIN 0

#define HEATER_1_PIN 7
#define TEMP_1_PIN 1

#ifdef BARICUDA
#define HEATER_2_PIN 6
#else
#define HEATER_2_PIN -1
#endif
#define TEMP_2_PIN -1

#define E0_STEP_PIN         34
#define E0_DIR_PIN          43
#define E0_ENABLE_PIN       26
#define E0_MS1_PIN 65
#define E0_MS2_PIN 66

#define E1_STEP_PIN         33
#define E1_DIR_PIN          42
#define E1_ENABLE_PIN       25
#define E1_MS1_PIN 63
#define E1_MS2_PIN 64

#define DIGIPOTSS_PIN -1
#define DIGIPOT_CHANNELS {4,5,3,0,1} // X Y Z E0 E1 digipot channels to stepper driver mapping

#define SDPOWER_PIN            -1
#define SDSS               53
#define LED_PIN            13
#define FAN0_PIN           8  //Fan0 --- Extruer0 Fan
#define FAN1_PIN           6  //Fan1 --- Extruer0 Fan
#define FAN2_PIN           2  //Fan2 --- Case Fan
#define PS_ON_PIN          4
#define KILL_PIN           -1 //80 with Smart Controller LCD
#define SUICIDE_PIN        -1  //PIN that has to be turned on right after start, to keep power flowing.

#ifdef ULTRA_LCD
  #define KILL_PIN 80
  #ifdef NEWPANEL
   //arduino pin which triggers an piezzo BEEPER_PIN_PIN
    #define BEEPER_PIN_PIN 79      // BEEPER_PIN_PIN on AUX-4
    #define LCD_PINS_RS 70
    #define LCD_PINS_ENABLE 71
    #define LCD_PINS_D4 72
    #define LCD_PINS_D5 73
    #define LCD_PINS_D6 74
    #define LCD_PINS_D7 75

    //buttons are directly attached using AUX-2
    #define BTN_EN1 76
    #define BTN_EN2 77
    #define BTN_ENC 78  //the click

    #define BLEN_C 2
    #define BLEN_B 1
    #define BLEN_A 0

    #define SD_DETECT_PIN 81    // Ramps does not use this port

    //encoder rotation values
    #define encrot0 0
    #define encrot1 2
    #define encrot2 3
    #define encrot3 1
  #else //old style panel with shift register
    //arduino pin witch triggers an piezzo BEEPER_PIN_PIN
    #define BEEPER_PIN_PIN 33    No BEEPER_PIN_PIN added
    //buttons are attached to a shift register
    // Not wired this yet
    // #define SHIFT_CLK 38
    // #define SHIFT_LD 42
    // #define SHIFT_OUT 40
    // #define SHIFT_EN 17

    #define LCD_PINS_RS 75
    #define LCD_PINS_ENABLE 17
    #define LCD_PINS_D4 23
    #define LCD_PINS_D5 25
    #define LCD_PINS_D6 27
    #define LCD_PINS_D7 29

    //encoder rotation values
    #define encrot0 0
    #define encrot1 2
    #define encrot2 3
    #define encrot3 1

    //bits in the shift register that carry the buttons for:
    // left up center down right red
    #define BL_LE 7
    #define BL_UP 6
    #define BL_MI 5
    #define BL_DW 4
    #define BL_RI 3
    #define BL_ST 2
    #define BLEN_B 1
    #define BLEN_A 0
  #endif
#endif //ULTRA_LCD


#endif

#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, PS_ON_PIN, \
                        HEATER_BED_PIN, FAN_PIN,                  \
                        _E0_PINS _E1_PINS _E2_PINS             \
                        analogInputToDigitalPin(TEMP_0_PIN), analogInputToDigitalPin(TEMP_1_PIN), analogInputToDigitalPin(TEMP_2_PIN), analogInputToDigitalPin(TEMP_BED_PIN) }
#endif


