
// Practice6_2View.cpp : CPractice6_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice6_2.h"
#endif

#include "Practice6_2Doc.h"
#include "Practice6_2View.h"

#include "PenSizeDlg.h"
#include "EraserSizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice6_2View

IMPLEMENT_DYNCREATE(CPractice6_2View, CView)

BEGIN_MESSAGE_MAP(CPractice6_2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice6_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_PEN_SIZE, &CPractice6_2View::OnPenSize)
	ON_COMMAND(ID_ERASER_SIZE, &CPractice6_2View::OnEraserSize)
	ON_COMMAND(ID_PEN_COLOR, &CPractice6_2View::OnPenColor)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CPractice6_2View ����/�Ҹ�

CPractice6_2View::CPractice6_2View()
	: m_nPenSize(0)
	, m_nEraserSize(0)
	, m_ptPrev(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_nPenSize=2;
	m_nEraserSize=4;
	m_colorPen=RGB(0,0,0);

}

CPractice6_2View::~CPractice6_2View()
{
}

BOOL CPractice6_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPractice6_2View �׸���

void CPractice6_2View::OnDraw(CDC* /*pDC*/)
{
	CPractice6_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CPractice6_2View �μ�


void CPractice6_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice6_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPractice6_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPractice6_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CPractice6_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice6_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice6_2View ����

#ifdef _DEBUG
void CPractice6_2View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice6_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice6_2Doc* CPractice6_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice6_2Doc)));
	return (CPractice6_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice6_2View �޽��� ó����


void CPractice6_2View::OnPenSize()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CPenSizeDlg* pdlgPen=new CPenSizeDlg;
	if(pdlgPen->DoModal()==IDOK)
	{
		m_nPenSize=pdlgPen->m_nPenSize;
	}
}


void CPractice6_2View::OnEraserSize()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CEraserSizeDlg* pdlgEraser=new CEraserSizeDlg;
	if(pdlgEraser->DoModal()==IDOK)
	{
		m_nEraserSize=pdlgEraser->m_nEraserSize;
	}
}


void CPractice6_2View::OnPenColor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorDialog colorDlg;
	if(colorDlg.DoModal()==IDOK)
	{
		m_colorPen=colorDlg.GetColor();
	}
}


void CPractice6_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_ptPrev=point;
	HCURSOR hCursor=AfxGetApp()->LoadCursorW(IDC_CURSOR_PEN);
	SetCursor(hCursor);

	CView::OnLButtonDown(nFlags, point);
}


void CPractice6_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_ptPrev=point;
	HCURSOR hCursor=AfxGetApp()->LoadCursorW(IDC_CURSOR_ERASER);
	SetCursor(hCursor);

	CView::OnRButtonDown(nFlags, point);
}


void CPractice6_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	Graphics graphics(dc);

	Gdiplus::Color clr;
	clr.SetFromCOLORREF(m_colorPen);

	if(nFlags==MK_LBUTTON)
	{
		HCURSOR hCursor=AfxGetApp()->LoadCursorW(IDC_CURSOR_PEN);
		SetCursor(hCursor);
		Pen pen(Color(clr),m_nPenSize);
		graphics.DrawLine(&pen,m_ptPrev.x,m_ptPrev.y, point.x, point.y);
		m_ptPrev=point;
	}
	if(nFlags==MK_RBUTTON)
	{
		HCURSOR hCursor=AfxGetApp()->LoadCursorW(IDC_CURSOR_ERASER);
		SetCursor(hCursor);
		Pen pen(Color(255,255,255),m_nEraserSize);
		graphics.DrawLine(&pen,m_ptPrev.x, m_ptPrev.y, point.x, point.y);
		m_ptPrev=point;
	}

	CView::OnMouseMove(nFlags, point);
}
