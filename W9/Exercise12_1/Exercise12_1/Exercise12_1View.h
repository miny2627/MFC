
// Exercise12_1View.h : CExercise12_1View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "PRODUCT.h"
#include "ORDERLIST.h"


class CExercise12_1View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CExercise12_1View();
	DECLARE_DYNCREATE(CExercise12_1View)

public:
	enum{ IDD = IDD_EXERCISE12_1_FORM };

// 특성입니다.
public:
	CExercise12_1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CExercise12_1View();
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

#ifndef _DEBUG  // Exercise12_1View.cpp의 디버그 버전
inline CExercise12_1Doc* CExercise12_1View::GetDocument() const
   { return reinterpret_cast<CExercise12_1Doc*>(m_pDocument); }
#endif

