/***************************************************************
 * Name:      NotepadApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Alas Team ()
 * Created:   2018-12-25
 * Copyright: Alas Team ()
 * License:
 **************************************************************/

#include "NotepadApp.h"

//(*AppHeaders
#include "NotepadMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(NotepadApp);

bool NotepadApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	NotepadFrame* Frame = new NotepadFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        