#include <stdint.h>
#include "usb_hid_keys.h"

#define KEYBOARD_NUM_OF_COLUMNS 16 // !< Number of columns in the keyboard matrix
#define KEYBOARD_NUM_OF_ROWS    9  // !< Number of rows in the keyboard matrix

static const uint8_t row_pin_array[KEYBOARD_NUM_OF_ROWS] = {0,3,21,22,23,25,28,20,30};
static const uint8_t column_pin_array[KEYBOARD_NUM_OF_COLUMNS] = {1,2,4,5,6,7,8,9,10,11,12,13,14,15,24,29};

static const uint8_t wakeup_button_row_index = 6;			//select row_pin_array[2] = 21
static const uint8_t wakeup_button_column_index = 10;	//select column_pin_array[1] = 2 
//wakeup button is default_matrix_lookup[2][1] = 0x29 and it's ESC key

/** Table containing the mapping between the key matrix and the HID Usage codes for each key. */
static const uint8_t default_matrix_lookup[KEYBOARD_NUM_OF_COLUMNS * KEYBOARD_NUM_OF_ROWS] =
{
	KEY_NONE,       KEY_NONE,    KEY_KP6,        KEY_KP5,     KEY_KP4,     KEY_LEFTBRACE,  KEY_RIGHTBRACE, KEY_BACKSPACE, KEY_NONE,      KEY_LEFTSHIFT,  KEY_TAB,   KEY_CAPSLOCK,  KEY_F3,   KEY_T,    KEY_Y,    KEY_F7,
	KEY_NONE,       KEY_HOME,    KEY_PAGEUP,     KEY_INSERT,  KEY_DELETE,  KEY_MINUS,      KEY_EQUAL,      KEY_F9,        KEY_LEFTCTRL,  KEY_NONE,       KEY_GRAVE, KEY_F1,        KEY_F2,   KEY_5,    KEY_6,    KEY_F8,
	KEY_SYSRQ,      KEY_END,     KEY_PAGEDOWN,   KEY_F12,     KEY_F11,     KEY_0,          KEY_8,          KEY_F10,       KEY_NONE,      KEY_NONE,       KEY_1,     KEY_2,         KEY_3,    KEY_4,    KEY_7,    KEY_9,
	KEY_SCROLLLOCK, KEY_KPPLUS,  KEY_KP9,        KEY_KP8,     KEY_KP7,     KEY_P,          KEY_I,          KEY_NONE,      KEY_NONE,      KEY_NONE,       KEY_Q,     KEY_W,         KEY_E,    KEY_R,    KEY_U,    KEY_O,
	KEY_NONE,       KEY_KPENTER, KEY_KP3,        KEY_KP2,     KEY_KP1,     KEY_SEMICOLON,  KEY_K,          KEY_HASHTILDE, KEY_NONE,      KEY_NONE,       KEY_A,     KEY_S,         KEY_D,    KEY_F,    KEY_J,    KEY_L,
	KEY_RIGHTALT,   KEY_LEFT,    KEY_KPMINUS,    KEY_RIGHT,   KEY_DOWN,    KEY_SLASH,      KEY_NONE,       KEY_SPACE,     KEY_NONE,      KEY_NONE,       KEY_NONE,  KEY_NONE,      KEY_NONE, KEY_B,    KEY_N,    KEY_NONE,
	KEY_LEFTALT,    KEY_UP,      KEY_KPDOT,      KEY_KP0,     KEY_NONE,    KEY_APOSTROPHE, KEY_F6,         KEY_F5,        KEY_NONE,      KEY_NONE,       KEY_ESC,   KEY_102ND,     KEY_F4,   KEY_G,    KEY_H,    KEY_NONE,
	KEY_NONE,       KEY_PAUSE,   KEY_KPASTERISK, KEY_KPSLASH, KEY_NUMLOCK, KEY_NONE,       KEY_COMMA,      KEY_ENTER,     KEY_RIGHTCTRL, KEY_RIGHTSHIFT, KEY_Z,     KEY_X,         KEY_C,    KEY_V,    KEY_M,    KEY_DOT,
	KEY_NONE,       KEY_NONE,    KEY_NONE,       KEY_NONE,    KEY_NONE,    KEY_NONE,       KEY_NONE,       KEY_NONE,      KEY_NONE,      KEY_NONE,       KEY_NONE,  KEY_NONE,      KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE
};