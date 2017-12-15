#pragma once


// CellEditDlg dialog

class CellEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CellEditDlg)

public:
	CellEditDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CellEditDlg();

// Dialog Data
	enum { IDD = IDD_EDITCELL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString text;
	bool confirmed = false;
	afx_msg void OnBnClickedOk();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
