#ifndef __mainframe_h
#define __mainframe_h

#include <wx/wx.h>
#include <wx/menu.h>

class Frame : public wxFrame
{

public:
	Frame(const wxString &title, const wxPoint &pos, const wxSize &size);
	void OnExit( wxCommandEvent& event);

	wxMenuBar *menubar;
	wxMenu *filemenu;
	wxMenu *importsubmenu;
};

#endif
