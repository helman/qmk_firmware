#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1
#define _NUMPAD 2
#define _BLANK  3

// Some basic macros
#define TASK    LCTL(LSFT(KC_ESC))
#define TAB_R   LCTL(KC_TAB)
#define TAB_L   LCTL(LSFT(KC_TAB))
#define TAB_RO  LCTL(LSFT(KC_T))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_5x7(
  // left hand
   KC_GRV,        KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_VOLD,
   KC_TAB,        KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_MUTE,
   LT(_FN,KC_ESC),  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_LBRC,
   KC_LSFT,       KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
   KC_LCTL,       KC_ESC,   ,  TT(_FN),
                               KC_BSPC, KC_SPC,
                               KC_LALT, KC_END,
                               KC_LGUI, KC_HOME,
        // right hand
                     KC_VOLU, KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,
                     KC_EQL,  KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
                     KC_RBRC, KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                              KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  OSM(MOD_RSFT),
                                                KC_LEFT, KC_DOWN,   KC_UP,    KC_RGHT,
        KC_SPC, KC_ENT,
        KC_PGUP, KC_RALT,
        KC_PGDN, KC_LGUI),

[_FN] = LAYOUT_5x7(
  // left hand
   KC_TRNS,   KC_F1,     KC_F2,      KC_F3,    KC_F4,    KC_F5,    KC_F6,
   _______,   _______,   _______,    KC_UP,    KC_NO,    RGB_SPI,  RGB_VAI,
   _______,   _______,   KC_LEFT,    KC_DOWN,  KC_RGHT,  RGB_SPD,  RGB_VAD,
   _______,   _______,   _______,   _______,   KC_NO,    KC_NO,
   KC_MSTP,   KC_MPLY,   KC_MPRV,   KC_MNXT,
                               RGB_TOG, _______,
                               _______, _______,
                               _______, _______,
        // right hand
                     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NO,
                     RGB_MOD,   RGB_RMOD,  RGB_SAI,   RGB_SAD,   RGB_HUI,   RGB_HUD,   KC_NO,
                     RGB_TOG,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_NO,     KC_NO,
                                RGB_M_P,   RGB_M_B,   RGB_M_R,   RGB_M_SW,  RGB_M_SN,  KC_NO,
                                                      RGB_M_K,   RGB_M_X,   RGB_M_G,   RGB_M_T,
        KC_DEL, _______,
        _______, _______,
        _______, _______),

[_NUMPAD] = LAYOUT_5x7(
  // left hand
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,
   _______,   _______,   _______,   _______,
                               _______, _______,
                               _______, _______,
                               _______, _______,
        // right hand
                     _______,   _______,   KC_NLCK,   _______,   KC_PMNS,   KC_PPLS,   _______,
                     _______,   _______,   KC_P7,     KC_P8,     KC_P9,     _______,   _______,
                     _______,   _______,   KC_P4,     KC_P5,     KC_P6,     KC_PAST,   _______,
                                _______,   KC_P1,     KC_P2,     KC_P3,     KC_PSLS,   _______,
                                                      KC_P0,     KC_PDOT,   _______,   _______,
        _______, KC_PENT,
        _______, _______,
        _______, _______),

[_BLANK] = LAYOUT_5x7(
  // left hand
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,
   _______,   _______,   _______,   _______,
                               _______, _______,
                               _______, _______,
                               _______, _______,
        // right hand
                     _______,   _______,   _______,   _______,   _______,   _______,   _______,
                     _______,   _______,   _______,   _______,   _______,   _______,   _______,
                     _______,   _______,   _______,   _______,   _______,   _______,   _______,
                                _______,   _______,   _______,   _______,   _______,   _______,
                                                      _______,   _______,   _______,   _______,
        _______, _______,
        _______, _______,
        _______, _______),


};
