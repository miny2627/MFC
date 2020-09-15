
// Exercise14_1.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
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


// CExercise14_1App ����

CExercise14_1App::CExercise14_1App()
	: m_pServer(NULL)
	, m_pClient(NULL)
{
	// �ٽ� ���� ������ ����
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CExercise14_1App ��ü�Դϴ�.

CExercise14_1App theApp;


// CExercise14_1App �ʱ�ȭ

BOOL CExercise14_1App::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�.
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	AfxEnableControlContainer();

	// ��ȭ ���ڿ� �� Ʈ�� �� �Ǵ�
	// �� ��� �� ��Ʈ���� ���ԵǾ� �ִ� ��� �� �����ڸ� ����ϴ�.
	CShellManager *pShellManager = new CShellManager;

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));

	CExercise14_1Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ���⿡ [Ȯ��]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ���⿡ [���]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}

	// ������ ���� �� �����ڸ� �����մϴ�.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�  ���� ���α׷��� ���� �� �ֵ��� FALSE��
	// ��ȯ�մϴ�.
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
		AfxMessageBox(_T("���� ���� ����"));
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
