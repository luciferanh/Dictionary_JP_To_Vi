#include "pch.h"
#include "TuDien.h"

TuDien::TuDien()
{
	bool is_connect = false;
	db.Close();
	CString connectString = _T("");
	connectString.Format(L"Driver={SQL Server};Server=%s;Database=%s;Uid=%s;Pwd=%s;", \
		server, databaseName, username, password);
	if (!db.IsOpen() && !db.OpenEx(connectString))
		is_connect = false;
	else is_connect = true;
	CRecordset recset(&this->db);
	CString SqlString = _T("SELECT * FROM J_V");
	CString dinhnghia, cachdoc,ynghia, id;
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

	}
	recset.Close();
	db.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		WCHAR buff[500];                                      // WCHAR not char
		WCHAR author[] = L"ERROR";                              // WCHAR not char
		swprintf_s(buff, L" (This is %s)", author);  // swprintf_s not sprintf_s
		MessageBoxW(0, buff, L"(Error)", 0);
	}
	END_CATCH;

}

TuDien::~TuDien()
{
	this->db.Close();
}

void TuDien::Add_String(CString* tu_add)
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

CString* TuDien::Search(CString tucantim)
{
	CString* mang = new CString[4];
	for (size_t i = 0; i < dinhnghia_Array.GetSize(); i++)
	{	
		if (!tucantim.CompareNoCase(dinhnghia_Array.GetAt(i)))
		{
			
			mang[0]= cachdoc_Array.GetAt(i);
			mang[1] = ynghia_Array.GetAt(i);
			mang[2] = strID_Array.GetAt(i);
			mang[3] = dinhnghia_Array.GetAt(i);
			return mang;
		}
	}
	mang = NULL;
	return mang;
}
