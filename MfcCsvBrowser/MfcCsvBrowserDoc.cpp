// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// MfcCsvBrowserDoc.cpp : implementation of the CMfcCsvBrowserDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MfcCsvBrowser.h"
#endif

#include "MfcCsvBrowserDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

// CMfcCsvBrowserDoc

IMPLEMENT_DYNCREATE(CMfcCsvBrowserDoc, CDocument)

BEGIN_MESSAGE_MAP(CMfcCsvBrowserDoc, CDocument)
END_MESSAGE_MAP()
const int UNICODE_TXT_FLG = 0xFEFF;

// CMfcCsvBrowserDoc construction/destruction

CMfcCsvBrowserDoc::CMfcCsvBrowserDoc()
{
	// TODO: add one-time construction code here

}

CMfcCsvBrowserDoc::~CMfcCsvBrowserDoc()
{
}

BOOL CMfcCsvBrowserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMfcCsvBrowserDoc serialization

void CMfcCsvBrowserDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// storing code here
		((CMainFrame*)AfxGetMainWnd())->UpdateStatusBar(ID_STATUSBAR_PANE1, L"Saving...");
		CFile *file = ar.GetFile();
		char str[204800] = { 0 };
		CString buff;
		//file->Write(&UNICODE_TXT_FLG, 2);
		int length = 0;
		for (int i = 0; i < m_data.size(); i++){
			for (int ii = 0; ii < m_data[i].size(); ii++){
				buff += m_data[i][ii];
				length += sizeof(m_data[i][ii]);
				if (ii != m_data[i].size() - 1) {
					buff += L',';
					length++;
				}
			}
			if (i != m_data.size() - 1) {
				buff += L"\r\n";
				length += 2;
			}
		}
		file->Write(CW2A(buff, CP_UTF8), length);
		file->Flush();
		((CMainFrame*)AfxGetMainWnd())->UpdateStatusBar(ID_STATUSBAR_PANE1, L"Saved.");
	}
	else
	{
		// loading code here
		CFile *file = ar.GetFile();
		char str[204800] = { 0 };

		if (file->GetLength() == 0){
			AfxMessageBox(L"Empty File!");
			return;
		}


		((CMainFrame*)AfxGetMainWnd())->UpdateStatusBar(ID_STATUSBAR_PANE1, L"Reading data...");

		CString cstr;
		file->Read(str, 204799);
		cstr = CA2W(str, CP_UTF8);
		//AfxMessageBox(cstr);
		CString line;
		int i = 0;

		while (AfxExtractSubString(line, cstr, i, _T('\n'))){
			i++;
			CString cell;
			int ii = 0;
			vector<CString> v_line;
			while (AfxExtractSubString(cell, line, ii, _T(','))){
				ii++;
				v_line.push_back(cell);
			}
			m_data.push_back(v_line);
		}
		//AfxMessageBox(m_data[1][2]);

	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMfcCsvBrowserDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMfcCsvBrowserDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMfcCsvBrowserDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMfcCsvBrowserDoc diagnostics

#ifdef _DEBUG
void CMfcCsvBrowserDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMfcCsvBrowserDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMfcCsvBrowserDoc commands
