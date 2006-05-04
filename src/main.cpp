
#include "StdAfx.h"
#include "karel3d_app.h"

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR lpStr,int iCmdShow)
{
	HoeGame::Console con;
	HoeGame::Settings set("config.ini");

	Karel3DApp app(hInstance,&con,&set);
#else

int main(int argc,char * argv[])
{
	HoeGame::Console con;
	HoeGame::Settings set(argc,argv,"linux.ini");
	Karel3DApp app(NULL,&con,&set);
#endif

	con.SetFileLogging("karel3d.log");

	if (!app.Init())
	{
		app.HandleError();
		return 0;
	}
	if (!app.LoadScene())
		return 0;

	app.Run();

	app.Destroy();

	return 0;
}



