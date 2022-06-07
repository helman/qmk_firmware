/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define PRODUCT_ID      0x3537
#define DEVICE_VER      0x0001
#define PRODUCT         Dactyl-Manuform (5x7)

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }

#define DIODE_DIRECTION ROW2COL

// WS2812 RGB LED strip input and number of LEDs
#define RGB_DI_PIN D3
#define RGBLED_NUM 74
#define RGBLED_SPLIT { 37, 37 }

#define DRIVER_LED_TOTAL RGBLED_NUM

#ifdef RGB_MATRIX_ENABLE

#   define ENABLE_RGB_MATRIX_ALPHAS_MODS
#   define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_BAND_SAT
#   define ENABLE_RGB_MATRIX_BAND_VAL
#   define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#   define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#   define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#   define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#   define ENABLE_RGB_MATRIX_CYCLE_ALL
#   define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#   define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#   define ENABLE_RGB_MATRIX_DUAL_BEACON
#   define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#   define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#   define ENABLE_RGB_MATRIX_RAINDROPS
#   define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#   define ENABLE_RGB_MATRIX_HUE_BREATHING
#   define ENABLE_RGB_MATRIX_HUE_PENDULUM
#   define ENABLE_RGB_MATRIX_HUE_WAVE
#   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   define ENABLE_RGB_MATRIX_SPLASH
#   define ENABLE_RGB_MATRIX_MULTISPLASH
#   define ENABLE_RGB_MATRIX_SOLID_SPLASH
#   define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#   define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50

#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
//#define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
#   define RGB_DISABLE_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
#   define RGB_DISABLE_AFTER_TIMEOUT 0 // OBSOLETE: number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#   define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT // Sets the default mode, if none has been set
#   define RGB_MATRIX_STARTUP_HUE 0 // Sets the default hue value, if none has been set
#   define RGB_MATRIX_STARTUP_SAT 255 // Sets the default saturation value, if none has been set
#   define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#   define RGB_MATRIX_STARTUP_SPD 127 // Sets the default animation speed, if none has been set
//#define RGB_MATRIX_DISABLE_KEYCODES // disables control of rgb matrix by keycodes (must use code functions to control the feature)
#   define RGB_MATRIX_SPLIT RGBLED_SPLIT     // (Optional) For split keyboards, the number of LEDs connected on each half. X = left, Y = Right.
#   define SPLIT_TRANSPORT_MIRROR

#endif

// define all of this if rgb light is enabled
#ifdef RGBLIGHT_ENABLE

#   define RGBLIGHT_ANIMATIONS
#   define RGBLIGHT_LIMIT_VAL 100
#   define RGBLIGHT_HUE_STEP 5
#   define RGBLIGHT_SAT_STEP 5
#   define RGBLIGHT_VAL_STEP 5
#   define RGBLIGHT_SLEEP
#   define RGBLIGHT_SPLIT
#   define RGBLIGHT_DEFAULT_MODE 14

// Enable Light Layers implementation
#   define RGBLIGHT_LAYERS
// Allow Light Layers to override RGB off configuration
#   define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#   define LED_LAYOUT( \
  L11, L12, L13, L14, L15, L16, L17,       R11, R12, R13, R14, R15, R16, R17, \
  L21, L22, L23, L24, L25, L26, L27,       R21, R22, R23, R24, R25, R26, R27, \
  L31, L32, L33, L34, L35, L36, L37,       R31, R32, R33, R34, R35, R36, R37, \
  L41, L42, L43, L44, L45, L46,                 R41, R42, R43, R44, R45, R46, \
  L51, L52, L53, L54,                                     R51, R52, R53, R54, \
                 L55, L56,                           R55, R56, \
                      L61, L62,                 R61, R62, \
                      L63, L64,                 R63, R64 ) \
  { \
  L17, L16, L15, L14, L13, L12, L11, \
  L27, L26, L25, L24, L23, L22, L21, \
  L37, L36, L35, L34, L33, L32, L31, \
  L46, L45, L44, L43, L42, L41, \
  L56, L55, L54, L53, \
                 L52, L51, \
                      L62, L61, \
                      L64, L63, \
  R17, R16, R15, R14, R13, R12, R11, \
  R27, R26, R25, R24, R23, R22, R21, \
  R37, R36, R35, R34, R33, R32, R31, \
       R46, R45, R44, R43, R42, R41, \
                 R56, R55, R54, R53, \
            R52, R51, \
       R62, R61, \
       R64, R63 \
  }

#   define RGBLIGHT_LED_MAP LED_LAYOUT( \
   6,  5,  4,  3,  2,  1,  0,      13, 12, 11, 10,  9,  8,  7, \
  21, 22, 23, 24, 25, 26, 27,      14, 15, 16, 17, 18, 19, 20, \
  34, 33, 32, 31, 30, 29, 28,      41, 40, 39, 38, 37, 36, 35, \
  48, 49, 50, 51, 52, 53,              42, 43, 44, 45, 46, 47, \
  59, 58, 57, 56,                              73, 72, 71, 70, \
              55, 54,                      69, 68, \
                  62, 61,              67, 64, \
                  63, 60,              66, 65 )

#endif
