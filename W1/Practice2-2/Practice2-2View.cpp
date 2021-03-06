
// Practice2-2View.cpp : CPractice22View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice2-2.h"
#endif

#include "Practice2-2Doc.h"
#include "Practice2-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice22View

IMPLEMENT_DYNCREATE(CPractice22View, CView)

BEGIN_MESSAGE_MAP(CPractice22View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice22View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CPractice22View 생성/소멸

CPractice22View::CPractice22View()
	: m_strWindowSize(_T(""))
	, m_strOutput(_T(""))
	, m_bDrag(false)
	, m_ptMouseMove(0)
	, m_strPointText(_T(""))
	, m_Point(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPractice22View::~CPractice22View()
{
}

BOOL CPractice22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice22View 그리기

void CPractice22View::OnDraw(CDC* pDC)
{
	CPractice22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	// 윈도우 크기를 나타내는 문자열을 윈도우 좌측 상단(10,10)에 출력
	pDC->TextOutW(10,10,m_strWindowSize);
	pDC->TextOutW(m_Point.x, m_Point.y, m_strPointText);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutput,rect,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CPractice22View 인쇄


void CPractice22View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CPractice22View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice22View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice22View 진단

#ifdef _DEBUG
void CPractice22View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice22Doc* CPractice22View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice22Doc)));
	return (CPractice22Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice22View 메시지 처리기


void CPractice22View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ??? ??? ??? ??? ?????.
	// 윈도우 크기가 변경될 때 윈도우 크기를 나타내는 문자열 생성
	m_strWindowSize.Format(_T("윈도우 크기는 넓이 %d, 높이 %d 입니다."),cx,cy);
	//화면 갱신
	Invalidate();
}


void CPractice22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ??? ??? ??? ??? ?? ?/?? ???? ?????.
	m_bDrag=TRUE;
	m_strOutput=_T("왼쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CPractice22View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ??? ??? ??? ??? ?? ?/?? ???? ?????.
	m_strOutput=_T("오른쪽 마우스 버튼을 눌렀습니다.");
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CPractice22View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ??? ??? ??? ??? ?? ?/?? ???? ?????.
	m_strOutput=_T("키보드를 눌렀습니다.");
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CPractice22View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ??? ??? ??? ??? ?? ?/?? ???? ?????.
	if(m_bDrag==TRUE)
	{
		m_strOutput=_T("마우스를 드래그하고 있습니다.");
	}
	else
	{
		m_strOutput=_T("마우스를 이동 중입니다.");
	}
	m_strPointText.Format(_T("X : %d Y : %d"),point.x,point.y);
	m_Point=point;
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CPractice22View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ??? ??? ??? ??? ?? ?/?? ???? ?????.
	m_bDrag=FALSE;

	CView::OnLButtonUp(nFlags, point);
}
