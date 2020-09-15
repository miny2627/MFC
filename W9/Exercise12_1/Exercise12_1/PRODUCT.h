// PRODUCT.h : CPRODUCT의 선언입니다.

#pragma once

// 코드 생성 위치 2018년 5월 26일 토요일, 오전 9:32

class CPRODUCTAccessor
{
public:
	TCHAR m_Code[256];
	LONG m_ID;
	TCHAR m_NProduct[256];
	TCHAR m_Price[256];

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dwCodeStatus;
	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwNProductStatus;
	DBSTATUS m_dwPriceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dwCodeLength;
	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwNProductLength;
	DBLENGTH m_dwPriceLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;

		hr = _db.OpenFromInitializationString(L"Provider=Microsoft.ACE.OLEDB.12.0;User ID=Admin;Data Source=C:\\Users\\LG\\Documents\\MY\\MFC\\Exercise12_1\\Exercise12_1\\Orderdb.accdb;Mode=Share Deny None;Extended Properties=\"\";Jet OLEDB:System database=\"\";Jet OLEDB:Registry Path=\"\";Jet OLEDB:Database Password=\"\";Jet OLEDB:Engine Type=6;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:New Database Password=\"\";Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;Jet OLEDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False;Jet OLEDB:Support Complex Data=False");
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

	DEFINE_COMMAND_EX(CPRODUCTAccessor, L" \
	SELECT \
		Code, \
		ID, \
		NProduct, \
		Price \
		FROM PRODUCT")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_COLUMN_MAP(CPRODUCTAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_Code, m_dwCodeLength, m_dwCodeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_NProduct, m_dwNProductLength, m_dwNProductStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_Price, m_dwPriceLength, m_dwPriceStatus)
	END_COLUMN_MAP()
};

template <class T>
class CPRODUCT : public CCommand<CAccessor<T> >
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

class CPRODUCTModeAccessor
{
public:
	TCHAR m_Code[256];
	LONG m_ID;
	TCHAR m_NProduct[256];
	TCHAR m_Price[256];

	// 다음 마법사 생성 데이터 멤버에는  열 맵의 해당 
	// 필드에 대한 상태 값이 들어 있습니다. 이 값을
	// 사용하여 데이터베이스에서반환하는 NULL 값을
	// 보유하거나 컴파일러에서 오류를 반환할 때
	// 오류 정보를 보유할 수 있습니다. 이러한 필드 사용에
	// 대한 자세한 내용은 Visual C++ 설명서의
	//  "마법사 생성 접근자"에서 "필드 상태 데이터 멤버"를 참조하십시오.
	// 참고: 데이터를 설정/삽입하기 전에 이들 필드를 초기화해야 합니다.

	DBSTATUS m_dwCodeStatus;
	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwNProductStatus;
	DBSTATUS m_dwPriceStatus;

	// 다음 마법사 생성 데이터 멤버에는 열 맵의 해당 필드에 대한
	// 길이 값이 들어 있습니다.
	// 참고: 가변 길이 열의 경우 데이터를 설정/삽입하기 전에 
//       이러한 	 필드를 초기화해야 합니다.

	DBLENGTH m_dwCodeLength;
	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwNProductLength;
	DBLENGTH m_dwPriceLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;

		hr = _db.OpenFromInitializationString(L"Provider=Microsoft.ACE.OLEDB.12.0;User ID=Admin;Data Source=C:\\Users\\LG\\Documents\\MY\\MFC\\Exercise12_1\\Exercise12_1\\Orderdb.accdb;Mode=Share Deny None;Extended Properties=\"\";Jet OLEDB:System database=\"\";Jet OLEDB:Registry Path=\"\";Jet OLEDB:Database Password=\"\";Jet OLEDB:Engine Type=6;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:New Database Password=\"\";Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;Jet OLEDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False;Jet OLEDB:Support Complex Data=False");
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

	DEFINE_COMMAND_EX(CPRODUCTModeAccessor, L" \
	SELECT * \
		FROM PRODUCT")


	// 일부 공급자와 관련된 몇몇 문제점을 해결하기 위해 아래 코드에서는 
	// 공급자가 보고하는 것과 다른 순서로 열을 바인딩할 수 있습니다.

	BEGIN_COLUMN_MAP(CPRODUCTModeAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_Code, m_dwCodeLength, m_dwCodeStatus)
		//COLUMN_ENTRY_LENGTH_STATUS(0, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_NProduct, m_dwNProductLength, m_dwNProductStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_Price, m_dwPriceLength, m_dwPriceStatus)
	END_COLUMN_MAP()
};
