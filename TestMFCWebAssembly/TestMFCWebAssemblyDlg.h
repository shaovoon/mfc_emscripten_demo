
// TestMFCWebAssemblyDlg.h : header file
//

#pragma once
#include "Dialog.h"
#include <memory>

// CTestMFCWebAssemblyDlg dialog
class CTestMFCWebAssemblyDlg : public CDialogEx
{
// Construction
public:
	CTestMFCWebAssemblyDlg(CWnd* pParent = nullptr);	// standard constructor

private:
	std::shared_ptr<Dialog> m_pDialog;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTMFCWEBASSEMBLY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edtMessage;
	CButton m_chkPrependHello;
	CButton m_btnSayHello;
	afx_msg void OnBnClickedBtnSayHello();
};
