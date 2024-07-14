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
bool process_record_user(uint16_t keycode, keyrecord_t * record) {
  if (record -> event.pressed) {
    switch (keycode) {
        case KC_CUSTOM_A:
            unregister_code(KC_D); // Release 'D'
            register_code(KC_A);  // Register 'A'
            return false;
        case KC_CUSTOM_D:
            unregister_code(KC_A); // Release 'A'
            register_code(KC_D);  // Register 'D'
            return false;
        case KC_CUSTOM_W:
            unregister_code(KC_S); // Release 'D'
            register_code(KC_W);  // Register 'W'
            return false;
        case KC_CUSTOM_S:
            unregister_code(KC_W); // Release 'D'
            register_code(KC_S);  // Register 'S'
            return false;
    }
  } else {
    switch (keycode) {
        case KC_CUSTOM_A:
            unregister_code(KC_A);  // Release 'A'
            return false;
        case KC_CUSTOM_D:
            unregister_code(KC_D);  // Release 'D'
            return false;
        case KC_CUSTOM_W:
            unregister_code(KC_W);  // Release 'W'
            return false;
        case KC_CUSTOM_S:
            unregister_code(KC_S);  // Release 'S'
            return false;
    }
  }

  if (!process_record_keychron(keycode, record)) {
    return false;
  }

  return true;
}
```
