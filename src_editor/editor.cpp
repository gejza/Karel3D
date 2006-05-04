
#include "StdAfx.h"
#include "editor.h"

IMPLEMENT_APP(LevelEditorApp)

const char * EditorName = "LevelEditor";

enum {
	ID_SHOWRES = HoeEditor::ID_CUSTOMMENU_FIRST,
	ID_OBJECT,
};

BEGIN_EVENT_TABLE(LevelEditor, HoeEditor::LevelEditor)
	/*EVT_MENU(ID_SHOWRES, BecherEdit::OnResMgr)
	EVT_MENU(HoeEditor::ID_NEW, BecherEdit::OnNewFile)
	EVT_MENU(HoeEditor::ID_OPEN, BecherEdit::OnOpenFile)
	EVT_MENU(HoeEditor::ID_SAVE, BecherEdit::OnSaveFile)
	EVT_MENU(HoeEditor::ID_SAVEAS, BecherEdit::OnSaveFile)
	EVT_MENU_RANGE(ID_OBJECT, ID_OBJECT + EBO_Max, BecherEdit::OnNewObject)
*/
END_EVENT_TABLE()


HoeEditor::BaseEditor * LevelEditorApp::CreateEditor()
{
	LevelEditor * e = new LevelEditor();
	e->Create("Level Editor");

 //   wxBitmap bitmap;
 //   if (bitmap.LoadFile(_T("splash.bmp"), wxBITMAP_TYPE_BMP))

	//m_splash = new wxSplashScreen(bitmap,
 //           wxSPLASH_CENTRE_ON_PARENT/*|wxSPLASH_TIMEOUT*/,
 //           4000, e, wxID_ANY, wxDefaultPosition, wxDefaultSize,
 //           wxSIMPLE_BORDER|wxSTAY_ON_TOP|wxFRAME_NO_TASKBAR);
	return e;
}

void LevelEditorApp::OnPostInit()
{
	//m_splash->
	//delete m_splash;
	// nahranej engine??
	IHoe3DEngine * e = this->m_editor->GetEngineView()->GetEngine();
	IHoeScene * s = e->CreateScene(HOETS_GRAPH);
	e->SetActiveScene(s);
	IHoeSceneEnv * env = s->GetSceneEnv();
}

LevelEditor::LevelEditor()
{
}

LevelEditor::~LevelEditor()
{
}

bool LevelEditor::Create(const wxString & title)
{
	HoeEditor::LevelEditor::Create(title);

	wxSplitterWindow * split = new wxSplitterWindow(this,10, wxDefaultPosition, wxDefaultSize,0);
	split->SetSashGravity(0.3);
	
	// seradit do layoutu

	this->m_leftpanel.Create(split, -1);
	this->m_engview.Create(split, -1);

	split->SplitVertically(&m_leftpanel, &m_engview, 150);

	/*m_prop = new HoeEditor::PropertyGrid(GetPanelMgr());
	GetPanelMgr()->AddPanel(
		new ToolObjects(GetPanelMgr(), 80, 50), _("Tools"), true, true);
	GetPanelMgr()->AddPanel(
		m_prop, _("Properties"), false, true);
	*/

	// create status bar
	wxStatusBar *statbar = GetStatusBar();
	statbar->SetFieldsCount(2);

	return true;
}

void LevelEditor::OnInitMenu()
{
    // file
    wxMenu * m_menuFile = new wxMenu;
	m_menuFile->Append(HoeEditor::ID_NEW, _("&New...\tCtrl+N"), _("Creates a new file or project."));
	m_menuFile->Append(HoeEditor::ID_OPEN, _("&Open...\tCtrl+O"), _("Open an existing file."));
	m_menuFile->AppendSeparator();
	m_menuFile->Append(HoeEditor::ID_SAVE, _("&Save\tCtrl+S"), _("Save file."));
	m_menuFile->Append(HoeEditor::ID_SAVEAS, _("Save &As..."), _("Save file."));
	m_menuFile->AppendSeparator();
	m_menuFile->Append(HoeEditor::ID_QUIT, _("E&xit\tAlt-F4"), _("Quit this program")); 

	// view
	wxMenu * menuView = new wxMenu;
	menuView->Append(HoeEditor::ID_SHOWLOG, _("Show &Log...\tF2"), _("Show log dialog."));
	/*menuView->Append(ID_VIEWENGINE, _("&Engine"), _("Show engine view."));
	menuView->Append(ID_VIEWCODE, _("&Code Editor"), _("Show code editor."));
	menuView->AppendSeparator();*/
	menuView->AppendCheckItem(HoeEditor::ID_VIEWFULLSCREEN, _("F&ull Screen\tF12"), _("Switch to fullscreen."));
	/*menuView->AppendSeparator();
	// advanced
	wxMenu * menuAdvanced = new wxMenu;
	menuAdvanced->Append(ID_ADV_WHITESPACE, _("View &White Space"), _("View white space in code editor."));
    menuView->Append(-1, _("Ad&vanced"), menuAdvanced);
	*/
	// tools
	wxMenu * m_menuTools = new wxMenu;
#ifndef HOE_STATIC
	m_menuTools->Append(HoeEditor::ID_ENGINE, _("&Load Engine...\tF10"), _("Load engine from library"));
	m_menuTools->AppendSeparator();
#endif
	m_menuTools->Append(ID_SHOWRES, _("&Resource Manager..."), _("Resource Manager"));

	wxMenu * menuHelp = new wxMenu;
	menuHelp->Append(HoeEditor::ID_ABOUT, _("&About..."), _("Show about"));

    // now append the freshly created menu to the menu bar...
    m_menu = new wxMenuBar(/*wxMB_DOCKABLE*/);
    m_menu->Append(m_menuFile, _("&File"));
	m_menu->Append(menuView, _("&View"));
	m_menu->Append(m_menuTools, _("&Tools"));
	m_menu->Append(menuHelp, _("&Help"));

    // ... and attach this menu bar to the frame
    SetMenuBar(m_menu); 


}

//////////////////////////////////
EditBaseConsole * GetCon()
{
	return HoeEditor::App::Get()->GetConsole();
}


