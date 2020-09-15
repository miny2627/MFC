#include "StdAfx.h"
#include "DataSet.h"


CDataSet::CDataSet(void)
	: m_bOpenSession(false)
{
	m_bOpenSession=false;
	m_bOpenSession=Open();
	if(!m_bOpenSession)
	{
		AfxMessageBox(_T("Can't access database"));
		exit(1);
	}
}


CDataSet::~CDataSet(void)
{
	m_dbSession.Close();
}


bool CDataSet::Open(void)
{
	m_dbSession.Close();
	CDataSource db;
	HRESULT hr=CoInitialize(NULL);

	TCHAR programpath[_MAX_PATH];
	int index;
	CString strPath;
	GetModuleFileName(NULL,programpath,_MAX_PATH);
	strPath=programpath;
	index=strPath.ReverseFind('\\');
	strPath=strPath.Left(index+1);
	
	//DB���� ��ġ�� �ٸ� ��� �� �ڵ�� �����ص� ��
	//DB���� ��ġ�� ���� dbFilePath ����
	CString dbFilePath;
	dbFilePath.Format(_T("%sCardDb.accdb"),strPath);

	CString strConnect;
	strConnect.Format(_T("Provider=Microsoft.ace.oledb.12.0;Data Source=%s"),dbFilePath);

	hr=db.OpenFromInitializationString(strConnect);
	if(FAILED(hr))
	{
		return m_bOpenSession=false;
	}
	
	hr=m_dbSession.Open(db);
	if(FAILED(hr))
	{
		return m_bOpenSession=false;
	}

	CComVariant Var;
	hr=db.GetProperty(DBPROPSET_DATASOURCEINFO,DBPROP_DATASOURCENAME,&Var);
	if(FAILED(hr))
	{
		return m_bOpenSession=false;
	}
	return m_bOpenSession=true;
}


bool CDataSet::Query(CString strQuery, DbCommand* pDbCommand)
{
	if(!m_bOpenSession)
	{
		return false;
	}
	CDBPropSet propset(DBPROPSET_ROWSET);
	propset.AddProperty(DBPROP_IRowsetChange,true);
	propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE |
					DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
	propset.AddProperty(DBPROP_CANSCROLLBACKWARDS,true);
	HRESULT hr=pDbCommand->Open(m_dbSession,strQuery,&propset);
	if(FAILED(hr))
	{
#ifdef _DEBUG
		AtlTraceErrorRecords(hr);
#endif
		return false;
	}
	return true;
}
