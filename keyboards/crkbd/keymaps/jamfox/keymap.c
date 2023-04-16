/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 JamFox <@jamfox>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_est.h"

// Left-hand homerow mod taps
#define MT_S LGUI_T(KC_S)
#define MT_D LALT_T(KC_D)
#define MT_4 LGUI_T(KC_4)
#define MT_5 LALT_T(KC_5)
// Right-hand homerow mod taps
#define MT_K LALT_T(KC_K)
#define MT_L LGUI_T(KC_L)
#define MT_RPRN LALT_T(EE_RPRN)
#define MT_GRV LGUI_T(EE_GRV)
// Temporary mod taps because these keys register incorrectly otherwise
#define MT_A LALT_T(KC_A)
#define MT_XXXX LALT_T(KC_NO)

enum custom_keycodes {
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_BSPC_DEL
};

#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
    {EE_SLSH, EE_BSLS}, // Shift / is backslash
    {EE_DQUO, EE_QUOT}, // Shift " is '
    {EE_LPRN, EE_LBRC}, // Shift ( is [
    {EE_RPRN, EE_RBRC}, // Shift ) is ]
    {EE_LCBR, EE_LABK}, // Shift { is <
    {EE_RCBR, EE_RABK}, // Shift } is >
    {EE_DLR,  EE_EURO}, // Shift $ is €
    {KC_BSPC,  KC_DEL}, // Shift Backspace is Delete
    {EE_HASH, EE_PERC}, // Shift # is %
    {EE_EXLM, EE_QUES}, // Shift ! is ?
    {EE_PLUS, EE_MINS}, // Shift + is -
    {EE_CIRC, EE_CARN}, // Shift ^ is ˇ
    {EE_GRV,  EE_ACUT}, // Shift ` is ´
    {EE_ASTR, EE_CURR}, // Shift * is ¤
    {EE_EQL,  EE_PIPE}, // Shift = is |
    {EE_AT,    EE_PND}, // Shift @ is £
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0 - DEFAULT LAYER
    ,-----------------------------------------------------.                    ,-----------------------------------------------------.
    |        |   Q    |   W    |   E    |   R    |   T    |                    |    Y   |   U    |   I    |   O    |   P    |        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |   A    |   S gui|   D alt|   F    |   G    |                    |    H   |   J    |   K alt|   L gui|   /    |        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |   Z    |   X    |   C    |   V    |   B    |                    |    N   |   M    |   ,    |   .    |   -    |        |
    |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        |        |  Space | LCtrl  |  | LShft  |  LYR1  |        |
                                        `--------------------------'  `--------------------------'
*/
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MT_XXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX,    MT_A,    MT_S,    MT_D,    KC_F,    KC_G,                         KC_H,    KC_J,    MT_K,    MT_L, EE_SLSH, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, EE_MINS, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MT_XXXX,  KC_SPC, KC_LCTL,    KC_LSFT,   TO(1), MT_XXXX
                                      //`--------------------------'  `--------------------------'
  ),

/* 1 - NUM SYM LAYER
    ,-----------------------------------------------------.                    ,-----------------------------------------------------.
    |        |   ESC  |   1    |   2    |   3    |   #%   |                    |   @£   |   +-   |   !?   |   "'   |  Enter |        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |   TAB  |   4 gui|   5 alt|   6    |   $€   |                    |   =|   |   ([alt|   )]gui|   `´   |BSpc Del|        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |   ~    |   7    |   8    |   9    |   0    |                    |   ^ˇ   |   {<   |   }>   |   *¤   |  LYR2  |        |
    |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        |        |  LYR0  | LCtrl  |  | LShft  |  LYR3  |        |
                                        `--------------------------'  `--------------------------'
*/
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     MT_XXXX,KC_ESCAPE,    KC_1,    KC_2,    KC_3, EE_HASH,                        EE_AT, EE_PLUS, EE_EXLM, EE_DQUO,  KC_ENT, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX,  KC_TAB,    MT_4,    MT_5,    KC_6,  EE_DLR,                       EE_EQL, EE_LPRN, MT_RPRN,  MT_GRV, KC_BSPC, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX, EE_TILD,    KC_7,    KC_8,    KC_9,    KC_0,                      EE_CIRC, EE_LCBR, EE_RCBR, MT_XXXX,   TO(2), MT_XXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MT_XXXX,   TO(0), KC_LCTL,    KC_LSFT,   TO(3), MT_XXXX
                                      //`--------------------------'  `--------------------------'
  ),

/* 2 - DIA LAYER
    ,-----------------------------------------------------.                    ,-----------------------------------------------------.
    |        |        |        |        |        |        |                    |        |   Ü    |        |   Ö    |   Õ    |        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |   Ä    |   Š    |        |        |        |                    |        |        |        |        |        |        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |   Ž    |        |        |        |        |                    |        |        |        |        |        |        |
    |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        |        |  LYR0  | LCtrl  |  | LShft  |  LYR4  |        |
                                        `--------------------------'  `--------------------------'
*/
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX,                      MT_XXXX, EE_UDIA, MT_XXXX, EE_ODIA, EE_OTIL, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX, EE_ADIA, EE_SCAR, MT_XXXX, MT_XXXX, MT_XXXX,                      MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX, EE_ZCAR, MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX,                      MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MT_XXXX,   TO(0), KC_LCTL,    KC_LSFT,   TO(4), MT_XXXX
                                      //`--------------------------'  `--------------------------'
  ),

/* 3 - EXT LAYER
    ,-----------------------------------------------------.                    ,-----------------------------------------------------.
    |        |        |        | VOLDO  | VOLUP  |  MUTE  |                    | PageUp |  PWrd  |   Up   |  NWrd  |  Home  |        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |        | Insert | PrtScr |  Alt   |  Gui   |                    | PageDn |  Left  |  Down  |  Right |  End   |        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |  Undo  |  Cut   |  Copy  | Paste  |        |                    |        |  PREV  |  PLAY  |  NEXT  |        |        |
    |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        |        |  LYR0  | LCtrl  |  | LShft  |  LYR4  |        |
                                        `--------------------------'  `--------------------------'
*/
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MT_XXXX, MT_XXXX, MT_XXXX, KC_VOLD, KC_VOLU, KC_MUTE,                      KC_PGUP,KC_PRVWD,   KC_UP,KC_NXTWD, KC_HOME, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX, MT_XXXX, KC_INS, KC_PSCR,  KC_LALT, KC_LGUI,                      KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_END, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, MT_XXXX,                      MT_XXXX, KC_MPRV, KC_MPLY, KC_MNXT, MT_XXXX, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MT_XXXX,   TO(0), KC_LCTL,    KC_LSFT,   TO(4), MT_XXXX
                                      //`--------------------------'  `--------------------------'
  ),

/* 4 - FUNC LAYER
    ,-----------------------------------------------------.                    ,-----------------------------------------------------.
    |        |        |   F1   |   F2   |   F3   |   F10  |                    |        |        |        |        | Enter  |        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |        |   F4   |   F5   |   F6   |   F11  |                    |        |        |  Alt   |  Gui   |BSpc Del|        |
    |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    |        |        |   F7   |   F8   |   F9   |   F12  |                    |        |        |        |        |        |        |
    |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        |        |  LYR0  | LCtrl  |  | LShft  |        |        |
                                        `--------------------------'  `--------------------------'
*/
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MT_XXXX, MT_XXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                      MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX,  KC_ENT, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX, MT_XXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      MT_XXXX, MT_XXXX, KC_LALT, KC_LGUI, KC_BSPC, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT_XXXX, MT_XXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                      MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX, MT_XXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MT_XXXX,   TO(0), KC_LCTL,    KC_LSFT, MT_XXXX, MT_XXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Print keylog to OLED
    #ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    #endif
    // Process custom shift keys
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    // Intercept custom keycodes
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}
