#include "GlutWindow.h"
#include "openGlObj.h"
#include <vector>



class InputWrapper//: public GlutWindow

{
public:
	InputWrapper();
	~InputWrapper();
	void display();
	void keyboard(unsigned char key, int x, int y);
	void keyboardUp(unsigned char key, int x, int y);
	void specialKeyboard(int key, int x, int y);
	void specialKeyboardUp(int key, int x, int y);
	void onMouse (int button, int state, int x, int y);
	void onMotion (int x, int y);
	void onReshape(int width, int height);
	keyboard_params get_params();

private:
	
	keyboard_params params;


};

