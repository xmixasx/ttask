#include "GL\glew.h"
#include <iostream>
#include "GL\glut.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class GlutFrame
{
protected:
	static GlutFrame *instance;
public:
	static void displayWrapper();
	static void runWrapper();
	static void keyboardWrapper(unsigned char key, int x, int y);
	static void keyboardUpWrapper(unsigned char key, int x, int y);
	static void specialKeyboardWrapper(int key, int x, int y);
	static void specialKeyboardUpWrapper(int key, int x, int y);
	void startFramework(int argc, char *argv[]);
	void setInstance(GlutFrame *framework);
 
	//void run();
	virtual void display(){};
	virtual void keyboard(unsigned char key, int x, int y) =0 ;
	virtual void keyboardUp(unsigned char key, int x, int y)=0;
	virtual void specialKeyboard(int key, int x, int y)=0;
	virtual void specialKeyboardUp(int key, int x, int y)=0;
};