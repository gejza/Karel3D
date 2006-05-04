
#ifndef _KAREL3D_APP_H_
#define _KAREL3D_APP_H_

class Karel3DApp : public HoeGame::HoeApp
{

	//iHoeMap * hm;
	//iHoeCamera* cam;

public:
	Karel3DApp(HOE_INSTANCE instance, HoeGame::Console * con, HoeGame::Settings * set);
	virtual const char * GetAppName() { return "Karel3D"; }
	bool LoadScene();
	virtual void OnUpdate(float t);
};

#endif // _KAREL3D_APP_H_

