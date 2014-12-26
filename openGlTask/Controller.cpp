#include "Controller.h"



Controller::Controller()
{
	mTransformator = new Transformator();
	mRenderer = new Renderer();
	mScene = new Scene();
	mRenderer->intialize();
	
}

Controller::~Controller()
{
	delete mTransformator;
	delete mRenderer;
	delete mScene;
}
void Controller::onDisplay(keyboard_params params){
	mTransformator->setParams(params);
	mTransformator->MeshTransformation(mScene, mScene->getCamera(), mRenderer->getShaderprogram());
	mRenderer->drawScene(mScene);
}

void Controller::addMesh(char* filename)
{
	mScene->addMesh(filename);
}
