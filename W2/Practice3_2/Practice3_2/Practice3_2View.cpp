
// Practice3_2View.cpp : CPractice3_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice3_2.h"
#endif

#include "Practice3_2Doc.h"
#include "Practice3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice3_2View

IMPLEMENT_DYNCREATE(CPractice3_2View, CView)

BEGIN_MESSAGE_MAP(CPractice3_2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice3_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CPractice3_2View ����/�Ҹ�

CPractice3_2View::CPractice3_2View()
	: m_bTimerRun(false)
	, m_bTimerType(true)
	, m_strTimer(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CPractice3_2View::~CPractice3_2View()
{
}

BOOL CPractice3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPractice3_2View �׸���

void CPractice3_2View::OnDraw(CDC* pDC)
{
	CPractice3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CRect rect;
	GetClientRect(&rect);			//������ Ŭ���̾�Ʈ ������ ��´�.
									//������ �߾ӿ� Ÿ�̸Ӹ� ���
	pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CPractice3_2View �μ�


void CPractice3_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPractice3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPractice3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CPractice3_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice3_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice3_2View ����

#ifdef _DEBUG
void CPractice3_2View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice3_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice3_2Doc* CPractice3_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice3_2Doc)));
	return (CPractice3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice3_2View �޽��� ó����


int CPractice3_2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	SetTimer(0, 1000, NULL);				// Ÿ�̸� ����
	m_bTimerRun = TRUE;						// Ÿ�̸� ����
	return 0;
}


void CPractice3_2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int hour;
	CString str;
	CTime timer;							//Ÿ�̸� ���� ����
	timer = CTime :: GetCurrentTime();		//���� �ð� ����

	if(m_bTimerType)
	{
		m_strTimer.Format(_T("����� %d�� %d�� %d�� %d�� %d�� %d��"), timer.GetYear(), timer.GetMonth(), timer.GetDay(), timer.GetHour(), timer.GetMinute(), timer.GetSecond());
	}
	else{
		hour = timer.GetHour();
		if(hour >= 12){
			str = _T("PM");
			if(hour >=13) hour = hour - 12;
		}else{
			str = _T("AM");
		}
		m_strTimer.Format(_T("������ %s %d�� %d�� %d��"), str, hour, timer.GetMinute(), timer.GetSecond());
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CPractice3_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_bTimerType){
		/*��, ��, ��, ��, ��, �� ���·� ��� ��*/
		if(AfxMessageBox(_T("��,��,�� ���·� ǥ���ϰڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES){
			m_bTimerType = false;
		}
	}else{
		if(AfxMessageBox(_T("��,��,��,��,��,�� ���·� ǥ���ϰڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES){
			m_bTimerType = true;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CPractice3_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_bTimerRun == false){
		if(AfxMessageBox(_T("�����нð踦 ���۽�Ű�ڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES){
			SetTimer(0, 1000, NULL);
			m_bTimerRun = true;
		}
	}else{
		if(AfxMessageBox(_T("������ �����нð� ������ ���߰ڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES){
			KillTimer(0);
			m_bTimerRun = false;
		}
	}
	CView::OnRButtonDown(nFlags, point);
}


void CPractice3_2View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if(m_bTimerRun) KillTimer(0);
}
