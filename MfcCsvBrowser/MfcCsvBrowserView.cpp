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

#include "MainFrm.h"
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
	ON_WM_MBUTTONDBLCLK()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_LBUTTONUP()
ON_COMMAND(ID_BRUSH, &CMfcCsvBrowserView::OnBrush)
ON_WM_LBUTTONDOWN()
ON_WM_MOUSEMOVE()
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

void CMfcCsvBrowserView::OnDraw(CDC* pDC)
{
	CMfcCsvBrowserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->MoveTo(100, 100);
	pDC->LineTo(600, 100);

	CPen pp(PS_DASHDOT, 1, RGB(255, 0, 0));
	pDC->SelectObject(pp);
	pDC->MoveTo(100, 100);
	pDC->LineTo(100, 600);

	//OnDraw函数中重绘位图的操作：
	CRect rect;
	GetClientRect(&rect);
	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &pBack, 0, 0, SRCCOPY);

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



//void CMfcCsvBrowserView::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CView::OnLButtonDblClk(nFlags, point);
//}


void CMfcCsvBrowserView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CString m_msg;
	pressed = false;
	/*m_msg.Format(_T("Mouse: x:%d, y:%d."), point.x, point.y);
	AfxMessageBox(m_msg);*/
	CView::OnLButtonUp(nFlags, point);
}



void CMfcCsvBrowserView::OnBrush()
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	pDC->MoveTo(100, 100);
	pDC->LineTo(600, 100);

	CPen pp(PS_DASHDOT, 1, RGB(255, 0, 0));
	pDC->SelectObject(pp);
	pDC->MoveTo(100, 100);
	pDC->LineTo(100, 600);
}


void CMfcCsvBrowserView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDown(nFlags, point);
	if (!inited){
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
		theDC = GetDC();
		/*CRect rect;
		GetClientRect(&rect);
		MemDC.CreateCompatibleDC(NULL);
		MemBitmap.CreateCompatibleBitmap(theDC, rect.Width(), rect.Height());*/
		inited = true;
	}

	pressed = true;
	mouseX = point.x;
	mouseY = point.y;
}


void CMfcCsvBrowserView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnMouseMove(nFlags, point);
	if (pressed) {
		theDC = GetDC();
		//CMainFrame* pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
		CPen pp(PS_SOLID, 1, pMain->PenColor);
		//pDC->SetPixel(point.x, point.y, pMain->PenColor);
		
		theDC->SelectObject(pp);
		theDC->MoveTo(mouseX, mouseY);
		theDC->LineTo(point.x, point.y);
		mouseX = point.x;
		mouseY = point.y;

		/*CRect rect;
		GetClientRect(&rect);
		pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);*/
		
	}
}
