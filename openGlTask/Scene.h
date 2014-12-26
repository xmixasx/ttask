#include "Camera.h"
#include <vector>
class Mesh;
class Scene
{
public:
	Scene();
	~Scene();
	void addMeshtoScene(Mesh *mMesh);
	Mesh* getMesh(int position);
	Camera * getCamera();
	void addMesh(char* filename);
	std::vector<Mesh*> getSceneObj();

private:
	std::vector <Mesh*> mMesh;
	Camera *mCamera;
};