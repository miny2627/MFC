// ServerSock.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise14_1.h"
#include "ServerSock.h"
#include "Exercise14_1.h"

// CServerSock

CServerSock::CServerSock()
{
}

CServerSock::~CServerSock()
{
}


// CServerSock ��� �Լ�


void CServerSock::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CExercise14_1App*)AfxGetApp())->Accept();

	CAsyncSocket::OnAccept(nErrorCode);
}
