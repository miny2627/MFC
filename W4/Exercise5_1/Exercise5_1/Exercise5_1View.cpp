
// Exercise5_1View.cpp : CExercise5_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Exercise5_1.h"
#endif

#include "Exercise5_1Doc.h"
#include "Exercise5_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise5_1View

IMPLEMENT_DYNCREATE(CExercise5_1View, CView)

BEGIN_MESSAGE_MAP(CExercise5_1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExercise5_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
//	ON_COMMAND(IDC_BUTTON_RESULT, &CExercise5_1View::OnButtonResult)
END_MESSAGE_MAP()

// CExercise5_1View ����/�Ҹ�

CExercise5_1View::CExercise5_1View()
	: m_strName(_T(""))
	, m_strSex(_T(""))
	, m_strHobby(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CExercise5_1View::~CExercise5_1View()
{
}

BOOL CExercise5_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CExercise5_1View �׸���

void CExercise5_1View::OnDraw(CDC* pDC)
{
	CExercise5_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOutW(20,20,_T("�̸� : ")+m_strName);
	pDC->TextOutW(20,50,_T("���� : ")+m_strSex);
	pDC->TextOutW(20,80,_T("���� ������ ��� : ")+m_strHobby);

}


// CExercise5_1View �μ�


void CExercise5_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExercise5_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CExercise5_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CExercise5_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CExercise5_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExercise5_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExercise5_1View ����

#ifdef _DEBUG
void CExercise5_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExercise5_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExercise5_1Doc* CExercise5_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExercise5_1Doc)));
	return (CExercise5_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExercise5_1View �޽��� ó����