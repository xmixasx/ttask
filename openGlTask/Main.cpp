#include <stdio.h>
#include <stdlib.h>
#include "InputWrapper.h"
#include "Controller.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

InputWrapper *f ;
Controller *mController;


void onSpecial(int key, int x, int y) {f->specialKeyboard( key,  x,  y);}

void onSpecialUp(int key, int x, int y) {f->specialKeyboardUp( key,  x,  y);}

void onDisplay() 
{
	mController->onDisplay(f->get_params());
	glutSwapBuffers();	

}

void onMouse(int button, int state, int x, int y) {f->onMouse( button,  state,  x,  y);}

void onMotion(int x, int y) {f->onMotion(x,y);}

void onReshape(int width, int height) {f->onReshape(width,  height);}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OBJ viewer");
			GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		
	}
	f = new InputWrapper();
	mController = new Controller();
	mController->addMesh("some.obj");
	
	
	glutDisplayFunc(onDisplay);
	glutSpecialFunc(onSpecial);
	glutSpecialUpFunc(onSpecialUp);
	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	
	delete f;
	delete mController;
	
	return 0;
}