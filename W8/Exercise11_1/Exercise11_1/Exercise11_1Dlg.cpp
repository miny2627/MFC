
// Exercise11_1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Exercise11_1.h"
#include "Exercise11_1Dlg.h"
#include "afxdialogex.h"
#include "Calculator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CExercise11_1Dlg 대화 상자




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


// CExercise11_1Dlg 메시지 처리기

BOOL CExercise11_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CExercise11_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CExercise11_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise11_1Dlg::OnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		CString strTemp;
		int a, b;
		a=GetDlgItemInt(IDC_EDIT_NUM1,NULL,false);
		b=GetDlgItemInt(IDC_EDIT_NUM2,NULL,false);

		if(b==0) {
			AfxMessageBox(_T("0으로 나눌 수 없습니다."));
			SetDlgItemText(IDC_EDIT_RESULT,_T(""));
		}

		double result=m_calc.Divide(a,b);
		strTemp.Format(_T("%f"),result);
		SetDlgItemText(IDC_EDIT_RESULT,strTemp);
}


void CExercise11_1Dlg::OnClickedButtonBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("계산 결과를 초기화합니다!"));
	SetDlgItemText(IDC_EDIT_RESULT,_T(""));
	SetDlgItemText(IDC_EDIT_NUM1,_T(""));
	SetDlgItemText(IDC_EDIT_NUM2,_T(""));
}

void CExercise11_1Dlg::OnClickedButtonOne()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(1);
}


void CExercise11_1Dlg::OnClickedButtonZero()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(0);
}


void CExercise11_1Dlg::OnClickedButtonTwo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(2);
}


void CExercise11_1Dlg::OnClickedButtonThree()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(3);
}


void CExercise11_1Dlg::OnClickedButtonFour()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(4);
}


void CExercise11_1Dlg::OnClickedButtonFive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(5);
}


void CExercise11_1Dlg::OnClickedButtonSix()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(6);
}


void CExercise11_1Dlg::OnClickedButtonSeven()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(7);
}


void CExercise11_1Dlg::OnClickedButtonEight()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(8);
}


void CExercise11_1Dlg::OnClickedButtonNine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PressNumber(9);
}


void CExercise11_1Dlg::OnClickedRadioNum1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_num=1;
}


void CExercise11_1Dlg::OnRadioNum2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
		AfxMessageBox(_T("먼저 입력하려는 숫자의 라디오 버튼을 선택하세요."));
	}
}
