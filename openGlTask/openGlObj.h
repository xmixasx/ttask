#include "Mesh.h"
#include "OpenglIncludes.h"

class openGlObj
{
public:
	openGlObj();
	~openGlObj();

private:
	glm::vec3 position;
	Mesh mMesh;

};

