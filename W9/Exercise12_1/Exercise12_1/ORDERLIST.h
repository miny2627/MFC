// ORDERLIST.h : CORDERLIST�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 5�� 26�� �����, ���� 11:02

class CORDERLISTAccessor
{
public:
	TCHAR m_Code[256];
	TCHAR m_FDate[256];
	LONG m_ID;
	TCHAR m_Product[256];
	TCHAR m_TCount[256];
	TCHAR m_TPrice[256];

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwCodeStatus;
	DBSTATUS m_dwFDateStatus;
	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwProductStatus;
	DBSTATUS m_dwTCountStatus;
	DBSTATUS m_dwTPriceStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwCodeLength;
	DBLENGTH m_dwFDateLength;
	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwProductLength;
	DBLENGTH m_dwTCountLength;
	DBLENGTH m_dwTPriceLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
		hr = _db.OpenFromInitializationString(L"Provider=Microsoft.ACE.OLEDB.12.0;User ID=Admin;Data Source=C:\\Users\\LG\\Documents\\MY\\MFC\\Exercise12_1\\Exercise12_1\\OrderDb.accdb;Mode=Share Deny None;Extended Properties=\"\";Jet OLEDB:System database=\"\";Jet OLEDB:Registry Path=\"\";Jet OLEDB:Database Password=\"\";Jet OLEDB:Engine Type=6;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:New Database Password=\"\";Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;Jet OLEDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False;Jet OLEDB:Support Complex Data=False");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	DEFINE_COMMAND_EX(CORDERLISTAccessor, L" \
	SELECT \
		Code, \
		FDate, \
		ID, \
		Product, \
		TCount, \
		TPrice \
		FROM ORDERLIST")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_COLUMN_MAP(CORDERLISTAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_Code, m_dwCodeLength, m_dwCodeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_FDate, m_dwFDateLength, m_dwFDateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_Product, m_dwProductLength, m_dwProductStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_TCount, m_dwTCountLength, m_dwTCountStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_TPrice, m_dwTPriceLength, m_dwTPriceStatus)
	END_COLUMN_MAP()
};

template <class T>
class CORDERLIST : public CCommand<CAccessor<T> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, NULL, pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		ReleaseCommand();
		CloseDataSource();
	}
};

class CORDERLISTModeAccessor
{
public:
	TCHAR m_Code[256];
	TCHAR m_FDate[256];
	LONG m_ID;
	TCHAR m_Product[256];
	TCHAR m_TCount[256];
	TCHAR m_TPrice[256];

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwCodeStatus;
	DBSTATUS m_dwFDateStatus;
	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwProductStatus;
	DBSTATUS m_dwTCountStatus;
	DBSTATUS m_dwTPriceStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwCodeLength;
	DBLENGTH m_dwFDateLength;
	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwProductLength;
	DBLENGTH m_dwTCountLength;
	DBLENGTH m_dwTPriceLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
		hr = _db.OpenFromInitializationString(L"Provider=Microsoft.ACE.OLEDB.12.0;User ID=Admin;Data Source=C:\\Users\\LG\\Documents\\MY\\MFC\\Exercise12_1\\Exercise12_1\\OrderDb.accdb;Mode=Share Deny None;Extended Properties=\"\";Jet OLEDB:System database=\"\";Jet OLEDB:Registry Path=\"\";Jet OLEDB:Database Password=\"\";Jet OLEDB:Engine Type=6;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:New Database Password=\"\";Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;Jet OLEDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False;Jet OLEDB:Support Complex Data=False");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	DEFINE_COMMAND_EX(CORDERLISTModeAccessor, L" \
	SELECT \
		Code, \
		FDate, \
		ID, \
		Product, \
		TCount, \
		TPrice \
		FROM ORDERLIST")


	// �Ϻ� �����ڿ� ���õ� ��� �������� �ذ��ϱ� ���� �Ʒ� �ڵ忡���� 
	// �����ڰ� �����ϴ� �Ͱ� �ٸ� ������ ���� ���ε��� �� �ֽ��ϴ�.

	BEGIN_COLUMN_MAP(CORDERLISTModeAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_Code, m_dwCodeLength, m_dwCodeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_FDate, m_dwFDateLength, m_dwFDateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_Product, m_dwProductLength, m_dwProductStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_TCount, m_dwTCountLength, m_dwTCountStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_TPrice, m_dwTPriceLength, m_dwTPriceStatus)
	END_COLUMN_MAP()
};

