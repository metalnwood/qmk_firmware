#include QMK_KEYBOARD_H


enum {
	_DVORAK = 0,
	_COLEMAK,
	_QWERTY,
	_SYMBOL,
	_NUMROW,
	_NUMPAD,
	_ARROWRGB,
	_WM,
	_MEDIA
};
/* enum layer_number { */
/*   _COLEMAK = 0, */
/*   _QWERTY, */
/*   _MEDIA, */
/*   _SYMBOL, */
/*   _NUMPAD, */
/*   _ARROWS, */
/*   _XMONAD */
/* }; */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DVORAK] = LAYOUT(
        S(KC_GRV)/* KC_TILD  */,     KC_KP_PLUS,        KC_LCBR, KC_LBRC,    KC_LPRN,    KC_PERC,                           KC_CIRC,    KC_RPRN,    KC_RBRC,    KC_RBRC,    KC_PLUS,    KC_BSPC,
        LT(_NUMPAD, KC_TAB),    KC_SCLN,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,

        LT(_ARROWRGB,KC_ESC), LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), KC_I, KC_D, RSFT_T(KC_H), RCTL_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S), KC_MINS,

        KC_LSFT,    KC_QUOTE,    KC_Q,    KC_J,    KC_K,    KC_X, TO(_QWERTY), KC_SLSH, KC_B,    KC_M, KC_W,  KC_V, KC_Z,  KC_RSFT,
        KC_NO,      LT(_NUMPAD, KC_CAPS),   LT(_NUMPAD,KC_BSPC),  LT(_NUMROW,KC_BSPC),                LT(_NUMROW,KC_SPC),   LT(_WM	,KC_ENT), MO(_MEDIA), KC_NO),

	[_COLEMAK] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
               KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
               LT(_ARROWRGB,KC_ESC), LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), LT(_WM,KC_QUOT),
               KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, TO(_QWERTY), KC_RBRC, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLS),

                KC_NO,                          LT(_NUMPAD, KC_CAPS),   LT(_NUMPAD,KC_SPC),  LT(_NUMROW,KC_SPC),     LT(_NUMROW,KC_SPC),   LT(_WM	,KC_ENT), MO(_MEDIA),KC_NO) ,
//               KC_NO, KC_NO, TT(_SYMBOL), LT(_SYMBOL,KC_ENT), LT(_SYMBOL,KC_SPC), LT(_SYMBOL,KC_SPC), LT(_MEDIA,KC_DEL), KC_NO),
 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TO(_DVORAK), KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LALT, KC_LGUI, MO(_SYMBOL), KC_SPC, KC_ENT, MO(_SYMBOL), KC_BSPC, KC_RGUI
),
  [_SYMBOL] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_COLN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_CAPS,KC_NO,KC_NO, KC_LBRC, KC_LPRN, KC_LCBR,                             KC_RCBR, KC_RPRN, KC_RBRC, KC_UNDS, KC_QUOT, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LSFT_T(KC_GRV), KC_COLN, KC_QUES, KC_LBRC, KC_RBRC, KC_LCBR,    KC_NO, KC_NO,            KC_RCBR, KC_LPRN, KC_LT, KC_GT, KC_TILD, RSFT_T(KC_KP_PLUS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_NO,       KC_LGUI, _______,  KC_ENT,     KC_SPC,   MO(_NUMROW), KC_RALT, KC_NO
                                      //`--------------------------'  `--------------------------'
 ),
  // numrow
  [_NUMROW] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_KP_PLUS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_DOT, KC_1, LALT_T(KC_2),LCTL_T( KC_3),LSFT_T(KC_4),KC_5,         KC_6,     RSFT_T(KC_7),   RCTL_T( KC_8), RALT_T(KC_9),   KC_0,    KC_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LSFT_T(KC_GRV),   KC_COLN, KC_QUES,   KC_LBRC,KC_RBRC, KC_LCBR,   KC_NO, KC_TILDE,         KC_RCBR, KC_LPRN, KC_RPRN,  KC_UNDS,KC_PIPE, RSFT_T(KC_BSLS),
  //  LSFT_T(KC_GRV),   KC_COLN, KC_QUES,   KC_LBRC, KC_LPRN, KC_LCBR,            KC_RCBR, KC_RPRN, KC_RBRC,  KC_UNDS,KC_SLSH, RSFT_T(KC_KP_PLUS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_NO,     KC_LT, KC_GT,  KC_SPC,     KC_SPC,   KC_ENT, KC_RALT, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),
  // numpad
  [_NUMPAD] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   KC_NO, KC_NO,KC_F7, KC_F8, KC_F9, KC_F10,                                    KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_NO, KC_NO,KC_F4, KC_F5, KC_F6, KC_F11,                                    KC_DOT, KC_4, KC_5, KC_6, KC_PAST, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_NO, KC_NO,KC_F1, KC_F2, KC_F3, KC_F12,           KC_NO, KC_NO,                         KC_0, KC_1, KC_2, KC_3, KC_PSLS, KC_PPLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_NO,      KC_LGUI,   KC_0,  KC_SPC,  KC_SPC ,    KC_ENT, KC_0, KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),
  // arrows
  [_ARROWRGB] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                      KC_NO, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI,RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,                       G(RCTL(KC_J)), KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,   KC_NO, KC_NO,                    KC_NO, KC_PGUP, KC_DEL, KC_PGDN, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_NO,      KC_LGUI, KC_BTN2,  KC_BTN1,     KC_ENT, _______, KC_RALT, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),
  // xmonad
  [_WM] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, SGUI(KC_1), SGUI(KC_2), SGUI(KC_3), SGUI(KC_4), SGUI(KC_5),   KC_NO, KC_NO,                 SGUI(KC_6), SGUI(KC_7), SGUI(KC_8), SGUI(KC_9), SGUI(KC_0), KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_NO,      KC_LGUI, G(KC_J),  G(RCTL(KC_J)),     G(RCTL(KC_J)), _______, KC_RALT, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),
  // media
  [_MEDIA] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     DF(_COLEMAK), DF(_DVORAK), DF(_QWERTY), KC_MS_U, KC_BTN1, KC_NO,                            KC_NO, KC_MPLY, KC_VOLU, KC_MSTP, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRV, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_PERC,                         KC_NO, KC_MRWD, KC_VOLD, KC_MFFD, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_NO, KC_NO,                 KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_NO,     KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT, KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};
//layer_state_t layer_state_set_user(layer_state_t state) {
//  return update_tri_layer_state(state, _MEDIA, _SYMBOL, _NUMPAD, _ARROWS, _XMONAD);
//}



//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
