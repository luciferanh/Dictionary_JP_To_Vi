
// MFCAppTesttDlg.h : header file
//

#pragma once

#include <mmsystem.h>
// CMFCAppTesttDlg dialog
class CMFCAppTesttDlg : public CDialogEx
{
// Construction
public:
	CMFCAppTesttDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPTESTT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	CEdit m_edt_search_;
	CEdit m_dinh_nghia_;
	afx_msg void OnBnClickedBtnTim();
	CButton m_check_dt_;
	afx_msg void OnBnClickedCheckTe();

	CListCtrl list_dong_tu_;
	afx_msg void OnBnClickedBtnVerb();


	int m_check_ls;
	int m_check_te;
	int m_check_yc_;
	int m_check_kn_;
	int m_check_dk_;
	int m_check_pd_;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedBtnXemDs();
	afx_msg void OnBnClickedBtnThem();
	CButton m_add_str_;
	afx_msg void OnBnClickedButton1();
};
