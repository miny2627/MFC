
// Exercise10_1View.cpp : CExercise10_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Exercise10_1.h"
#endif

#include "Exercise10_1Doc.h"
#include "Exercise10_1View.h"
#include "LeftViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise10_1View

IMPLEMENT_DYNCREATE(CExercise10_1View, CTreeView)

BEGIN_MESSAGE_MAP(CExercise10_1View, CTreeView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CExercise10_1View::OnTvnSelchanged)
END_MESSAGE_MAP()

// CExercise10_1View ����/�Ҹ�

CExercise10_1View::CExercise10_1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CExercise10_1View::~CExercise10_1View()
{
}

BOOL CExercise10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CTreeView::PreCreateWindow(cs);
}

void CExercise10_1View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	CTreeCtrl& TreeCtrl=GetTreeCtrl();
	m_hRoot=TreeCtrl.InsertItem(_T("��Ʈ ���"),0,0,TVI_ROOT,TVI_LAST);
	m_hSelectedNode=m_hRoot;
	TreeCtrl.ModifyStyle(0,TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS);
}

void CExercise10_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExercise10_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExercise10_1View ����

#ifdef _DEBUG
void CExercise10_1View::AssertValid() const
{
	CTreeView::AssertValid();
}

void CExercise10_1View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CExercise10_1Doc* CExercise10_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExercise10_1Doc)));
	return (CExercise10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExercise10_1View �޽��� ó����


void CExercise10_1View::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
	//m_hSelectedNode=pNMTreeView->itemNew.hItem;
	m_hSelectedNode=GetTreeCtrl().GetSelectedItem();

	CLeftViewDlg * pDlg=(CLeftViewDlg *) this->GetNextWindow(GW_HWNDPREV);
	pDlg->m_strSelectedNode=GetTreeCtrl().GetItemText(m_hSelectedNode);
}
