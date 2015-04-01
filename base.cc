#include "base.hh"
#include "mainframe.hh"
#include <wx/progdlg.h>

IMPLEMENT_APP(App)

bool App::OnInit()
{
	Frame *MainWin = new Frame(_("Bobcat Music Player"), wxDefaultPosition, wxSize(500, 500));
	MainWin->Show(true);
	SetTopWindow(MainWin);
	return true;
}
