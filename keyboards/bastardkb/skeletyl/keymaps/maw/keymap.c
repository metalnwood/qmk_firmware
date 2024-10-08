/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include <stdio.h>

enum {
    M_SMILE = SAFE_RANGE,
    M_JOY,
    M_CD,
};

enum {
	_DVORAK = 0,
	_QWERTY,
	_SYMBOLS,
	_SECOND_SYMBOLS,
	_NUMPAD,
	_FUNC_PAD,
	_NAVIGATION,
	_WM,
	_MEDIA,
};

int32_t last_pressed = 0;
int capsl = 0;
int num_word = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_SCLN,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), LT(_NAVIGATION,KC_I),     LT(_FUNC_PAD,KC_D), RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_QUOT,    KC_Q,    KC_J,    LT(_SECOND_SYMBOLS, KC_K),    KC_X,                                 KC_B,    LT(_SECOND_SYMBOLS, KC_M), KC_W,  KC_V, KC_Z,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            LT(_SYMBOLS,KC_ESC),  LT(_NAVIGATION,KC_TAB), LT(_MEDIA, KC_ESC),             LT(_WM, KC_MINS),   LT(_SYMBOLS, KC_ENT), LT(_SYMBOLS,KC_SPC)

  ),
  [_QWERTY] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            LT(_SYMBOLS,KC_SPC),  LT(_NAVIGATION,KC_TAB), LT(_NAVIGATION, KC_ESC),             LT(_MEDIA, KC_TAB),   LT(_WM, KC_ESC), LT(_SYMBOLS,KC_SPC)
  ),
 [_SECOND_SYMBOLS] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      // KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                 KC_SLSH, KC_GRV, KC_COLN, KC_EQL, KC_KP_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     // KC_1, LALT_T(KC_2),LCTL_T( KC_3),LSFT_T(KC_4),KC_5,                       KC_PIPE,     RSFT_T(KC_7),   KC_TILDE, RALT_T(KC_9),   KC_BSPC,
     M_SMILE,     M_JOY,   KC_LBRC,KC_PIPE,      KC_NO,                               KC_PSLS, KC_GRV      , KC_NO,    KC_NO,   KC_KP_PLUS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_NO,                          KC_COLN,  KC_PSLS,KC_TILDE, M_CD, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DQUO, KC_NO,   KC_LCBR,  KC_RCBR, KC_NO,                             KC_BSLS, KC_LCBR, KC_RCBR,  KC_UNDS, KC_QUES,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                                           KC_SPC,KC_BSPC,  KC_SPC,         XXXXXXX,     KC_ENT, KC_SPC
                                      //`--------------------------'  `--------------------------'
 ),

 [_SYMBOLS] = LAYOUT_split_3x5_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     /* KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                   KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_KP_PLUS, */
     KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                   KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_1,     KC_2,    KC_3,   LSFT_T(KC_4),       KC_5,                              KC_6,     KC_7,    KC_8,   KC_9,       KC_0,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DQUO, KC_BSLS,   KC_LBRC,LT(_SECOND_SYMBOLS, KC_RBRC), KC_LCBR,                             KC_RCBR, KC_LPRN, KC_RPRN,  KC_TILDE, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                                           KC_SPC,KC_LT,  KC_GT,         KC_CAPS,     KC_ENT, KC_SPC
                                       //`--------------------------'  `--------------------------'
),
  [_NUMPAD] = LAYOUT_split_3x5_3(

  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   KC_COLN,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                     KC_PAST, KC_7, KC_8, KC_9, KC_PSLS ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_DOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                    KC_DOT, RSFT_T(KC_4), RCTL_T(KC_5), RALT_T(KC_6),KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                    KC_0, KC_1, KC_2, KC_3, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_SPC,KC_BSPC,  KC_SPC,               KC_SPC,     KC_ENT, KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC_PAD] = LAYOUT_split_3x5_3(

  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   KC_NO,KC_F7, KC_F8, KC_F9, KC_F10,                                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_NO,KC_F4, KC_F5, KC_F6, KC_F11,                                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_NO,KC_F1, KC_F2, KC_F3, KC_F12,                                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_SPC,KC_BSPC  ,KC_SPC,               KC_SPC,     KC_ENT, KC_0
                                      //`--------------------------'  `--------------------------'
  ),
  [_NAVIGATION] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              KC_PGUP, KC_HOME, KC_UP, KC_END, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, LCTL(KC_C), LCTL(KC_V), KC_MUTE,                              KC_WH_D, KC_WH_U, KC_DEL, KC_PGDN, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,  KC_SPC, _______,     _______, KC_ENT, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_WM] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LAG(KC_1), LAG(KC_2), LAG(KC_3), LAG(KC_4),   XXXXXXX,                    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       SGUI(KC_1), SGUI(KC_2), SGUI(KC_3), SGUI(KC_4), SGUI(KC_5),                    SGUI(KC_6), SGUI(KC_7), SGUI(KC_8), SGUI(KC_9), SGUI(KC_0),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          G(KC_K), G(KC_J),  G(RCTL(KC_J)),     G(RCTL(KC_J)), _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

                             /* XXXXXXX,LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4) , XXXXXXX,         QK_BOOTRESETRESET,, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SGUI(KC_C), */
  // media
  [_MEDIA] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DF(_DVORAK), DF(_QWERTY), KC_MS_U, KC_BTN1, KC_BTN2,                            KC_NO, KC_MPLY, KC_VOLU, KC_MSTP, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRV, KC_TILDE, KC_MS_L, KC_MS_D, KC_MS_R,                          KC_NO, KC_MRWD, KC_VOLD, KC_MFFD, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_TRNS, KC_WH_D , KC_WH_D, KC_WH_U,                      KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC, KC_TAB,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )

};



enum combo_events {
    CAPS_COMBO,
    // NUMWORD_COMBO,
    // ONESHOT_SHIFT_COMBO,
    RETURN_COMBO,
    BSPC_COMBO,
    ESC_COMBO,
    TAB_COMBO,

};
// other good ones to use   'qj'  'wv'  'kx'
const uint16_t PROGMEM caps_lock_combo[] = {KC_V, KC_W, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_C, KC_G, COMBO_END};
const uint16_t PROGMEM return_combo[] = {LT(_SECOND_SYMBOLS, KC_M), KC_W, COMBO_END};
//const uint16_t PROGMEM num_word_combo[] = {RALT_T(KC_N), RCTL_T(KC_T), RSFT_T(KC_H), COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_COMMA,    KC_DOT, COMBO_END};
const uint16_t PROGMEM esc_combo[] ={RALT_T(KC_N), RCTL_T(KC_T), RSFT_T(KC_H), COMBO_END} ;
//const uint16_t PROGMEM oneshot_shift_combo[]= {RSFT_T(KC_H),  RCTL_T(KC_T), COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO] = COMBO_ACTION(caps_lock_combo),
  //[NUMWORD_COMBO] = COMBO_ACTION(num_word_combo),
  //[ONESHOT_SHIFT_COMBO] = COMBO_ACTION(oneshot_shift_combo),
  [RETURN_COMBO] = COMBO_ACTION(return_combo),
  [BSPC_COMBO] = COMBO_ACTION(bspc_combo),
  [ESC_COMBO] = COMBO_ACTION(esc_combo),
  [TAB_COMBO] = COMBO_ACTION(tab_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
//  int32_t  elapsed;

   switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        caps_word_on();
      }
      break;
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
    // case NUMWORD_COMBO:
    //   if (pressed){
    //     num_word = 1;
    //     layer_move(_NUMPAD);
    //     break;
    //   }
    // case ONESHOT_SHIFT_COMBO:
    //   if (pressed) {
    //     set_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT));
    //   }
    //   break;


    case BSPC_COMBO:
        if(pressed) {
            tap_code16(KC_BSPC);

        }
        break;
   case RETURN_COMBO :
        if(pressed) {
            tap_code16(KC_ENT);

        }
        break;

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
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_JOY:
            if (record->event.pressed) {
                SEND_STRING(":joy:");
            }
            return false;
        case M_SMILE:
            if (record->event.pressed) {
                SEND_STRING(":)");
            }
            return false;
        case M_CD:
            if (record->event.pressed) {
                SEND_STRING("cd ");
            }
            return false;
    }

    return true;
}
