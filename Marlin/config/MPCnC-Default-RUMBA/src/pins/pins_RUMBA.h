/**
 ********************************************************************
 * MARLIN 2.0.x [13-04-2019] - MODIFICADO EL 09-06-2019-001 *
 *
 * ARCHIVOS MODIFICADOS:
 * 	- CONFIGURATION.H
 *	- CONFIGURATION_ADV.H
 *	- pins_RUMBA.h
 *
 * ARCHIVOS AÑADIDOS:
 * 	- _Bootscreen.h
 *
 ********************************************************************
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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
 * RUMBA pin assignments
 */

#ifndef __AVR_ATmega2560__
  #error "Oops! Select 'Arduino/Genuino Mega or Mega 2560' in 'Tools > Board.'"
#endif

#if HOTENDS > 3 || E_STEPPERS > 3
  #error "RUMBA supports up to 3 hotends / E-steppers. Comment out this line to continue."
#endif

#ifndef DEFAULT_MACHINE_NAME
  #define DEFAULT_MACHINE_NAME "Rumba"
#endif
#ifndef BOARD_NAME
  #define BOARD_NAME "Rumba"
#endif

//
// Servos
//
#define SERVO0_PIN          5

//
// Limit Switches
//
#define X_MIN_PIN          37
#define X_MAX_PIN          36
#define Y_MIN_PIN          35
#define Y_MAX_PIN          34
#define Z_MIN_PIN          33
#define Z_MAX_PIN          32

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  32
#endif

//
// Steppers
//
/** 
 * MPCnC.Mx usa doble motor, doble driver y doble Final de Carrera (FdC) en los ejes X (X1-X2) e Y (Y1-Y2)
 * para ello se hace valer de los drivers destinados a los extrusores (inecesarios en una CNC) quedando la
 * siguiente distribución:
 * 
 * Motor X1 --> Driver X
 * Motor X2 --> Driver E1
 * Motor Y1 --> Driver Y
 * Motor Y2 --> Driver E2
 * Motor Z  --> Driver Z
 * 
 * *Marlín por defecto no permite la NO existencia de un Extrusor y da erroes al compilar así que para las
 * placas con solo 5 Drivers se crearia un E0 Virtual de la siguiente manera:
 * 
 * // CONFIGURA UN EXTRUSOR "VIRTUAL"
 * #define E0_STEP_PIN        70
 * #define E0_DIR_PIN         70
 * #define E0_ENABLE_PIN      70
 * #ifndef E0_CS_PIN
 *   #define E0_CS_PIN        70
 * #endif
 *
 * Para las placas con 6 o mas Drivers se puede dejar tal cual, crearlo virtual, o desplazar a ultima
 * posición. En este caso el E0 se a virtualizado, E1 y E2 se han movido y se dejado el ultimo drivers
 * como un nuevo Driver (E3)
 */
 
 
/* BACKUP!!!!!!!
#define X_STEP_PIN         17
#define X_DIR_PIN          16
#define X_ENABLE_PIN       48

#define Y_STEP_PIN         54
#define Y_DIR_PIN          47
#define Y_ENABLE_PIN       55

#define Z_STEP_PIN         57
#define Z_DIR_PIN          56
#define Z_ENABLE_PIN       62

#ifndef E0_STEP_PIN
  #define E0_STEP_PIN      23
  #define E0_DIR_PIN       22
  #define E0_ENABLE_PIN    24
#endif

#ifndef E1_STEP_PIN
  #define E1_STEP_PIN      26
  #define E1_DIR_PIN       25
  #define E1_ENABLE_PIN    27
#endif

#if E1_STEP_PIN != 29
  #define E2_STEP_PIN      29
  #define E2_DIR_PIN       28
  #define E2_ENABLE_PIN    39
#endif
**/

#define X_STEP_PIN         17   // X1
#define X_DIR_PIN          16
#define X_ENABLE_PIN       48

#define Y_STEP_PIN         54   // Y1
#define Y_DIR_PIN          47
#define Y_ENABLE_PIN       55

#define Z_STEP_PIN         57   // Z
#define Z_DIR_PIN          56
#define Z_ENABLE_PIN       62

#ifndef E0_STEP_PIN             // Virtualización del Extrusor
  #define E0_STEP_PIN      70 //23
  #define E0_DIR_PIN       70 //22
  #define E0_ENABLE_PIN    70 //24
#endif

#ifndef E1_STEP_PIN             // X2
  #define E1_STEP_PIN      23 //26
  #define E1_DIR_PIN       22 //25
  #define E1_ENABLE_PIN    24 //27
#endif

#ifndef E2_STEP_PIN             // Y2
  #define E2_STEP_PIN      26 //29
  #define E2_DIR_PIN       25 //28
  #define E2_ENABLE_PIN    27 //39
#endif

#ifndef E3_STEP_PIN
  #define E3_STEP_PIN      29
  #define E3_DIR_PIN       28
  #define E3_ENABLE_PIN    39
#endif



//
// Temperature Sensors
//
#ifndef TEMP_0_PIN
  #if TEMP_SENSOR_0 == -1
    #define TEMP_0_PIN      6   // Analog Input (connector *K1* on RUMBA thermocouple ADD ON is used)
  #else
    #define TEMP_0_PIN     15   // Analog Input (default connector for thermistor *T0* on rumba board is used)
  #endif
#endif

#ifndef TEMP_1_PIN
  #if TEMP_SENSOR_1 == -1
    #define TEMP_1_PIN      5   // Analog Input (connector *K2* on RUMBA thermocouple ADD ON is used)
  #else
    #define TEMP_1_PIN     14   // Analog Input (default connector for thermistor *T1* on rumba board is used)
  #endif
#endif

#if TEMP_SENSOR_2 == -1
  #define TEMP_2_PIN        7   // Analog Input (connector *K3* on RUMBA thermocouple ADD ON is used <-- this can't be used when TEMP_SENSOR_BED is defined as thermocouple)
#else
  #define TEMP_2_PIN       13   // Analog Input (default connector for thermistor *T2* on rumba board is used)
#endif

// Optional for extruder 4 or chamber:
//#define TEMP_X_PIN         12   // Analog Input (default connector for thermistor *T3* on rumba board is used)
//#define TEMP_CHAMBER_PIN   12   // Analog Input (default connector for thermistor *T3* on rumba board is used)

#if TEMP_SENSOR_BED == -1
  #define TEMP_BED_PIN      7   // Analog Input (connector *K3* on RUMBA thermocouple ADD ON is used <-- this can't be used when TEMP_SENSOR_2 is defined as thermocouple)
#else
  #define TEMP_BED_PIN     11   // Analog Input (default connector for thermistor *THB* on rumba board is used)
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN        2
#define HEATER_1_PIN        3
#define HEATER_2_PIN        6
#define HEATER_3_PIN        8
#define HEATER_BED_PIN      9

#ifndef FAN_PIN
  #define FAN_PIN           7
#endif
#define FAN1_PIN            8

//
// Misc. Functions
//
#define LED_PIN            13
#define PS_ON_PIN          45
#define KILL_PIN           46
#define CASE_LIGHT_PIN     45

//
// M3/M4/M5 - Spindle/Laser Control
//
#ifndef SPINDLE_LASER_PWM_PIN
  #define SPINDLE_LASER_PWM_PIN 4   // MUST BE HARDWARE PWM. Pin 4 interrupts OC0* and OC1* always in use?
#endif
#ifndef SPINDLE_LASER_ENA_PIN
  #define SPINDLE_LASER_ENA_PIN    14   // Pin should have a pullup!
#endif
#ifndef SPINDLE_DIR_PIN
  #define SPINDLE_DIR_PIN  15
#endif

//
// LCD / Controller
//
#if EITHER(MKS_12864OLED, MKS_12864OLED_SSD1306)
  #define LCD_PINS_DC      38   // Set as output on init
  #define LCD_PINS_RS      41   // Pull low for 1s to init
  // DOGM SPI LCD Support
  #define DOGLCD_CS        19
  #define DOGLCD_MOSI      42
  #define DOGLCD_SCK       18
  #define DOGLCD_A0        LCD_PINS_DC
#else
  #define LCD_PINS_RS      19
  #define LCD_PINS_ENABLE  42
  #define LCD_PINS_D4      18
  #define LCD_PINS_D5      38
  #define LCD_PINS_D6      41
#endif

#define LCD_PINS_D7        40

//
// Beeper, SD Card, Encoder
//
#define BEEPER_PIN         44

#if ENABLED(SDSUPPORT)
  #define SDPOWER          -1
  #define SDSS             53
  #define SD_DETECT_PIN    49
#endif

#if ENABLED(NEWPANEL)
  #define BTN_EN1          11
  #define BTN_EN2          12
  #define BTN_ENC          43
#endif
