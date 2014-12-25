#include <stdio.h>
#include <stdlib.h>
#include "InputWrapper.h"
#include "Renderer.h"

InputWrapper *f = new InputWrapper();
Mesh *mMesh = new Mesh();
Transformator *mTransformator = new Transformator();
Camera *mCamera = new Camera();
Renderer *mRenderer = new Renderer();


void onSpecial(int key, int x, int y) {f->specialKeyboard( key,  x,  y);}

void onSpecialUp(int key, int x, int y) {f->specialKeyboardUp( key,  x,  y);}

void onDisplay() 
{
	mTransformator->setParams(f->get_params());
	mTransformator->MeshTransformation(mMesh, mCamera, mRenderer->getShaderprogram());
	mRenderer->draw(mMesh);
	glutSwapBuffers();	

}

void onMouse(int button, int state, int x, int y) {f->onMouse( button,  state,  x,  y);}

void onMotion(int x, int y) {f->onMotion(x,y);}

void onReshape(int width, int height) {f->onReshape(width,  height);}


int main(int argc, char* argv[])
{
	
	//Renderer *renderer = new Renderer();
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OBJ viewer");
			GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		
	}
	
	mRenderer->intialize();
	ReadFileHelper::ReadMeshFromFile(mMesh,"some.obj");
	ReadFileHelper::uploadMesh(mMesh);
	glutDisplayFunc(onDisplay);
	glutSpecialFunc(onSpecial);
	glutSpecialUpFunc(onSpecialUp);
	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	//glutReshapeFunc(onReshape);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	
	delete f;
	delete mTransformator;
	delete mMesh;
	delete mCamera;
	delete mRenderer;
	//delete renderer;
	return 0;
}