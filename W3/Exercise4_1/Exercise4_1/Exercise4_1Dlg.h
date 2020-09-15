
// Exercise4_1Dlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CExercise4_1Dlg 대화 상자
class CExercise4_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CExercise4_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EXERCISE4_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();

private:
	afx_msg void OnEnChangeEdit1();
public:
	afx_msg void OnLbnSelchangeList2();
	CListBox m_listLeft;
	CListBox m_listRight;
	CComboBox m_cbMove;
	CString m_strResult;
	afx_msg void OnSelchangeComboMove();
	afx_msg void OnClickedButtonPurchase();
	CString m_strCombo;
};
