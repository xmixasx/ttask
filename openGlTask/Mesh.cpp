#include "Mesh.h"

Mesh::Mesh(): vbo_vertices(0), vbo_normals(0), ibo_elements(0), object2world(glm::mat4(1)) {}


Mesh::~Mesh()
{
}
void Mesh::setObjToWorls(int x, int y, int z)
{ 
	float aaa[16] = {x, 0, 0, 0,
					0, y ,0, 0, 
					0, 0, z, 0,
					0, 0, 0, 1};
	memcpy( glm::value_ptr( object2world ), aaa, sizeof( aaa ) );
}