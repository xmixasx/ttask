#include "Mesh.h"


#include "OpenglIncludes.h"

class Transformator
{
public:
	Transformator();
	~Transformator();
	void setRotY_direct(int rotY_direction);
	void setRotX_direct(int rotX_direction);
	void setLast_mx(int last_mx);
	void setlast_my(int last_my);
	void setCur_mx(int cur_mx);
	void setCur_my(int cur_my);
	void setArcball(bool acrball);
	void setTransZDicrect(int transZ_direction);
	void setstrife(int strife);
	void setSpeed_factor(float speed_factor);
	void setLast_ticks(int last_ticks);
	void setScreenSize(int screen_width, int screen_height);
	bool getArc(); 
	void calcWorldToObj(Mesh *mMesh);
	void handleArcballTransform (Mesh *mMesh, Camera *mCamera);
	glm::vec3 get_arcball_vector(int x, int y);
	void changeCamera(Camera *camera, Shader *program);
	void setParams (keyboard_params params);
	void MeshTransformation(Mesh *mesh, Camera *mCamera,Shader *program);

private:
	
	keyboard_params transParams;

};