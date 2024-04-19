/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include QMK_KEYBOARD_H
#include <stdio.h>


#define ENTER_COMBO_TIMER 140
enum {
	_DVORAK = 0,
	_COLEMAK,
	_QWERTY,
	_SYMBOLS,
	_NUMPAD,
	_ARROWRGB,
	_WM,
	_MEDIA,
  _NUMWORD
};
int32_t last_pressed = 0;
int capsl = 0;
int num_word = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
<<<<<<< HEAD
                                 KC_TAB,    KC_SCLN,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R, KC_L,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LT(_ARROWRGB,KC_ESC), LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), LT(_NUMPAD,KC_I), LT(_NUMPAD,KC_D), RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S), KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILDE, KC_QUOT   ,    KC_Q,    KC_J,    LT(_NUMPAD,KC_K),    KC_X,                         KC_B,    KC_M, KC_W,  KC_V, KC_Z,  KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_CAPS,  LT(_NUMPAD, LSFT(KC_COLN)),  LT(_SYMBOLS,KC_SPC), LT(_SYMBOLS,KC_SPC),   LT(_WM	,KC_ENT), MO(_MEDIA)
=======
                                 KC_TAB,    KC_SCLN,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R, KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LT(_ARROWRGB,KC_ESC), LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), LT(_NUMPAD,KC_I), LT(_NUMPAD,KC_D), RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S), KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILDE, KC_QUOT   ,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M, KC_W,  KC_V, KC_Z,  KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_CAPS,   LSFT(KC_COLN),  LT(_SYMBOLS,KC_SPC), LT(_SYMBOLS,KC_SPC),   LT(_WM	,KC_ENT), MO(_MEDIA)
>>>>>>> 4ea0c0cd91e897dc8f2d54883f9a7bac4af69f25
                                      //`--------------------------'  `--------------------------'

  ),
  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LT(_ARROWRGB,KC_ESC), LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), LT(_NUMPAD,KC_G), LT(_NUMPAD,KC_M), RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), LT(_WM	,KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILDE,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                                          KC_CAPS,   LSFT(KC_COLN),  LT(_SYMBOLS,KC_SPC),     LT(_SYMBOLS,KC_SPC), LT(_WM	,KC_ENT),  MO(_MEDIA)
                                      //`--------------------------'  `--------------------------'

  ),
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O, KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LT(_ARROWRGB,KC_ESC),KC_A,KC_S , KC_D , KC_F , KC_G, KC_H, KC_J , KC_K , KC_L , KC_SCLN , LT(_WM	,KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  RSFT_T(KC_BSLS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LT(_NUMPAD, KC_CAPS),   MO(_ARROWRGB),  LT(_SYMBOLS,KC_SPC),     LT(_SYMBOLS,KC_SPC),   LT(_SYMBOLS,KC_ENT), MO(_MEDIA)
                                      //`--------------------------'  `--------------------------'

  ),
  // numrow
<<<<<<< HEAD
 // [_SYMBOLS] = LAYOUT_split_3x6_3(
 //  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 //     KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_KP_PLUS, KC_BSPC,
 //  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 //     KC_DOT, KC_1, LALT_T(KC_2),LCTL_T( KC_3),LSFT_T(KC_4),KC_5,         KC_6,     RSFT_T(KC_7),   RCTL_T( KC_8), RALT_T(KC_9),   KC_0,    KC_UNDS,
 //  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 //     LSFT_T(KC_TILD),   KC_DQUO, KC_COLN,   KC_LBRC,KC_RBRC, KC_LCBR,            KC_RCBR, KC_LPRN, KC_RPRN,  KC_UNDS,KC_PIPE, RSFT_T(KC_BSLS),
 //  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
 //                                           KC_LT, KC_GT,  KC_SPC,     KC_SPC,   KC_ENT, XXXXXXX
 //                                      //`--------------------------'  `--------------------------'
 // ),
 [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     //KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_KP_PLUS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_DOT,KC_PIPE,    KC_COLN,     KC_LCBR,    KC_RCBR,       KC_5,                              KC_BSLS,  KC_TILDE, KC_SLSH,    KC_UNDS,   KC_MINS,KC_UNDS,
     KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_KP_PLUS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    --------+--------+--------+--------+--------+--------|
      KC_NO, KC_DQUO, KC_COLN,   KC_LBRC,KC_RBRC,KC_LT ,                             KC_GT, KC_LPRN, KC_RPRN,  KC_UNDS,KC_QUES, KC_NO,
=======
 [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_KP_PLUS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_DOT, KC_1, LALT_T(KC_2),LCTL_T( KC_3),LSFT_T(KC_4),KC_5,         KC_6,     RSFT_T(KC_7),   RCTL_T( KC_8), RALT_T(KC_9),   KC_0,    KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LSFT_T(KC_TILD),   KC_DQUO, KC_COLN,   KC_LBRC,KC_RBRC, KC_LCBR,            KC_RCBR, KC_LPRN, KC_RPRN,  KC_UNDS,KC_PIPE, RSFT_T(KC_BSLS),
>>>>>>> 4ea0c0cd91e897dc8f2d54883f9a7bac4af69f25
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LT, KC_GT,  KC_SPC,     KC_SPC,   KC_ENT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
 ),


  // numpad
  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   KC_NO, KC_NO,KC_F7, KC_F8, KC_F9, KC_F10,                                    KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_NO, KC_NO,KC_F4, KC_F5, KC_F6, KC_F11,                                    KC_0, RSFT_T(KC_4), RCTL_T(KC_5), RALT_T(KC_6), KC_PAST, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_NO, KC_NO,KC_F1, KC_F2, KC_F3, KC_F12,                                    KC_DOT, KC_1, KC_2, KC_3, KC_PSLS, KC_PPLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   KC_LGUI,   KC_0,  KC_SPC,  KC_SPC,     KC_ENT, KC_0
                                      //`--------------------------'  `--------------------------'
  ),
  // arrows
  [_ARROWRGB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                      KC_PGUP, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  XXXXXXX, KC_LGUI,LALT_T(RGB_TOG), LCTL_T(RGB_HUI), LSFT_T(RGB_SAI), RGB_VAI,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, G(RCTL(KC_J)),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,                       KC_WH_D, KC_WH_U, KC_DEL, KC_PGDN, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,XXXXXXX,  KC_BTN1,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  // xmonad
  [_WM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, LAG(KC_1), LAG(KC_2), LAG(KC_3), LAG(KC_4),   XXXXXXX,                    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SGUI(KC_C),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, SGUI(KC_1), SGUI(KC_2), SGUI(KC_3), SGUI(KC_4), SGUI(KC_5),                    SGUI(KC_6), SGUI(KC_7), SGUI(KC_8), SGUI(KC_9), SGUI(KC_0), KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          G(KC_K), G(KC_J),  G(RCTL(KC_J)),     G(RCTL(KC_J)), _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

                             /* XXXXXXX,LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4) , XXXXXXX,         QK_BOOTRESETRESET,, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SGUI(KC_C), */
  // media
  [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     DF(_COLEMAK), DF(_DVORAK), DF(_QWERTY), KC_MS_U, KC_BTN1, KC_BTN2,                            KC_NO, KC_MPLY, KC_VOLU, KC_MSTP, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRV, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_PERC,                         KC_NO, KC_MRWD, KC_VOLD, KC_MFFD, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_TRNS, KC_WH_D , KC_WH_D, KC_WH_U, KC_TRNS,                      KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

 [_NUMWORD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_KP_PLUS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_DOT, KC_1, LALT_T(KC_2),LCTL_T( KC_3),LSFT_T(KC_4),KC_5,         KC_6,     RSFT_T(KC_7),   RCTL_T( KC_8), RALT_T(KC_9),   KC_0,    KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LSFT_T(KC_TILD),   KC_DQUO, KC_COLN,   KC_LBRC,KC_RBRC, KC_LCBR,            KC_RCBR, KC_LPRN, KC_RPRN,  KC_UNDS,KC_PIPE, RSFT_T(KC_BSLS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LT, KC_GT,  KC_SPC,     KC_SPC,   KC_ENT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
 )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _DVORAK:
            oled_write_ln_P(PSTR("Dvorak"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("Numrow"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    /* set_keylog(keycode, record); */


    // if NUM_WORD then check if we are pressing numbers, if not then go back to default layer and process key.
    //
    if(num_word){
      /* if((keycode >= KC_1  && keycode <= KC_0) || keycode == KC_DOT) */
      if(keycode == KC_SPACE || keycode == KC_ENT)
        {
          num_word = 0;
          layer_move(_DVORAK);
          tap_code16( keycode );
        }
    }

    last_pressed = timer_read32();


  }
  return true;
}
#endif // OLED_ENABLE

/* void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { */
/*     if (host_keyboard_led_state().caps_lock) { */
/*       if(  ) */
/*         for (uint8_t i = led_min; i <= led_max; i++) { */
/*             if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) { */
/*                 rgb_matrix_set_color(i, RGB_RED); */
/*             } */
/*         } */
/*     } */
/* } */
/* const uint16_t PROGMEM caps_lock_combo[] = {KC_M, KC_W, COMBO_END}; */
/* const uint16_t PROGMEM escape_combo[] = {KC_C, KC_G, COMBO_END}; */
/* const uint16_t PROGMEM enter_combo[] = {RSFT_T(KC_H),  RCTL_T(KC_T), COMBO_END}; */
/* combo_t key_combos[] = { */
/*     COMBO(caps_lock_combo, KC_CAPS), */
/*     COMBO(escape_combo, KC_ESC), // keycodes with modifiers are possible too! */
/*     COMBO(enter_combo, KC_ENT), // keycodes with modifiers are possible too! */
/* }; */



enum combo_events {
<<<<<<< HEAD
    CAPS_COMBO,
      /* ESCAPE_COMBO, */
      /* ENTER_COMBO, */
    NUMWORD_COMBO,
    ONESHOT_SHIFT_COMBO,
    RETURN_COMBO,
    BSPC2_COMBO,
    ESC_COMBO,
    TAB_COMBO,


};
const uint16_t PROGMEM caps_lock_combo[] = {LCTL_T(KC_E), LSFT_T(KC_U), COMBO_END};
/* const uint16_t PROGMEM escape_combo[] = {KC_C, KC_G, COMBO_END}; */
/* const uint16_t PROGMEM enter_combo[] = {KC_C, KC_G, COMBO_END}; */
const uint16_t PROGMEM num_word_combo[] = {KC_C, KC_G, COMBO_END};
const uint16_t PROGMEM return_combo[] = {KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM bspc2_combo[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_COMM,    KC_DOT, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U),COMBO_END};
=======
  CAPS_COMBO,
  /* ESCAPE_COMBO, */
  /* ENTER_COMBO, */
  NUMWORD_COMBO,
  ONESHOT_SHIFT_COMBO,
};

const uint16_t PROGMEM caps_lock_combo[] = {KC_M, KC_W, COMBO_END};
/* const uint16_t PROGMEM escape_combo[] = {KC_C, KC_G, COMBO_END}; */
/* const uint16_t PROGMEM enter_combo[] = {KC_C, KC_G, COMBO_END}; */
const uint16_t PROGMEM num_word_combo[] = {KC_C, KC_G, COMBO_END};
>>>>>>> 4ea0c0cd91e897dc8f2d54883f9a7bac4af69f25
/* const uint16_t PROGMEM num_word_combo[] = {LSFT_T(KC_U),  LCTL_T(KC_E), COMBO_END}; */
const uint16_t PROGMEM oneshot_shift_combo[]= {RSFT_T(KC_H),  RCTL_T(KC_T), COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO] = COMBO_ACTION(caps_lock_combo),
<<<<<<< HEAD
  [NUMWORD_COMBO] = COMBO_ACTION(num_word_combo),
  [ONESHOT_SHIFT_COMBO] = COMBO_ACTION(oneshot_shift_combo),
  [RETURN_COMBO] = COMBO_ACTION(return_combo),
  [BSPC2_COMBO] = COMBO_ACTION(bspc2_combo),
  [ESC_COMBO] = COMBO_ACTION(esc_combo),
  [TAB_COMBO] = COMBO_ACTION(tab_combo),
=======
  /* [ESCAPE_COMBO] = COMBO_ACTION(escape_combo), */
  /* [ENTER_COMBO] = COMBO_ACTION(enter_combo), */
  [NUMWORD_COMBO] = COMBO_ACTION(num_word_combo),
  [ONESHOT_SHIFT_COMBO] = COMBO_ACTION(oneshot_shift_combo),
>>>>>>> 4ea0c0cd91e897dc8f2d54883f9a7bac4af69f25
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
<<<<<<< HEAD
//  int32_t  elapsed;
=======
  /* int32_t  elapsed; */
>>>>>>> 4ea0c0cd91e897dc8f2d54883f9a7bac4af69f25

   switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        caps_word_on();
      }
      break;
<<<<<<< HEAD
    case TAB_COMBO:
      if (pressed) {
                tap_code16(KC_TAB);
      }
      break;
    case ESC_COMBO:
      if (pressed) {
                tap_code16(KC_ESC);
      }
      break;
=======
>>>>>>> 4ea0c0cd91e897dc8f2d54883f9a7bac4af69f25
    /* case ESCAPE_COMBO: */
    /*   if (pressed) { */
    /*     tap_code16(KC_ESC); */
    /*   } */
    /*   break; */
    case NUMWORD_COMBO:
      if (pressed){
        num_word = 1;
<<<<<<< HEAD
        layer_move(_NUMPAD);
=======
        layer_move(_NUMWORD);
>>>>>>> 4ea0c0cd91e897dc8f2d54883f9a7bac4af69f25
        break;
      }
    case ONESHOT_SHIFT_COMBO:
      if (pressed) {
        set_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT));
      }
      break;
<<<<<<< HEAD


    case BSPC2_COMBO:
        if(pressed) {
            tap_code16(KC_BSPC);

        }
        break;
    case RETURN_COMBO:
        if(pressed) {
            tap_code16(KC_ENT);

        }
        break;
=======
>>>>>>> 4ea0c0cd91e897dc8f2d54883f9a7bac4af69f25
    /* case ENTER_COMBO: */
    /*   if (pressed) { */

    /*     elapsed = timer_elapsed32(last_pressed); */
    /*     if (elapsed > ENTER_COMBO_TIMER ) */
    /*       tap_code16(KC_ENT); */
    /*     else { */

    /*       tap_code16(KC_T); */
    /*       tap_code16(KC_H); */

    /*       last_pressed = timer_read32(); */
    /*     } */
    /*   } */
    /*   break; */
  }
}
