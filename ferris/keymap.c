#include QMK_KEYBOARD_H

#include "keymap_uk.h"

// enum custom_keycodes {
//     REPEAT = SAFE_RANGE
// };

enum layers {
    DEF,
    EXT,
    SYM,
    NAV,
    FUN,
    QWERTY
};

#define HOME_R MT(MOD_LALT, KC_R)
#define HOME_S MT(MOD_LGUI, KC_S)
#define HOME_T MT(MOD_LCTL, KC_T)

#define HOME_N MT(MOD_LCTL, KC_N)
#define HOME_E MT(MOD_LGUI, KC_E)
#define HOME_I MT(MOD_LALT, KC_I)

#define LYR_NAV LT(NAV, KC_ENT)


// Custom shift actions. 4th argument is layer (bitmask, but easy to translate)
// Stop shift action on some keys
// DEF
// const key_override_t shift_comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_COMM, 1 << DEF | 1 << QWERTY);
// const key_override_t shift_fstop_override = ko_make_with_layers(MOD_MASK_SHIFT,  KC_DOT,  KC_DOT, 1 << DEF | 1 << QWERTY);

// // SYM
// const key_override_t shift_pound_override = ko_make_with_layers(MOD_MASK_SHIFT,  UK_PND,  KC_DLR, 1 << SYM);
// const key_override_t shift_semic_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SCLN, KC_SCLN, 1 << SYM);
// const key_override_t shift_lbrace_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, KC_LBRC, 1 << SYM);
// const key_override_t shift_rbrace_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_RBRC, KC_RBRC, 1 << SYM);
// const key_override_t shift_bksp_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSLS, KC_BSLS, 1 << SYM);
// const key_override_t shift_slash_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_SLSH, 1 << SYM);
// const key_override_t shift_grave_override = ko_make_with_layers(MOD_MASK_SHIFT,  KC_GRV,  KC_GRV, 1 << SYM);

// // NAV
// const key_override_t shift_1_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, KC_1, 1 << NAV);
// const key_override_t shift_2_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, KC_2, 1 << NAV);
// const key_override_t shift_3_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_3, KC_3, 1 << NAV);
// const key_override_t shift_4_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_4, KC_4, 1 << NAV);
// const key_override_t shift_5_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_5, KC_5, 1 << NAV);
// const key_override_t shift_6_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_6, KC_6, 1 << NAV);
// const key_override_t shift_7_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_7, KC_7, 1 << NAV);
// const key_override_t shift_8_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_8, KC_8, 1 << NAV);
// const key_override_t shift_9_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, KC_9, 1 << NAV);
// const key_override_t shift_0_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, KC_0, 1 << NAV);
// const key_override_t shift_minus_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_MINS, 1 << NAV);
// const key_override_t shift_equal_override = ko_make_with_layers(MOD_MASK_SHIFT,  KC_EQL,  KC_EQL, 1 << NAV);
// const key_override_t shift_slash_nav_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_SLSH, 1 << NAV);

// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &shift_comma_override,
//     &shift_fstop_override,
//     &shift_pound_override,
//     &shift_semic_override,
//     &shift_lbrace_override,
//     &shift_rbrace_override,
//     &shift_bksp_override,
//     &shift_slash_override,
//     &shift_grave_override,
//     &shift_1_override,
//     &shift_2_override,
//     &shift_3_override,
//     &shift_4_override,
//     &shift_5_override,
//     &shift_6_override,
//     &shift_7_override,
//     &shift_8_override,
//     &shift_9_override,
//     &shift_0_override,
//     &shift_minus_override,
//     &shift_equal_override,
//     &shift_slash_nav_override,
//     NULL // Null terminate the array of overrides!
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 1: Default/Base - Colemak-DH
[  q  ][  w  ][  f  ][  p  ][  b  ]     [  j  ][  l  ][  u  ][  y  ][ bksp]
[  a  ][  r  ][  s  ][  t  ][  g  ]     [  m  ][  n  ][  e  ][  i  ][  o  ]
[  z  ][  x  ][  c  ][  d  ][  v  ]     [  k  ][  h  ][  ,  ][  .  ][  "  ]
                     [enter][shift]     [space][ SYM ]
*/
[DEF] = LAYOUT(
   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_BSPC,
   KC_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,       KC_M,  HOME_N,  HOME_E,  HOME_I,    KC_O,
   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT, KC_DQUO,
                            KC_ENT, KC_LSFT,     KC_SPC, TO(SYM)
),

/* Layer: Symbols
[ esc ][ £ $ ][  _  ][  @  ][  %  ]     [  ;  ][  :  ][  &  ][  _  ][  +  ]
[ alt ][ gui ][shift][ ctrl][  ^  ]     [  /  ][  (  ][  {  ][  [  ][  <  ]
[  `  ][  |  ][  #  ][  ~  ][  &  ]     [  \  ][  )  ][  }  ][  ]  ][  >  ]
                     [ DEF ][shift]     [space][ NAV ]
*/
[SYM] = LAYOUT(
 KC_ESC, UK_PND,  KC_UNDS,   KC_AT, KC_PERC,    KC_SCLN, KC_COLN, KC_AMPR, KC_PIPE,  KC_DEL,
 KC_TAB, KC_LALT, KC_LGUI, KC_LCTL, KC_EXLM,    KC_SLSH, KC_LPRN, KC_LCBR, KC_LBRC,   KC_LT,
 KC_GRV, KC_CIRC, KC_HASH, KC_TILD, KC_QUES,    KC_BSLS, KC_RPRN, KC_RCBR, KC_RBRC,   KC_GT,
                           TO(DEF), KC_LSFT,     KC_SPC, TO(NAV)
),

/* Layer: Navigation, Numbers
[ esc ][  7  ][  8  ][  9  ][  +  ]     [ del ][ home][ pgdn][ pgup][ end ]
[  *  ][  4  ][  5  ][  6  ][  /  ]     [ bspc][ left][ down][  up ][right]
[  =  ][  1  ][  2  ][  3  ][  -  ]     [ tab ][ ctrl][ gui ][ alt ][shift]
                     [ DEF ][  0  ]     [enter][SYM]
*/
[NAV] = LAYOUT(
 KC_ESC,   KC_7,   KC_8,   KC_9, KC_PLUS,      KC_DEL, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
KC_ASTR,   KC_4,   KC_5,   KC_6, KC_SLSH,     KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
 KC_EQL,   KC_1,   KC_2,   KC_3, KC_MINS,      KC_TAB, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
                        TO(DEF),    KC_0,      KC_ENT, TO(FUN)
),

/* Layer: Functions
[sleep][ B D ][ B U ][ptscr][ D(Q)]     [ RALT][  F9 ][ F10 ][ F11 ][ F12 ]
[ stop][ prev][ next][pl pu][ D(D)]     [ RCTL][  F5 ][  F6 ][  F7 ][  F8 ]
[ mute][ V D ][ V U ][ app ][ calc]     [ RGUI][  F1 ][  F2 ][  F3 ][  F4 ]
                     [ DEF ][shift]     [rpeat][     ]
*/
[FUN] = LAYOUT(
KC_SLEP, KC_BRID, KC_BRIU, KC_PSCR, DF(QWERTY),   KC_LALT,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, DF(DEF),      KC_LCTL,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
KC_MUTE, KC_VOLD, KC_VOLU, KC_APP,  KC_CALC,      KC_LGUI,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
                           TO(DEF), KC_LSFT,       QK_REP, _______
),

/* Layer: QWERTY - Alternative base layer for games, troubleshooting, etc.
[  q  ][  w  ][  e  ][  r  ][  t  ]     [  y  ][  u  ][  i  ][  o  ][  p  ]
[  a  ][  s  ][  d  ][  f  ][  g  ]     [  h  ][  j  ][  k  ][  l  ][ bksp]
[  z  ][  x  ][  c  ][  v  ][  b  ]     [  n  ][  m  ][  ,  ][  .  ][  "  ]
                     [enter][shift]     [space][ NAV ]
*/
[QWERTY] = LAYOUT(
   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC,
   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_DQUO,
                            KC_ENT, KC_LSFT,      KC_SPC, TO(DEF)
)
};