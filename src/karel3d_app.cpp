
#include "StdAfx.h"
#include "karel3d_app.h"

Karel3DApp::Karel3DApp(HOE_INSTANCE instance, HoeGame::Console * con, HoeGame::Settings * set) : HoeApp(instance, con, set)
{
}

bool Karel3DApp::LoadScene()
{
	return true;
}

void Karel3DApp::OnUpdate(float tt)
{
	/*static float t = 0;
	t += tt;
	float p[3] = {0,0,0};
	float l[3] = {sin(t),0,cos(t)};
	//float l[3] = {0,0.88,0.2};

	cam->Set(hm,p,l);

	*/
}

