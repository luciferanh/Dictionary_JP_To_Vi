// Main_DS.cpp : implementation file
//

#include "pch.h"
#include "MFCAppTestt.h"
#include "Main_DS.h"
#include "afxdialogex.h"
#include "list_remember.h"

// Main_DS dialog

IMPLEMENT_DYNAMIC(Main_DS, CDialogEx)
list_remember list_db;
Main_DS::Main_DS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIA_DS_REM, pParent)
{

}

Main_DS::~Main_DS()
{
}

void Main_DS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_REMOVE, m_remove_voc_);
	DDX_Control(pDX, IDC_BTN_MZ, m_check_mazii_);
	DDX_Control(pDX, IDC_LIST_REM, m_list_rem_);
	m_list_rem_.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
	m_list_rem_.InsertColumn(0, L"Định nghĩa", LVCFMT_LEFT, 150);
	m_list_rem_.InsertColumn(1, L"Giải thích", LVCFMT_LEFT, 350);
	list_db.Init_Table(m_list_rem_);
}


BEGIN_MESSAGE_MAP(Main_DS, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_MZ, &Main_DS::OnBnClickedBtnMz)
	ON_BN_CLICKED(IDC_BTN_REMOVE, &Main_DS::OnBnClickedBtnRemove)
END_MESSAGE_MAP()


// Main_DS message handlers


void Main_DS::OnBnClickedBtnMz()
{
	for (size_t i = 0; i < m_list_rem_.GetItemCount(); i++)
	{
		if (ListView_GetCheckState(m_list_rem_.GetSafeHwnd(),i)) {
			CString temp= m_list_rem_.GetItemText(i,0), link__;
			link__ += L"https://mazii.vn/#!/search?dict=javi&type=w&query=" + temp;

			ShellExecute(NULL, NULL, link__, NULL, NULL, SW_SHOWNORMAL);
		}
	}

	// TODO: Add your control notification handler code here
}


void Main_DS::OnBnClickedBtnRemove()
{
	UpdateData(FALSE);
	for (size_t i = 0; i < m_list_rem_.GetItemCount(); i++)
	{

		if (ListView_GetCheckState(m_list_rem_.GetSafeHwnd(), i)) {

			CString temp = m_list_rem_.GetItemText(i, 0);

			list_db.Remove(temp);

			break;
		}
	}
	m_list_rem_.DeleteAllItems();
	UpdateData(FALSE);

	// TODO: Add your control notification handler code here
}
