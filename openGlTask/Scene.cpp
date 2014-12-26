#include "Scene.h"
#include "ReadFileHelper.h"

Scene::Scene()
{	
	mCamera = new Camera();
}

Scene::~Scene()
{
	delete mCamera;
}
void Scene::addMesh(char* filename)
{
	Mesh* mMesh = new Mesh();
	ReadFileHelper::ReadMeshFromFile(mMesh,filename);
	ReadFileHelper::uploadMesh(mMesh);
	addMeshtoScene(mMesh);

}
void Scene::addMeshtoScene(Mesh *mMesh1)
{
	mMesh.push_back(mMesh1);
}

Mesh* Scene::getMesh(int pos){
	return mMesh.at(pos);
}
Camera* Scene::getCamera(){
	return mCamera;
}
std::vector <Mesh*> Scene::getSceneObj(){
	return mMesh;
}