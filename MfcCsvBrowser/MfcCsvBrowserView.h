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

// MfcCsvBrowserView.h : interface of the CMfcCsvBrowserView class
//

#pragma once


class CMfcCsvBrowserView : public CView
{
protected: // create from serialization only
	CMfcCsvBrowserView();
	DECLARE_DYNCREATE(CMfcCsvBrowserView)

// Attributes
public:
	CMfcCsvBrowserDoc* GetDocument() const;
	bool pressed = false;
	int mouseX = 0;
	int mouseY = 0;
	CDC MemDC;
	CBitmap MemBitmap;
	CDC *theDC;
	CMainFrame* pMain;
	bool inited = false;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMfcCsvBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnColor();
	afx_msg void OnBrush();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MfcCsvBrowserView.cpp
inline CMfcCsvBrowserDoc* CMfcCsvBrowserView::GetDocument() const
   { return reinterpret_cast<CMfcCsvBrowserDoc*>(m_pDocument); }
#endif

