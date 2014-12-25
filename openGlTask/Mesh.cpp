#include "Mesh.h"

Mesh::Mesh(): vbo_vertices(0), vbo_normals(0), ibo_elements(0), object2world(glm::mat4(1)) {}


Mesh::~Mesh()
{
}