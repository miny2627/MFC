
// Practice3_2View.h : CPractice3_2View Ŭ������ �������̽�
//

#pragma once


class CPractice3_2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CPractice3_2View();
	DECLARE_DYNCREATE(CPractice3_2View)

// Ư���Դϴ�.
public:
	CPractice3_2Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CPractice3_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	bool m_bTimerRun;
	bool m_bTimerType;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString m_strTimer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // Practice3_2View.cpp�� ����� ����
inline CPractice3_2Doc* CPractice3_2View::GetDocument() const
   { return reinterpret_cast<CPractice3_2Doc*>(m_pDocument); }
#endif

