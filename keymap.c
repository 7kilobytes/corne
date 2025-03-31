#include QMK_KEYBOARD_H

#include "keymap_colemak.h"

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,

    HR_A,
    HR_S,
    HR_D,
    HR_F,
    HR_J,
    HR_K,
    HR_L,
    HR_SCLN,
    HR_Z,
    HR_SLSH,

    CKC_TAB,
    CKC_ESC,
    CKC_RET,
    CKC_BSP,

    CKC_G,     // mouse layer
    CKC_RALT,  // for cyrillic layout

    SMTD_KEYCODES_END,
};

#include "sm_td.h"

enum custom_layers {
    _QWERTY = 0,
    _COLEMAK,
    _NUM,
    _SYM,
    _NAV,
    _MS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,    HR_A,    HR_S,    HR_D,    HR_F,   CKC_G,                         KC_H,    HR_J,    HR_K,    HR_L, HR_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG,    HR_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, HR_SLSH,CKC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CKC_TAB,  KC_SPC, CKC_ESC,    CKC_RET,  KC_SPC, CKC_BSP
                                      //`--------------------------'  `--------------------------'

  ),

    [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_LLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                      KC_PLUS,    KC_7,    KC_8,    KC_9, KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F11,                         KC_0,    KC_1,    KC_2,    KC_3, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F10,                      KC_MINS,    KC_4,    KC_5,    KC_6,  KC_DOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_QUOT, KC_LABK, KC_RABK, KC_DQUO,  KC_DOT,                      KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_PERC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,                      KC_PIPE, CM_COLN, KC_LPRN, KC_RPRN, KC_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, CM_SCLN,                      KC_TILD,  KC_DLR, KC_LCBR, KC_RCBR,   KC_AT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_MS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_D, KC_MS_U, KC_WH_U, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ACL0, KC_ACL1, KC_ACL2,    KC_BTN1, KC_BTN2, KC_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

   return true;
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // left
        SMTD_LT(HR_A, KC_A, _SYM)
        SMTD_MT(HR_S, KC_S, KC_LEFT_ALT)
        SMTD_MT(HR_D, KC_D, KC_LSFT)
        SMTD_MT(HR_F, KC_F, KC_LEFT_CTRL)
        SMTD_MT(HR_Z, KC_Z, KC_LEFT_GUI)

        // right
        SMTD_MT(HR_J, KC_J, KC_RIGHT_CTRL, 1)
        SMTD_MT(HR_K, KC_K, KC_RSFT)
        SMTD_MT(HR_L, KC_L, KC_LEFT_ALT)
        SMTD_LT(HR_SCLN, KC_SCLN, _SYM)
        SMTD_MT(HR_SLSH, KC_SLSH, KC_LEFT_GUI)

        // thumbs
        SMTD_LT(CKC_TAB, KC_TAB, _NUM)
        SMTD_LT(CKC_BSP, KC_BSPC, _NUM)
        SMTD_LT(CKC_ESC, KC_ESC, _NAV)
        SMTD_LT(CKC_RET, KC_ENT, _NAV)

        SMTD_LT(CKC_G, KC_G, _MS)
        SMTD_MT(CKC_RALT, KC_BSLS, KC_RIGHT_ALT)

    }
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch(keycode) {
    case HR_A:
    case HR_S:
    case HR_L:
    case HR_SCLN:
        if (timeout == SMTD_TIMEOUT_TAP) return 300;
        if (timeout == SMTD_TIMEOUT_RELEASE) return 10;
        if (timeout == SMTD_TIMEOUT_SEQUENCE) return 250;
        break;
    }
    return get_smtd_timeout_default(timeout);
}
