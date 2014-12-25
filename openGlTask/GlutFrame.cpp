#include "GlutWindow.h"

void GlutWindow::displayWrapper() {
	instance->display(); // calls display(float) with time delta
}
//void GlutFrame::runWrapper() {
//	instance->run();
//}
void GlutWindow::keyboardWrapper(unsigned char key, int x, int y) {
	instance->keyboard(key,x,y);
}
void GlutWindow::keyboardUpWrapper(unsigned char key, int x, int y) {
	instance->keyboardUp(key,x,y);
}
void GlutWindow::onMouseWrapper(int button, int state, int x, int y) {
	instance->onMouse(button, state ,x,y);
}
void GlutWindow::onMotionWrapper(int x, int y) {
	instance->onMotion(x,y);
}
void GlutWindow::specialKeyboardWrapper(int key, int x, int y) {
	instance->specialKeyboard(key,x,y);
}
void GlutWindow::specialKeyboardUpWrapper(int key, int x, int y) {
	instance->specialKeyboardUp(key,x,y);
}
GlutWindow *GlutWindow::instance = 0;
void GlutWindow::setInstance(GlutWindow *framework) {
	instance = framework;
}
void GlutWindow::startFramework(int argc, char* argv[])
{
	
}