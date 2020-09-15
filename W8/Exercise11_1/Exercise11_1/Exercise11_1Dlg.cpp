
// Exercise11_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Exercise11_1.h"
#include "Exercise11_1Dlg.h"
#include "afxdialogex.h"
#include "Calculator.h"

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


// CExercise11_1Dlg ��ȭ ����




CExercise11_1Dlg::CExercise11_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise11_1Dlg::IDD, pParent)
	, m_num(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise11_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExercise11_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CExercise11_1Dlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CExercise11_1Dlg::OnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CExercise11_1Dlg::OnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CExercise11_1Dlg::OnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CExercise11_1Dlg::OnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CExercise11_1Dlg::OnClickedButtonClear)
//	ON_COMMAND(IDC_RADIO_NUM1, &CExercise11_1Dlg::OnRadioNum1)
//	ON_COMMAND(IDC_RADIO_NUM2, &CExercise11_1Dlg::OnRadioNum2)
ON_BN_CLICKED(IDC_BUTTON_ONE, &CExercise11_1Dlg::OnClickedButtonOne)
ON_BN_CLICKED(IDC_BUTTON_ZERO, &CExercise11_1Dlg::OnClickedButtonZero)
ON_BN_CLICKED(IDC_BUTTON_TWO, &CExercise11_1Dlg::OnClickedButtonTwo)
ON_BN_CLICKED(IDC_BUTTON_THREE, &CExercise11_1Dlg::OnClickedButtonThree)
ON_BN_CLICKED(IDC_BUTTON_FOUR, &CExercise11_1Dlg::OnClickedButtonFour)
ON_BN_CLICKED(IDC_BUTTON_FIVE, &CExercise11_1Dlg::OnClickedButtonFive)
ON_BN_CLICKED(IDC_BUTTON_SIX, &CExercise11_1Dlg::OnClickedButtonSix)
ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CExercise11_1Dlg::OnClickedButtonSeven)
ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CExercise11_1Dlg::OnClickedButtonEight)
ON_BN_CLICKED(IDC_BUTTON_NINE, &CExercise11_1Dlg::OnClickedButtonNine)
ON_BN_CLICKED(IDC_RADIO_NUM1, &CExercise11_1Dlg::OnClickedRadioNum1)
ON_COMMAND(IDC_RADIO_NUM2, &CExercise11_1Dlg::OnRadioNum2)
END_MESSAGE_MAP()


// CExercise11_1Dlg �޽��� ó����

BOOL CExercise11_1Dlg::OnInitDialog()
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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CExercise11_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExercise11_1Dlg::OnPaint()
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
HCURSOR CExercise11_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise11_1Dlg::OnClickedButtonAdd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strTemp;
	int a, b;
	a=GetDlgItemInt(IDC_EDIT_NUM1,NULL,false);
	b=GetDlgItemInt(IDC_EDIT_NUM2,NULL,false);
	
	int result=m_calc.Add(a,b);
	strTemp.Format(_T("%d"),result);
	SetDlgItemText(IDC_EDIT_RESULT,strTemp);
}


void CExercise11_1Dlg::OnClickedButtonSub()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strTemp;
	int a, b;
	a=GetDlgItemInt(IDC_EDIT_NUM1,NULL,false);
	b=GetDlgItemInt(IDC_EDIT_NUM2,NULL,false);

	int result=m_calc.Subtract(a,b);
	strTemp.Format(_T("%d"),result);
	SetDlgItemText(IDC_EDIT_RESULT,strTemp);
}


void CExercise11_1Dlg::OnClickedButtonMul()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strTemp;
	int a, b;
	a=GetDlgItemInt(IDC_EDIT_NUM1,NULL,false);
	b=GetDlgItemInt(IDC_EDIT_NUM2,NULL,false);
	
	int result=m_calc.Multiply(a,b);
	strTemp.Format(_T("%d"),result);
	SetDlgItemText(IDC_EDIT_RESULT,strTemp);
}


void CExercise11_1Dlg::OnClickedButtonDiv()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
		CString strTemp;
		int a, b;
		a=GetDlgItemInt(IDC_EDIT_NUM1,NULL,false);
		b=GetDlgItemInt(IDC_EDIT_NUM2,NULL,false);

		if(b==0) {
			AfxMessageBox(_T("0���� ���� �� �����ϴ�."));
			SetDlgItemText(IDC_EDIT_RESULT,_T(""));
		}

		double result=m_calc.Divide(a,b);
		strTemp.Format(_T("%f"),result);
		SetDlgItemText(IDC_EDIT_RESULT,strTemp);
}


void CExercise11_1Dlg::OnClickedButtonBack()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UINT oper1,oper2;
	switch(m_num)
	{
	case 1:
		oper1=GetDlgItemInt(IDC_EDIT_NUM1);
		oper1 /=10;
		SetDlgItemInt(IDC_EDIT_NUM1,oper1,false);
		return;
	case 2:
		oper2=GetDlgItemInt(IDC_EDIT_NUM2);
		oper2 /=10;
		SetDlgItemInt(IDC_EDIT_NUM2,oper2,false);
		return;
	}
}


void CExercise11_1Dlg::OnClickedButtonClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox(_T("��� ����� �ʱ�ȭ�մϴ�!"));
	SetDlgItemText(IDC_EDIT_RESULT,_T(""));
	SetDlgItemText(IDC_EDIT_NUM1,_T(""));
	SetDlgItemText(IDC_EDIT_NUM2,_T(""));
}

void CExercise11_1Dlg::OnClickedButtonOne()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(1);
}


void CExercise11_1Dlg::OnClickedButtonZero()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(0);
}


void CExercise11_1Dlg::OnClickedButtonTwo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(2);
}


void CExercise11_1Dlg::OnClickedButtonThree()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(3);
}


void CExercise11_1Dlg::OnClickedButtonFour()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(4);
}


void CExercise11_1Dlg::OnClickedButtonFive()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(5);
}


void CExercise11_1Dlg::OnClickedButtonSix()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(6);
}


void CExercise11_1Dlg::OnClickedButtonSeven()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(7);
}


void CExercise11_1Dlg::OnClickedButtonEight()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(8);
}


void CExercise11_1Dlg::OnClickedButtonNine()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(9);
}


void CExercise11_1Dlg::OnClickedRadioNum1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_num=1;
}


void CExercise11_1Dlg::OnRadioNum2()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_num=2;
}


void CExercise11_1Dlg::PressNumber(int num)
{
	int num1, num2;
	switch(m_num)
	{
	case 1:
		num1=GetDlgItemInt(IDC_EDIT_NUM1,NULL,false);
		num1=num1*10+num;
		SetDlgItemInt(IDC_EDIT_NUM1,num1,false);
		break;
	case 2:
		num2=GetDlgItemInt(IDC_EDIT_NUM2,NULL,false);
		num2=num2*10+num;
		SetDlgItemInt(IDC_EDIT_NUM2,num2,false);
		break;
	default:
		AfxMessageBox(_T("���� �Է��Ϸ��� ������ ���� ��ư�� �����ϼ���."));
	}
}
