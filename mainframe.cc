#include "mainframe.hh"

std::vector<std::string> Frame::split_filename(std::string filename){
	std::vector<std::string> split_filename;
	for(int i=filename.length();i!=0;--i){
		if(filename[i] == '.'){
			std::string file = filename.substr(0, i);
			std::string ext = filename.substr(i, filename.length() - 1);
			split_filename.push_back(file);
			split_filename.push_back(ext);
			return split_filename;
		}
	}
	split_filename.push_back(filename);
	return split_filename;
}

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *) NULL, -1, title, pos, size)
{	
	//Menu bar definitions and functions
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

	//Toolbar definitions and functions
	wxImage::AddHandler(new wxPNGHandler);
	play = new wxBitmap(wxT("icons/play.png"), wxBITMAP_TYPE_PNG);
	pause = new wxBitmap(wxT("icons/pause.png"), wxBITMAP_TYPE_PNG);
	advance_left = new wxBitmap(wxT("icons/advance_left.png"), wxBITMAP_TYPE_PNG);
	advance_right = new wxBitmap(wxT("icons/advance_right.png"), wxBITMAP_TYPE_PNG);
	toolbar = CreateToolBar();
	toolbar->AddTool(wxID_ANY, *play, wxT("Play Media"));
	toolbar->AddTool(wxID_ANY, *pause, wxT("Pause Media"));
	toolbar->AddTool(wxID_ANY, *advance_left, wxT("Previous Song"));
	toolbar->AddTool(wxID_ANY, *advance_right, wxT("Next Song"));
	toolbar->Realize();


	//Callback functions
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnExit));

	//Table definitions
	file_table = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	
	wxListItem file_col, prop_col;
	file_col.SetId(0);
	file_col.SetText(_("Media File"));
	file_col.SetWidth(200);
	file_table->InsertColumn(0, file_col);

	prop_col.SetId(1);
	prop_col.SetText(_("Media File Type"));
	prop_col.SetWidth(125);
	file_table->InsertColumn(1, prop_col);
	
	//initialize directory reading after window is loaded
	library_location = new std::string(".");
	dir = opendir(library_location->c_str());
	if(dir){
		wxListItem *item = nullptr;
		for(int i=0;(entry = readdir(dir)) != NULL;){
			std::string file = entry->d_name;	
			if(file[0] != '.'){
				std::vector<std::string> filename = split_filename(file);

				item = new wxListItem();
				item->SetId(i);
				item->SetText(entry->d_name);
								
				if(filename.size() > 1) {
					file_table->InsertItem(*item);
					file_table->SetItem(i,0,filename.at(0));
					file_table->SetItem(i,1,filename.at(1));
				}
				else{
					file_table->InsertItem(*item);
					file_table->SetItem(i,0,filename.at(0));
				}
				++i;
			}
		}
		delete item;
	}
}

void Frame::OnExit(wxCommandEvent& event){
	Close(TRUE);
}
