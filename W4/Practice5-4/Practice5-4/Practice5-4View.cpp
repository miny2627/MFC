
// Practice5-4View.cpp : CPractice54View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice5-4.h"
#endif

#include "Practice5-4Doc.h"
#include "Practice5-4View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice54View

IMPLEMENT_DYNCREATE(CPractice54View, CView)

BEGIN_MESSAGE_MAP(CPractice54View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice54View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CPractice54View ����/�Ҹ�

CPractice54View::CPractice54View()
	: m_strOutput(_T(""))
	, m_nTextWidth(0)
	, m_nTextHeight(0)
	, m_ptPosition(0)
	, m_bFont(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CPractice54View::~CPractice54View()
{
}

BOOL CPractice54View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPractice54View �׸���

void CPractice54View::OnDraw(CDC* pDC)
{
	CPractice54Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	//���� �۲� ������ �����Ѵ�.
	CFont *oldFont, *currentFont, newFont;

	if(m_bFont==TRUE)
	{
		newFont.CreateFontIndirectW(&m_logFont);
		oldFont=pDC->SelectObject(&newFont);
	}
	else
	{
		currentFont=pDC->GetCurrentFont();
		oldFont=pDC->SelectObject(currentFont);
	}

	//���� ��ȭ���ڿ��� ������ ������ �ؽ�Ʈ �������� ����
	pDC->SetTextColor(m_colorText);

	//������ ��ġ�� ���ڿ� ���
	pDC->TextOutW(m_ptPosition.x, m_ptPosition.y, m_strOutput);

	//��µǴ� ���ڿ��� �ʺ�� ���̸� ����
	CSize sizeText;
	sizeText=pDC->GetTextExtent(m_strOutput);
	m_nTextWidth=sizeText.cx;
	m_nTextHeight=sizeText.cy;

	//�۲��� ����
	pDC->SelectObject(oldFont);
}


// CPractice54View �μ�


void CPractice54View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice54View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPractice54View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPractice54View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CPractice54View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice54View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice54View ����

#ifdef _DEBUG
void CPractice54View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice54View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice54Doc* CPractice54View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice54Doc)));
	return (CPractice54Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice54View �޽��� ó����


void CPractice54View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch(nChar)
	{
	case VK_LEFT:
		m_ptPosition.x-=10;
		break;
	case VK_RIGHT:
		m_ptPosition.x+=10;
		break;
	case VK_UP:
		m_ptPosition.y-=10;
		break;
	case VK_DOWN:
		m_ptPosition.y+=10;
		break;
	}
	if(m_ptPosition.x<0)
	{
		m_ptPosition.x=0;
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if(m_ptPosition.y<0)
	{
		m_ptPosition.y=0;
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	RECT rect;
	GetClientRect(&rect);
	if(m_ptPosition.x>rect.right-m_nTextWidth)
	{
		m_ptPosition.x=rect.right-m_nTextWidth;
		AfxMessageBox(_T("���������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if(m_ptPosition.y>rect.bottom-m_nTextHeight)
	{
		m_ptPosition.x=rect.bottom-m_nTextHeight;
		AfxMessageBox(_T("�Ʒ������� �� �̻� �̵��� �� �����ϴ�."));
	}

	//����� ���ڿ��� ��ǥ ���� ��ŷ ���� X, Y Edit Control�� �ݿ��Ѵ�,
	CMainFrame *pFrame=(CMainFrame*)AfxGetMainWnd();
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_X,m_ptPosition.x);
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_Y,m_ptPosition.y);

	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
