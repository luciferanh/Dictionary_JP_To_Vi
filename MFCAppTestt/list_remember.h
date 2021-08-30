#pragma once
#include "odbcinst.h"
#include "framework.h"
#include "MFCAppTestt.h"
#include "MFCAppTesttDlg.h"
#include "afxdialogex.h"
#include <afxdb.h>
class list_remember 
{
	CArray<CString, CString> dinhnghia_Array;
	CArray<CString, CString> cachdoc_Array;
	CArray<CString, CString> ynghia_Array;
	CArray<CString, CString> strID_Array;
	CString server = _T("DESKTOP-LERS9E6"), databaseName = _T("mytest"), username = _T("vietanhh"), password = _T("123456");
public:
	CDatabase db;
	list_remember();
	~list_remember();
	void Add_String(CString*);
	void Init_Table(CListCtrl&);
	void Remove(CString);

};


