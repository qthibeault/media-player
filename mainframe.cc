#include "mainframe.hh"

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *) NULL, -1, title, pos, size) 
{
	
}

void Frame::OnExit(wxCommandEvent& event){
	Close(TRUE);
}
