#ifndef CONTROLLER_H
#define CONTROLLER_H

enum Key { KEY_NONE, KEY_LEFT, KEY_RIGHT, KEY_FIRE, KEY_COUNT };

/* Use gCtrl.isDown(keycode) to check if command <keycode> is pressed.
 * If the player should fire only once per key press,
 * use gCtrl.reset(KEY_FIRE) after firing.
 * Otherwise, keep an internal cooldown timer in the player class.
 */


class Controller
{
public:
	static void registerCallbacks();

	void reset(Key key)  { is_down[key] = false; }
	bool isDown(Key key) { return  is_down[key]; }
	bool isUp(Key key)   { return !is_down[key]; }
private:
	static void onKeyPress(unsigned char ascii, int x, int y);
	static void onKeyUp(unsigned char ascii, int x, int y);
	void setKeyPressed(unsigned char ascii, bool state);

	// Initialize all keys to "not down"
	bool is_down[KEY_COUNT] = { false };
};

// Global controller
extern Controller gCtrl;

#endif
