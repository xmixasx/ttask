#include "Controller.h"



Controller::Controller (int argc, char* argv[])
{
	mScene = new SceneCreator();
	mScene->setInstance(mScene);
	mScene->startFramework(argc, argv);
	
}

Controller::~Controller()
{
}
static void onDisplay(){

}

