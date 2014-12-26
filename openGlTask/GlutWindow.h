
#include <iostream>
#include "OpenglIncludes.h"




class GlutWindow
{
protected:
	static GlutWindow *instance;
public:
	static void displayWrapper();
	static void runWrapper();
	static void keyboardWrapper(unsigned char key, int x, int y);
	static void onMouseWrapper(int button, int state, int x, int y);
	static void keyboardUpWrapper(unsigned char key, int x, int y);
	static void specialKeyboardWrapper(int key, int x, int y);
	static void specialKeyboardUpWrapper(int key, int x, int y);
	static void onMotionWrapper(int x, int y);
	void startFramework(int argc, char *argv[]);
	void setInstance(GlutWindow *framework);
	virtual keyboard_params get_params();
 
	//void run();
	virtual void display(){};
	virtual void keyboard(unsigned char key, int x, int y) = 0 ;
	virtual void keyboardUp(unsigned char key, int x, int y) = 0;
	virtual void specialKeyboard(int key, int x, int y) = 0;
	virtual void specialKeyboardUp(int key, int x, int y) =  0;
	virtual void onMouse (int button, int state, int x, int y) = 0;
	virtual void onMotion (int x, int y) = 0 ;
};