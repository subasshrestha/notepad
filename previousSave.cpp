#include "previousSave.h"
//(*InternalHeaders(previousSave)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(previousSave)
const long previousSave::ID_STATICTEXT1 = wxNewId();
const long previousSave::ID_STATICBITMAP1 = wxNewId();
const long previousSave::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(previousSave,wxDialog)
	//(*EventTable(previousSave)
	//*)
END_EVENT_TABLE()

previousSave::previousSave(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(previousSave)
	Create(parent, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(376,153));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,-8), wxSize(376,160), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(255,255,255));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Do you want to save this document\?"), wxPoint(64,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxColour(26,26,26));
	StaticText1->SetBackgroundColour(wxColour(255,255,255));
	wxFont StaticText1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	Button1 = new wxButton(Panel1, wxID_YES, _("Yes"), wxPoint(16,104), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_YES"));
	Button2 = new wxButton(Panel1, wxID_NO, _("No"), wxPoint(144,104), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_NO"));
	Button3 = new wxButton(Panel1, wxID_CANCEL, _("Cancel"), wxPoint(272,104), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_WARNING")),wxART_MAKE_CLIENT_ID_FROM_STR(wxString(_T("wxART_MESSAGE_BOX"))),wxSize(48,48)), wxPoint(8,24), wxSize(48,48), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));

	Connect(wxID_YES,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&previousSave::OnYesClick);
	Connect(wxID_NO,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&previousSave::OnNoClick);
	Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&previousSave::OnPanel1Paint,0,this);
	//*)
}

previousSave::~previousSave()
{
	//(*Destroy(previousSave)
	//*)
}


void previousSave::OnPanel1Paint(wxPaintEvent& event)
{
}

void previousSave::OnNoClick(wxCommandEvent& event)
{
    result=0;
    Close();
}
void previousSave::OnYesClick(wxCommandEvent& event)
{
    result=1;
    Close();
}
