
// MFCAppTesttDlg.cpp : implementation file
//

#pragma comment(lib, "Winmm")
#include "pch.h"
#include "framework.h"
#include "MFCAppTestt.h"
#include "MFCAppTesttDlg.h"
#include "afxdialogex.h"
#include "TuDien.h"
#include "DongTu.h"
#include <Windows.h>
#include "Main_DS.h"
#include "list_remember.h"
#include <mmsystem.h>
#include <Mmsystem.h>
#include <cstdlib>
#include <fstream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString* dong_tu_can_chia = NULL;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCAppTesttDlg dialog



CMFCAppTesttDlg::CMFCAppTesttDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPTESTT_DIALOG, pParent)
	, m_check_ls(0)
	, m_check_te(0)
	, m_check_yc_(0)
	, m_check_kn_(0)
	, m_check_dk_(0)
	, m_check_pd_(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAppTesttDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH, m_edt_search_);
	DDX_Control(pDX, IDC_GIAI_THICH, m_dinh_nghia_);
	DDX_Control(pDX, IDC_BTN_VERB, m_check_dt_);

	DDX_Control(pDX, IDC_LIST_CHIA_DONG_TU, list_dong_tu_);
	//DDX_Control(pDX, IDC_CHECK_DK2, check_phu_dinh_);
	DDX_Check(pDX, IDC_CHECK_LS, m_check_ls);
	DDX_Check(pDX, IDC_CHECK_TE, m_check_te);
	DDX_Check(pDX, IDC_CHECK_YC, m_check_yc_);
	DDX_Check(pDX, IDC_CHECK_KN, m_check_kn_);
	DDX_Check(pDX, IDC_CHECK_DK, m_check_dk_);
	DDX_Check(pDX, IDC_CHECK_PD, m_check_pd_);
	DDX_Control(pDX, IDC_BTN_THEM, m_add_str_);
}

BEGIN_MESSAGE_MAP(CMFCAppTesttDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TIM, &CMFCAppTesttDlg::OnBnClickedBtnTim)
	ON_BN_CLICKED(IDC_CHECK_TE, &CMFCAppTesttDlg::OnBnClickedCheckTe)
	ON_BN_CLICKED(IDC_BTN_VERB, &CMFCAppTesttDlg::OnBnClickedBtnVerb)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCAppTesttDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BTN_XEM_DS, &CMFCAppTesttDlg::OnBnClickedBtnXemDs)
	ON_BN_CLICKED(IDC_BTN_THEM, &CMFCAppTesttDlg::OnBnClickedBtnThem)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCAppTesttDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCAppTesttDlg message handlers

BOOL CMFCAppTesttDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	list_dong_tu_.InsertColumn(0, L"Các thể", LVCFMT_LEFT, 300);
	list_dong_tu_.InsertColumn(1, L"Động từ", LVCFMT_LEFT, 350);
	m_check_dt_.EnableWindow(FALSE);
	m_check_ls = m_check_te = m_check_yc_ = m_check_kn_ = m_check_dk_ = m_check_pd_ = 1;
	UpdateData(FALSE);
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCAppTesttDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCAppTesttDlg::OnPaint()
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
HCURSOR CMFCAppTesttDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCAppTesttDlg::OnBnClickedBtnTim()
{
	UpdateData(TRUE);
	CString tu_can_tim = _T("");
	m_edt_search_.GetWindowText(tu_can_tim);
	TuDien a;
	CString* giaithich = a.Search(tu_can_tim);
	if (giaithich) {
		CString strData;
		strData.Format(L"%s\r\nÝ nghĩa: %s", giaithich[0], giaithich[1]);
		m_dinh_nghia_.SetWindowText(strData);
		
		if (giaithich[2] == L"1" || giaithich[2] == L"2" || giaithich[2] == L"3") {
			m_check_dt_.EnableWindow(TRUE);
			dong_tu_can_chia = giaithich;
		} else{
			m_check_dt_.EnableWindow(FALSE);
		}
	}
	else {
		AfxMessageBox(L"Database error: ");
	}
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CMFCAppTesttDlg::OnBnClickedCheckTe()
{
	// TODO: Add your control notification handler code here
}


void CMFCAppTesttDlg::OnBnClickedBtnVerb()
{
	UpdateData(TRUE);
	DongTu a(dong_tu_can_chia);
	CString* listV = a.chiadongtu();
	list_dong_tu_.DeleteAllItems();
	CString dsV[] = { L"Thể từ điển",L"Thể lịch sự", L"Thể te", L"Thể ý chí", L"Thể khả năng", L"Thể điều kiện" , L"Thể phủ định" };
	int check_[] = {1, m_check_ls ,m_check_te, m_check_yc_,m_check_kn_,m_check_dk_,m_check_pd_  };
	if (listV)
	{

		for (size_t i = 0; i < 7; i++)
		{
			if (check_[7-i-1])
			{
				list_dong_tu_.InsertItem(0, dsV[7 - i - 1]);
				list_dong_tu_.SetItemText(0, 1, listV[7 - i - 1]);
			}

		}

	}
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CMFCAppTesttDlg::OnBnClickedButton5()
{
	CString url,link__;
	m_edt_search_.GetWindowText(url);
	link__ += L"https://mazii.vn/#!/search?dict=javi&type=w&query=" + url ;

	ShellExecute(NULL, NULL, link__, NULL, NULL, SW_SHOWNORMAL);
	// TODO: Add your control notification handler code here
}


void CMFCAppTesttDlg::OnBnClickedBtnXemDs()
{
	Main_DS main_dlg;
	main_dlg.DoModal();
	// TODO: Add your control notification handler code here
}


void CMFCAppTesttDlg::OnBnClickedBtnThem()
{
	list_remember a;
	if(dong_tu_can_chia)
		a.Add_String(dong_tu_can_chia);
	
	// TODO: Add your control notification handler code here
}

void PlayFrom(CString TheFile) {
	CString TheDir= _T("C://Users//vieta//source//repos//MFCAppTestt//MFCAppTestt//Sounds//");
	CString Load_IT = _T("open \"") + TheDir + TheFile + _T("\" type mpegvideo alias ") + TheFile;
	mciSendString(Load_IT, NULL, 0, 0);
	CString Play_IT = _T("play ") + TheFile + _T("from 0");
	mciSendString(Play_IT, NULL, 0, 0);
}
void CMFCAppTesttDlg::OnBnClickedButton1()
{
	//CString tu_can_tim = _T(""), file_=_T("");
	//m_edt_search_.GetWindowText(tu_can_tim);
	//file_.Format(TEXT("C://Users//vieta//source//repos//MFCAppTestt//MFCAppTestt//Sounds//%s.wav"), tu_can_tim);
	bool runn = PlaySound(L"行く.wav", NULL, SND_FILENAME | SND_ASYNC);

		//PlayFrom(tu_can_tim + L".wav");
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}
