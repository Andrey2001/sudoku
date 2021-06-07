#include "Sudoku.h"

//(*InternalHeaders(Sudoku)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Sudoku)
const long Sudoku::ID_BUTTON1 = wxNewId();
const long Sudoku::ID_BUTTON2 = wxNewId();
const long Sudoku::ID_BUTTON3 = wxNewId();
const long Sudoku::ID_BUTTON4 = wxNewId();
const long Sudoku::ID_TEXTCTRL73 = wxNewId();
const long Sudoku::ID_TEXTCTRL74 = wxNewId();
const long Sudoku::ID_TEXTCTRL75 = wxNewId();
const long Sudoku::ID_TEXTCTRL76 = wxNewId();
const long Sudoku::ID_TEXTCTRL77 = wxNewId();
const long Sudoku::ID_TEXTCTRL78 = wxNewId();
const long Sudoku::ID_TEXTCTRL79 = wxNewId();
const long Sudoku::ID_TEXTCTRL80 = wxNewId();
const long Sudoku::ID_TEXTCTRL81 = wxNewId();
const long Sudoku::ID_PANEL9 = wxNewId();
const long Sudoku::ID_TEXTCTRL64 = wxNewId();
const long Sudoku::ID_TEXTCTRL65 = wxNewId();
const long Sudoku::ID_TEXTCTRL66 = wxNewId();
const long Sudoku::ID_TEXTCTRL67 = wxNewId();
const long Sudoku::ID_TEXTCTRL68 = wxNewId();
const long Sudoku::ID_TEXTCTRL69 = wxNewId();
const long Sudoku::ID_TEXTCTRL70 = wxNewId();
const long Sudoku::ID_TEXTCTRL71 = wxNewId();
const long Sudoku::ID_TEXTCTRL72 = wxNewId();
const long Sudoku::ID_PANEL8 = wxNewId();
const long Sudoku::ID_TEXTCTRL46 = wxNewId();
const long Sudoku::ID_TEXTCTRL47 = wxNewId();
const long Sudoku::ID_TEXTCTRL48 = wxNewId();
const long Sudoku::ID_TEXTCTRL49 = wxNewId();
const long Sudoku::ID_TEXTCTRL50 = wxNewId();
const long Sudoku::ID_TEXTCTRL51 = wxNewId();
const long Sudoku::ID_TEXTCTRL52 = wxNewId();
const long Sudoku::ID_TEXTCTRL53 = wxNewId();
const long Sudoku::ID_TEXTCTRL54 = wxNewId();
const long Sudoku::ID_PANEL6 = wxNewId();
const long Sudoku::ID_TEXTCTRL55 = wxNewId();
const long Sudoku::ID_TEXTCTRL56 = wxNewId();
const long Sudoku::ID_TEXTCTRL57 = wxNewId();
const long Sudoku::ID_TEXTCTRL58 = wxNewId();
const long Sudoku::ID_TEXTCTRL59 = wxNewId();
const long Sudoku::ID_TEXTCTRL60 = wxNewId();
const long Sudoku::ID_TEXTCTRL61 = wxNewId();
const long Sudoku::ID_TEXTCTRL62 = wxNewId();
const long Sudoku::ID_TEXTCTRL63 = wxNewId();
const long Sudoku::ID_PANEL7 = wxNewId();
const long Sudoku::ID_TEXTCTRL37 = wxNewId();
const long Sudoku::ID_TEXTCTRL38 = wxNewId();
const long Sudoku::ID_TEXTCTRL39 = wxNewId();
const long Sudoku::ID_TEXTCTRL40 = wxNewId();
const long Sudoku::ID_TEXTCTRL41 = wxNewId();
const long Sudoku::ID_TEXTCTRL42 = wxNewId();
const long Sudoku::ID_TEXTCTRL43 = wxNewId();
const long Sudoku::ID_TEXTCTRL44 = wxNewId();
const long Sudoku::ID_TEXTCTRL45 = wxNewId();
const long Sudoku::ID_PANEL5 = wxNewId();
const long Sudoku::ID_TEXTCTRL28 = wxNewId();
const long Sudoku::ID_TEXTCTRL29 = wxNewId();
const long Sudoku::ID_TEXTCTRL30 = wxNewId();
const long Sudoku::ID_TEXTCTRL31 = wxNewId();
const long Sudoku::ID_TEXTCTRL32 = wxNewId();
const long Sudoku::ID_TEXTCTRL33 = wxNewId();
const long Sudoku::ID_TEXTCTRL34 = wxNewId();
const long Sudoku::ID_TEXTCTRL35 = wxNewId();
const long Sudoku::ID_TEXTCTRL36 = wxNewId();
const long Sudoku::ID_PANEL4 = wxNewId();
const long Sudoku::ID_TEXTCTRL19 = wxNewId();
const long Sudoku::ID_TEXTCTRL20 = wxNewId();
const long Sudoku::ID_TEXTCTRL21 = wxNewId();
const long Sudoku::ID_TEXTCTRL22 = wxNewId();
const long Sudoku::ID_TEXTCTRL23 = wxNewId();
const long Sudoku::ID_TEXTCTRL24 = wxNewId();
const long Sudoku::ID_TEXTCTRL25 = wxNewId();
const long Sudoku::ID_TEXTCTRL26 = wxNewId();
const long Sudoku::ID_TEXTCTRL27 = wxNewId();
const long Sudoku::ID_PANEL3 = wxNewId();
const long Sudoku::ID_TEXTCTRL10 = wxNewId();
const long Sudoku::ID_TEXTCTRL11 = wxNewId();
const long Sudoku::ID_TEXTCTRL12 = wxNewId();
const long Sudoku::ID_TEXTCTRL13 = wxNewId();
const long Sudoku::ID_TEXTCTRL14 = wxNewId();
const long Sudoku::ID_TEXTCTRL15 = wxNewId();
const long Sudoku::ID_TEXTCTRL16 = wxNewId();
const long Sudoku::ID_TEXTCTRL17 = wxNewId();
const long Sudoku::ID_TEXTCTRL18 = wxNewId();
const long Sudoku::ID_PANEL2 = wxNewId();
const long Sudoku::ID_TEXTCTRL1 = wxNewId();
const long Sudoku::ID_TEXTCTRL2 = wxNewId();
const long Sudoku::ID_TEXTCTRL3 = wxNewId();
const long Sudoku::ID_TEXTCTRL4 = wxNewId();
const long Sudoku::ID_TEXTCTRL5 = wxNewId();
const long Sudoku::ID_TEXTCTRL6 = wxNewId();
const long Sudoku::ID_TEXTCTRL7 = wxNewId();
const long Sudoku::ID_TEXTCTRL8 = wxNewId();
const long Sudoku::ID_TEXTCTRL9 = wxNewId();
const long Sudoku::ID_PANEL1 = wxNewId();
const long Sudoku::ID_TEXTCTRL82 = wxNewId();
const long Sudoku::ID_STATICBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Sudoku,wxDialog)
	//(*EventTable(Sudoku)
	//*)
END_EVENT_TABLE()

Sudoku::Sudoku(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Sudoku)
	Create(parent, wxID_ANY, _("Судоку"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(414,526));
	btnClean = new wxButton(this, ID_BUTTON1, _("Очистить"), wxPoint(14,416), wxSize(86,28), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	btnSave = new wxButton(this, ID_BUTTON2, _("Сохранить"), wxPoint(116,416), wxSize(86,28), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	btnLoad = new wxButton(this, ID_BUTTON3, _("Загрузить"), wxPoint(214,416), wxSize(86,28), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	btnSolve = new wxButton(this, ID_BUTTON4, _("Решить"), wxPoint(312,416), wxSize(86,28), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Panel9 = new wxPanel(this, ID_PANEL9, wxPoint(8,8), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL9"));
	TextCtrl73 = new wxTextCtrl(Panel9, ID_TEXTCTRL73, _("01"), wxPoint(8,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL73"));
	TextCtrl74 = new wxTextCtrl(Panel9, ID_TEXTCTRL74, _("02"), wxPoint(48,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL74"));
	TextCtrl75 = new wxTextCtrl(Panel9, ID_TEXTCTRL75, _("03"), wxPoint(88,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL75"));
	TextCtrl76 = new wxTextCtrl(Panel9, ID_TEXTCTRL76, _("04"), wxPoint(8,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL76"));
	TextCtrl77 = new wxTextCtrl(Panel9, ID_TEXTCTRL77, _("05"), wxPoint(48,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL77"));
	TextCtrl78 = new wxTextCtrl(Panel9, ID_TEXTCTRL78, _("06"), wxPoint(88,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL78"));
	TextCtrl79 = new wxTextCtrl(Panel9, ID_TEXTCTRL79, _("07"), wxPoint(8,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL79"));
	TextCtrl80 = new wxTextCtrl(Panel9, ID_TEXTCTRL80, _("08"), wxPoint(48,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL80"));
	TextCtrl81 = new wxTextCtrl(Panel9, ID_TEXTCTRL81, _("09"), wxPoint(88,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL81"));
	Panel8 = new wxPanel(this, ID_PANEL8, wxPoint(280,280), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL8"));
	TextCtrl64 = new wxTextCtrl(Panel8, ID_TEXTCTRL64, _("01"), wxPoint(8,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL64"));
	TextCtrl65 = new wxTextCtrl(Panel8, ID_TEXTCTRL65, _("02"), wxPoint(48,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL65"));
	TextCtrl66 = new wxTextCtrl(Panel8, ID_TEXTCTRL66, _("03"), wxPoint(88,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL66"));
	TextCtrl67 = new wxTextCtrl(Panel8, ID_TEXTCTRL67, _("04"), wxPoint(8,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL67"));
	TextCtrl68 = new wxTextCtrl(Panel8, ID_TEXTCTRL68, _("05"), wxPoint(48,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL68"));
	TextCtrl69 = new wxTextCtrl(Panel8, ID_TEXTCTRL69, _("06"), wxPoint(88,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL69"));
	TextCtrl70 = new wxTextCtrl(Panel8, ID_TEXTCTRL70, _("07"), wxPoint(8,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL70"));
	TextCtrl71 = new wxTextCtrl(Panel8, ID_TEXTCTRL71, _("08"), wxPoint(48,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL71"));
	TextCtrl72 = new wxTextCtrl(Panel8, ID_TEXTCTRL72, _("09"), wxPoint(88,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL72"));
	Panel6 = new wxPanel(this, ID_PANEL6, wxPoint(144,280), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
	TextCtrl46 = new wxTextCtrl(Panel6, ID_TEXTCTRL46, _("01"), wxPoint(8,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL46"));
	TextCtrl47 = new wxTextCtrl(Panel6, ID_TEXTCTRL47, _("02"), wxPoint(48,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL47"));
	TextCtrl48 = new wxTextCtrl(Panel6, ID_TEXTCTRL48, _("03"), wxPoint(88,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL48"));
	TextCtrl49 = new wxTextCtrl(Panel6, ID_TEXTCTRL49, _("04"), wxPoint(8,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL49"));
	TextCtrl50 = new wxTextCtrl(Panel6, ID_TEXTCTRL50, _("05"), wxPoint(48,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL50"));
	TextCtrl51 = new wxTextCtrl(Panel6, ID_TEXTCTRL51, _("06"), wxPoint(88,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL51"));
	TextCtrl52 = new wxTextCtrl(Panel6, ID_TEXTCTRL52, _("07"), wxPoint(8,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL52"));
	TextCtrl53 = new wxTextCtrl(Panel6, ID_TEXTCTRL53, _("08"), wxPoint(48,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL53"));
	TextCtrl54 = new wxTextCtrl(Panel6, ID_TEXTCTRL54, _("09"), wxPoint(88,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL54"));
	Panel7 = new wxPanel(this, ID_PANEL7, wxPoint(8,280), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
	TextCtrl55 = new wxTextCtrl(Panel7, ID_TEXTCTRL55, _("01"), wxPoint(8,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL55"));
	TextCtrl56 = new wxTextCtrl(Panel7, ID_TEXTCTRL56, _("02"), wxPoint(48,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL56"));
	TextCtrl57 = new wxTextCtrl(Panel7, ID_TEXTCTRL57, _("03"), wxPoint(88,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL57"));
	TextCtrl58 = new wxTextCtrl(Panel7, ID_TEXTCTRL58, _("04"), wxPoint(8,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL58"));
	TextCtrl59 = new wxTextCtrl(Panel7, ID_TEXTCTRL59, _("05"), wxPoint(48,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL59"));
	TextCtrl60 = new wxTextCtrl(Panel7, ID_TEXTCTRL60, _("06"), wxPoint(88,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL60"));
	TextCtrl61 = new wxTextCtrl(Panel7, ID_TEXTCTRL61, _("07"), wxPoint(8,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL61"));
	TextCtrl62 = new wxTextCtrl(Panel7, ID_TEXTCTRL62, _("08"), wxPoint(48,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL62"));
	TextCtrl63 = new wxTextCtrl(Panel7, ID_TEXTCTRL63, _("09"), wxPoint(88,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL63"));
	Panel5 = new wxPanel(this, ID_PANEL5, wxPoint(280,144), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
	TextCtrl37 = new wxTextCtrl(Panel5, ID_TEXTCTRL37, _("01"), wxPoint(8,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL37"));
	TextCtrl38 = new wxTextCtrl(Panel5, ID_TEXTCTRL38, _("02"), wxPoint(48,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL38"));
	TextCtrl39 = new wxTextCtrl(Panel5, ID_TEXTCTRL39, _("03"), wxPoint(88,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL39"));
	TextCtrl40 = new wxTextCtrl(Panel5, ID_TEXTCTRL40, _("04"), wxPoint(8,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL40"));
	TextCtrl41 = new wxTextCtrl(Panel5, ID_TEXTCTRL41, _("05"), wxPoint(48,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL41"));
	TextCtrl42 = new wxTextCtrl(Panel5, ID_TEXTCTRL42, _("06"), wxPoint(88,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL42"));
	TextCtrl43 = new wxTextCtrl(Panel5, ID_TEXTCTRL43, _("07"), wxPoint(8,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL43"));
	TextCtrl44 = new wxTextCtrl(Panel5, ID_TEXTCTRL44, _("08"), wxPoint(48,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL44"));
	TextCtrl45 = new wxTextCtrl(Panel5, ID_TEXTCTRL45, _("09"), wxPoint(88,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL45"));
	Panel4 = new wxPanel(this, ID_PANEL4, wxPoint(144,144), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	TextCtrl28 = new wxTextCtrl(Panel4, ID_TEXTCTRL28, _("01"), wxPoint(8,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL28"));
	TextCtrl29 = new wxTextCtrl(Panel4, ID_TEXTCTRL29, _("02"), wxPoint(48,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL29"));
	TextCtrl30 = new wxTextCtrl(Panel4, ID_TEXTCTRL30, _("03"), wxPoint(88,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL30"));
	TextCtrl31 = new wxTextCtrl(Panel4, ID_TEXTCTRL31, _("04"), wxPoint(8,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL31"));
	TextCtrl32 = new wxTextCtrl(Panel4, ID_TEXTCTRL32, _("05"), wxPoint(48,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL32"));
	TextCtrl33 = new wxTextCtrl(Panel4, ID_TEXTCTRL33, _("06"), wxPoint(88,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL33"));
	TextCtrl34 = new wxTextCtrl(Panel4, ID_TEXTCTRL34, _("07"), wxPoint(8,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL34"));
	TextCtrl35 = new wxTextCtrl(Panel4, ID_TEXTCTRL35, _("08"), wxPoint(48,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL35"));
	TextCtrl36 = new wxTextCtrl(Panel4, ID_TEXTCTRL36, _("09"), wxPoint(88,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL36"));
	Panel3 = new wxPanel(this, ID_PANEL3, wxPoint(8,144), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	TextCtrl19 = new wxTextCtrl(Panel3, ID_TEXTCTRL19, _("01"), wxPoint(8,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
	TextCtrl20 = new wxTextCtrl(Panel3, ID_TEXTCTRL20, _("02"), wxPoint(48,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
	TextCtrl21 = new wxTextCtrl(Panel3, ID_TEXTCTRL21, _("03"), wxPoint(88,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));
	TextCtrl22 = new wxTextCtrl(Panel3, ID_TEXTCTRL22, _("04"), wxPoint(8,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
	TextCtrl23 = new wxTextCtrl(Panel3, ID_TEXTCTRL23, _("05"), wxPoint(48,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL23"));
	TextCtrl24 = new wxTextCtrl(Panel3, ID_TEXTCTRL24, _("06"), wxPoint(88,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
	TextCtrl25 = new wxTextCtrl(Panel3, ID_TEXTCTRL25, _("07"), wxPoint(8,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL25"));
	TextCtrl26 = new wxTextCtrl(Panel3, ID_TEXTCTRL26, _("08"), wxPoint(48,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL26"));
	TextCtrl27 = new wxTextCtrl(Panel3, ID_TEXTCTRL27, _("09"), wxPoint(88,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL27"));
	Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(280,8), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	TextCtrl10 = new wxTextCtrl(Panel2, ID_TEXTCTRL10, _("01"), wxPoint(8,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	TextCtrl11 = new wxTextCtrl(Panel2, ID_TEXTCTRL11, _("02"), wxPoint(48,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
	TextCtrl12 = new wxTextCtrl(Panel2, ID_TEXTCTRL12, _("03"), wxPoint(88,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
	TextCtrl13 = new wxTextCtrl(Panel2, ID_TEXTCTRL13, _("04"), wxPoint(8,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
	TextCtrl14 = new wxTextCtrl(Panel2, ID_TEXTCTRL14, _("05"), wxPoint(48,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
	TextCtrl15 = new wxTextCtrl(Panel2, ID_TEXTCTRL15, _("06"), wxPoint(88,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
	TextCtrl16 = new wxTextCtrl(Panel2, ID_TEXTCTRL16, _("07"), wxPoint(8,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
	TextCtrl17 = new wxTextCtrl(Panel2, ID_TEXTCTRL17, _("08"), wxPoint(48,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
	TextCtrl18 = new wxTextCtrl(Panel2, ID_TEXTCTRL18, _("09"), wxPoint(88,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(144,8), wxSize(128,128), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("01"), wxPoint(8,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("02"), wxPoint(48,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("03"), wxPoint(88,8), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("04"), wxPoint(8,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl5 = new wxTextCtrl(Panel1, ID_TEXTCTRL5, _("05"), wxPoint(48,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	TextCtrl6 = new wxTextCtrl(Panel1, ID_TEXTCTRL6, _("06"), wxPoint(88,48), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	TextCtrl7 = new wxTextCtrl(Panel1, ID_TEXTCTRL7, _("07"), wxPoint(8,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	TextCtrl8 = new wxTextCtrl(Panel1, ID_TEXTCTRL8, _("08"), wxPoint(48,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	TextCtrl9 = new wxTextCtrl(Panel1, ID_TEXTCTRL9, _("09"), wxPoint(88,88), wxSize(32,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	txtLeft = new wxTextCtrl(this, ID_TEXTCTRL82, _("81"), wxPoint(152,480), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL82"));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Осталось"), wxPoint(48,480), wxDefaultSize, 0, _T("ID_STATICBOX1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Sudoku::OnbtnCleanClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Sudoku::OnbtnSaveClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Sudoku::OnbtnLoadClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Sudoku::OnbtnSolveClick);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&Sudoku::OnInit);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Sudoku::OnClose);
	//*)
}

Sudoku::~Sudoku()
{
	//(*Destroy(Sudoku)
	//*)
}

void Sudoku::OnInit(wxInitDialogEvent& event)
{
	TextCtrl[0][0] = TextCtrl73;
	TextCtrl[0][1] = TextCtrl74;
	TextCtrl[0][2] = TextCtrl75;
	TextCtrl[0][3] = TextCtrl1;
	TextCtrl[0][4] = TextCtrl2;
	TextCtrl[0][5] = TextCtrl3;
	TextCtrl[0][6] = TextCtrl10;
	TextCtrl[0][7] = TextCtrl11;
	TextCtrl[0][8] = TextCtrl12;
	TextCtrl[1][0] = TextCtrl76;
	TextCtrl[1][1] = TextCtrl77;
	TextCtrl[1][2] = TextCtrl78;
	TextCtrl[1][3] = TextCtrl4;
	TextCtrl[1][4] = TextCtrl5;
	TextCtrl[1][5] = TextCtrl6;
	TextCtrl[1][6] = TextCtrl13;
	TextCtrl[1][7] = TextCtrl14;
	TextCtrl[1][8] = TextCtrl15;
	TextCtrl[2][0] = TextCtrl79;
	TextCtrl[2][1] = TextCtrl80;
	TextCtrl[2][2] = TextCtrl81;
	TextCtrl[2][3] = TextCtrl7;
	TextCtrl[2][4] = TextCtrl8;
	TextCtrl[2][5] = TextCtrl9;
	TextCtrl[2][6] = TextCtrl16;
	TextCtrl[2][7] = TextCtrl17;
	TextCtrl[2][8] = TextCtrl18;
	TextCtrl[3][0] = TextCtrl19;
	TextCtrl[3][1] = TextCtrl20;
	TextCtrl[3][2] = TextCtrl21;
	TextCtrl[3][3] = TextCtrl28;
	TextCtrl[3][4] = TextCtrl29;
	TextCtrl[3][5] = TextCtrl30;
	TextCtrl[3][6] = TextCtrl37;
	TextCtrl[3][7] = TextCtrl38;
	TextCtrl[3][8] = TextCtrl39;
	TextCtrl[4][0] = TextCtrl22;
	TextCtrl[4][1] = TextCtrl23;
	TextCtrl[4][2] = TextCtrl24;
	TextCtrl[4][3] = TextCtrl31;
	TextCtrl[4][4] = TextCtrl32;
	TextCtrl[4][5] = TextCtrl33;
	TextCtrl[4][6] = TextCtrl40;
	TextCtrl[4][7] = TextCtrl41;
	TextCtrl[4][8] = TextCtrl42;
	TextCtrl[5][0] = TextCtrl25;
	TextCtrl[5][1] = TextCtrl26;
	TextCtrl[5][2] = TextCtrl27;
	TextCtrl[5][3] = TextCtrl34;
	TextCtrl[5][4] = TextCtrl35;
	TextCtrl[5][5] = TextCtrl36;
	TextCtrl[5][6] = TextCtrl43;
	TextCtrl[5][7] = TextCtrl44;
	TextCtrl[5][8] = TextCtrl45;
	TextCtrl[6][0] = TextCtrl55;
	TextCtrl[6][1] = TextCtrl56;
	TextCtrl[6][2] = TextCtrl57;
	TextCtrl[6][3] = TextCtrl46;
	TextCtrl[6][4] = TextCtrl47;
	TextCtrl[6][5] = TextCtrl48;
	TextCtrl[6][6] = TextCtrl64;
	TextCtrl[6][7] = TextCtrl65;
	TextCtrl[6][8] = TextCtrl66;
	TextCtrl[7][0] = TextCtrl58;
	TextCtrl[7][1] = TextCtrl59;
	TextCtrl[7][2] = TextCtrl60;
	TextCtrl[7][3] = TextCtrl49;
	TextCtrl[7][4] = TextCtrl50;
	TextCtrl[7][5] = TextCtrl51;
	TextCtrl[7][6] = TextCtrl67;
	TextCtrl[7][7] = TextCtrl68;
	TextCtrl[7][8] = TextCtrl69;
	TextCtrl[8][0] = TextCtrl61;
	TextCtrl[8][1] = TextCtrl62;
	TextCtrl[8][2] = TextCtrl63;
	TextCtrl[8][3] = TextCtrl52;
	TextCtrl[8][4] = TextCtrl53;
	TextCtrl[8][5] = TextCtrl54;
	TextCtrl[8][6] = TextCtrl70;
	TextCtrl[8][7] = TextCtrl71;
	TextCtrl[8][8] = TextCtrl72;
	OnbtnCleanClick(*(wxCommandEvent*)NULL);
}

void Sudoku::OnbtnCleanClick(wxCommandEvent& event)
{
	wxFont* font = new wxFont(18, wxDEFAULT, wxNORMAL, wxNORMAL);
	for (int y = 0; y < 9; ++y) {
		for (int x = 0; x < 9; ++x) {
			TextCtrl[y][x]->SetFont(*font);
			TextCtrl[y][x]->SetValue("");
		}
	}
}


typedef wxTextCtrl* Field[9][9];

int Get(int y, int x, void * fld)
{
    Field * field = (Field *)fld;
    wxString s = (*field)[y][x]->GetValue();
    return (0 < s.Len() && '1' <= s.GetChar(0) && s.GetChar(0) <= '9') ? s.GetChar(0) - '0' : 0;
}

#include <wx/utils.h>

void Set(int y, int x, int v, void * fld)
{
    Field * field = (Field *)fld;
    wxString s = "";
    if (1 <= v && v <= 9) s.append((char)('0' + v));
    (*field)[y][x]->SetValue(s);
    wxYield();  // отрисовать изменения на форме
    Sleep(100); // пауза 0.1 секунды
}

void SetHowManyLeft(int left, void * fld)
{
    Field * field = (Field *)fld;
    Sudoku * sud = (Sudoku *) ( (*field)[0][0]->GetParent()->GetParent() );
    wxString s = ""; s.append((char)('0' + left/10)); s.append((char)('0' + left % 10));
    sud->txtLeft->SetValue(s);
}

int main2(void * fld);

void Sudoku::OnbtnSolveClick(wxCommandEvent& event)
{
    main2(&TextCtrl);
}


#include <wx/filedlg.h>
#include <wx/msw/filedlg.h>

void Sudoku::OnbtnLoadClick(wxCommandEvent& event)
{
    wxFileDialog * o = new wxFileDialog(this, "Загрузка головоломки", ".", wxEmptyString, "*.txt", wxFD_OPEN);
    if (o->ShowModal() == wxID_OK) {
        FILE * f = fopen(o->GetPath(), "r");
        if (f) {  int y, x;  char s[99];
            for (y = 0; y < 9; ++y) {
                fgets(s, 90, f);
                for (x = 0; x < 9; ++x) { wxString c = "";
                    if ('1' <= s[x+x] && s[x+x] <= '9') c.append(s[x+x]);
                    TextCtrl[y][x]->SetValue(c);
                }
            }
            fclose(f);
        }
    }
    delete o;
}

void Sudoku::OnbtnSaveClick(wxCommandEvent& event)
{
    wxFileDialog * o = new wxFileDialog(this, "Сохранение головоломки", ".", wxEmptyString, "*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (o->ShowModal() == wxID_OK) {
        FILE * f = fopen(o->GetPath(), "w");
        if (f) {  int y, x;
            for (y = 0; y < 9; ++y) {  char s[] = "0 0 0 0 0 0 0 0 0\n";
                for (x = 0; x < 9; ++x) {  wxString c = TextCtrl[y][x]->GetValue();
                    if (0 < c.Len() && '1' <= c.GetChar(0) && c.GetChar(0) <= '9') s[x+x] = c.GetChar(0);
                }
                fputs(s, f);
            }
            fclose(f);
        }
    }
    delete o;
}


#include <wx/app.h>

void Sudoku::OnClose(wxCloseEvent& event)
{
	wxApp::GetInstance()->Exit();
}

#include <wx/wx.h>

void MyBox(char * msg)
{
    wxMessageBox(msg, _("Информация"));
}
