#ifndef __mainframe_h
#define __mainframe_h

#include <wx/wx.h>
#include <wx/menu.h>

class Frame : public wxFrame
{

public:
	//wxWidgets required functions
	Frame(const wxString &title, const wxPoint &pos, const wxSize &size);
	void OnExit( wxCommandEvent& event);

	//Menubar declarations
	wxMenuBar *menubar;
	wxMenu *filemenu;
	wxMenu *importsubmenu;

	//Toolbar declaratons
	wxToolBar *toolbar;
	wxBitmap *play;
	wxBitmap *pause;
};

#endif
