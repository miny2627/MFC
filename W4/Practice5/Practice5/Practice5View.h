
// Practice5View.h : CPractice5View Ŭ������ �������̽�
//

#pragma once


class CPractice5View : public CView
{
protected: // serialization������ ��������ϴ�.
	CPractice5View();
	DECLARE_DYNCREATE(CPractice5View)

// Ư���Դϴ�.
public:
	CPractice5Doc* GetDocument() const;

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
	virtual ~CPractice5View();
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
	CString m_strResult;
};

#ifndef _DEBUG  // Practice5View.cpp�� ����� ����
inline CPractice5Doc* CPractice5View::GetDocument() const
   { return reinterpret_cast<CPractice5Doc*>(m_pDocument); }
#endif

