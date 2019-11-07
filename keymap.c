/* Copyright 2019 Garret G. (TheRoyalSweatshirt)
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

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   *        ,-----------------------------------------------------------------------------------.
   *        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10  | F11 |  F12 |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|
   *  RotEn | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | PgUp | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | Lower| Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | PgDn | Del  | Ctrl | Alt  | Cmd  |Lower |SPACE |SPACE | Raise| Left | Down |  Up  |Right |
   * `------------------------------------------------------------------------------------------'
   */
  	[_BASE] = LAYOUT(
              KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,
              KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,    KC_MINUS,
    KC__MUTE, KC_ESC,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_BSPC,   
    KC_PGUP,  KC_TAB,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,
    KC_HOME,  KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,   KC_ENT,
    KC_PGDN,  KC_DEL,    KC_RCTRL, KC_LALT,  KC_LCMD,  LOWER,    KC_SPC,   KC_SPC,   RAISE,   KC_LEFT,  KC_DOWN,   KC_UP,    KC_RGHT
  ),

  /* LOWER
   *        ,-----------------------------------------------------------------------------------.
   *        |TOGRGB|      |      |      |Sat(-)|Hue(-)|Hue(+)|Sat(+)|      |      |Brght-|Brght+|
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |  `   |      |      |      |      |      |      |      |      |      |      |   =  |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|
   *  RotEn |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Home | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | End  |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `------------------------------------------------------------------------------------------'
   */
    [_LOWER] = LAYOUT(
              RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SAD,  RGB_HUD,  RGB_HUI,  RGB_SAI,  KC_TRNS,  KC_TRNS,  RGB_VAD,  RGB_VAI,
              KC_GRAVE, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_EQUAL,
    KC_NLCK,  KC_TILD,   KC_EXLM, KC_AT,     KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC, 
    KC_HOME,  KC_DEL,    KC_F1,   KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TRNS,  _______,   KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    KC_END,   _______,   _______, _______,   _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
  ),

  /* RAISE
   *        ,-----------------------------------------------------------------------------------.
   *        |TOGRGB|      |      |      |Sat(-)|Hue(-)|Hue(+)|Sat(+)|      |      |Brght-|Brght+|
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |  `   |      |      |      |      |      |      |      |      |      |      |   =  |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|
   *  RotEn |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Home | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | End  |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `------------------------------------------------------------------------------------------'
   */
    [_RAISE] = LAYOUT(
              RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SAD,  RGB_HUD,  RGB_HUI,  RGB_SAI,  KC_TRNS,  KC_TRNS,  RGB_VAD,  RGB_VAI,
              KC_GRAVE, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_EQUAL,
    KC_NLCK,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
    KC_HOME,  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TRNS,  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    KC_END,   _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC__VOLUP);
        } else {
            tap_code(KC__VOLDOWN);
        }
    }
}
