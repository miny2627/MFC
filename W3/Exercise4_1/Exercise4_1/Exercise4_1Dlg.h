
// Exercise4_1Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CExercise4_1Dlg ��ȭ ����
class CExercise4_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CExercise4_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EXERCISE4_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
