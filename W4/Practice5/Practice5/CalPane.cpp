// CalPane.cpp : ���� �����Դϴ�.
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



// CCalPane �޽��� ó�����Դϴ�.




int CCalPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if(!m_ctrlCal.Create(IDD_DIALOG_CAL,this))
	{
		TRACE0("���ڿ� ��� �����츦 ������ ���߽��ϴ�.\n");
		return -1;
	}
	m_ctrlCal.ShowWindow(SW_SHOW);

	return 0;
}


void CCalPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if(m_ctrlCal.GetSafeHwnd())
	{
		m_ctrlCal.MoveWindow(0,0,cx,cy);
		m_ctrlCal.SetFocus();
	}
}
