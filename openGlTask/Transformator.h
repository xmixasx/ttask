#include "Mesh.h"



#include "OpenglIncludes.h"
class Camera;
class Scene;
class Transformator
{
public:
	Transformator();
	~Transformator();
	void calcWorldToObj(Mesh *mMesh);
	void handleArcballTransform (Mesh *mMesh, Camera *mCamera);
	glm::vec3 get_arcball_vector(int x, int y);
	void changeCamera(Camera *camera, Shader *program);
	void setParams (keyboard_params params);
	void MeshTransformation(Scene *mScene, Camera *mCamera,Shader *program);

private:
	
	keyboard_params transParams;

};