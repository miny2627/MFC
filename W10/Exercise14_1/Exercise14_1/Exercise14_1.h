
// Exercise14_1.h : PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.
#include "ClientSock.h"
#include "ServerSock.h"
#include "afxcoll.h"


// CExercise14_1App:
// 이 클래스의 구현에 대해서는 Exercise14_1.cpp을 참조하십시오.
//

class CExercise14_1App : public CWinApp
{
public:
	CExercise14_1App();

// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.

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