/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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

/**
 * AZTEEG_X3 Arduino Mega with RAMPS v1.4 pin assignments
 */

#ifndef __AVR_ATmega2560__
  #error "Oops! Make sure you have 'Arduino Mega 2560' selected from the 'Tools -> Boards' menu."
#endif

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Azteeg X3 supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_NAME "Azteeg X3"

#if !PIN_EXISTS(CASE_LIGHT)         // doesn't already exist so OK to change the definition coming
  #define OK_TO_CHANGE_CASE_LIGHT   // in from from the include file
#endif

#include "pins_RAMPS_13.h"

//
// Servos
//
#undef SERVO0_PIN
#undef SERVO1_PIN
#define SERVO0_PIN  44  // SERVO1 port
#define SERVO1_PIN  55  // SERVO2 port

//
// LCD / Controller
//
#if ENABLED(VIKI2) || ENABLED(miniVIKI)

  #undef DOGLCD_A0
  #undef DOGLCD_CS
  #undef BTN_ENC
  #define DOGLCD_A0         31
  #define DOGLCD_CS         32
  #define BTN_ENC           12

  #undef STAT_LED_RED_PIN
  #undef STAT_LED_BLUE_PIN
  #define STAT_LED_RED_PIN  64
  #define STAT_LED_BLUE_PIN 63

#else

  #define STAT_LED_RED_PIN   6
  #define STAT_LED_BLUE_PIN 11

#endif

//
// Misc
//
#if ENABLED(OK_TO_CHANGE_CASE_LIGHT) && STAT_LED_RED_PIN == 6
  #undef STAT_LED_RED_PIN
  #undef CASE_LIGHT_PIN
  #define CASE_LIGHT_PIN 6  // open collector FET driver
#endif

//
// M3/M4/M5 - Spindle/Laser Control
//
#undef SPINDLE_LASER_PWM_PIN    // Definitions in pins_RAMPS.h are no good with the AzteegX3 board
#undef SPINDLE_LASER_ENABLE_PIN
#undef SPINDLE_DIR_PIN

#if ENABLED(SPINDLE_LASER_ENABLE)
  #undef SDA                       // use EXP3 header
  #undef SCL
  #if SERVO0_PIN == 7
    #undef SERVO0_PIN
    #def SERVO0_PIN 11
  #define SPINDLE_LASER_PWM_PIN     7  // MUST BE HARDWARE PWM
  #define SPINDLE_LASER_ENABLE_PIN 20  // Pin should have a pullup!
  #define SPINDLE_DIR_PIN          21
#endif
