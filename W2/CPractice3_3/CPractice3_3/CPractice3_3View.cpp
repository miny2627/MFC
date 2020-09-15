
// CPractice3_3View.cpp : CCPractice3_3View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "CPractice3_3.h"
#endif

#include "CPractice3_3Doc.h"
#include "CPractice3_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCPractice3_3View

IMPLEMENT_DYNCREATE(CCPractice3_3View, CView)

BEGIN_MESSAGE_MAP(CCPractice3_3View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCPractice3_3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CCPractice3_3View ����/�Ҹ�

CCPractice3_3View::CCPractice3_3View()
	: m_strOutput(_T(""))
	, m_ptLocation(0)
	, m_ptClientSize(0)
	, m_bDrag(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CCPractice3_3View::~CCPractice3_3View()
{
}

BOOL CCPractice3_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CCPractice3_3View �׸���

void CCPractice3_3View::OnDraw(CDC* pDC)
{
	CCPractice3_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	//�����쿡 ���ڿ� ���
	pDC->TextOutW(m_ptLocation.x, m_ptLocation.y, m_strOutput);
}


// CCPractice3_3View �μ�


void CCPractice3_3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCPractice3_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CCPractice3_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CCPractice3_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CCPractice3_3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCPractice3_3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCPractice3_3View ����

#ifdef _DEBUG
void CCPractice3_3View::AssertValid() const
{
	CView::AssertValid();
}

void CCPractice3_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCPractice3_3Doc* CCPractice3_3View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCPractice3_3Doc)));
	return (CCPractice3_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CCPractice3_3View �޽��� ó����


void CCPractice3_3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nCharIndex;
	nCharIndex=m_strOutput.GetLength();

	if(nChar==VK_BACK)
		m_strOutput.Delete(nCharIndex -1,1);
	else
		m_strOutput+=(WCHAR)nChar;

	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CCPractice3_3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch(nChar)
	{
	case VK_LEFT:
		m_ptLocation.x--;
		break;
	case VK_RIGHT:
		m_ptLocation.x++;
		break;
	case VK_UP:
		m_ptLocation.y--;
		break;
	case VK_DOWN:
		m_ptLocation.y++;
		break;
	case VK_PRIOR:
		m_ptLocation.y-=50;
		break;
	case VK_NEXT:
		m_ptLocation.y+=50;
		break;
	case VK_HOME:
		m_ptLocation=CPoint(0,0);
		break;
	}

	if(m_ptLocation.x<0)
	{
		m_ptLocation.x=0;
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if(m_ptLocation.y<0)
	{
		m_ptLocation.y=0;
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if(m_ptLocation.x>m_ptClientSize.x)
	{
		m_ptLocation.x=m_ptClientSize.x;
		AfxMessageBox(_T("���������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if(m_ptLocation.y>m_ptClientSize.y)
	{
		m_ptLocation.y=m_ptClientSize.y;
		AfxMessageBox(_T("�Ʒ������� �� �̻� �̵��� �� �����ϴ�."));
	}

	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CCPractice3_3View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	m_ptClientSize.x=cx;
	m_ptClientSize.y=cy;

	Invalidate();
}


void CCPractice3_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_ptLocation.x=point.x;
	m_ptLocation.y-point.y;
	if(m_ptLocation.x-30<=point.x && point.x<=m_ptLocation.x+30 && m_ptLocation.y-30<=point.y && point.y<=m_ptLocation.y+30)
	{
		m_bDrag=TRUE;
	}
	
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CCPractice3_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_strOutput.IsEmpty()==false)
	{
		if(AfxMessageBox(_T("���ڸ� ��� ����ðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION)==IDYES)
		{
			m_strOutput.Empty();
		}
	}
	else
	{
		AfxMessageBox(_T("���ڿ��� �Է��Ͻÿ�."));
	}
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CCPractice3_3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_bDrag==TRUE)
	{
		m_ptLocation=point;
	}
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CCPractice3_3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_bDrag==TRUE) 
	{	
		m_bDrag=FALSE;
		m_ptLocation=point;
	}
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}
