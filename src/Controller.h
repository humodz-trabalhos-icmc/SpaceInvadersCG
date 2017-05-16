#ifndef CONTROLLER_H
#define CONTROLLER_H

enum Key { KEY_NONE, KEY_LEFT, KEY_RIGHT, KEY_FIRE, KEY_COUNT };

/* Usage examples
 * gCtrl.isDown(KEY_FIRE) == true -> fire button is pressed
 * gCtrl.reset(KEY_FIRE) -> set fire button to "not pressed"
 *
 * Event handlers are used to determine which keys are pressed
 */

class Controller
{
public:
	static void registerCallbacks();

	// Sets <key> to "not pressed"
	void reset(Key key)  { is_down[key] = false; }

	// Returns true if the key is pressed/released
	bool isDown(Key key) { return  is_down[key]; }
	bool isUp(Key key)   { return !is_down[key]; }
private:
	// Event handlers
	static void onKeyPress(unsigned char ascii, int x, int y);
	static void onKeyUp(unsigned char ascii, int x, int y);

	// Sets the state of the corresponding key
	// state == true  -> key was pressed
	// state == false -> key was released
	void setKeyPressed(unsigned char ascii, bool state);

	// is_down[name] == true  -> key <name> is pressed
	// is_down[name] == false -> key <name> is not pressed
	bool is_down[KEY_COUNT] = { false };
};

// Global controller
// Don't instantiate another controller, use this instance
extern Controller gCtrl;

#endif
