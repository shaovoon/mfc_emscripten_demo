
// TestMFCWebAssemblyDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "TestMFCWebAssembly.h"
#include "TestMFCWebAssemblyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCWebAssemblyDlg dialog



CTestMFCWebAssemblyDlg::CTestMFCWebAssemblyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTMFCWEBASSEMBLY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCWebAssemblyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_MESSAGE, m_edtMessage);
	DDX_Control(pDX, IDC_CHK_PREPEND_HELLO, m_chkPrependHello);
	DDX_Control(pDX, IDC_BTN_SAY_HELLO, m_btnSayHello);
}

BEGIN_MESSAGE_MAP(CTestMFCWebAssemblyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SAY_HELLO, &CTestMFCWebAssemblyDlg::OnBnClickedBtnSayHello)
END_MESSAGE_MAP()


// CTestMFCWebAssemblyDlg message handlers

BOOL CTestMFCWebAssemblyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_pDialog = std::make_shared<Dialog>(&m_edtMessage, &m_chkPrependHello, &m_btnSayHello);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestMFCWebAssemblyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestMFCWebAssemblyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestMFCWebAssemblyDlg::OnBnClickedBtnSayHello()
{
	m_pDialog->m_Button.CallClickHandler();
}
