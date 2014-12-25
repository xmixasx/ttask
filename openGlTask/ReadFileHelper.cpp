#include "ReadFileHelper.h"
#include <fstream>
#include <iostream>
#include <sstream>


ReadFileHelper::ReadFileHelper()
{
}

ReadFileHelper::~ReadFileHelper()
{
}

 void ReadFileHelper::ReadMeshFromFile(Mesh *mMesh, char *filename)
{
	ifstream in(filename, ios::in);

	if (!in) { cerr << "Cannot open " << filename << endl; exit(1); }
	vector<int> nb_seen;

	string line;
	while (getline(in, line)) {
		if (line.substr(0,2) == "v ") {
			istringstream s(line.substr(2));
			glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0;
			mMesh->vertices.push_back(v);
		}  else if (line.substr(0,3) == "vn ") {
			istringstream s(line.substr(2));
			glm::vec3 v; s >> v.x; s >> v.y; s >> v.z;			
			mMesh->normals.push_back(v); 
		}
		 else if (line.substr(0,2) == "f ") {
			istringstream s(line.substr(2));
			string a;
			while (s >> a){
			int g = abs(atoi(a.c_str()));
			mMesh->elements.push_back(g-1); }
		}
		else if (line[0] == '#') { /* ignoring this line */ }
		else { /* ignoring this line */ }
	}

	mMesh->normals.resize(mMesh->vertices.size(), glm::vec3(0.0, 0.0, 0.0));
	nb_seen.resize(mMesh->vertices.size(), 0);
	for (unsigned int i = 0; i < mMesh->elements.size(); i+=3) {
		GLushort ia = mMesh->elements[i];
		GLushort ib = mMesh->elements[i+1];
		GLushort ic = mMesh->elements[i+2];
		glm::vec3 normal = glm::normalize(glm::cross(
			glm::vec3(mMesh->vertices[ib]) - glm::vec3(mMesh->vertices[ia]),
			glm::vec3(mMesh->vertices[ic]) - glm::vec3(mMesh->vertices[ia])));

		int v[3];  v[0] = ia;  v[1] = ib;  v[2] = ic;
		for (int j = 0; j < 3; j++) {
			GLushort cur_v = v[j];
			nb_seen[cur_v]++;
			if (nb_seen[cur_v] == 1) {
				mMesh->normals[cur_v] = normal;
			} else {
				// average
				mMesh->normals[cur_v].x = mMesh->normals[cur_v].x * (1.0 - 1.0/nb_seen[cur_v]) + normal.x * 1.0/nb_seen[cur_v];
				mMesh->normals[cur_v].y = mMesh->normals[cur_v].y * (1.0 - 1.0/nb_seen[cur_v]) + normal.y * 1.0/nb_seen[cur_v];
				mMesh->normals[cur_v].z = mMesh->normals[cur_v].z * (1.0 - 1.0/nb_seen[cur_v]) + normal.z * 1.0/nb_seen[cur_v];
				mMesh->normals[cur_v] = glm::normalize(mMesh->normals[cur_v]);
			}
		}
	}

}
 bool ReadFileHelper::readShaderfromFile(Shader *mShader, char *vShaderfilename, char *fShaderfilename)
{

	if ((mShader->vs = create_shader(vShaderfilename, GL_VERTEX_SHADER))   == 0) return false;
	if ((mShader->fs = create_shader(fShaderfilename, GL_FRAGMENT_SHADER)) == 0) return false;
	return true;
}

 GLuint ReadFileHelper::create_shader(const char* filename, GLenum type)
{
	const GLchar* source = file_read(filename);
	if (source == NULL) {
		fprintf(stderr, "Error opening %s: ", filename); perror("");
		return 0;
	}
	GLuint res = glCreateShader(type);
	glShaderSource(res, 1, &source, NULL);
	free((void*)source);

	glCompileShader(res);
	GLint compile_ok = GL_FALSE;
	glGetShaderiv(res, GL_COMPILE_STATUS, &compile_ok);
	if (compile_ok == GL_FALSE) {
		fprintf(stderr, "%s:", filename);
		//print_log(res);
		glDeleteShader(res);
		return 0;
	}

	return res;
}


char* ReadFileHelper::file_read(const char* filename)
{
	FILE* in = fopen(filename, "rb");
	if (in == NULL) return NULL;

	int res_size = BUFSIZ;
	char* res = (char*)malloc(res_size);
	int nb_read_total = 0;

	while (!feof(in) && !ferror(in)) {
		if (nb_read_total + BUFSIZ > res_size) {
			if (res_size > 10*1024*1024) break;
			res_size = res_size * 2;
			res = (char*)realloc(res, res_size);
		}
		char* p_res = res + nb_read_total;
		nb_read_total += fread(p_res, 1, BUFSIZ, in);
	}

	fclose(in);
	res = (char*)realloc(res, nb_read_total + 1);
	res[nb_read_total] = '\0';
	return res;
}
void ReadFileHelper::uploadMesh(Mesh *mMesh)
{
	 if (mMesh->vertices.size() > 0) {
      glGenBuffers(1, &mMesh->vbo_vertices);
      glBindBuffer(GL_ARRAY_BUFFER, mMesh->vbo_vertices);
      glBufferData(GL_ARRAY_BUFFER, mMesh->vertices.size() * sizeof(mMesh->vertices[0]),
           mMesh->vertices.data(), GL_STATIC_DRAW);
    }
    
    if (mMesh->normals.size() > 0) {
      glGenBuffers(1, &mMesh->vbo_normals);
      glBindBuffer(GL_ARRAY_BUFFER, mMesh->vbo_normals);
      glBufferData(GL_ARRAY_BUFFER, mMesh->normals.size() * sizeof(mMesh->normals[0]),
           mMesh->normals.data(), GL_STATIC_DRAW);
    }
    
    if (mMesh->elements.size() > 0) {
      glGenBuffers(1, &mMesh->ibo_elements);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mMesh->ibo_elements);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, mMesh->elements.size() * sizeof(mMesh->elements[0]),
           mMesh->elements.data(), GL_STATIC_DRAW);
    }
}