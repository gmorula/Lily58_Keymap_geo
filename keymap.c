#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>

extern uint8_t is_master;

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif 

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Tap Dance enum
enum {
    TD_CAPSLK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BkSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift/CAPS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE | Menu | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,	    KC_1, 	KC_2, 	KC_3,	KC_4,	KC_5,                       KC_6,	  KC_7,	  KC_8,	    KC_9,	  KC_0,	    KC_BSPC, \
  KC_TAB,       KC_Q,	KC_W,   KC_E,   KC_R,	KC_T,	                    KC_Y,	  KC_U,	  KC_I,	    KC_O,	  KC_P,	    KC_BSLS, \
  KC_LSFT,      KC_A, 	KC_S,	KC_D,	KC_F,   KC_G,	                    KC_H,	  KC_J,   KC_K,	    KC_L,	  KC_SCLN,	KC_QUOT, \
  KC_LCTL,	    KC_Z,	KC_X, 	KC_C,	KC_V,   KC_B,  KC_LBRC,	KC_RBRC,	KC_N,	  KC_M,	  KC_COMM,	KC_DOT,	KC_SLSH,	TD(TD_CAPSLK), \
                        KC_LGUI,	KC_LALT,  MO(_LOWER), KC_SPC,	KC_ENT,	MO(_RAISE),	KC_APP,	KC_RALT \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      |      |      |      |      |                    |      |      |      |  -  |  =   | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LCTRL |      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift/CAPS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | Menu | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,	KC_NO,	KC_NO,	    KC_NO,      KC_NO,  KC_NO,	                KC_NO,	KC_NO,  KC_NO,	KC_MINS,    KC_EQL,	  KC_DEL, \
  KC_F1,	KC_F2,	KC_F3,	    KC_F4,	    KC_F5,	KC_F6,                  KC_F7,  KC_F8,	KC_F9,	KC_F10,	    KC_F11,	  KC_F12, \
  KC_LSFT,	KC_NO,	KC_NO,	    KC_NO,	    KC_NO,  KC_NO,                  KC_NO,	KC_NO,	KC_NO,	KC_NO,	    KC_NO,	  KC_NO, \
  KC_LCTL,	KC_NO,	KC_NO,	    KC_NO,	    KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,      KC_NO,	  TD(TD_CAPSLK), \
                    KC_LGUI,    KC_LALT,    MO(_LOWER), KC_SPC,	KC_ENT,	MO(_RAISE),	KC_APP,	KC_RALT \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ~  |      |      |      |      | BRI+ |                    | PSCR |PAUSE | BRAKE|   _   |   +  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      | BRI- |                    | Home |  Up  | PgUp |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|      |      |      |      | VOl+ |-------.    ,-------| Left | Down | Right|      |      |      |
 * |------+------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
 * |LCTRL |      |      |      |      | VOL- |-------|    |-------|  End | Ins  | PgDn |      |      |RShift/CAPS|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | Menu | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT( \
  RSFT(KC_GRV),	 KC_NO,	  KC_NO,	  KC_NO,	  KC_NO,	  KC_BRIU,                          KC_PSCR,	KC_PAUS,	 KC_BRK,	RSFT(KC_MINS),	RSFT(KC_EQL),	KC_DEL, \
  KC_NO,	  KC_NO,	  KC_NO,	  KC_NO,	  KC_NO,	  KC_BRID,                          KC_HOME,	KC_UP,	    KC_PGUP,	KC_NO,	KC_NO,	KC_NO, \
  KC_LSFT,	  KC_NO,	  KC_NO,	  KC_NO,	  KC_NO,	  KC_VOLU,	                    KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_NO,	KC_NO,	KC_NO, \
  KC_LCTL,	  KC_NO,	  KC_NO,	  KC_NO,	  KC_NO,	  KC_VOLD,  KC_MUTE,   KC_NO,	KC_END,	  KC_INS,	  KC_PGDN,	KC_NO,	KC_NO,	TD(TD_CAPSLK), \
                      KC_LGUI,	KC_LALT,  MO(_LOWER), KC_SPC,	KC_ENT,	MO(_RAISE),	KC_APP,	KC_RALT \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | PWR  |      |      |      |      |      |                    |      |      |      |      |      |  CTRL+ALT+DEL |
 * |- -----+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | SLEEP|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | Menu | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  KC_PWR,    KC_NO,	  KC_NO,  KC_NO,    KC_NO,  KC_NO,                 KC_NO,    KC_NO,	  KC_NO,  KC_NO,    KC_NO, LALT(LCTL(KC_DEL)), \
  KC_SLEP,    KC_NO,	  KC_NO,  KC_NO,    KC_NO,  KC_NO,             KC_NO,    KC_NO,	  KC_NO,  KC_NO,    KC_NO,  KC_NO, \
  KC_NO,    KC_NO,	  KC_NO,  KC_NO,    KC_NO,  KC_NO,                 KC_NO,    KC_NO,	  KC_NO,  KC_NO,    KC_NO,  KC_NO, \
  KC_NO,    KC_NO,	  KC_NO,  KC_NO,    KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,    KC_NO,	  KC_NO,  KC_NO,    KC_NO,  KC_NO,\
                        KC_LGUI,	KC_LALT,  MO(_LOWER), KC_SPC,	KC_ENT,	MO(_RAISE),	KC_APP,	KC_RALT \
  )
};

//----------- RGB Config -----------------------
#ifdef RGBLIGHT_ENABLE
int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}
#endif 
//-------------------------------------------------


//---------- Tap Dance definitions ----------------
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPSLK] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS)
};
//--------------------------------------------------


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


//------------ SSD1306 OLED update loop ------------
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { 
  if (!is_keyboard_master()) {
      return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  } else {
      return OLED_ROTATION_270;
  }
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};
    
    // Set host_keyboard_led_state to detect CAPS
    led_t led_state = host_keyboard_led_state();

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if((modifiers & MOD_MASK_SHIFT) || (led_state.caps_lock)) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if((modifiers & MOD_MASK_SHIFT) || (led_state.caps_lock)) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if((modifiers & MOD_MASK_SHIFT) || (led_state.caps_lock)) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if((modifiers & MOD_MASK_SHIFT) || (led_state.caps_lock)) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM lily58_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    static const char PROGMEM lily58_text[] = {
        0x01, 0x02, 0x03, 0x04, 0x05, 0};

    oled_write_P(lily58_logo, false);
    oled_write_P(lily58_text, false);
}

static void render_logo_secondary(void) {
    static const char PROGMEM raw_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 
        0x70, 0x18, 0x0c, 0x18, 0x30, 0xe0, 0x80, 0x00, 0x00, 0x10, 0xf8, 0x90, 0x10, 0x30, 0x78, 0x30, 
        0x10, 0xb8, 0xfc, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xf8, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x9c, 0x1c, 0x00, 0x00, 
        0x00, 0x00, 0xf8, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xfc, 0xf8, 0xc0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0x7c, 0x1c, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0xfc, 
        0xfc, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 
        0xf0, 0xf8, 0x38, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x3c, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xbc, 0xe0, 0x81, 0x81, 0x81, 0x83, 0x83, 0x82, 0x87, 0x0c, 
        0x18, 0x30, 0x60, 0xc0, 0x00, 0x00, 0x1f, 0xfe, 0x90, 0xb9, 0xff, 0xbb, 0x91, 0x98, 0x3c, 0x18, 
        0x11, 0x13, 0x3f, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x7f, 
        0xf8, 0xe0, 0x80, 0xf0, 0xfc, 0x3f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 
        0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x3c, 0x78, 0xf8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xc3, 
        0xe7, 0xff, 0x7e, 0x3c, 0x38, 0x78, 0x78, 0x70, 0x70, 0xf8, 0xff, 0xdf, 0x87, 0x00, 0x00, 0x00, 
        0x18, 0x3c, 0x24, 0x66, 0x63, 0x41, 0xc1, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0xc1, 
        0x41, 0x62, 0x38, 0x6c, 0x4c, 0xc6, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0xc1, 0x43, 
        0x62, 0x36, 0x1c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0xc0, 
        0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x7f, 0x00, 0x00, 
        0x00, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x80, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xe0, 
        0xf9, 0x7f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf0, 0xe0, 
        0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xf0, 0xf8, 0x7f, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x3f, 
        0x7f, 0xf9, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xf9, 0x7f, 0x3f, 0x1f, 0x00, 0x00
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}


void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_status_main(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_logo_secondary();
}


void oled_task_user(void) {

    if (is_keyboard_master()) {
        render_status_main();
    } else {
        render_status_secondary();
    }
}

#endif 
// END OLED_DRIVER_ENABLE
//--------------------------------------------------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {

  }
  return true;
}