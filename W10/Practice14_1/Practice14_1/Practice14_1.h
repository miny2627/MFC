
// Practice14_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "ServerSock.h"
#include "ClientSock.h"


// CPractice14_1App:
// �� Ŭ������ ������ ���ؼ��� Practice14_1.cpp�� �����Ͻʽÿ�.
//

class CPractice14_1App : public CWinApp
{
public:
	CPractice14_1App();

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
	void ReceiveData(void);
	void SendData(CString strData);
	void CloseChild(void);
};

extern CPractice14_1App theApp;