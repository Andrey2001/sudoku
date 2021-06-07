#ifndef SUDOKU_H
#define SUDOKU_H

//(*Headers(Sudoku)
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Sudoku: public wxDialog
{
	public:

		Sudoku(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Sudoku();

		//(*Declarations(Sudoku)
		wxTextCtrl* TextCtrl28;
		wxTextCtrl* TextCtrl42;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl80;
		wxPanel* Panel5;
		wxTextCtrl* TextCtrl69;
		wxTextCtrl* TextCtrl58;
		wxTextCtrl* TextCtrl34;
		wxButton* btnSolve;
		wxTextCtrl* TextCtrl74;
		wxTextCtrl* TextCtrl70;
		wxTextCtrl* TextCtrl45;
		wxButton* btnSave;
		wxTextCtrl* TextCtrl57;
		wxPanel* Panel4;
		wxTextCtrl* TextCtrl55;
		wxTextCtrl* TextCtrl68;
		wxTextCtrl* TextCtrl41;
		wxTextCtrl* txtLeft;
		wxTextCtrl* TextCtrl16;
		wxTextCtrl* TextCtrl6;
		wxTextCtrl* TextCtrl26;
		wxTextCtrl* TextCtrl37;
		wxTextCtrl* TextCtrl71;
		wxTextCtrl* TextCtrl59;
		wxTextCtrl* TextCtrl78;
		wxTextCtrl* TextCtrl27;
		wxTextCtrl* TextCtrl64;
		wxPanel* Panel9;
		wxTextCtrl* TextCtrl76;
		wxTextCtrl* TextCtrl39;
		wxTextCtrl* TextCtrl75;
		wxTextCtrl* TextCtrl19;
		wxPanel* Panel8;
		wxPanel* Panel1;
		wxStaticBox* StaticBox1;
		wxTextCtrl* TextCtrl54;
		wxPanel* Panel6;
		wxTextCtrl* TextCtrl18;
		wxPanel* Panel3;
		wxTextCtrl* TextCtrl77;
		wxTextCtrl* TextCtrl81;
		wxTextCtrl* TextCtrl47;
		wxTextCtrl* TextCtrl48;
		wxTextCtrl* TextCtrl30;
		wxTextCtrl* TextCtrl66;
		wxTextCtrl* TextCtrl17;
		wxTextCtrl* TextCtrl24;
		wxTextCtrl* TextCtrl14;
		wxTextCtrl* TextCtrl15;
		wxTextCtrl* TextCtrl60;
		wxTextCtrl* TextCtrl56;
		wxTextCtrl* TextCtrl13;
		wxTextCtrl* TextCtrl21;
		wxPanel* Panel7;
		wxButton* btnLoad;
		wxTextCtrl* TextCtrl79;
		wxTextCtrl* TextCtrl53;
		wxButton* btnClean;
		wxTextCtrl* TextCtrl50;
		wxTextCtrl* TextCtrl44;
		wxTextCtrl* TextCtrl72;
		wxTextCtrl* TextCtrl22;
		wxTextCtrl* TextCtrl20;
		wxTextCtrl* TextCtrl8;
		wxTextCtrl* TextCtrl43;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl29;
		wxTextCtrl* TextCtrl7;
		wxTextCtrl* TextCtrl52;
		wxTextCtrl* TextCtrl61;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl25;
		wxTextCtrl* TextCtrl32;
		wxTextCtrl* TextCtrl9;
		wxPanel* Panel2;
		wxTextCtrl* TextCtrl63;
		wxTextCtrl* TextCtrl5;
		wxTextCtrl* TextCtrl51;
		wxTextCtrl* TextCtrl23;
		wxTextCtrl* TextCtrl73;
		wxTextCtrl* TextCtrl31;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl67;
		wxTextCtrl* TextCtrl40;
		wxTextCtrl* TextCtrl10;
		wxTextCtrl* TextCtrl12;
		wxTextCtrl* TextCtrl36;
		wxTextCtrl* TextCtrl38;
		wxTextCtrl* TextCtrl49;
		wxTextCtrl* TextCtrl46;
		wxTextCtrl* TextCtrl35;
		wxTextCtrl* TextCtrl11;
		wxTextCtrl* TextCtrl33;
		wxTextCtrl* TextCtrl62;
		wxTextCtrl* TextCtrl65;
		//*)

		wxTextCtrl* TextCtrl[9][9];

	protected:

		//(*Identifiers(Sudoku)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_TEXTCTRL73;
		static const long ID_TEXTCTRL74;
		static const long ID_TEXTCTRL75;
		static const long ID_TEXTCTRL76;
		static const long ID_TEXTCTRL77;
		static const long ID_TEXTCTRL78;
		static const long ID_TEXTCTRL79;
		static const long ID_TEXTCTRL80;
		static const long ID_TEXTCTRL81;
		static const long ID_PANEL9;
		static const long ID_TEXTCTRL64;
		static const long ID_TEXTCTRL65;
		static const long ID_TEXTCTRL66;
		static const long ID_TEXTCTRL67;
		static const long ID_TEXTCTRL68;
		static const long ID_TEXTCTRL69;
		static const long ID_TEXTCTRL70;
		static const long ID_TEXTCTRL71;
		static const long ID_TEXTCTRL72;
		static const long ID_PANEL8;
		static const long ID_TEXTCTRL46;
		static const long ID_TEXTCTRL47;
		static const long ID_TEXTCTRL48;
		static const long ID_TEXTCTRL49;
		static const long ID_TEXTCTRL50;
		static const long ID_TEXTCTRL51;
		static const long ID_TEXTCTRL52;
		static const long ID_TEXTCTRL53;
		static const long ID_TEXTCTRL54;
		static const long ID_PANEL6;
		static const long ID_TEXTCTRL55;
		static const long ID_TEXTCTRL56;
		static const long ID_TEXTCTRL57;
		static const long ID_TEXTCTRL58;
		static const long ID_TEXTCTRL59;
		static const long ID_TEXTCTRL60;
		static const long ID_TEXTCTRL61;
		static const long ID_TEXTCTRL62;
		static const long ID_TEXTCTRL63;
		static const long ID_PANEL7;
		static const long ID_TEXTCTRL37;
		static const long ID_TEXTCTRL38;
		static const long ID_TEXTCTRL39;
		static const long ID_TEXTCTRL40;
		static const long ID_TEXTCTRL41;
		static const long ID_TEXTCTRL42;
		static const long ID_TEXTCTRL43;
		static const long ID_TEXTCTRL44;
		static const long ID_TEXTCTRL45;
		static const long ID_PANEL5;
		static const long ID_TEXTCTRL28;
		static const long ID_TEXTCTRL29;
		static const long ID_TEXTCTRL30;
		static const long ID_TEXTCTRL31;
		static const long ID_TEXTCTRL32;
		static const long ID_TEXTCTRL33;
		static const long ID_TEXTCTRL34;
		static const long ID_TEXTCTRL35;
		static const long ID_TEXTCTRL36;
		static const long ID_PANEL4;
		static const long ID_TEXTCTRL19;
		static const long ID_TEXTCTRL20;
		static const long ID_TEXTCTRL21;
		static const long ID_TEXTCTRL22;
		static const long ID_TEXTCTRL23;
		static const long ID_TEXTCTRL24;
		static const long ID_TEXTCTRL25;
		static const long ID_TEXTCTRL26;
		static const long ID_TEXTCTRL27;
		static const long ID_PANEL3;
		static const long ID_TEXTCTRL10;
		static const long ID_TEXTCTRL11;
		static const long ID_TEXTCTRL12;
		static const long ID_TEXTCTRL13;
		static const long ID_TEXTCTRL14;
		static const long ID_TEXTCTRL15;
		static const long ID_TEXTCTRL16;
		static const long ID_TEXTCTRL17;
		static const long ID_TEXTCTRL18;
		static const long ID_PANEL2;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_TEXTCTRL6;
		static const long ID_TEXTCTRL7;
		static const long ID_TEXTCTRL8;
		static const long ID_TEXTCTRL9;
		static const long ID_PANEL1;
		static const long ID_TEXTCTRL82;
		static const long ID_STATICBOX1;
		//*)

	private:

		//(*Handlers(Sudoku)
		void OnInit(wxInitDialogEvent& event);
		void OnbtnCleanClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnbtnLoadClick(wxCommandEvent& event);
		void OnbtnSolveClick(wxCommandEvent& event);
		void OnbtnSaveClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
