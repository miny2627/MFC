
// Exercise14_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "ClientSock.h"
#include "ServerSock.h"
#include "afxcoll.h"


// CExercise14_1App:
// �� Ŭ������ ������ ���ؼ��� Exercise14_1.cpp�� �����Ͻʽÿ�.
//

class CExercise14_1App : public CWinApp
{
public:
	CExercise14_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CServerSock* m_pServer;
	CClientSock* m_pClient;
	void InitServer(void);
	void Accept(void);
	void CleanUp(void);
	void Connect(CString strIP);
	void ReceiveData(CClientSock* pSock);
	void SendData(CString strData);
	void CloseChild(CClientSock* pClose);
	CObList m_ClientList;
};

extern CExercise14_1App theApp;