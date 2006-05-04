
#ifndef _BECHER_EDITOR_H_
#define _BECHER_EDITOR_H_

/*
class ToolObjects;
class BecherEditorMap;
class BecherEditor : public HoePlugin::PluginFileType
{
	std::vector<BecherEditorMap*> m_maps;
	int m_fileimage;
	ToolObjects * m_toolPanel;
	void * m_toolPanelHandle;
	void * m_ter;
	PluginResources m_resources;
public:
	BecherEditor();
	virtual const char * GetIS();
	virtual void New(const char * path);
	virtual HoePlugin::PluginFile * OpenFile(const char * fpath);
	virtual bool SaveProject(HoeExtern::IProjectSave *);
	virtual bool LoadProject(HoeExtern::IProjectLoad *);
	virtual bool Init();
	int GetFileImageIndex() { return m_fileimage; }
	void Select(BecherEditorMap * map);
	void Unselect();
	virtual HoeCore::PluginFS * GetCustomFS() { return &m_resources; }
	void AddMap(BecherEditorMap * map);
	virtual int Msg(HoePlugin::EPluginMsg msg, int par1, void * par2);
	virtual void Destroy() { delete this; }
	virtual int GetNumExt() { return 1; }
	virtual const char * GetExt(int i) { return "bl"; }
	virtual const char * GetLongDesc(int i) { return GetShortDesc(i); }
	virtual const char * GetShortDesc(int i) { return "Becher Level"; }

	static const char * is;
};
*/

class LevelEditor : public HoeEditor::LevelEditor
{
protected:
	//HoeEditor::PropertyGrid * m_prop;
	HoeEditor::EngineView m_engview;
	HoeEditor::PanelMgr m_leftpanel;
public:
	LevelEditor();
	virtual ~LevelEditor();
	virtual void OnInitMenu();
	virtual XHoeFS * GetFS() { return NULL; }
	//HoeEditor::PropertyGrid * GetProp() { return m_prop; }
	virtual HoeEditor::EngineView * GetEngineView() { return &m_engview; }
	//virtual HoeEditor::PanelMgr * GetPanelMgr() { return &m_leftpanel; }

	bool Create(const wxString & title);

    DECLARE_EVENT_TABLE()
};

class LevelEditorApp : public HoeEditor::App
{
	//wxSplashScreen *m_splash;
public:
	virtual HoeEditor::BaseEditor * CreateEditor();
	virtual void OnPostInit();
};

#endif // _BECHER_EDITOR_H_

