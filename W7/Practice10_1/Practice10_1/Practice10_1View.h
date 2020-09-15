
// Practice10_1View.h : CPractice10_1View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"


class CPractice10_1View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CPractice10_1View();
	DECLARE_DYNCREATE(CPractice10_1View)

public:
	enum{ IDD = IDD_PRACTICE10_1_FORM };

// Ư���Դϴ�.
public:
	CPractice10_1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CPractice10_1View();
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
	CString m_strText;
	int m_nRed;
	int m_nGreen;
	int m_nBlue;
	int m_nX;
	int m_nY;
	CSliderCtrl m_sliderX;
	CSliderCtrl m_sliderY;
	COLORREF m_colorText;
	afx_msg void OnClickedButtonOutput();
	afx_msg void OnClickedButtonColor();
	afx_msg void OnClickedButtonReset();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnChangeEditRed();
	afx_msg void OnChangeEditGreen();
	afx_msg void OnChangeEditBlue();
	afx_msg void OnChangeEditText();
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // Practice10_1View.cpp�� ����� ����
inline CPractice10_1Doc* CPractice10_1View::GetDocument() const
   { return reinterpret_cast<CPractice10_1Doc*>(m_pDocument); }
#endif

