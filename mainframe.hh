#ifndef __mainframe_h
#define __mainframe_h

#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/grid.h>

#include <dirent.h>

class Frame : public wxFrame
{

private:
	std::string *library_location;
	
	//directory listing
	DIR* dir;	

public:
	void debug_dialog(std::string message){
		wxMessageDialog *dial = new wxMessageDialog(NULL, message, wxT("Exclamation"), wxOK | wxICON_EXCLAMATION);
  		dial->ShowModal();
	}
	
	//wxWidgets required functions
	Frame(const wxString &title, const wxPoint &pos, const wxSize &size);
	void OnExit( wxCommandEvent& event);

	//Menubar declarations
	wxMenuBar *menubar;
	wxMenu *filemenu;
	wxMenu *importsubmenu;

	//Toolbar declaratons
	wxToolBar *toolbar;
	wxBitmap *play, *pause, *advance_left, *advance_right;
};

#endif
