#include QMK_KEYBOARD_H

#include "keymap_uk.h"

enum layers {
    _QWERTY,
    _FN,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    FN,
    LOWER,
    RAISE
};


const key_override_t pnd_key_override = ko_make_basic(MOD_MASK_SHIFT, UK_PND, UK_EURO);
const key_override_t two_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, UK_AT);
const key_override_t three_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_3, UK_HASH);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, UK_DQUO);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &pnd_key_override,
    &two_key_override,
    &three_key_override,
    &quot_key_override,
    NULL // Null terminate the array of overrides!
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   =   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Tab  |   q   |   w   |   e   |   r   |   t   |   y   |   u   |   i   |   o   |   p   | Bksp  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |   a   |   s   |   d   |   f   |   g   |   h   |   j   |   k   |   l   |   ;   |   "   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   z   |   x   |   c   |   v   |   b   |   n   |   m   |   ,   |   .   |   /   | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   Fn  | Ctrl  |  Alt  |  GUI  | Lower |     Space     | Raise | Left  | Down  |  Up   | Right |
 * `-----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL, 
KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
KC_LCTL, MO(_FN), KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Fn
 * ,-----------------------------------------------------------------------------------------------.
 * |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Tab  |   q   |   w   |   e   |   r   |   t   |   y   |   u   |   i   |   o   |   p   | Bksp  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |   a   |   s   |   d   |   f   |   g   |   h   |   j   |   k   |   l   |   ;   |   "   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   z   |   x   |   c   |   v   |   b   |   n   |   m   |   ,   |   .   |   /   | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  |  Fn   |  Alt  |  GUI  | Lower |     Space     | Raise | Left  | Down  |  Up   | Right |
 * `-----------------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid(
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
KC_LCTL, _______, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |  £    |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
UK_BSLS, _______, _______, UK_PND,  _______, _______, _______, _______, _______, _______, _______, KC_MINS,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, KC_MPLY,
_______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |  £    |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------|
 * |       | Reset| Debug|       |       |       |       |TermOf|TermOn|       |       |  Del |
 * |-------+-------+-------+-------+-------+--------------+-------+-------+-------+-------+------|
 * |       |       |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|       |       |
 * |-------+-------+-------+-------+-------+------|-------+-------+-------+-------+-------+------|
 * |       |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------|
 * |       |       |       |       |       |               |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
         case QWERTY:
              if (record->event.pressed) {
                  set_single_persistent_default_layer(_QWERTY);
              }
              return false;
              break;
         case LOWER:
              if (record->event.pressed) {
                  layer_on(_LOWER);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              } else {
                  layer_off(_LOWER);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              }
              return false;
              break;
         case RAISE:
              if (record->event.pressed) {
                  layer_on(_RAISE);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              } else {
                  layer_off(_RAISE);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              }
              return false;
              break;
    }
    return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
         register_code(KC_PGDN);
         unregister_code(KC_PGDN);
    } else {
         register_code(KC_PGUP);
         unregister_code(KC_PGUP);
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
         case 0:
              if (active) {
                  layer_on(_ADJUST);
              } else {
                  layer_off(_ADJUST);
              }
              break;
         // case 1:
         //     if (active) {
         //          muse_mode = true;
         //     } else {
         //          muse_mode = false;
         //     }
    }
    return true;
}