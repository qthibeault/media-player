#ifndef __base_h
#define __base_h

class MainApp : public wxApp
{

public:
	virtual bool OnInit();

};
class MainFrame : public wxFrame
{

public:
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
	wxButton *testbutton;
	void OnExit( wxCommandEvent& event);

	DECLARE_EVENT_TABLE()

};

enum
{
	button_testbutton = wxID_HIGHEST+1
};

#endif
