// TextOutPane.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise5_1.h"
#include "TextOutPane.h"


// CTextOutPane

IMPLEMENT_DYNAMIC(CTextOutPane, CWnd)

CTextOutPane::CTextOutPane()
{

}

CTextOutPane::~CTextOutPane()
{
}


BEGIN_MESSAGE_MAP(CTextOutPane, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CTextOutPane �޽��� ó�����Դϴ�.




int CTextOutPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if(!m_ctrlHobby.Create(IDD_DIALOG_TEXTOUT,this))
	{
		TRACE0("���ڿ� ��� �����츦 ������ ���߽��ϴ�.\n");
		return -1;
	}
	m_ctrlHobby.ShowWindow(SW_SHOW);

	return 0;
}


void CTextOutPane::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if(m_ctrlHobby.GetSafeHwnd())
	{
		m_ctrlHobby.MoveWindow(0,0,cx,cy);
		m_ctrlHobby.SetFocus();
	}
}
