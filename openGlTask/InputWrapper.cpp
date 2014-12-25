#include "InputWrapper.h"

InputWrapper::InputWrapper()
{
	params.last_mx = 0, params.last_my = 0, params.cur_mx = 0, params.cur_my = 0;
	params.arcball_on = false;

	params.rotY_direction = 0, params.rotX_direction = 0, params.transZ_direction = 0, params.strife = 0;
	params.speed_factor = 1;
	
	params.screen_width=800, params.screen_height=600;

	params.last_ticks = glutGet(GLUT_ELAPSED_TIME);
}

InputWrapper::~InputWrapper()
{
}

void InputWrapper::display(){};
	void InputWrapper::keyboard(unsigned char key, int x, int y){};
	void InputWrapper::keyboardUp(unsigned char key, int x, int y){};
	void InputWrapper::specialKeyboard(int key, int x, int y){
	int modifiers = glutGetModifiers();
	if ((modifiers & GLUT_ACTIVE_ALT) == GLUT_ACTIVE_ALT)
		params.strife = 1;
	else
		params.strife = 0;

	if ((modifiers & GLUT_ACTIVE_SHIFT) == GLUT_ACTIVE_SHIFT)
		params.speed_factor = 0.1;
	else
		params.speed_factor = 1;

	switch (key) {
	
	case GLUT_KEY_LEFT:
		params.rotY_direction = 1;
		break;
	case GLUT_KEY_RIGHT:
		params.rotY_direction = -1;
		break;
	case GLUT_KEY_UP:
		params.transZ_direction = 1;
		break;
	case GLUT_KEY_DOWN:
		params.transZ_direction =- 1;
		break;
	case GLUT_KEY_PAGE_UP:
		params.rotX_direction =-1;
		break;
	case GLUT_KEY_PAGE_DOWN:
		params.rotX_direction = 1;
		break;
	case GLUT_KEY_HOME:
		//init_view();
		break;
	}}
	void InputWrapper::specialKeyboardUp(int key, int x, int y){
	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
		params.rotY_direction = 0;
		break;
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN:
		params.transZ_direction = 0;
		break;
	case GLUT_KEY_PAGE_UP:
	case GLUT_KEY_PAGE_DOWN:
		params.rotX_direction = 0;
		break;
	}
	};
	void InputWrapper::onMouse (int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		params.arcball_on = true;
		params.cur_mx = x;
		params.last_mx = x;
		params.cur_my = y;
		params.last_my = y;
	} else {
		params.arcball_on = false;
	}};
	void InputWrapper::onMotion (int x, int y){
		if (params.arcball_on) {  // if left button is pressed
		params.cur_mx = x;
		params.cur_my = y;
	}}
	void InputWrapper::onReshape(int width, int height) {
		params.screen_width = width;
		params.screen_height = height;
}
	keyboard_params InputWrapper::get_params(){
		return params;
	}
