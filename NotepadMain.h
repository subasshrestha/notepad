/***************************************************************
 * Name:      NotepadMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alas Team ()
 * Created:   2018-12-25
 * Copyright: Alas Team ()
 * License:
 **************************************************************/

#ifndef NOTEPADMAIN_H
#define NOTEPADMAIN_H
#include <wx/msgdlg.h>
#include <wx/file.h>

//(*Headers(NotepadFrame)
#include <wx/filedlg.h>
#include <wx/fontdlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
//*)

class NotepadFrame: public wxFrame
{
    public:
        wxString path="",text,title="Untitled",tempPath;
        int saveClickCheck=0,openClickCheck=1;
        NotepadFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~NotepadFrame();

    private:
        //(*Handlers(NotepadFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnOpen(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnNew(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);
        void OnChangeFont(wxCommandEvent& event);
        //*)

        //(*Identifiers(NotepadFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM1;
        static const long IdChangeFont;
        static const long idMenuAbout;
        //*)

        //(*Declarations(NotepadFrame)
        wxFileDialog* FileDialog1;
        wxFileDialog* FileDialog2;
        wxFontDialog* FontDialog1;
        wxMenu* Menu3;
        wxMenuItem* Menu4;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxTextCtrl* TextCtrl1;
        //*)
    public:
        void save(){
            int result;
            if(path!=""){
                wxFile file;
                text<<TextCtrl1->GetValue() .ToStdString();
                file.Create(path,true);
                file.Write(text);
                file.Close();
                text="";
                openClickCheck=1;
                SetLabel(title+" ::Notepad 1.0");
            }
            else{
                result=FileDialog1->ShowModal();
                if(result==wxID_OK){
                    path<<FileDialog1->GetPath();
                    text<<TextCtrl1->GetValue() .ToStdString();
                    wxFile file;
                    file.Create(path,true);
                    file.Write(text);
                    file.Close();
                    text="";
                    title=wxFileNameFromPath(path);
                    openClickCheck=1;
                    SetLabel(title+" ::Notepad 1.0");
                }
                else{
                    path=tempPath;
                }
            }
        }
        DECLARE_EVENT_TABLE()
};

#endif // NOTEPADMAIN_H
