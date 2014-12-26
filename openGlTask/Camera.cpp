#include "Camera.h"
Camera::Camera()
{
	
	transforms = glm::lookAt(
		glm::vec3(0.0,  1.0, 10.0),   // eye
		glm::vec3(0.0,  0.0, 0.0),   // direction
		glm::vec3(0.0,  0.0, 1.0));  // up
}

Camera::~Camera()
{
}