#include "Renderer.h"


Renderer::Renderer()
{
	mShader = new Shader();
	isFirst = false;
	
}

Renderer::~Renderer()
{
	delete mShader;
}
void Renderer::intialize()
{
	if(!isFirst){
		ReadFileHelper::readShaderfromFile(mShader, "Vertex.glsl", "Fragment.glsl");
		mShader->loadShader();
		isFirst = true;
	}
	else return;
}
void Renderer::draw (Mesh *mMesh)
{
	glClearColor(0.45, 0.45, 0.45, 1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glUseProgram(mShader->program);
	if (mMesh->vbo_vertices != 0) {
      glEnableVertexAttribArray(mShader->getAttrCoord());
      glBindBuffer(GL_ARRAY_BUFFER, mMesh->vbo_vertices);
      glVertexAttribPointer(
        mShader->getAttrCoord(),  // attribute
        4,                  // number of elements per vertex, here (x,y,z,w)
        GL_FLOAT,           // the type of each element
        GL_FALSE,           // take our values as-is
        0,                  // no extra data between each position
        0                   // offset of first element
      );
    }
 
    if (mMesh->vbo_normals != 0) {
		glEnableVertexAttribArray(mShader->getAttrNormal());
      glBindBuffer(GL_ARRAY_BUFFER, mMesh->vbo_normals);
      glVertexAttribPointer(
        mShader->getAttrNormal(), // attribute
        3,                  // number of elements per vertex, here (x,y,z)
        GL_FLOAT,           // the type of each element
        GL_FALSE,           // take our values as-is
        0,                  // no extra data between each position
        0                   // offset of first element
      );
    }
    
    /* Apply object's transformation matrix */
	glUniformMatrix4fv(mShader->getUniform_M(), 1, GL_FALSE, glm::value_ptr(mMesh->object2world));
    /* Transform normal vectors with transpose of inverse of upper left
       3x3 model matrix (ex-gl_NormalMatrix): */
    glm::mat3 m_3x3_inv_transp = glm::transpose(glm::inverse(glm::mat3(mMesh->object2world)));
	glUniformMatrix3fv(mShader->getunifrom_transp(), 1, GL_FALSE, glm::value_ptr(m_3x3_inv_transp));
    
    /* Push each element in buffer_vertices to the vertex shader */
    if (mMesh->ibo_elements != 0) {
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mMesh->ibo_elements);
      int size;  glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
      glDrawElements(GL_TRIANGLES, size/sizeof(GLushort), GL_UNSIGNED_SHORT, 0);
    } else {
      glDrawArrays(GL_TRIANGLES, 0, mMesh->vertices.size());
    }
 
    if (mMesh->vbo_normals != 0)
      glDisableVertexAttribArray(mShader->getAttrNormal());
    if (mMesh->vbo_vertices != 0)
      glDisableVertexAttribArray(mShader->getAttrCoord());
}
Shader* Renderer::getShaderprogram()
{
	return mShader;
}