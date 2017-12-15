// CellEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MfcCsvBrowser.h"
#include "CellEditDlg.h"
#include "afxdialogex.h"


// CellEditDlg dialog

IMPLEMENT_DYNAMIC(CellEditDlg, CDialogEx)

CellEditDlg::CellEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CellEditDlg::IDD, pParent)
	, text(_T(""))
{

}

CellEditDlg::~CellEditDlg()
{
}

void CellEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, text);
}


BEGIN_MESSAGE_MAP(CellEditDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CellEditDlg::OnBnClickedOk)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CellEditDlg message handlers


void CellEditDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	confirmed = true;

	CDialogEx::OnOK();
}


void CellEditDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	confirmed = false;
}
