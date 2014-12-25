#include "ReadFileHelper.h"
#include "OpenglIncludes.h"
class Renderer
{
public:
	Renderer();
	~Renderer();
	void intialize();
	void draw (Mesh *mMesh);
	void setCamera(Camera *mCamera);
	Shader* getShaderprogram();
	

private:
	Shader *mShader;
	bool isFirst;

};

