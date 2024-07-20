/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

#include "keychron_common.h"
#include "sync_timer.h"

bool     is_siri_active = false;
uint32_t siri_timer     = 0;

key_combination_t key_comb_list[4] = {{2, {KC_LWIN, KC_TAB}}, {2, {KC_LWIN, KC_E}}, {3, {KC_LSFT, KC_LCMD, KC_4}}, {2, {KC_LWIN, KC_C}}};

static uint8_t mac_keycode[4] = {KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD};

void housekeeping_task_keychron(void) {
    if (is_siri_active) {
        if (sync_timer_elapsed32(siri_timer) >= 500) {
            unregister_code(KC_LCMD);
            unregister_code(KC_SPACE);
            is_siri_active = false;
        }
    }
}

bool process_record_keychron(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case KC_A:
        //     if (record->event.pressed) {
        //         a_stopped = false;
        //         a_pressed = true;
        //
        //         unregister_code(KC_D);
        //
        //         if (!d_stopped) {
        //             d_stopped = true;
        //         }
        //
        //         register_code(KC_A);
        //     } else {
        //        if (d_pressed && d_stopped) {
        //             register_code(KC_D);
        //        }
        //
        //        a_pressed = false;
        //        d_stopped = false;
        //
        //        unregister_code(KC_A);
        //     }
        //     return false;
        // case KC_D:
        //     if (record->event.pressed) {
        //         d_stopped = false;
        //         d_pressed = true;
        //
        //         unregister_code(KC_A);
        //
        //         if (!a_stopped) {
        //             a_stopped = true;
        //         }
        //
        //         register_code(KC_D);
        //     } else {
        //         if (a_pressed && a_stopped) {
        //             register_code(KC_A);
        //         }
        //
        //         d_pressed = false;
        //         a_stopped = false;
        //
        //         unregister_code(KC_D);
        //     }
        //     return false;
        // case KC_W:
        //     if (record->event.pressed) {
        //         w_stopped = false;
        //         w_pressed = true;
        //
        //         unregister_code(KC_S);
        //
        //         if (!s_stopped) {
        //             s_stopped = true;
        //         }
        //
        //         register_code(KC_W);
        //     } else {
        //         if (s_pressed && s_stopped) {
        //             register_code(KC_S);
        //         }
        //         w_pressed = false;
        //         s_stopped = false;
        //
        //         unregister_code(KC_W);
        //     }
        //     return false;
        // case KC_S:
        //     if (record->event.pressed) {
        //         s_stopped = false;
        //         s_pressed = true;
        //
        //         unregister_code(KC_W);
        //
        //         if (!w_stopped) {
        //             w_stopped = true;
        //         }
        //
        //         register_code(KC_S);
        //     } else {
        //         if (w_pressed && w_stopped) {
        //             register_code(KC_W);
        //         }
        //
        //         s_pressed = false;
        //         w_stopped = false;
        //
        //         unregister_code(KC_S);
        //     }
        //     return false;
        case QK_KB_0:
            if (record->event.pressed) {
                register_code(KC_MISSION_CONTROL);
            } else {
                unregister_code(KC_MISSION_CONTROL);
            }
            return false; // Skip all further processing of this key
        case QK_KB_1:
            if (record->event.pressed) {
                register_code(KC_LAUNCHPAD);
            } else {
                unregister_code(KC_LAUNCHPAD);
            }
            return false; // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false; // Skip all further processing of this key
        case KC_SIRI:
            if (record->event.pressed) {
                if (!is_siri_active) {
                    is_siri_active = true;
                    register_code(KC_LCMD);
                    register_code(KC_SPACE);
                }
                siri_timer = sync_timer_read32();
            } else {
                // Do something else when release
            }
            return false; // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
        case KC_SNAP:
        case KC_CRTA:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}
