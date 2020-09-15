#pragma once
#include "atldbcli.h"

typedef CCommand<CDynamicStringAccessorW,CRowset> DbCommand;

class CDataSet
{
public:
	CDataSet(void);
	~CDataSet(void);
	CSession m_dbSession;
	bool m_bOpenSession;
	bool Open(void);
	bool Query(CString strQuery, DbCommand* pDbCommand);
};

