/***************************************************************
 * Name:      NotepadMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Alas Team ()
 * Created:   2018-12-25
 * Copyright: Alas Team ()
 * License:
 **************************************************************/

#include "NotepadMain.h"
#include <wx/msgdlg.h>
#include <wx/file.h>
#include "previousSave.h"
#include "exitWarning.h"

//(*InternalHeaders(NotepadFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(NotepadFrame)
const long NotepadFrame::ID_TEXTCTRL1 = wxNewId();
const long NotepadFrame::ID_MENUITEM2 = wxNewId();
const long NotepadFrame::ID_MENUITEM3 = wxNewId();
const long NotepadFrame::ID_MENUITEM4 = wxNewId();
const long NotepadFrame::ID_MENUITEM5 = wxNewId();
const long NotepadFrame::ID_MENUITEM1 = wxNewId();
const long NotepadFrame::IdChangeFont = wxNewId();
const long NotepadFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(NotepadFrame,wxFrame)
    //(*EventTable(NotepadFrame)
    //*)
END_EVENT_TABLE()

NotepadFrame::NotepadFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(NotepadFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Untitled ::Notepad 1.0"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(600,600));
    SetForegroundColour(wxColour(0,0,0));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOTEXT));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DELETE")),wxART_FRAME_ICON));
    	SetIcon(FrameIcon);
    }
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetFocus();
    TextCtrl1->SetForegroundColour(wxColour(0,0,0));
    TextCtrl1->SetBackgroundColour(wxColour(255,255,255));
    wxFont TextCtrl1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM2, _("New\tCtrl+N"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, ID_MENUITEM3, _("Open\tCtrl+O"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu1, ID_MENUITEM4, _("Save\tCtrl+S"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu1, ID_MENUITEM5, _("Save as\tCtrl+Shift+S"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    Menu4 = new wxMenuItem(Menu3, IdChangeFont, _("Change Font"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(Menu4);
    MenuBar1->Append(Menu3, _("Edit"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), _("~"), _("Untitled.txt"), wxFileSelectorDefaultWildcardStr, wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FileDialog2 = new wxFileDialog(this, _("Select file"), _("~"), wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    	wxFontData fontData_1;
    	fontData_1.SetInitialFont(*wxNORMAL_FONT);
    FontDialog1 = new wxFontDialog(this, fontData_1);
    Center();

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NotepadFrame::OnTextCtrl1Text);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&NotepadFrame::OnNew);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&NotepadFrame::OnOpen);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&NotepadFrame::OnSave);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&NotepadFrame::OnSaveAs);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&NotepadFrame::OnQuit);
    Connect(IdChangeFont,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&NotepadFrame::OnChangeFont);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&NotepadFrame::OnAbout);
    //*)
}

NotepadFrame::~NotepadFrame()
{
    //(*Destroy(NotepadFrame)
    //*)
    if(openClickCheck==0){
        exitWarning e(this);
        e.ShowModal();
        if(e.result==1){
            save();
        }
    }
}

void NotepadFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void NotepadFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a notepad Created by Alas TEAM", _("About"));
}

void NotepadFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
    openClickCheck=0;
    if(saveClickCheck==0){
        SetLabel("~"+title+" ::Notepad 1.0 ");
    }else{
        SetLabel(title+" ::Notepad 1.0");
        saveClickCheck=0;
    }
}

void NotepadFrame::OnOpen(wxCommandEvent& event)
{
    int result;
    path="";
    result=FileDialog2->ShowModal();
    if(result==wxID_OK)
    {
        path<<FileDialog2->GetPath();
        wxFile file;
        file.Open(path);
        file.ReadAll(&text);
        file.Close();
        TextCtrl1->SetValue(text);
        text="";
        title=wxFileNameFromPath(path);
        openClickCheck=1;
        SetLabel(title+" ::Notepad 1.0");
    }
}
void NotepadFrame::OnSave(wxCommandEvent& event)
{
    save();
}

void NotepadFrame::OnNew(wxCommandEvent& event)
{
    if(openClickCheck==1){
        TextCtrl1->SetValue("");
        title="Untitled";
        path="";
        text="";
        SetLabel(title+" ::Notepad 1.0");
        saveClickCheck=0;
    }
    else{
            previousSave p(this);
            p.ShowModal();
            if(p.result==1){
                save();
            }
            else if(p.result==0){
                TextCtrl1->SetValue("");
                title="Untitled";
                path="";
                text="";
                SetLabel(title+" ::Notepad 1.0");
                openClickCheck=1;
            }
    }
}
void NotepadFrame::OnSaveAs(wxCommandEvent& event)
{
    tempPath=path;
    path="";
    save();
}

void NotepadFrame::OnChangeFont(wxCommandEvent& event)
{
    wxFont font;
    int result;
    result=FontDialog1->ShowModal();
    if(result==wxID_OK)
    {
        font=FontDialog1->GetFontData().GetChosenFont();
        TextCtrl1->SetFont(font);
        TextCtrl1->SetFocus();
    }
}
