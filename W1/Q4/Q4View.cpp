
// Q4View.cpp : CQ4View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Q4.h"
#endif

#include "Q4Doc.h"
#include "Q4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQ4View

IMPLEMENT_DYNCREATE(CQ4View, CView)

BEGIN_MESSAGE_MAP(CQ4View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CQ4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
//	ON_WM_LBUTTONDBLCLK()
//	ON_WM_RBUTTONDBLCLK()
ON_WM_DESTROY()
END_MESSAGE_MAP()

// CQ4View 생성/소멸

CQ4View::CQ4View()
	: m_strOutput(_T(""))
	, m_strWindowSize(_T(""))
	, m_bDrag(false)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CQ4View::~CQ4View()
{
}

BOOL CQ4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CQ4View 그리기

void CQ4View::OnDraw(CDC* pDC)
{
	CQ4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	// 윈도우 크기를 나타내는 문자열을 윈도우 좌측 상단(10,10)에 출력
	pDC->TextOutW(10,10,m_strWindowSize);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutput,rect,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CQ4View 인쇄


void CQ4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CQ4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CQ4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CQ4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CQ4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CQ4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CQ4View 진단

#ifdef _DEBUG
void CQ4View::AssertValid() const
{
	CView::AssertValid();
}

void CQ4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQ4Doc* CQ4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQ4Doc)));
	return (CQ4Doc*)m_pDocument;
}
#endif //_DEBUG


// CQ4View 메시지 처리기


void CQ4View::OnMouseMove(UINT nFlags, CPoint point)
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
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CQ4View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ??? ??? ??? ??? ?? ?/?? ???? ?????.
	m_strOutput=_T("오른쪽 마우스 버튼을 눌렀습니다.");
	AfxMessageBox(_T("오른쪽 마우스 버튼을 눌렀습니다."),MB_OKCANCEL | MB_ICONINFORMATION);
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CQ4View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ??? ??? ??? ??? ?????.
	// 윈도우 크기가 변경될 때 윈도우 크기를 나타내는 문자열 생성
	m_strWindowSize.Format(_T("윈도우 크기는 넓이 %d, 높이 %d 입니다."),cx,cy);
	//화면 갱신
	Invalidate();
}


void CQ4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ??? ??? ??? ??? ?? ?/?? ???? ?????.
	m_bDrag=TRUE;
	m_strOutput=_T("왼쪽 마우스 버튼을 눌렀습니다.");
	AfxMessageBox(_T("왼쪽 마우스 버튼을 눌렀습니다."),MB_OKCANCEL | MB_ICONINFORMATION);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CQ4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ??? ??? ??? ??? ?? ?/?? ???? ?????.
	m_bDrag=FALSE;

	CView::OnLButtonUp(nFlags, point);
}


void CQ4View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ??? ??? ??? ??? ?? ?/?? ???? ?????.
	m_strOutput=_T("키보드를 눌렀습니다.");
	AfxMessageBox(_T("키보드를 눌렀습니다."),MB_OKCANCEL | MB_ICONINFORMATION);
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


int CQ4View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ??? ???? ?? ??? ?????.
	/// 윈도우가 생성될 때 메시지 박스 출력
	AfxMessageBox(_T("윈도우가 생성되었습니다."),MB_OKCANCEL | MB_ICONINFORMATION);

	return 0;
}


void CQ4View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ??? ??? ??? ??? ?????.
	AfxMessageBox(_T("윈도우가 종료되었습니다."),MB_YESNO | MB_ICONWARNING);
}
