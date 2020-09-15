
// Q1View.cpp : CQ1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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

// CQ1View 생성/소멸

CQ1View::CQ1View()
	: m_strStopWatch(_T("00: 00. 00"))
	, m_nCount(0)
	, m_nMinute(0)
	, m_nSecond(0)
	, m_nMSec(0)
	, m_strStopWatchRun(false)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CQ1View::~CQ1View()
{
}

BOOL CQ1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CQ1View 그리기

void CQ1View::OnDraw(CDC* pDC)
{
	CQ1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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
		DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,_T("굴림체"));
	
	pDC->DrawText(m_strStopWatch, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	CClientDC dc(this);
}


// CQ1View 인쇄


void CQ1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CQ1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CQ1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CQ1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CQ1View 진단

#ifdef _DEBUG
void CQ1View::AssertValid() const
{
	CView::AssertValid();
}

void CQ1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQ1Doc* CQ1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQ1Doc)));
	return (CQ1Doc*)m_pDocument;
}
#endif //_DEBUG


// CQ1View 메시지 처리기


void CQ1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(m_strStopWatchRun == false){
		if(AfxMessageBox(_T("스톱워치를 초기화 하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
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
		AfxMessageBox(_T("작동 중에는 스톱워치를 초기화시킬 수 없습니다."), MB_OK | MB_ICONWARNING);
	}
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


int CQ1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	AfxMessageBox(_T("윈도우가 생성되었습니다."),
		MB_OKCANCEL | MB_ICONINFORMATION);
	m_strStopWatchRun = false;

	return 0;
}


void CQ1View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	AfxMessageBox(_T("윈도우가 종료되었습니다."), MB_YESNO | MB_ICONWARNING);
}
