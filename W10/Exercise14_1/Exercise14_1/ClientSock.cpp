// ClientSock.cpp : 구현 파일입니다.
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


// CClientSock 멤버 함수


void CClientSock::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	((CExercise14_1App*)AfxGetApp())->ReceiveData(this);

	CAsyncSocket::OnReceive(nErrorCode);
}


void CClientSock::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	((CExercise14_1App*)AfxGetApp())->CloseChild(this);

	CAsyncSocket::OnClose(nErrorCode);
}
