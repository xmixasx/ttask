#include "OpenglIncludes.h"

//extern GLuint program;
//extern GLint attribute_v_coord;
//extern GLint attribute_v_normal;
//extern GLint uniform_m;
//extern GLint uniform_v;
//extern GLint uniform_p;
//extern GLint uniform_m_3x3_inv_transp;
//extern GLint uniform_v_inv ;

class Shader {
public:
	int loadShader();
	Shader();
	GLuint vs, fs;
	GLuint program;
	GLint getAttrCoord();
	GLint getAttrNormal();
	GLint getUniform_M();
	GLint getUniform_V();
	GLint getUniform_P();
	GLint getunifrom_transp();
	GLint getuniform_inv();
private:
	
	GLint attribute_v_coord;
	GLint attribute_v_normal;
	GLint uniform_m;
	GLint uniform_v;
	GLint uniform_p;
	GLint uniform_m_3x3_inv_transp;
	GLint uniform_v_inv ;
	GLint create_shader(const char* filename, GLenum type);
	char* file_read(const char* filename);
};