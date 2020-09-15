
// Practice3-1View.cpp : CPractice31View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice3-1.h"
#endif

#include "Practice3-1Doc.h"
#include "Practice3-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice31View

IMPLEMENT_DYNCREATE(CPractice31View, CView)

BEGIN_MESSAGE_MAP(CPractice31View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice31View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CPractice31View ����/�Ҹ�

CPractice31View::CPractice31View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CPractice31View::~CPractice31View()
{
}

BOOL CPractice31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPractice31View �׸���

void CPractice31View::OnDraw(CDC* /*pDC*/)
{
	CPractice31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CPractice31View �μ�


void CPractice31View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice31View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPractice31View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPractice31View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CPractice31View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice31View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice31View ����

#ifdef _DEBUG
void CPractice31View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice31Doc* CPractice31View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice31Doc)));
	return (CPractice31Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice31View �޽��� ó����


int CPractice31View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	/// �����찡 ������ �� �޽��� �ڽ� ���
	AfxMessageBox(_T("�����찡 �����Ǿ����ϴ�."),MB_OKCANCEL | MB_ICONINFORMATION);

	return 0;
}


void CPractice31View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ���� ���콺�� ���� Ŭ���� �� �޽��� �ڽ� ���
	AfxMessageBox(_T("���� ���콺�� ����Ŭ�� �߽��ϱ�?"), MB_YESNO | MB_ICONQUESTION);

	CView::OnLButtonDblClk(nFlags, point);
}


void CPractice31View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �����찡 ����� �� �޽��� �ڽ� ���
	AfxMessageBox(_T("�����찡 ����Ǿ����ϴ�."), MB_YESNO | MB_ICONWARNING);
}
