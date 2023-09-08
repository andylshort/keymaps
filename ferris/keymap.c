#include QMK_KEYBOARD_H

#include "keymap_uk.h"

// enum custom_keycodes {
//     REPEAT = SAFE_RANGE
// };

enum layers {
    DEF,
    NAV,
    SYM,
    FUN
};

/* Remaining keys to add:
- Play, Pause, Next, Previous, Volume Up, Volume Down
- Brightness Up, Brightness Down
*/

const key_override_t shift_quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, UK_DQUO);
const key_override_t shift_comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t shift_fstop_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_COLN);
const key_override_t shift_pound_override = ko_make_basic(MOD_MASK_SHIFT, UK_PND,  UK_EURO);
const key_override_t shift_bksp_override  = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL );

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_quote_override,
    &shift_comma_override,
    &shift_fstop_override,
    &shift_pound_override,
    &shift_bksp_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 1: Default/Base
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|   q   |   w   |   f   |   p   |   b   |   |   j   |   l   |   u   |   y   |  ' "  |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|   a   | alt/r | gui/s | ctl/t |   g   |   |   m   | ctl/n | gui/e | alt/i |   o   |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|   z   |   x   |   c   |   d   |   v   |   |   k   |   h   |  , ;  |  . :  |  / ?  |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
                        | SHIFT | SPACE |   | enter |  NAV  |
                        +-------+-------+   +-------+-------+
*/
[DEF] = LAYOUT(
KC_Q, KC_W,              KC_F,              KC_P,              KC_B,       KC_J,   KC_L,              KC_U,              KC_Y,              KC_QUOT,
KC_A, MT(MOD_LALT,KC_R), MT(MOD_LGUI,KC_S), MT(MOD_LCTL,KC_T), KC_G,       KC_M,   MT(MOD_RCTL,KC_N), MT(MOD_RGUI,KC_E), MT(MOD_LALT,KC_I), KC_O,
KC_Z, KC_X,              KC_C,              KC_D,              KC_V,       KC_K,   KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,
                                            MT(MOD_LSFT,KC_LSFT),KC_SPC,   KC_ENT, TO(NAV)
),

/* Layer 2: Navigation and Numbers
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|  esc  |   7   |   8   |   9   |   *   |   |       | home  | pgup  | pgdn  |  end  |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|  tab  |   4   |   5   |   6   |   +   |   |       | left  | down  |  up   | right |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|   =   |   1   |   2   |   3   |   -   |   |       | CTRL  |  GUI  |  ALT  | SHIFT |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
                        |  DEF  |   0   |   | bkspc |  SYM  |
                        +-------+-------+   +-------+-------+
*/
[NAV] = LAYOUT(
KC_ESC,  KC_7, KC_8, KC_9,    UK_ASTR,     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
KC_TAB,  KC_4, KC_5, KC_6,    UK_PLUS,     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
KC_EQL , KC_1, KC_2, KC_3,    KC_MINS,     _______, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
                     TO(DEF), KC_0,        KC_BSPC, TO(SYM)
),

/* Layer 3: Symbols
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|   !   |   @   |  £ €  |   $   |   %   |   |       |   {   |   }   |       |       |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|   ^   |   &   |   #   |   ~   |   `   |   |       |   (   |   )   |   <   |   >   |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|   \   |   |   |   _   |       |       |   |       |   [   |   ]   |       |       |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
                        |  NAV  |       |   |       |  FUN  |
                        +-------+-------+   +-------+-------+
*/
[SYM] = LAYOUT(
KC_EXLM, KC_AT,   UK_PND , KC_DLR,  KC_PERC,     _______, KC_LCBR, KC_RCBR, _______, _______,
KC_CIRC, KC_AMPR, KC_HASH, KC_TILD, KC_GRV,      _______, KC_LPRN, KC_RPRN, KC_LT,   KC_GT,
UK_BSLS, KC_PIPE, KC_UNDS, _______, _______,     _______, KC_LBRC, KC_RBRC, _______, _______,
                           TO(NAV), _______,     _______, TO(FUN)
),

/* Layer 4: Function Keys
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|  F1   |  F2   |  F3   |  F4   |  F5   |   |  F6   |  F7   |  F8   |  F9   |  F10  |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|       |       |       |       |  F11  |   |  F12  |       |       |       |       |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
|       |       |       |       |       |   |       |       |       |       |       |
+-------+-------+-------+-------+-------+   +-------+-------+-------+-------+-------+
                        |  SYM  |       |   |       |       |
                        +-------+-------+   +-------+-------+
*/
[FUN] = LAYOUT(
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
_______, _______, _______, _______, KC_F11,      KC_F12,  _______, _______, _______, _______,
_______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
                           TO(SYM), _______,     _______, _______
)
};

// REPEAT key functionality
// From gist: https://gist.github.com/NotGate/3e3d8ab81300a86522b2c2549f99b131

// // Used to extract the basic tapping keycode from a dual-role key.
// // Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
// #define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
// uint16_t last_keycode = KC_NO;
// uint8_t last_modifier = 0;

// // Initialize variables holding the bitfield
// // representation of active modifiers.
// uint8_t mod_state;
// uint8_t oneshot_mod_state;

// void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
//     if (keycode != REPEAT) {
//         // Early return when holding down a pure layer key
//         // to retain modifiers
//         switch (keycode) {
//             case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
//             case QK_MOMENTARY ... QK_MOMENTARY_MAX:
//             case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
//             case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
//             case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
//             case QK_TO ... QK_TO_MAX:
//             case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
//                 return;
//         }
//         last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
//         switch (keycode) {
//             case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
//             case QK_MOD_TAP ... QK_MOD_TAP_MAX:
//                 if (record->event.pressed) {
//                     last_keycode = GET_TAP_KC(keycode);
//                 }
//                 break;
//             default:
//                 if (record->event.pressed) {
//                     last_keycode = keycode;
//                 }
//                 break;
//         }
//     } else { // keycode == REPEAT
//         if (record->event.pressed) {
//             register_mods(last_modifier);
//             register_code16(last_keycode);
//         } else {
//             unregister_code16(last_keycode);
//             unregister_mods(last_modifier);
//         }
//     }
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     process_repeat_key(keycode, record);
//     // It's important to update the mod variables *after* calling process_repeat_key, or else
//     // only a single modifier from the previous key is repeated (e.g. Ctrl+Shift+T then Repeat produces Shift+T)
//     mod_state = get_mods();
//     oneshot_mod_state = get_oneshot_mods();
//     return true;
// };