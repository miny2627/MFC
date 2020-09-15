
// Exercise14_1.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "Exercise14_1.h"
#include "Exercise14_1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise14_1App

BEGIN_MESSAGE_MAP(CExercise14_1App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExercise14_1App 생성

CExercise14_1App::CExercise14_1App()
	: m_pServer(NULL)
	, m_pClient(NULL)
{
	// 다시 시작 관리자 지원
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CExercise14_1App 개체입니다.

CExercise14_1App theApp;


// CExercise14_1App 초기화

BOOL CExercise14_1App::InitInstance()
{
	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다.
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	AfxEnableControlContainer();

	// 대화 상자에 셸 트리 뷰 또는
	// 셸 목록 뷰 컨트롤이 포함되어 있는 경우 셸 관리자를 만듭니다.
	CShellManager *pShellManager = new CShellManager;

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));

	CExercise14_1Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 여기에 [확인]을 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 여기에 [취소]를 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}

	// 위에서 만든 셸 관리자를 삭제합니다.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 대화 상자가 닫혔으므로 응용 프로그램의 메시지 펌프를 시작하지 않고  응용 프로그램을 끝낼 수 있도록 FALSE를
	// 반환합니다.
	return FALSE;
}



void CExercise14_1App::InitServer(void)
{
	m_pServer=new CServerSock;
	m_pServer->Create(7777);
	m_pServer->Listen();
}


void CExercise14_1App::Accept(void)
{
	CClientSock* pClient=new CClientSock;
	if(m_pServer->Accept(*pClient))
	{
		m_ClientList.AddTail(pClient);
	}
}


void CExercise14_1App::CleanUp(void)
{
	if(m_pServer)
	{
		delete m_pServer;
		m_pServer=NULL;
		
		if(m_ClientList.GetCount()>0)
		{
			CClientSock* pClient;
			POSITION pos=m_ClientList.GetHeadPosition();
			while(pos!=NULL)
			{
				pClient=(CClientSock*)m_ClientList.GetAt(pos);
				m_ClientList.RemoveAt(pos);
				delete pClient;
				m_ClientList.GetNext(pos);
			}
		}
	}

	if(m_pClient)
		delete m_pClient;
}


void CExercise14_1App::Connect(CString strIP)
{
	m_pClient=new CClientSock;
	m_pClient->Create();
	m_pClient->Connect(strIP,7777);
}


void CExercise14_1App::ReceiveData(CClientSock* pSock)
{
	wchar_t temp[MAX_PATH];
	int nSize=pSock->Receive(temp,sizeof(temp));
	CString strOut;
	if(m_pServer)
	{
		CString strIP;
		UINT nPort;
		pSock->GetPeerName(strIP,nPort);
		strOut.Format(_T("[%s]:%s"),strIP,temp);
		((CExercise14_1Dlg*)m_pMainWnd)->ReceiveData(strOut);

		if(m_ClientList.GetCount()>1)
		{
			CClientSock* pReceive;
			POSITION pos=m_ClientList.GetHeadPosition();
			while(pos!=NULL)
			{
				pReceive=(CClientSock*)m_ClientList.GetAt(pos);
				if(pSock!=pReceive)
				{
					pReceive->Send((LPCTSTR)strOut,sizeof(TCHAR)*(strOut.GetLength()+1));
				}
				m_ClientList.GetNext(pos);
			}
			int count=(int)m_ClientList.GetCount();
		}
	}
	else
		((CExercise14_1Dlg*)m_pMainWnd)->ReceiveData(temp);
}


void CExercise14_1App::SendData(CString strData)
{
	if(m_pClient)
	{
		m_pClient->Send((LPCTSTR)strData,sizeof(TCHAR)*(strData.GetLength()+1));
	}
	else
	{
		CClientSock* pClient;
		POSITION pos=m_ClientList.GetHeadPosition();
		CString strSend;
		while(pos!=NULL)
		{
			strSend.Format(_T("[%s]:%s"),((CExercise14_1Dlg*)m_pMainWnd)->m_strMyIP,strData);
			pClient=(CClientSock*)m_ClientList.GetAt(pos);
			pClient->Send((LPCTSTR)strSend,sizeof(TCHAR)*(strSend.GetLength()+1));
			m_ClientList.GetNext(pos);
		}
	}
}


void CExercise14_1App::CloseChild(CClientSock* pClose)
{
	if(m_pClient==pClose)
	{
		AfxMessageBox(_T("상대방 연결 끊김"));
		delete m_pClient;
		m_pClient=NULL;
	}
	else
	{
		if(m_ClientList.GetCount()>0)
		{
			CClientSock* pClient;
			POSITION pos=m_ClientList.Find(pClose);
			if(pos!=NULL)
			{
				pClient=(CClientSock*)m_ClientList.GetAt(pos);
				if(pClient==pClose)
				{
					m_ClientList.RemoveAt(pos);
					delete pClient;
				}
			}
		}
	}
}
