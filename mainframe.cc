#include "mainframe.hh"

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *) NULL, -1, title, pos, size)
{
	//Menu bar declarations
	filemenu = new wxMenu;
	filemenu->Append(wxID_ANY, wxT("&New Library"));
	filemenu->Append(wxID_ANY, wxT("&Open Library"));
	filemenu->Append(wxID_ANY, wxT("&Save Library"));
	filemenu->AppendSeparator();

	importsubmenu = new wxMenu;
	importsubmenu->Append(wxID_ANY, wxT("&Import media file"));
	importsubmenu->Append(wxID_ANY, wxT("&Import media folder"));
	filemenu->AppendSubMenu(importsubmenu, wxT("&Import"));

	filemenu->AppendSeparator();
	filemenu->Append(wxID_EXIT, wxT("&Quit"));


	menubar = new wxMenuBar;
	menubar->Append(filemenu, wxT("&File"));
	SetMenuBar(menubar);

	//Callback functions
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnExit));
}

void Frame::OnExit(wxCommandEvent& event){
	Close(TRUE);
}
