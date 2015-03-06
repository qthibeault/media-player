#include "mainframe.hh"

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *) NULL, -1, title, pos, size) 
{
	wxPanel *panel = new wxPanel(this, wxID_ANY);
	wxButton *quit_button = new wxButton(panel, wxID_EXIT, wxT("Quit"), wxPoint(20, 20));
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::OnExit));
	quit_button->SetFocus();
	
	Centre();
}

void Frame::OnExit(wxCommandEvent& event){
	Close(TRUE);
}
