#ifndef EXITWARNING_H
#define EXITWARNING_H

//(*Headers(exitWarning)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)

class exitWarning: public wxDialog
{
	public:
        int result=0;
       	exitWarning(wxWindow* parent);
		virtual ~exitWarning();

		//(*Declarations(exitWarning)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		//*)
	protected:

		//(*Identifiers(exitWarning)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		//*)

	private:

		//(*Handlers(exitWarning)
		void OnYesClick(wxCommandEvent& event);
		void OnNoClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
