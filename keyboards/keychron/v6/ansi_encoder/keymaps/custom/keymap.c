#include QMK_KEYBOARD_H

#include "keychron_common.h"

enum layers {
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

enum kc_custom_keycodes {
  KC_CUSTOM_A = SAFE_RANGE,
  KC_CUSTOM_D,
  KC_CUSTOM_W,
  KC_CUSTOM_S,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAC_BASE] = LAYOUT_ansi_109(KC_ESC, KC_BRID, KC_BRIU, KC_NO, KC_NO, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO, RGB_MOD, KC_F13, KC_F14, KC_F15, KC_F16, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN, KC_P7, KC_P8, KC_P9, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_LCTL, KC_LOPT, KC_LGUI, KC_SPC, KC_RGUI, KC_ROPT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT, KC_PENT),
  [MAC_FN] = LAYOUT_ansi_109(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RGB_TOG, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [WIN_BASE] = LAYOUT_ansi_109(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MUTE, KC_PSCR, KC_F17, KC_F18, KC_F13, KC_F14, KC_F15, KC_F16, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, KC_TAB, KC_Q, KC_CUSTOM_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN, KC_P7, KC_P8, KC_P9, KC_CAPS, KC_CUSTOM_A, KC_CUSTOM_S, KC_CUSTOM_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, MO(3), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT, KC_PENT),
  [WIN_FN] = LAYOUT_ansi_109(KC_TRNS, KC_BRID, KC_BRIU, LGUI(KC_TAB), LGUI(KC_E), RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, RGB_TOG, KC_TRNS, KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [MAC_BASE] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
  },
  [MAC_FN] = {
    ENCODER_CCW_CW(RGB_VAD, RGB_VAI)
  },
  [WIN_BASE] = {
    ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
  },
  [WIN_FN] = {
    ENCODER_CCW_CW(RGB_VAD, RGB_VAI)
  }
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    if (!snap_tap(keycode, record)) {
        return false;
    }
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}

bool a_stopped = false;
bool d_stopped = false;
bool w_stopped = false;
bool s_stopped = false;

bool a_pressed = false;
bool d_pressed = false;
bool w_pressed = false;
bool s_pressed = false;

bool snap_tap(uint16_t keycode, keyrecord_t * record) {
    switch (keycode) {
        case KC_CUSTOM_A:
            if (record->event.pressed) {
                a_stopped = false;
                a_pressed = true;

                unregister_code(KC_D);

                if (!d_stopped) {
                    d_stopped = true;
                }

                register_code(KC_A);
            } else {
               if (d_pressed && d_stopped) {
                    register_code(KC_D);
               }

               a_pressed = false;
               d_stopped = false;

               unregister_code(KC_A);
            }
            return false;
        case KC_CUSTOM_D:
            if (record->event.pressed) {
                d_stopped = false;
                d_pressed = true;

                unregister_code(KC_A);

                if (!a_stopped) {
                    a_stopped = true;
                }

                register_code(KC_D);
            } else {
                if (a_pressed && a_stopped) {
                    register_code(KC_A);
                }

                d_pressed = false;
                a_stopped = false;

                unregister_code(KC_D);
            }
            return false;
        case KC_CUSTOM_W:
            if (record->event.pressed) {
                w_stopped = false;
                w_pressed = true;

                unregister_code(KC_S);

                if (!s_stopped) {
                    s_stopped = true;
                }

                register_code(KC_W);
            } else {
                if (s_pressed && s_stopped) {
                    register_code(KC_S);
                }
                w_pressed = false;
                s_stopped = false;

                unregister_code(KC_W);
            }
            return false;
        case KC_CUSTOM_S:
            if (record->event.pressed) {
                s_stopped = false;
                s_pressed = true;

                unregister_code(KC_W);

                if (!w_stopped) {
                    w_stopped = true;
                }

                register_code(KC_S);
            } else {
                if (w_pressed && w_stopped) {
                    register_code(KC_W);
                }

                s_pressed = false;
                w_stopped = false;

                unregister_code(KC_S);
            }
            return false;
        default:
            return true;
    }
}

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}
