// CalPane.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Practice5.h"
#include "CalPane.h"


// CCalPane

IMPLEMENT_DYNAMIC(CCalPane, CDockablePane)

CCalPane::CCalPane()
{

}

CCalPane::~CCalPane()
{
}


BEGIN_MESSAGE_MAP(CCalPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CCalPane 메시지 처리기입니다.




int CCalPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if(!m_ctrlCal.Create(IDD_DIALOG_CAL,this))
	{
		TRACE0("문자열 출력 윈도우를 만들지 못했습니다.\n");
		return -1;
	}
	m_ctrlCal.ShowWindow(SW_SHOW);

	return 0;
}


void CCalPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_ctrlCal.GetSafeHwnd())
	{
		m_ctrlCal.MoveWindow(0,0,cx,cy);
		m_ctrlCal.SetFocus();
	}
}
