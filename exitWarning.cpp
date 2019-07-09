#include "exitWarning.h"

//(*InternalHeaders(exitWarning)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(exitWarning)
const long exitWarning::ID_STATICBITMAP1 = wxNewId();
const long exitWarning::ID_STATICTEXT1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(exitWarning,wxDialog)
	//(*EventTable(exitWarning)
	//*)
END_EVENT_TABLE()

exitWarning::exitWarning(wxWindow* parent)
{
	//(*Initialize(exitWarning)
	Create(parent, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(402,167));
	Button1 = new wxButton(this, wxID_YES, _("Yes"), wxPoint(64,112), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_YES"));
	Button2 = new wxButton(this, wxID_NO, _("No"), wxPoint(256,112), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_NO"));
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_WARNING")),wxART_MAKE_CLIENT_ID_FROM_STR(wxString(_T("wxART_MESSAGE_BOX"))),wxSize(48,48)), wxPoint(24,32), wxSize(48,48), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Do you want to save this document\?"), wxPoint(88,48), wxSize(304,27), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);

	Connect(wxID_YES,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&exitWarning::OnYesClick);
	Connect(wxID_NO,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&exitWarning::OnNoClick);
	//*)
}

exitWarning::~exitWarning()
{
	//(*Destroy(exitWarning)
	//*)
}
void exitWarning::OnYesClick(wxCommandEvent& event)
{
    result=1;
    Close();
}

void exitWarning::OnNoClick(wxCommandEvent& event)
{
    Close();
}
