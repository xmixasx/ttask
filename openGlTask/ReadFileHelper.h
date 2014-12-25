#include "Mesh.h"


class ReadFileHelper
{
public:
	ReadFileHelper();
	~ReadFileHelper();
	static void ReadMeshFromFile(Mesh *mMesh, char *filename);
	static bool readShaderfromFile(Shader *mShader, char *filename, char *fShaderfilename);
	static void uploadMesh(Mesh *mMesh);

private:
	static GLuint create_shader(const char* filename, GLenum type);
	static char* file_read(const char* filename);

};

