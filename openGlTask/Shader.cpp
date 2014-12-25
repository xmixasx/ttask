#include <iostream>
#include <fstream>
#include <sstream>

#include "Shader.h"
Shader::Shader()
{
	 program = -1;
	 attribute_v_coord = -1;
	 attribute_v_normal = -1;
	 uniform_m = -1, uniform_v = -1, uniform_p = -1;
	 uniform_m_3x3_inv_transp = -1, uniform_v_inv = -1;
}

int Shader::loadShader()
{
	/* Compile and link shaders */
	GLint link_ok = GL_FALSE;
	GLint validate_ok = GL_FALSE;

	

	program = glCreateProgram();
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
	if (!link_ok) {
		fprintf(stderr, "glLinkProgram:");
		//print_log(program);
		return 0;
	}
	glValidateProgram(program);
	glGetProgramiv(program, GL_VALIDATE_STATUS, &validate_ok);
	if (!validate_ok) {
		fprintf(stderr, "glValidateProgram:");
		// print_log(program);
	}

	const char* attribute_name;
	attribute_name = "v_coord";
	attribute_v_coord = glGetAttribLocation(program, attribute_name);
	if (attribute_v_coord == -1) {
		fprintf(stderr, "Could not bind attribute %s\n", attribute_name);
		return 0;
	}
	attribute_name = "v_normal";
	attribute_v_normal = glGetAttribLocation(program, attribute_name);
	if (attribute_v_normal == -1) {
		fprintf(stderr, "Could not bind attribute %s\n", attribute_name);
		return 0;
	}
	const char* uniform_name;
	uniform_name = "m";
	uniform_m = glGetUniformLocation(program, uniform_name);
	if (uniform_m == -1) {
		fprintf(stderr, "Could not bind uniform %s\n", uniform_name);
		return 0;
	}
	uniform_name = "v";
	uniform_v = glGetUniformLocation(program, uniform_name);
	if (uniform_v == -1) {
		fprintf(stderr, "Could not bind uniform %s\n", uniform_name);
		return 0;
	}
	uniform_name = "p";
	uniform_p = glGetUniformLocation(program, uniform_name);
	if (uniform_p == -1) {
		fprintf(stderr, "Could not bind uniform %s\n", uniform_name);
		return 0;
	}
	uniform_name = "m_3x3_inv_transp";
	uniform_m_3x3_inv_transp = glGetUniformLocation(program, uniform_name);
	if (uniform_m_3x3_inv_transp == -1) {
		fprintf(stderr, "Could not bind uniform %s\n", uniform_name);
		return 0;
	}
	uniform_name = "v_inv";
	uniform_v_inv = glGetUniformLocation(program, uniform_name);
	if (uniform_v_inv == -1) {
		fprintf(stderr, "Could not bind uniform %s\n", uniform_name);
		return 0;
	}

	return 1;
}

GLint Shader::getAttrCoord()
{
	return attribute_v_coord;
}
GLint Shader::getAttrNormal()
{
	return attribute_v_normal;
}
GLint Shader::getUniform_M()
{
	return uniform_m;
}
GLint Shader::getUniform_V()
{
	return uniform_v;
}
GLint Shader::getUniform_P()
{
	return uniform_p;
}
GLint Shader::getunifrom_transp()
{
	return uniform_m_3x3_inv_transp;
}
GLint Shader::getuniform_inv()
{
	return uniform_v_inv;
}

