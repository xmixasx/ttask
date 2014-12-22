#include "GlutFrame.h"

class SceneCreator: public GlutFrame

{
public:
	SceneCreator();
	~SceneCreator();
	void display(){};
	void keyboard(unsigned char key, int x, int y){};
	void keyboardUp(unsigned char key, int x, int y){};
	void specialKeyboard(int key, int x, int y){}
	void specialKeyboardUp(int key, int x, int y){};

private:

};

