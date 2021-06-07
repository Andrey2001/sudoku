/***************************************************************
 * Name:      wxTestApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2017-02-25
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxTestApp.h"
#include "Sudoku.h"

IMPLEMENT_APP(wxTestApp);

bool wxTestApp::OnInit()
{
    Sudoku* dlg = new Sudoku((wxWindow*)NULL, wxID_ANY, wxDefaultPosition, wxSize(400, 400));
    dlg->Show();
    return true;
}
