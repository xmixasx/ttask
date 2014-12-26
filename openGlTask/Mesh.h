#ifndef _MESH_H
#define _MESH_H


#include <vector>

#include "OpenglIncludes.h"

#include "Shader.h"

using namespace std;

//extern GLint attribute_v_coord;
//extern GLint attribute_v_normal;
//extern GLint uniform_m;
//extern GLint uniform_v;
//extern GLint uniform_p;
//extern GLint uniform_m_3x3_inv_transp;
//extern GLint uniform_v_inv ;

class Mesh {
private:
  
public:
  vector<glm::vec4> vertices;
  vector<glm::vec3> normals;
  vector<GLushort> elements;
  glm::mat4 object2world;
  GLuint vbo_vertices, vbo_normals, ibo_elements;
  void setObjToWorls(int x, int y, int z);
 
  Mesh() ;
  ~Mesh();
};
#endif //