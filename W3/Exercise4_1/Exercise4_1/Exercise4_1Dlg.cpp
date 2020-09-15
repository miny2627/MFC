
// Exercise4_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Exercise4_1.h"
#include "Exercise4_1Dlg.h"
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


// CExercise4_1Dlg ��ȭ ����




CExercise4_1Dlg::CExercise4_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise4_1Dlg::IDD, pParent)
	, m_strResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strCombo = _T("");
}

void CExercise4_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LEFT, m_listLeft);
	DDX_Control(pDX, IDC_LIST_RIGHT, m_listRight);
	DDX_Control(pDX, IDC_COMBO_MOVE, m_cbMove);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
	DDX_CBString(pDX, IDC_COMBO_MOVE, m_strCombo);
}

BEGIN_MESSAGE_MAP(CExercise4_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_CBN_SELCHANGE(IDC_COMBO_MOVE, &CExercise4_1Dlg::OnCbnSelchangeCombo1)
	//ON_EN_CHANGE(IDC_EDIT_RESULT, &CExercise4_1Dlg::OnEnChangeEdit1)
	//ON_LBN_SELCHANGE(IDC_LIST_LEFT, &CExercise4_1Dlg::OnLbnSelchangeList2)
	ON_CBN_SELCHANGE(IDC_COMBO_MOVE, &CExercise4_1Dlg::OnSelchangeComboMove)
	ON_BN_CLICKED(IDC_BUTTON_PURCHASE, &CExercise4_1Dlg::OnClickedButtonPurchase)
END_MESSAGE_MAP()


// CExercise4_1Dlg �޽��� ó����

BOOL CExercise4_1Dlg::OnInitDialog()
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
	m_listLeft.AddString(_T("������"));
	m_listLeft.AddString(_T("����"));
	m_listLeft.AddString(_T("���"));
	m_listLeft.AddString(_T("�ٳ���"));
	m_listLeft.AddString(_T("����"));
	m_listLeft.AddString(_T("����"));
	m_listLeft.AddString(_T("���⸧"));
	m_listLeft.AddString(_T("����"));
	m_listLeft.AddString(_T("���"));
	m_listLeft.AddString(_T("����"));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CExercise4_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExercise4_1Dlg::OnPaint()
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
HCURSOR CExercise4_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise4_1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CExercise4_1Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CExercise4_1Dlg::OnLbnSelchangeList2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CExercise4_1Dlg::OnSelchangeComboMove()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strSelText;
	int index1=m_listLeft.GetCurSel();
	int index2=m_listRight.GetCurSel();

	m_cbMove.GetLBText(m_cbMove.GetCurSel(),m_strCombo);
	if(m_strCombo=="------------>") {
		if(index1!=LB_ERR)
		{
			m_listLeft.GetText(index1, strSelText);
			m_listLeft.DeleteString(index1);
			m_listRight.AddString(strSelText);
			m_listLeft.SetCurSel(index1);
		}
		else 
		{
			AfxMessageBox(_T("���� ����Ʈ �ڽ����� �̵��� �������� �����ϼ���"), MB_OK | MB_ICONWARNING);
		}
	}
	else
	{
		if(index2!=LB_ERR)
		{
			m_listRight.GetText(index2, strSelText);
			m_listRight.DeleteString(index2);
			m_listLeft.AddString(strSelText);
			m_listRight.SetCurSel(index2);
		}
		else
		{
			AfxMessageBox(_T("������ ����Ʈ �ڽ����� �̵��� �������� �����ϼ���"), MB_OK | MB_ICONWARNING);
		}
	}

}


void CExercise4_1Dlg::OnClickedButtonPurchase()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	CString str;
	int index=m_listRight.GetCurSel();
	
	m_listRight.GetText(index, str);
	m_strResult+=(str+_T("\r\n"));
	SetDlgItemText(IDC_EDIT_RESULT,m_strResult);
}
