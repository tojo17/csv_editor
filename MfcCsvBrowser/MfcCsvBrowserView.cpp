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

// MfcCsvBrowserView.cpp : implementation of the CMfcCsvBrowserView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MfcCsvBrowser.h"
#endif

#include "MfcCsvBrowserDoc.h"
#include "MfcCsvBrowserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcCsvBrowserView

IMPLEMENT_DYNCREATE(CMfcCsvBrowserView, CView)

BEGIN_MESSAGE_MAP(CMfcCsvBrowserView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMfcCsvBrowserView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMfcCsvBrowserView construction/destruction

CMfcCsvBrowserView::CMfcCsvBrowserView()
{
	// TODO: add construction code here

}

CMfcCsvBrowserView::~CMfcCsvBrowserView()
{
}

BOOL CMfcCsvBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMfcCsvBrowserView drawing

void CMfcCsvBrowserView::OnDraw(CDC* /*pDC*/)
{
	CMfcCsvBrowserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMfcCsvBrowserView printing


void CMfcCsvBrowserView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMfcCsvBrowserView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMfcCsvBrowserView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMfcCsvBrowserView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMfcCsvBrowserView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMfcCsvBrowserView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMfcCsvBrowserView diagnostics

#ifdef _DEBUG
void CMfcCsvBrowserView::AssertValid() const
{
	CView::AssertValid();
}

void CMfcCsvBrowserView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMfcCsvBrowserDoc* CMfcCsvBrowserView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMfcCsvBrowserDoc)));
	return (CMfcCsvBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CMfcCsvBrowserView message handlers
