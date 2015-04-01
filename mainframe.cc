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

int Frame::populateTable(wxListCtrl *file_table, DIR *dir){
	if(dir){
		wxListItem *item = nullptr;
		for(int i=0;(entry = readdir(dir)) != NULL;){
			std::string file = entry->d_name;	
			if(file[0] != '.'){
				std::vector<std::string> filename = split_filename(file);				
				file_table->InsertItem(i, file);
				file_table->SetItem(i, 1, filename.at(1));
				++i;
			}
		}
		delete item;
		return 0;
	}
	else{
		return -1;
	}
}

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *) NULL, -1, title, pos, size)
{	
	//Menu bar definitions and functions
	filemenu = new wxMenu;
	filemenu->Append(wxID_ANY, wxT("&New Playlist"));
	filemenu->Append(wxID_ANY, wxT("&Open Playlist"));
	filemenu->Append(wxID_ANY, wxT("&Save Playlist"));
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
	advance_left = new wxBitmap(wxT("icons/frw.png"), wxBITMAP_TYPE_PNG);
	advance_right = new wxBitmap(wxT("icons/ffw.png"), wxBITMAP_TYPE_PNG);
	skip = new wxBitmap(wxT("icons/skip.png"), wxBITMAP_TYPE_PNG);
	prev = new wxBitmap(wxT("icons/prev.png"), wxBITMAP_TYPE_PNG);
	
	toolbar = CreateToolBar();
	toolbar->AddTool(wxID_ANY, *prev, wxT("Previous Song"));
	toolbar->AddTool(wxID_ANY, *advance_left, wxT("Rewind"));
	toolbar->AddTool(wxID_ANY, *pause, wxT("Pause Media"));
	toolbar->AddTool(wxID_PLAY, *play, wxT("Play Media"));
	toolbar->AddTool(wxID_ANY, *advance_right, wxT("Fast Forward"));
	toolbar->AddTool(wxID_ANY, *skip, wxT("Next Song"));
	toolbar->Realize();


	//Callback functions
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Frame::OnExit));
	Connect(wxID_FILETABLE, wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(Frame::onSelected));
	Connect(wxID_PLAY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Frame::onPlay));
	

	//Table definitions
	file_table = new wxListCtrl(this, wxID_FILETABLE, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	
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
	library_location = new std::string("/home/quinn/Music/Bobcat/Library/");
	populateTable(file_table, opendir(library_location->c_str()));
}

void Frame::OnExit(wxCommandEvent& event){
	Close(TRUE);
}

void Frame::onSelected(wxListEvent& event){
	current_song = new std::string(event.GetLabel().ToStdString());
}

void Frame::onPlay(wxCommandEvent& event){
	if(current_song != nullptr){
		std::thread t(&media_player::play, &player, *library_location + *current_song);
		t.detach();
	}
	else{
		debug_dialog("No song selected");
	}
}
