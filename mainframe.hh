#ifndef __mainframe_h
#define __mainframe_h

#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/listctrl.h>
#include <string>
#include <vector>

#include <dirent.h>

#define wxID_FILETABLE wxID_HIGHEST+1

class Frame : public wxFrame
{

private:
	std::string *library_location = nullptr;
	
	//directory listing
	DIR* dir = nullptr;
	struct dirent* entry = nullptr;

	std::vector<std::string> split_filename(std::string filename);

public:
	void debug_dialog(std::string message){
		wxMessageDialog *dial = new wxMessageDialog(NULL, message, wxT("Exclamation"), wxOK | wxICON_EXCLAMATION);
  		dial->ShowModal();
	}
	
	//wxWidgets required functions
	Frame(const wxString &title, const wxPoint &pos, const wxSize &size);
	void OnExit( wxCommandEvent& event);

	//Menubar declarations
	wxMenuBar *menubar = nullptr;
	wxMenu *filemenu = nullptr;
	wxMenu *importsubmenu = nullptr;

	//Toolbar declaratons
	wxToolBar *toolbar = nullptr;
	wxBitmap *play, *pause, *advance_left, *advance_right, *skip, *prev = nullptr;

	//Table declarations
	wxListCtrl *file_table = nullptr;
	int populateTable(wxListCtrl *file_table, DIR* dir);
	void onSelected(wxListEvent& event);
};

#endif
