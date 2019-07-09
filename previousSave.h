#ifndef PREVIOUSSAVE_H
#define PREVIOUSSAVE_H

//(*Headers(previousSave)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class previousSave: public wxDialog
{
	public:

		previousSave(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~previousSave();

		//(*Declarations(previousSave)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxPanel* Panel1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(previousSave)
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(previousSave)
		void OnPanel1Paint(wxPaintEvent& event);
		void OnNoClick(wxCommandEvent& event);
		void OnYesClick(wxCommandEvent& event);
		//*)
    public:

        int result=2;
		DECLARE_EVENT_TABLE()
};

#endif
