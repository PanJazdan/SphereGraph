#include <wx/wxprec.h>
#include "GUIMyFrame1.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	SetProcessDPIAware();
	wxFrame* mainFrame = new GUIMyFrame1(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}