#include "pch.h"
#include "list_remember.h"

list_remember::list_remember()
{
	bool is_connect = false;
	db.Close();
	CString connectString = _T("");
	connectString.Format(L"Driver={SQL Server};Server=%s;Database=%s;Uid=%s;Pwd=%s;", \
		server, databaseName, username, password);
	if (!db.IsOpen() && !db.OpenEx(connectString))
		is_connect = false;
	else is_connect = true;
}

list_remember::~list_remember()
{
	this->db.Close();
}

void list_remember::Add_String(CString* tu_add)
{
	CString query;
	query.Format(L"INSERT INTO vocab_remmember \
						VALUES (N'%s',N'%s',N'%s',%s)", tu_add[3], tu_add[0], tu_add[1], tu_add[2]);

	TRY{
			this->db.ExecuteSQL(query);
			AfxMessageBox(L"Đã thêm thành công");
			this->db.Close();
	}
		CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Error:" + e->m_strError);
	}
	END_CATCH;
}

void list_remember::Init_Table(CListCtrl& m_list_rem_)
{
	CRecordset recset(&this->db);
	CString SqlString = _T("SELECT * FROM vocab_remmember");
	CString dinhnghia, cachdoc, ynghia, id;
	TRY{
	recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);

	while (!recset.IsEOF())
	{
		recset.GetFieldValue(_T("MAT2"), dinhnghia);
		recset.GetFieldValue(_T("TENT2"), cachdoc);
		recset.GetFieldValue(_T("Y_NGHIA"), ynghia);
		recset.GetFieldValue(_T("TYPE_SO"), id);
		recset.MoveNext();
		dinhnghia_Array.Add(dinhnghia);
		cachdoc_Array.Add(cachdoc);
		ynghia_Array.Add(ynghia);
		strID_Array.Add(id);
		if (ynghia !=L"")
		{
			m_list_rem_.InsertItem(0, dinhnghia);
			m_list_rem_.SetItemText(0, 1, ynghia);
		}


	}
	recset.Close();

	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		WCHAR buff[500];                                      // WCHAR not char
		WCHAR author[] = L"ERROR";                              // WCHAR not char
		swprintf_s(buff, L" (This is %s)", author);  // swprintf_s not sprintf_s
		MessageBoxW(0, buff, L"(Error)", 0);
		db.Close();
	}
	END_CATCH;

}

void list_remember::Remove(CString tu_xoa)
{
	CString query=_T("");
	query.Format(L"DELETE FROM  vocab_remmember WHERE MAT2 = N'%s'", tu_xoa);

	TRY{
			this->db.ExecuteSQL(query);
			AfxMessageBox(L"Đã xóa thành công");

	}
		CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Error:" + e->m_strError);
	}
	END_CATCH;
}
