#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    MOUSE,  // mouse
    EXPR,  // experiments
    EXPR1,  // experiments aux
    EXPR2,  // experiments aux
    CORNE1,
    CORNE2,
    CORNE3,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  | TO(5)|           | Mute |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  MWU |           |  MWD |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CapsLock|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|   =  |           |  -   |------+-----+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |TO(1) |KC_LNG1| Alt | Ctrl/Left| Gui/Right|                               |Gui/Up|Ctrl/Down|Alt/[|  ] | TO(2)  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Prev | Next |       | Left | Right |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | Back |      | Vol+ |       |  Up  |        |      |
 *                                 | Space| Esc  |------|       |------| Enter  |Space |
 *                                 |      |      | Vol- |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  //left hand
  KC_GRV,     KC_1,    KC_2,        KC_3,            KC_4,    KC_5,    TO(5),              KC_MUTE,     KC_6,   KC_7,          KC_8,            KC_9,            KC_0,    KC_DEL,
  KC_TAB,     KC_Q,    KC_W,        KC_E,            KC_R,    KC_T,    KC_WH_U,              KC_WH_D,     KC_Y,   KC_U,          KC_I,            KC_O,            KC_P,    KC_BSLS,
  KC_CAPS,    KC_A,    KC_S,        KC_D,            KC_F,    KC_G,                                       KC_H,   KC_J,          KC_K,            KC_L,            KC_SCLN, KC_QUOT,
  KC_LSFT,    KC_Z,    KC_X,        KC_C,            KC_V,    KC_B,    KC_EQL,               KC_MINS,     KC_N,   KC_M,          KC_COMM,         KC_DOT,          KC_SLSH, KC_RSFT,
  TO(1),      KC_LNG1, LALT(KC_NO), LCTL_T(KC_LEFT), LGUI_T(KC_RGHT),                                             RGUI_T(KC_UP), RCTL_T(KC_DOWN), RALT_T(KC_LBRC), KC_RBRC, TO(2),
                                                                 KC_MPRV, KC_MNXT,         KC_LEFT, KC_RGHT,
                                                                          KC_VOLU,         KC_UP,
                                                         KC_BSPC, KC_ESC, KC_VOLD,         KC_DOWN, KC_ENT, KC_SPC
),
/* Keymap 1: Mouse / Numeric Pad Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         | WH_U |      | MS_U |      |      |      |           |      |      |   7  |   8  |   9  |   *  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | WH_D | MS_L | MS_D | MS_D |   `  |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | WH_L |      | WH_R |      |      |           |      |      |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TO(0) |      |      |      |      |                                       |      |    . |   0  |   =  | TO(0) |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |M_BTN1|M_BTN2|------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOUSE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
  KC_TRNS, KC_WH_U, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_TRNS,
  KC_TRNS, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                     KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WH_L, KC_TRNS, KC_WH_R, KC_TRNS, KC_TRNS,   KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  TO(0),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  TO(0),
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_BTN1, KC_BTN2, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Experiment Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  | Play |           | Mute |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  MWU |           |  MWD |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CapsLock|   A  |Alt/S |Ctl/D |GUI/F |   G  |------|           |------|   H  |GUI/J | Ctl/K|Alt/L |  ;   |   '    |
 * |--------+------+------+------+------+------|   =  |           |  -   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |TO(0) |KC_LNG1|     |      |      |                                       |      |      |   [  |   ]  | TO(0)  |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Prev | Next |       | Left | Right |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | LT3  |      | Vol+ |       |  Up  |        | LT3  |
 *                                 | Back | Esc  |------|       |------| Enter  |Space |
 *                                 | Space|      | Vol- |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[EXPR] = LAYOUT_ergodox_pretty(
  //left hand
  KC_GRV,     KC_1,    KC_2,        KC_3,            KC_4,          KC_5,    KC_MPLY,              KC_MUTE,     KC_6,   KC_7,          KC_8,            KC_9,            KC_0,    KC_DEL,
  KC_TAB,     KC_Q,    KC_W,        KC_E,            KC_R,          KC_T,    KC_WH_U,              KC_WH_D,     KC_Y,   KC_U,          KC_I,            KC_O,            KC_P,    KC_BSLS,
  KC_CAPS,    KC_A,    LALT_T(KC_S),LCTL_T(KC_D),    LGUI_T(KC_F),  KC_G,                                       KC_H,   RGUI_T(KC_J),  RCTL_T(KC_K),    RALT_T(KC_L),    KC_SCLN, KC_QUOT,
  KC_LSFT,    KC_Z,    KC_X,        KC_C,            KC_V,          KC_B,    KC_EQL,               KC_MINS,     KC_N,   KC_M,          KC_COMM,         KC_DOT,          KC_SLSH, KC_RSFT,
  TO(0),      KC_LNG1, KC_TRNS,     KC_TRNS,         KC_TRNS,                                                           KC_TRNS,       KC_TRNS,         KC_LBRC,         KC_RBRC, TO(0),
                                                                 KC_MPRV, KC_MNXT,         KC_LEFT, KC_RGHT,
                                                                          KC_VOLU,         KC_UP,
                                           LT(3, KC_BSPC), LT(4, KC_ESC), KC_VOLD,         KC_DOWN, LT(4, KC_ENT), LT(3, KC_SPC)
),


/* Keymap 3: Experiment Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  | Play |           | Mute |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |      |      |  Up  |      |      |  MWU |           |  MWD |      |   7  |   8  |   9  |      |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CapsLock|      | Left | Down | Right|      |------|           |------|      |   4  |   5  |   6  |  ;   |   '    |
 * |--------+------+------+------+------+------|   =  |           |  -   |------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |TO(0) |KC_LNG1|  -  |      |      |                                       |   ,  |   0  |   .  |      | TO(0)  |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Prev | Next |       | Left | Right |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | Back |      | Vol+ |       |  Up  |        |      |
 *                                 | Space| Esc  |------|       |------| Enter  |Space |
 *                                 |      |      | Vol- |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[EXPR1] = LAYOUT_ergodox_pretty(
  //left hand
  KC_GRV,     KC_1,    KC_2,        KC_3,           KC_4,          KC_5,    KC_MPLY,              KC_MUTE,     KC_6,   KC_7,          KC_8,            KC_9,            KC_0,    KC_DEL,
  KC_TAB,     KC_TRNS, KC_TRNS,     KC_UP,          KC_TRNS,       KC_TRNS, KC_WH_U,              KC_WH_D,     KC_TRNS,KC_7,          KC_8,            KC_9,            KC_TRNS, KC_BSLS,
  KC_CAPS,    KC_TRNS, KC_LEFT,     KC_DOWN,        KC_RIGHT,      KC_TRNS,                                    KC_TRNS,KC_4,          KC_5,            KC_6,            KC_SCLN, KC_QUOT,
  KC_LSFT,    KC_TRNS, KC_TRNS,     KC_TRNS,        KC_TRNS,       KC_TRNS, KC_EQL,               KC_MINS,     KC_TRNS,KC_1,          KC_2,            KC_3,            KC_SLSH, KC_RSFT,
  TO(0),      KC_LNG1, KC_NO,       KC_TRNS,        KC_TRNS,                                                           KC_COMM,       KC_0,            KC_DOT,          KC_TRNS, TO(0),
                                                                 KC_MPRV, KC_MNXT,         KC_LEFT, KC_RGHT,
                                                                          KC_VOLU,         KC_UP,
                                                         KC_BSPC, KC_ESC, KC_VOLD,         KC_DOWN, KC_ENT, KC_SPC
),

/* Keymap 4: Experiment Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  | Play |           | Mute |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |  Up  |   R  |   T  |  MWU |           |  MWD |   Y  |   7  |   8  |   9  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CapsLock|   A  | Left | Down | Right|      |------|           |------|   H  |   4  |   5  |   6  |  ;   |   '    |
 * |--------+------+------+------+------+------|   =  |           |  -   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   1  |   2  |   3  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |TO(0) |KC_LNG1|  -  |      |      |                                       |      |   0  |   .  |   ]  | TO(0)  |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Prev | Next |       | Left | Right |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | Back |      | Vol+ |       |  Up  |        |      |
 *                                 | Space| Esc  |------|       |------| Enter  |Space |
 *                                 |      |      | Vol- |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[EXPR2] = LAYOUT_ergodox_pretty(
  //left hand
  KC_GRV,     KC_1,    KC_2,        KC_3,           KC_4,          KC_5,    KC_MPLY,              KC_MUTE,     KC_6,   KC_7,          KC_8,            KC_9,            KC_0,    KC_DEL,
  KC_TAB,     KC_Q,    KC_W,        KC_UP,          KC_R,          KC_T,    KC_WH_U,              KC_WH_D,     KC_Y,   KC_7,          KC_8,            KC_9,            KC_P,    KC_BSLS,
  KC_CAPS,    KC_A,    KC_LEFT,     KC_DOWN,        KC_RIGHT,      KC_TRNS,                                    KC_H,   KC_4,          KC_5,            KC_6,            KC_SCLN, KC_QUOT,
  KC_LSFT,    KC_Z,    KC_X,        KC_C,           KC_V,          KC_B,    KC_EQL,               KC_MINS,     KC_N,   KC_1,          KC_2,            KC_3,            KC_SLSH, KC_RSFT,
  TO(0),      KC_LNG1, KC_NO,       KC_TRNS,        KC_TRNS,                                                           KC_TRNS,       KC_0,            KC_DOT,          KC_RBRC, TO(0),
                                                                 KC_MPRV, KC_MNXT,         KC_LEFT, KC_RGHT,
                                                                          KC_VOLU,         KC_UP,
                                                         KC_BSPC, KC_ESC, KC_VOLD,         KC_DOWN, KC_ENT, KC_SPC
),

/* Keymap 5: Corne Layout Layer 1
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   -    |   -  |   -  |   -  |   -  |   -  |TO(0) |           |   -  |   -  |   -  |   -  |   -  |   -  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |  E   |   R  |   T  |   -  |           |   -  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    -   |   A  |   S  |  D   |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|   -  |           |   -  |------+------+------+------+------+--------|
 * |   -    |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  -   |   -  |  -  |   -  |   -  |                                       |   -  |   -  |   -  |   -  |    -  |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  -   |  -   |       |   -  |   -   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | LT7  | LT6  |  -   |       |   -  | LT7    | LT6  |
 *                                 | Back | Esc  |------|       |------| Enter  |Space |
 *                                 | Space|      | Vol- |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[CORNE1] = LAYOUT_ergodox_pretty(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO,   KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
  KC_NO, LALT_T(KC_A), LSFT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), KC_G,   KC_H, RGUI_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), RALT_T(KC_SCLN), KC_QUOT,
  KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO,   KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,

  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

  KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO,
  LT(7, KC_BSPC), LT(6, KC_ESC), KC_VOLD,   KC_DOWN, LT(7, KC_ENT), LT(6, KC_SPC)
),

/* Keymap 6: Corne Layout Layer 2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   -    |   -  |   -  |   -  |   -  |   -  |TO(0) |           |   -  |   -  |   -  |   -  |   -  |   -  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   1  |   2  |  3   |   4  |   5  |   -  |           |   -  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   -    |   -  |   -  |  -   |   -  |   -  |------|           |------| Left | Down |  Up  |Right |  -   |   -    |
 * |--------+------+------+------+------+------|   -  |           |   -  |------+------+------+------+------+--------|
 * |  -     |   -  |   -  |   -  |   -  |   -  |      |           |      |   -  |   -  |   -  |   -  |  -   |   -    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  -   |   -  |  -  |   -  |   -  |                                       |   -  |   -  |   -  |   -  |    -  |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  -   |  -   |       |   -  |   -   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | Back |      |  -   |       |   -  |        |      |
 *                                 | Space| Esc  |------|       |------| Enter  |Space |
 *                                 |      |      | Vol- |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[CORNE2] = LAYOUT_ergodox_pretty(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

  KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,   KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

  KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO,
  KC_BSPC, KC_ESC, KC_VOLD,   KC_DOWN, KC_ENT, KC_SPC
),

/* Keymap 7: Corne Layout Layer 3
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   -    |   -  |   -  |   -  |   -  |   -  |TO(0) |           |   -  |   -  |   -  |   -  |   -  |   -  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   !  |   @  |  #   |   $  |   %  |   -  |           |   -  |   ^  |   &  |   *  |   (  |   )  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    -   |   -  |   -  |  -   |   -  |   -  |------|           |------|  -_  |  +=  |  [{  |  }]  |  \|  |   -    |
 * |--------+------+------+------+------+------|   -  |           |   -  |------+------+------+------+------+--------|
 * |  -     |   -  |   -  |   -  |   -  |   -  |      |           |      |   -  |   +  |   {  |   }  |  |   |   -    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  -   |   -  |  -  |   -  |   -  |                                       |   -  |   -  |   -  |   -  |    -  |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  -   |  -   |       |   -  |   -   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | Back |      |  -   |       |   -  |        |      |
 *                                 | Space| Esc  |------|       |------| Enter  |Space |
 *                                 |      |      | Vol- |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
[CORNE3] = LAYOUT_ergodox_pretty(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

  KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_NO,   KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_NO,

  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

  KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO,
  KC_BSPC, KC_ESC, KC_VOLD,   KC_DOWN, KC_ENT, KC_SPC
),

};

const uint16_t PROGMEM caps_lock_combo[] = {KC_L, KC_S, COMBO_END};
const uint16_t PROGMEM lang_combo[] = {KC_SPC, KC_BSPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(caps_lock_combo, KC_CAPS),
    COMBO(lang_combo, KC_LNG1),
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN: SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case KC_LNG1:
                SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_SPC) SS_UP(X_LALT) SS_UP(X_LCTL));
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
}
