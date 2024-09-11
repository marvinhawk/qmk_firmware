#include QMK_KEYBOARD_H

/* Drag scroll setup */
// Configuration options
#define SCROLL_TIMEOUT 1000
#define DELTA_X_THRESHOLD 60
#define DELTA_Y_THRESHOLD 15

bool scroll_enabled = false;
bool lock_state     = false;

// State
static int8_t delta_x = 0;
static int8_t delta_y = 0;
/*---*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_LGUI)
};


/* Drag scroll stup */


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scroll_enabled) {
        delta_x += mouse_report.x;
        delta_y += mouse_report.y;

        if (delta_x > DELTA_X_THRESHOLD) {
            mouse_report.h = 1;
            delta_x        = 0;
        } else if (delta_x < -DELTA_X_THRESHOLD) {
            mouse_report.h = -1;
            delta_x        = 0;
        }

        if (delta_y > DELTA_Y_THRESHOLD) {
            mouse_report.v = -1;
            delta_y        = 0;
        } else if (delta_y < -DELTA_Y_THRESHOLD) {
            mouse_report.v = 1;
            delta_y        = 0;
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

void keyboard_post_init_user(void) {
	lock_state = host_keyboard_led_state().num_lock;
}

bool led_update_user(led_t led_state) {
	static uint8_t lock_count = 0;
	static uint16_t scroll_timer = 0;

	if (timer_elapsed(scroll_timer) > SCROLL_TIMEOUT) {
		scroll_timer = timer_read();
		lock_count = 0;
	}

	if (led_state.num_lock != lock_state) {
		lock_count++;

		if (lock_count == 2) {
			scroll_enabled = !scroll_enabled;
			lock_count = 0;
		}
	}

	lock_state = led_state.num_lock;
	return true;
}
