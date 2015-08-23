#ifndef  _SWAY_KEY_STATE_H
#define  _SWAY_KEY_STATE_H
#include <stdbool.h>
#include <stdint.h>
#include "container.h"

/* Keyboard state */

// returns true if key has been pressed, otherwise false
bool check_key(uint32_t key_sym, uint32_t key_code);

// sets a key as pressed
void press_key(uint32_t key_sym, uint32_t key_code);

// unsets a key as pressed
void release_key(uint32_t key_sym, uint32_t key_code);

/* Pointer state */

enum pointer_values {
	M_LEFT_CLICK = 272,
	M_RIGHT_CLICK = 273,
	M_SCROLL_CLICK = 274,
	M_SCROLL_UP = 275,
	M_SCROLL_DOWN = 276,
};

extern struct pointer_state {
	bool l_held;
	bool r_held;
	struct pointer_floating {
		bool drag;
		bool resize;
	} floating;
	struct pointer_tiling {
		bool resize;
		swayc_t *init_view;
		struct wlc_origin lock_pos;
	} tiling;
	struct pointer_lock {
		// Lock movement for certain edges
		bool left;
		bool right;
		bool top;
		bool bottom;
		// Lock movement in certain directions
		bool temp_left;
		bool temp_right;
		bool temp_up;
		bool temp_down;
	} lock;
} pointer_state;

void start_floating(swayc_t *view);
void reset_floating(swayc_t *view);
void input_init(void);

#endif

