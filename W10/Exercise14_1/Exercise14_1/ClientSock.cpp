// ClientSock.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise14_1.h"
#include "ClientSock.h"
#include "Exercise14_1.h"


// CClientSock

CClientSock::CClientSock()
{
}

CClientSock::~CClientSock()
{
}


// CClientSock ��� �Լ�


void CClientSock::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CExercise14_1App*)AfxGetApp())->ReceiveData(this);

	CAsyncSocket::OnReceive(nErrorCode);
}


void CClientSock::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CExercise14_1App*)AfxGetApp())->CloseChild(this);

	CAsyncSocket::OnClose(nErrorCode);
}
