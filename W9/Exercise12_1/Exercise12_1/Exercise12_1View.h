
// Exercise12_1View.h : CExercise12_1View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "PRODUCT.h"
#include "ORDERLIST.h"


class CExercise12_1View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CExercise12_1View();
	DECLARE_DYNCREATE(CExercise12_1View)

public:
	enum{ IDD = IDD_EXERCISE12_1_FORM };

// Ư���Դϴ�.
public:
	CExercise12_1Doc* GetDocument() const;

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
	virtual ~CExercise12_1View();
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
	CListCtrl m_listOrder;
	afx_msg void OnClickedButtonInsert();
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedButtonReset();
	afx_msg void OnClickedButtonCalc();
	CString m_strNumber;
	CString m_strSum;
	COleDateTime m_timeDate;
	CComboBox m_comboCode;
	CString m_strDate;
	int m_nSelectedItem;
	afx_msg void OnItemchangedListOrder(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_strSelected;
};

#ifndef _DEBUG  // Exercise12_1View.cpp�� ����� ����
inline CExercise12_1Doc* CExercise12_1View::GetDocument() const
   { return reinterpret_cast<CExercise12_1Doc*>(m_pDocument); }
#endif

