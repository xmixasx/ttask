#ifndef OPENGLINCLUDES_H
#define OPENGLINCLUDES_H

/* Use glew.h instead of gl.h to get all the GL prototypes declared */
#include <GL/glew.h>
/* Using the GLUT library for the base windowing setup */

/* GLM */
// #define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm\gtx\quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glut.h>


struct keyboard_params
{
	int last_mx; 
	int last_my; 
	int cur_mx; 
	int cur_my;

	bool arcball_on;	

	int rotY_direction; 
	int rotX_direction; 
	int transZ_direction; 
	int strife;
	float speed_factor;
	int last_ticks;
	int screen_width, screen_height;
};

#endif
