#include "ReadFileHelper.h"
#include "OpenglIncludes.h"
class Scene;

class Renderer
{
public:
	Renderer();
	~Renderer();
	void intialize();
	void draw (Mesh *mMesh);
	void drawScene(Scene *mScene);
	Shader* getShaderprogram();
	

private:
	Shader *mShader;
	bool isFirst;

};

