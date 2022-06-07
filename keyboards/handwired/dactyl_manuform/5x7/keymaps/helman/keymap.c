#include QMK_KEYBOARD_H
#include "rgb.h"
#include "rgb_matrix_types.h"


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
   KC_LCTL,       KC_ESC,   LGUI(LALT(KC_EJCT)),  MO(_FN),
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
   _______,   KC_NO,   KC_NO,    KC_UP,    KC_NO,    RGB_SPI,  RGB_VAI,
   _______,   KC_NO,   KC_LEFT,    KC_DOWN,  KC_RGHT,  RGB_SPD,  RGB_VAD,
   _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
   KC_MSTP,   KC_MPLY,   KC_MPRV,   KC_MNXT,
                               RGB_TOG, RGB_MOD,
                               RGB_SAI, RGB_SAD,
                               RGB_HUI, RGB_HUD,
        // right hand
                     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NO,
                     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
                     KC_NO,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_NO,     KC_NO,
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

#ifdef RGB_MATRIX_ENABLE
    led_config_t g_led_config = { {
      // Key Matrix to LED Index
      {        6,      5,  4,  3,  2,      1,      0 },
      {       13,     12, 11, 10,  9,      8,      7 },
      {       20,     19, 18, 17, 16,     15,    14 },
      {       26,     25, 24, 23, 22,     21, NO_LED },
      {       32,     31, 30, 29, 28,     27, NO_LED },
      {   NO_LED, NO_LED, 36, 35, 34,     33, NO_LED },
      {       43,     42, 41, 40, 39,     38,     37 },
      {       50,     49, 48, 47, 46,     45,     44 },
      {       57,     56, 55, 54, 53,     52,     51 },
      {   NO_LED,     63, 62, 61, 60,     59,     58 },
      {   NO_LED,     69, 68, 67, 66,     65,     64 },
      {   NO_LED,     73, 72, 71, 70, NO_LED, NO_LED }
    }, {
      // LED Index to Physical Position
      {   0,   0 }, {  16,   0 }, {  32,   0 }, {  48,   0 }, {  64,   0 }, {  80,   0 }, {  96,   0 },
      {   0,  16 }, {  16,  16 }, {  32,  16 }, {  48,  16 }, {  64,  16 }, {  80,  16 }, {  96,  16 },
      {   0,  32 }, {  16,  32 }, {  32,  32 }, {  48,  32 }, {  64,  32 }, {  80,  32 }, {  96,  32 },
      {   0,  40 }, {  16,  40 }, {  32,  40 }, {  48,  40 }, {  64,  40 }, {  80,  40 },
      {   0,  48 }, {  16,  48 }, {  32,  48 }, {  48,  48 },        {  72,  48 }, { 104,  48 },
                                                                            {  80,  56 }, {  96,  56 },
                                                                            {  80,  64 }, {  96,  64 },
      { 128,   0 }, { 144,   0 }, { 160,   0 }, { 176,   0 }, { 192,   0 }, { 208,   0 }, { 224,   0 },
      { 128,  16 }, { 144,  16 }, { 160,  16 }, { 176,  16 }, { 192,  16 }, { 208,  16 }, { 224,  16 },
      { 128,  32 }, { 144,  32 }, { 160,  32 }, { 176,  32 }, { 192,  32 }, { 208,  32 }, { 224,  32 },
                    { 144,  40 }, { 160,  40 }, { 176,  40 }, { 192,  40 }, { 208,  40 }, { 224,  40 },
           { 136,  48 }, { 152,  48 },          { 176,  48 }, { 192,  48 }, { 208,  48 }, { 224,  48 },
      { 128,  56 }, { 144,  56 },
      { 128,  64 }, { 144,  64 }
    }, {
      // LED Index to Flag
      1, 4, 4, 4, 4, 4, 1,
      1, 4, 4, 4, 4, 4, 4,
      1, 4, 4, 4, 4, 4, 4,
      1, 4, 4, 4, 4, 4,
      1, 1, 1, 1, 1, 1,
               1, 1, 1, 1,
      1, 4, 4, 4, 4, 4, 1,
      4, 4, 4, 4, 4, 4, 1,
      4, 4, 4, 4, 4, 4, 1,
         4, 4, 4, 4, 4, 1,
         1, 1, 1, 1, 1, 1,
      1, 1, 1, 1,
    } };
#endif

#ifdef RGBLIGHT_ENABLE
    // Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
    const rgblight_segment_t PROGMEM my_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //    {0, 74, HSV_GOLD},      // Set all keys to gold color
        {24, 1, HSV_CYAN},      // Light E key to cyan
        {30, 3, HSV_CYAN},      // Light SDF key to cyan
        {36, 4, HSV_CYAN}       // Light HJKL key to cyan
    );
    // Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
    const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {9, 2, HSV_CYAN}
    );

    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        my_fn_layer // Overrides default layer
    );

    void keyboard_post_init_user(void) {
        // Enable the LED layers
        rgblight_layers = my_rgb_layers;
    }

    // Enable layer on FN key press
    layer_state_t layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(0, layer_state_cmp(state, _FN));
        return state;
    }
#endif

