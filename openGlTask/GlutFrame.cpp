#include "GlutFrame.h"

void GlutFrame::displayWrapper() {
	instance->display(); // calls display(float) with time delta
}
//void GlutFrame::runWrapper() {
//	instance->run();
//}
void GlutFrame::keyboardWrapper(unsigned char key, int x, int y) {
	instance->keyboard(key,x,y);
}
void GlutFrame::keyboardUpWrapper(unsigned char key, int x, int y) {
	instance->keyboardUp(key,x,y);
}
void GlutFrame::specialKeyboardWrapper(int key, int x, int y) {
	instance->specialKeyboard(key,x,y);
}
void GlutFrame::specialKeyboardUpWrapper(int key, int x, int y) {
	instance->specialKeyboardUp(key,x,y);
}
GlutFrame *GlutFrame::instance = 0;
void GlutFrame::setInstance(GlutFrame *framework) {
	instance = framework;
}
void GlutFrame::startFramework(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OBJ viewer");

	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		return ;
	}

	if (!GLEW_VERSION_2_0) {
		fprintf(stderr, "Error: your graphic card does not support OpenGL 2.0\n");
		return ;
	}
	/*glutDisplayFunc(onDisplay);
	glutSpecialFunc(onSpecial);
	glutSpecialUpFunc(onSpecialUp);
	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);*/
	//glutReshapeFunc(onReshape);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}