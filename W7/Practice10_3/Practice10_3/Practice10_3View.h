
// Practice10_3View.h : CPractice10_3View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"


class CPractice10_3View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CPractice10_3View();
	DECLARE_DYNCREATE(CPractice10_3View)

public:
	enum{ IDD = IDD_PRACTICE10_3_FORM };

// Ư���Դϴ�.
public:
	CPractice10_3Doc* GetDocument() const;

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
	virtual ~CPractice10_3View();
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
	CString m_strInput;
	afx_msg void OnClickedButtonSave();
};

#ifndef _DEBUG  // Practice10_3View.cpp�� ����� ����
inline CPractice10_3Doc* CPractice10_3View::GetDocument() const
   { return reinterpret_cast<CPractice10_3Doc*>(m_pDocument); }
#endif

