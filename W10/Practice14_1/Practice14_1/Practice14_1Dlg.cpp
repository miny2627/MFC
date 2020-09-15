
// Practice14_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Practice14_1.h"
#include "Practice14_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPractice14_1Dlg ��ȭ ����




CPractice14_1Dlg::CPractice14_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPractice14_1Dlg::IDD, pParent)
	, m_strMyIP(_T(""))
	, m_strOtherIP(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nChatMode = 0;
}

void CPractice14_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS_SERVER, m_IPAddress);
	DDX_Control(pDX, IDC_LIST_CHAT, m_listChat);
	DDX_Radio(pDX, IDC_RADIO_SERVER, m_nChatMode);
}

BEGIN_MESSAGE_MAP(CPractice14_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_SERVER, &CPractice14_1Dlg::OnClickedRadioServer)
	ON_COMMAND(IDC_RADIO_CLIENT, &CPractice14_1Dlg::OnRadioClient)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CPractice14_1Dlg::OnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CPractice14_1Dlg::OnClickedButtonSend)
END_MESSAGE_MAP()


// CPractice14_1Dlg �޽��� ó����

BOOL CPractice14_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	char name[255];
	PHOSTENT hostinfo;
	if(gethostname(name,sizeof(name))==0)
	{
		if((hostinfo=gethostbyname(name))!=NULL)
		{
			m_strMyIP=inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
		}
	}

	m_IPAddress.SetWindowText(m_strMyIP);
	m_IPAddress.EnableWindow(false);
	SetDlgItemText(IDC_BUTTON_CONNECT,_T("Open"));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CPractice14_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CPractice14_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CPractice14_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPractice14_1Dlg::OnClickedRadioServer()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_IPAddress.SetWindowTextW(m_strMyIP);
	m_IPAddress.EnableWindow(false);
	SetDlgItemText(IDC_BUTTON_CONNECT,_T("Open"));
}


void CPractice14_1Dlg::OnRadioClient()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_IPAddress.SetWindowTextW(_T(""));
	m_IPAddress.EnableWindow(true);
	SetDlgItemText(IDC_BUTTON_CONNECT,_T("Connect"));
}


void CPractice14_1Dlg::OnClickedButtonConnect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData();
	if(!m_nChatMode)
	{
		((CPractice14_1App*)AfxGetApp())->InitServer();
		GetDlgItem(IDC_RADIO_SERVER)->EnableWindow(false);
		GetDlgItem(IDC_RADIO_CLIENT)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(false);
	}
	else
	{
		CString strIP;
		GetDlgItemText(IDC_IPADDRESS_SERVER,strIP);
		if(strIP!=_T("0.0.0.0"))
		{
			GetDlgItem(IDC_RADIO_SERVER)->EnableWindow(false);
			GetDlgItem(IDC_RADIO_CLIENT)->EnableWindow(false);
			((CPractice14_1App*)AfxGetApp())->Connect(strIP);
			m_strOtherIP=strIP;
		}
		else
		{
			AfxMessageBox(_T("������ ������ IP�ּҸ� �Է��ϼ���"));
		}
	}
}


void CPractice14_1Dlg::OnClickedButtonSend()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strSend, strInsert;
	GetDlgItemText(IDC_EDIT_SEND,strSend);
	strInsert.Format(_T("[%s]:%s"),m_strMyIP,strSend);
	theApp.SendData(strSend);
	int sel=m_listChat.InsertString(-1,strInsert);
	m_listChat.SetCurSel(sel);
	SetDlgItemText(IDC_EDIT_SEND,_T(""));
}


void CPractice14_1Dlg::ReceiveData(CString strReceive)
{
	CString strInsert;
	strInsert.Format(_T("[%s]:%s"),m_strOtherIP,strReceive);
	int sel=m_listChat.InsertString(-1,strInsert);
	m_listChat.SetCurSel(sel);
}


void CPractice14_1Dlg::Accept(CString strSock)
{
	m_strOtherIP=strSock;
}
