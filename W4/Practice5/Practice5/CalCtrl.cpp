// CalCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Practice5.h"
#include "CalCtrl.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Practice5Doc.h"
#include "Practice5View.h"


// CCalCtrl 대화 상자입니다.

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


// CCalCtrl 메시지 처리기입니다.


void CCalCtrl::OnClickedButtonPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	int num1, num2, result;
	num1=GetDlgItemInt(IDC_EDIT_ONE,NULL,false);
	num2=GetDlgItemInt(IDC_EDIT_TWO,NULL,false);
	result=num1+num2;

	pV->m_strResult.Format(_T("%d 더하기 %d는 %d입니다."),num1, num2,result);
	pV->Invalidate();
}


void CCalCtrl::OnClickedButtonMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	int num1, num2, result;
	num1=GetDlgItemInt(IDC_EDIT_ONE,NULL,false);
	num2=GetDlgItemInt(IDC_EDIT_TWO,NULL,false);
	result=num1-num2;

	pV->m_strResult.Format(_T("%d 빼기 %d는 %d입니다."),num1, num2,result);
	pV->Invalidate();
}


void CCalCtrl::OnClickedButtonMultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	int num1, num2,result;
	num1=GetDlgItemInt(IDC_EDIT_ONE,NULL,false);
	num2=GetDlgItemInt(IDC_EDIT_TWO,NULL,false);
	result=num1*num2;

	pV->m_strResult.Format(_T("%d 곱하기 %d는 %d입니다."),num1, num2,result);
	pV->Invalidate();
}


void CCalCtrl::OnClickedButtonDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	int num1, num2;
	double result=0;
	num1=GetDlgItemInt(IDC_EDIT_ONE,NULL,false);
	num2=GetDlgItemInt(IDC_EDIT_TWO,NULL,false);

	if(num2==0) AfxMessageBox(_T("0으로 나눌 수 없습니다."),MB_OK|MB_ICONWARNING);
	else result=(double)num1/(double)num2;

	pV->m_strResult.Format(_T("%d 나누기 %d는 %.3f입니다."),num1, num2,result);
	pV->Invalidate();
}


void CCalCtrl::OnRadioOne()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_num=1;
}


void CCalCtrl::OnRadioTwo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
			AfxMessageBox(_T("자릿수는 5자리까지만 가능합니다."),MB_OK | MB_ICONWARNING);
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
			AfxMessageBox(_T("자릿수는 5자리까지만 가능합니다."),MB_OK | MB_ICONWARNING);
		}
		SetDlgItemInt(IDC_EDIT_TWO,num2,false);
		break;
		
	default:
		AfxMessageBox(_T("먼저 입력하려는 숫자의 라디오 버튼을 선택하세요."),MB_OK | MB_ICONWARNING);
	}
}


void CCalCtrl::OnClickedButtonOne()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(1);
}


void CCalCtrl::OnClickedButtonTwo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(2);
}


void CCalCtrl::OnClickedButtonThree()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(3);
}


void CCalCtrl::OnClickedButtonFour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(4);
}


void CCalCtrl::OnClickedButtonFive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(5);
}


void CCalCtrl::OnClickedButtonSix()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(6);
}


void CCalCtrl::OnClickedButtonSeven()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(7);
}


void CCalCtrl::OnClickedButtonEight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(8);
}


void CCalCtrl::OnClickedButtonNine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(9);
}


void CCalCtrl::OnClickedButtonZero()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(0);
}


void CCalCtrl::OnClickedButtonBs()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pF=(CMainFrame *)AfxGetMainWnd();
	CPractice5View *pV=(CPractice5View *)pF->GetActiveView();

	AfxMessageBox(_T("계산 결과를 초기화합니다."),MB_OK | MB_ICONINFORMATION);
	pV->m_strResult.Empty();
	pV->Invalidate();
}
