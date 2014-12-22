#if !defined(__ObjViewer_Controller_h)
#define __ObjViewer_Controller_h

#include "SceneCreator.h"



class Controller
{
public:
   Controller (int argc, char* argv[]);
   ~Controller();
   void onSpecial(void);
   void onSpecialUp(void);
   static void onDisplay(void);
   void onMouse(void);
   void onMotion(void);
   void onReshape(void);
   bool InitWindow(int argc, char* argv[]);
   //void onDisplay();

protected:
private:
	GlutFrame *mScene;
   /*Camera mCamera;
   Light mLight;
   Shader mShader;
   Mesh mMesh;
   mRenderrer mRenderer;
   Transform mTrnasform;*/


};

#endif