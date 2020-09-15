// CalCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Practice5.h"
#include "CalCtrl.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Practice5Doc.h"
#include "Practice5View.h"


// CCalCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCalCtrl, CDialogEx)

CCalCtrl::CCalCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalCtrl::IDD, pParent)
	, m_num(0)
{

	m_num1 = 0;
	m_num2 = 0;
}

CCalCtrl::~CCalCtrl()
{
}

void CCalCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ONE, m_num1);
	DDV_MinMaxInt(pDX, m_num1, 0, 99999);
	DDX_Text(pDX, IDC_EDIT_TWO, m_num2);
	DDV_MinMaxInt(pDX, m_num2, 0, 99999);
}


BEGIN_MESSAGE_MAP(CCalCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalCtrl::OnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalCtrl::OnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalCtrl::OnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalCtrl::OnClickedButtonDivide)
	ON_COMMAND(IDC_RADIO_ONE, &CCalCtrl::OnRadioOne)
	ON_COMMAND(IDC_RADIO_TWO, &CCalCtrl::OnRadioTwo)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CCalCtrl::OnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CCalCtrl::OnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CCalCtrl::OnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &CCalCtrl::OnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_FIVE, &CCalCtrl::OnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SIX, &CCalCtrl::OnClickedButtonSix)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CCalCtrl::OnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CCalCtrl::OnClickedButtonEight)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &CCalCtrl::OnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_ZERO, &CCalCtrl::OnClickedButtonZero)
	ON_BN_CLICKED(IDC_BUTTON_BS, &CCalCtrl::OnClickedButtonBs)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalCtrl::OnClickedButtonClear)
END_MESSAGE_MAP()


// CCalCtrl �޽��� ó�����Դϴ�.


void CCalCtrl::OnClickedButtonPlus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	int num1, num2, result;
	num1=GetDlgItemInt(IDC_EDIT_ONE,NULL,false);
	num2=GetDlgItemInt(IDC_EDIT_TWO,NULL,false);
	result=num1+num2;

	pV->m_strResult.Format(_T("%d ���ϱ� %d�� %d�Դϴ�."),num1, num2,result);
	pV->Invalidate();
}


void CCalCtrl::OnClickedButtonMinus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	int num1, num2, result;
	num1=GetDlgItemInt(IDC_EDIT_ONE,NULL,false);
	num2=GetDlgItemInt(IDC_EDIT_TWO,NULL,false);
	result=num1-num2;

	pV->m_strResult.Format(_T("%d ���� %d�� %d�Դϴ�."),num1, num2,result);
	pV->Invalidate();
}


void CCalCtrl::OnClickedButtonMultiply()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	int num1, num2,result;
	num1=GetDlgItemInt(IDC_EDIT_ONE,NULL,false);
	num2=GetDlgItemInt(IDC_EDIT_TWO,NULL,false);
	result=num1*num2;

	pV->m_strResult.Format(_T("%d ���ϱ� %d�� %d�Դϴ�."),num1, num2,result);
	pV->Invalidate();
}


void CCalCtrl::OnClickedButtonDivide()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	int num1, num2;
	double result=0;
	num1=GetDlgItemInt(IDC_EDIT_ONE,NULL,false);
	num2=GetDlgItemInt(IDC_EDIT_TWO,NULL,false);

	if(num2==0) AfxMessageBox(_T("0���� ���� �� �����ϴ�."),MB_OK|MB_ICONWARNING);
	else result=(double)num1/(double)num2;

	pV->m_strResult.Format(_T("%d ������ %d�� %.3f�Դϴ�."),num1, num2,result);
	pV->Invalidate();
}


void CCalCtrl::OnRadioOne()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_num=1;
}


void CCalCtrl::OnRadioTwo()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_num=2;
}


void CCalCtrl::PressNumber(int num)
{
	int num1, num2;
	switch(m_num)
	{
	case 1:
		num1=GetDlgItemInt(IDC_EDIT_ONE,NULL,false);
		if(num1<10000)
		{
			num1=num1*10+num;
		}
		else
		{
			AfxMessageBox(_T("�ڸ����� 5�ڸ������� �����մϴ�."),MB_OK | MB_ICONWARNING);
		}
		SetDlgItemInt(IDC_EDIT_ONE,num1,false);
		break;

	case 2:
		num2=GetDlgItemInt(IDC_EDIT_TWO,NULL,false);
		if(num2<10000)
		{
			num2=num2*10+num;
		}
		else 
		{
			AfxMessageBox(_T("�ڸ����� 5�ڸ������� �����մϴ�."),MB_OK | MB_ICONWARNING);
		}
		SetDlgItemInt(IDC_EDIT_TWO,num2,false);
		break;
		
	default:
		AfxMessageBox(_T("���� �Է��Ϸ��� ������ ���� ��ư�� �����ϼ���."),MB_OK | MB_ICONWARNING);
	}
}


void CCalCtrl::OnClickedButtonOne()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(1);
}


void CCalCtrl::OnClickedButtonTwo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(2);
}


void CCalCtrl::OnClickedButtonThree()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(3);
}


void CCalCtrl::OnClickedButtonFour()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(4);
}


void CCalCtrl::OnClickedButtonFive()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(5);
}


void CCalCtrl::OnClickedButtonSix()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(6);
}


void CCalCtrl::OnClickedButtonSeven()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(7);
}


void CCalCtrl::OnClickedButtonEight()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(8);
}


void CCalCtrl::OnClickedButtonNine()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(9);
}


void CCalCtrl::OnClickedButtonZero()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PressNumber(0);
}


void CCalCtrl::OnClickedButtonBs()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UINT oper1,oper2;
	switch(m_num)
	{
	case 1:
		oper1=GetDlgItemInt(IDC_EDIT_ONE);
		oper1 /=10;
		SetDlgItemInt(IDC_EDIT_ONE,oper1,false);
		return;
	case 2:
		oper2=GetDlgItemInt(IDC_EDIT_TWO);
		oper2 /=10;
		SetDlgItemInt(IDC_EDIT_TWO,oper2,false);
		return;
	}
}


void CCalCtrl::OnClickedButtonClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	AfxMessageBox(_T("��� ����� �ʱ�ȭ�մϴ�."),MB_OK | MB_ICONINFORMATION);
	pV->m_strResult.Empty();
	pV->Invalidate();
}
