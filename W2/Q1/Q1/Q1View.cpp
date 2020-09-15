
// Q1View.cpp : CQ1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Q1.h"
#endif

#include "Q1Doc.h"
#include "Q1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQ1View

IMPLEMENT_DYNCREATE(CQ1View, CView)

BEGIN_MESSAGE_MAP(CQ1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CQ1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CQ1View ����/�Ҹ�

CQ1View::CQ1View()
	: m_strStopWatch(_T("00: 00. 00"))
	, m_nCount(0)
	, m_nMinute(0)
	, m_nSecond(0)
	, m_nMSec(0)
	, m_strStopWatchRun(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CQ1View::~CQ1View()
{
}

BOOL CQ1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CQ1View �׸���

void CQ1View::OnDraw(CDC* pDC)
{
	CQ1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CRect rect;
	GetClientRect(&rect);
	CFont big_font;
	int x=10;
	int y=10;
	for (int i = 0; i < m_nCount; i++){
		pDC->TextOutW(x, y, m_strRecord[i]);
		y +=20; 
	}
	big_font.CreateFont(100,0,0,0,FW_NORMAL,FALSE,FALSE,0,
		DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("����ü"));
	
	pDC->DrawText(m_strStopWatch, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	CClientDC dc(this);
}


// CQ1View �μ�


void CQ1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CQ1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CQ1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CQ1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CQ1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CQ1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CQ1View ����

#ifdef _DEBUG
void CQ1View::AssertValid() const
{
	CView::AssertValid();
}

void CQ1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQ1Doc* CQ1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQ1Doc)));
	return (CQ1Doc*)m_pDocument;
}
#endif //_DEBUG


// CQ1View �޽��� ó����


void CQ1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_nMSec++;
	
	if(m_nMSec>=100)
	{
		m_nSecond++;
		m_nMSec-=100;
	}
	if(m_nSecond>=60)
	{
		m_nMinute++;
		m_nSecond-=60;
	}
	if(m_nMinute>=60)
	{
		m_nMinute-=60;
	}
	m_strStopWatch.Format(_T("%02d: %02d. %02d"),m_nMinute, m_nSecond, m_nMSec);
	Invalidate();

	CView::OnTimer(nIDEvent);
}


void CQ1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_strStopWatchRun==false)
	{
		m_strStopWatchRun=true;
		SetTimer(0,100,NULL);
	}
	else
	{
		m_strStopWatchRun=false;
		KillTimer(0);
	}

	CView::OnLButtonDown(nFlags, point);
}


void CQ1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar == VK_SPACE){ 
		if (m_strStopWatchRun){ 
			m_strRecord[m_nCount++] = m_strStopWatch; 
			if (m_nCount == 40){ 
				m_nCount = 0; 
			} 
		} 
	} 
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CQ1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_strStopWatchRun == false){
		if(AfxMessageBox(_T("�����ġ�� �ʱ�ȭ �Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_strStopWatch = (_T("00: 00. 00")); 
			m_nMinute = 0;
			m_nMSec = 0;
			m_nSecond = 0;
			m_strStopWatchRun = false;
			for(int i=0; i<40; i++) {
				if(m_strRecord[i].IsEmpty()==false)
					m_strRecord[i].Empty();
			}
		}
	}
	else
	{
		AfxMessageBox(_T("�۵� �߿��� �����ġ�� �ʱ�ȭ��ų �� �����ϴ�."), MB_OK | MB_ICONWARNING);
	}
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


int CQ1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	AfxMessageBox(_T("�����찡 �����Ǿ����ϴ�."),
		MB_OKCANCEL | MB_ICONINFORMATION);
	m_strStopWatchRun = false;

	return 0;
}


void CQ1View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox(_T("�����찡 ����Ǿ����ϴ�."), MB_YESNO | MB_ICONWARNING);
}
