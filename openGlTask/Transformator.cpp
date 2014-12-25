#include "Transformator.h"
#include "OpenglIncludes.h"

Transformator::Transformator()
{
	transParams.last_mx = 0, transParams.last_my = 0, transParams.cur_mx = 0, transParams.cur_my = 0;
	transParams.arcball_on = false;

	transParams.rotY_direction = 0, transParams.rotX_direction = 0, transParams.transZ_direction = 0, transParams.strife = 0;
	transParams.speed_factor = 1;
	
	
	transParams.screen_width=800, transParams.screen_height=600;

	transParams.last_ticks = glutGet(GLUT_ELAPSED_TIME);
}

Transformator::~Transformator()
{
}

void Transformator::setRotY_direct(int rotY_direct){
	transParams.rotY_direction = rotY_direct;
}
void Transformator::setRotX_direct(int rotX_direct){
	transParams.rotX_direction = rotX_direct;
}
void Transformator::setLast_mx(int last_x){
	transParams.last_mx = last_x;
}
void Transformator::setlast_my(int last_y){
	transParams.last_my = last_y;
}
void Transformator::setCur_mx(int cur_x){
	transParams.cur_mx = cur_x;
}
void Transformator::setCur_my(int cur_y){
	transParams.cur_my = cur_y;
}
void Transformator::setArcball(bool acrBall){
	transParams.arcball_on = acrBall;
}
void Transformator::setTransZDicrect(int transZ_direct){
	transParams.transZ_direction = transZ_direct;
}
void Transformator::setstrife(int str){
	transParams.strife = str;
}
void Transformator::setSpeed_factor(float speed){
	transParams.speed_factor = speed;
}
void Transformator::setLast_ticks(int last_tick){
	transParams.last_ticks = last_tick;
}
void Transformator::setScreenSize(int width, int height){
	transParams.screen_width = width;
	transParams.screen_height = height;
}

bool Transformator::getArc(){
	return transParams.arcball_on;
}
void Transformator::calcWorldToObj(Mesh *mMesh)
{
	int delta_t = glutGet(GLUT_ELAPSED_TIME) - transParams.last_ticks;
	transParams.last_ticks = glutGet(GLUT_ELAPSED_TIME);

	float delta_transZ = transParams.transZ_direction * delta_t / 1000.0 * 5 * transParams.speed_factor;  // 5 units per second
	float delta_transX = 0, delta_transY = 0, delta_rotY = 0, delta_rotX = 0;
	if (transParams.strife) {
		delta_transX = transParams.rotY_direction * delta_t / 1000.0 * 3 * transParams.speed_factor;  // 3 units per second
		delta_transY = transParams.rotX_direction * delta_t / 1000.0 * 3 * transParams.speed_factor;  // 3 units per second
	} else {
		delta_rotY =  transParams.rotY_direction * delta_t / 1000.0 * 120 * transParams.speed_factor;  // 120° per second
		delta_rotX = -transParams.rotX_direction * delta_t / 1000.0 * 120 * transParams.speed_factor;  // 120° per second
	}

	
		mMesh->object2world = glm::rotate(mMesh->object2world, glm::radians(delta_rotY), glm::vec3(0.0, 1.0, 0.0));
		mMesh->object2world = glm::rotate(mMesh->object2world, glm::radians(delta_rotX), glm::vec3(1.0, 0.0, 0.0));
		mMesh->object2world = glm::translate(mMesh->object2world, glm::vec3(0.0, 0.0, delta_transZ));
}
void Transformator::handleArcballTransform(Mesh *mMesh, Camera *mCamera)
{
	if (transParams.cur_mx != transParams.last_mx || transParams.cur_my != transParams.last_my) {
		glm::vec3 va = get_arcball_vector(transParams.last_mx, transParams.last_my);
		glm::vec3 vb = get_arcball_vector( transParams.cur_mx,  transParams.cur_my);
		float angle = acos(min(1.0f, glm::dot(va, vb)));
		glm::vec3 axis_in_camera_coord = glm::cross(va, vb);
		glm::mat3 camera2object = glm::inverse(glm::mat3(mCamera->transforms) * glm::mat3(mMesh->object2world));
		glm::vec3 axis_in_object_coord = camera2object * axis_in_camera_coord;
		mMesh->object2world = glm::rotate(mMesh->object2world, angle, axis_in_object_coord);
		transParams.last_mx = transParams.cur_mx;
		transParams.last_my = transParams.cur_my;
	}
}
glm::vec3 Transformator::get_arcball_vector(int x, int y)
{
	glm::vec3 P = glm::vec3(1.0*x/transParams.screen_width*2 - 1.0,
		1.0*y/transParams.screen_height*2 - 1.0,
		0);
	P.y = -P.y;
	float OP_squared = P.x * P.x + P.y * P.y;
	if (OP_squared <= 1*1)
		P.z = sqrt(1*1 - OP_squared);  // Pythagore
	else
		P = glm::normalize(P);  // nearest point
	return P;
}
void Transformator::changeCamera(Camera *Camera, Shader *mshader)
{
	int delta_t = glutGet(GLUT_ELAPSED_TIME) - transParams.last_ticks;
	transParams.last_ticks = glutGet(GLUT_ELAPSED_TIME);
	float delta_transX = 0, delta_transY = 0, delta_rotY = 0, delta_rotX = 0;
	float delta_transZ = transParams.transZ_direction * delta_t / 1000.0 * 5 * transParams.speed_factor;
	if (transParams.strife) {
		delta_transX = transParams.rotY_direction * delta_t / 1000.0 * 3 * transParams.speed_factor;  // 3 units per second
		delta_transY = transParams.rotX_direction * delta_t / 1000.0 * 3 * transParams.speed_factor;  // 3 units per second
	} else {
		delta_rotY =  transParams.rotY_direction * delta_t / 1000.0 * 120 * transParams.speed_factor;  // 120° per second
		delta_rotX = -transParams.rotX_direction * delta_t / 1000.0 * 120 * transParams.speed_factor;  // 120° per second
	}
	
		if (transParams.strife) {
			Camera->transforms = glm::translate(glm::mat4(1.0), glm::vec3(delta_transX, 0.0, 0.0)) * Camera->transforms;
		} else {
			glm::vec3 y_axis_world = glm::mat3(Camera->transforms) * glm::vec3(0.0, 1.0, 0.0);
			Camera->transforms = glm::rotate(glm::mat4(1.0), glm::radians(-delta_rotY), y_axis_world) * Camera->transforms;
		}

		if (transParams.strife)
			Camera->transforms = glm::translate(glm::mat4(1.0), glm::vec3(0.0, delta_transY, 0.0)) * Camera->transforms;
		else
			Camera->transforms = glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, delta_transZ)) * Camera->transforms;

		Camera->transforms = glm::rotate(glm::mat4(1.0), glm::radians(delta_rotX), glm::vec3(1.0, 0.0, 0.0)) * Camera->transforms;

		glm::mat4 world2camera = Camera->transforms;

	// Projection
		glm::mat4 camera2screen = glm::perspective(45.0f, 1.0f*this->transParams.screen_height/this->transParams.screen_width, 0.1f, 100.0f);

	glUseProgram(mshader->program);
	glUniformMatrix4fv(mshader->getUniform_V(), 1, GL_FALSE, glm::value_ptr(world2camera));
	glUniformMatrix4fv(mshader->getUniform_P(), 1, GL_FALSE, glm::value_ptr(camera2screen));

	glm::mat4 v_inv = glm::inverse(world2camera);
	glUniformMatrix4fv(mshader->getuniform_inv(), 1, GL_FALSE, glm::value_ptr(v_inv));

	glutPostRedisplay();
	}

void Transformator::setParams (keyboard_params params){
	transParams = params;
}

void Transformator::MeshTransformation(Mesh *mesh , Camera *mCamera, Shader *mshader)
{
	calcWorldToObj(mesh);
	handleArcballTransform(mesh, mCamera);
	changeCamera(mCamera,  mshader);

}