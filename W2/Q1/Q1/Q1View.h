
// Q1View.h : CQ1View 클래스의 인터페이스
//

#pragma once


class CQ1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CQ1View();
	DECLARE_DYNCREATE(CQ1View)

// 특성입니다.
public:
	CQ1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CQ1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strStopWatch;
	CString m_strRecord[40];
	int m_nCount;
	int m_nMinute;
	int m_nSecond;
	int m_nMSec;
	bool m_strStopWatchRun;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // Q1View.cpp의 디버그 버전
inline CQ1Doc* CQ1View::GetDocument() const
   { return reinterpret_cast<CQ1Doc*>(m_pDocument); }
#endif

