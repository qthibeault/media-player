#ifndef __mainframe_h
#define __mainframe_h

#include <wx/wx.h>

class Frame : public wxFrame
{

public:
	Frame(const wxString &title, const wxPoint &pos, const wxSize &size);
	void OnExit( wxCommandEvent& event);
};

#endif
