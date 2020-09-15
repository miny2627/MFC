// HobbyPane.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Exercise5_1.h"
#include "HobbyPane.h"


// CHobbyPane

IMPLEMENT_DYNAMIC(CHobbyPane, CDockablePane)

CHobbyPane::CHobbyPane()
{

}

CHobbyPane::~CHobbyPane()
{
}


BEGIN_MESSAGE_MAP(CHobbyPane, CDockablePane)
	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CHobbyPane 메시지 처리기입니다.




void CHobbyPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if(m_ctrlHobby.GetSafeHwnd())
	{
		m_ctrlHobby.MoveWindow(0,0,cx,cy);
		m_ctrlHobby.SetFocus();
	}
}


int CHobbyPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if(!m_ctrlHobby.Create(IDD_DIALOG_TEXTOUT,this))
	{
		TRACE0("문자열 출력 윈도우를 만들지 못했습니다.\n");
		return -1;
	}
	m_ctrlHobby.ShowWindow(SW_SHOW);

	return 0;

}
