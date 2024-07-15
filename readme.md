# This is a custom fork [Keychron's QMK Firmware](https://github.com/Keychron/qmk_firmware)

## What is this?

This fork is a similar (very rudimentary) implementation of [Razer's SnapTap](https://www.razer.com/technology/snap-tap-mode) for the Keychron V6 Knob version.

Modified code can be found in `keyboards/keychron/v6/keymaps/custom/`.

## Build

You can build this firmware by running the following command `qmk compile -kb keychron/v6/ansi_encoder -km custom`.

## Create version for other Keychron keyboards

Copy the folder from `keyboards/keychron/YOURKEYBOARD/keymaps/keychron` and paste it to `keyboards/keychron/YOURKEYBOARD/keymaps/custom`

Define the following enum in `keymap.c`

``` c
enum kc_custom_keycodes {
  KC_CUSTOM_A = SAFE_RANGE,
  KC_CUSTOM_D,
  KC_CUSTOM_W,
  KC_CUSTOM_S,
};
```

Find and replace `KC_A` with `KC_CUSTOM_A`, `KC_D` with `KC_CUSTOM_D`, etc...

Then find the following function

``` c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}
```

And replace it with the following:

``` c
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
```
