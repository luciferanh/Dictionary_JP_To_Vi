#pragma once


// Main_DS dialog

class Main_DS : public CDialogEx
{
	DECLARE_DYNAMIC(Main_DS)

public:
	Main_DS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Main_DS();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIA_DS_REM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_remove_voc_;
	CButton m_check_mazii_;
	CListCtrl m_list_rem_;
	afx_msg void OnBnClickedBtnMz();
	afx_msg void OnBnClickedBtnRemove();
};
