#include "OpenglIncludes.h"
#include "Transformator.h"
#include "Renderer.h"
#include "Scene.h"

class Controller
{
public:
   Controller ();
   void onDisplay(keyboard_params params);
   ~Controller();
   void addMesh(char* filename);


protected:
private:
	Transformator *mTransformator;
	Scene* mScene;
	Renderer *mRenderer;
};