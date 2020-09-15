
// Practice10_3View.cpp : CPractice10_3View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice10_3.h"
#endif

#include "Practice10_3Doc.h"
#include "Practice10_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice10_3View

IMPLEMENT_DYNCREATE(CPractice10_3View, CFormView)

BEGIN_MESSAGE_MAP(CPractice10_3View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CPractice10_3View::OnClickedButtonSave)
END_MESSAGE_MAP()

// CPractice10_3View ����/�Ҹ�

CPractice10_3View::CPractice10_3View()
	: CFormView(CPractice10_3View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_strInput = _T("");
}

CPractice10_3View::~CPractice10_3View()
{
}

void CPractice10_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput);
}

BOOL CPractice10_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CPractice10_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CPractice10_3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice10_3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice10_3View ����

#ifdef _DEBUG
void CPractice10_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CPractice10_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPractice10_3Doc* CPractice10_3View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice10_3Doc)));
	return (CPractice10_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice10_3View �޽��� ó����


void CPractice10_3View::OnClickedButtonSave()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CPractice10_3Doc* pDoc=GetDocument();

	UpdateData(true);
	pDoc->m_strSaveInput=m_strInput;
}
