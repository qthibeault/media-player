#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#	include <wx/wx.h>
#endif
#include "base.h"

IMPLEMENT_APP(MainApp) // A macro that tells wxWidgets to create an instance of our application 
 
bool MainApp::OnInit() 
{
	// Create an instance of our frame, or window 
	MainFrame *MainWin = new MainFrame(_("Bobcat Music Player"), wxDefaultPosition, wxSize(300, 200));
	MainWin->Show(true); // show the window 
	SetTopWindow(MainWin); // and finally, set it as the main window 
	return true;
}

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(button_testbutton, MainFrame::OnExit)
END_EVENT_TABLE()
 
MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *) NULL, -1, title, pos, size) 
{
	testbutton = new wxButton(this, button_testbutton, _T("Test Button"), wxDefaultPosition, wxDefaultSize, 0); 
}

void MainFrame::OnExit(wxCommandEvent& event){
	Close(TRUE);
}
