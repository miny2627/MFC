
// Practice7_1Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CPractice7_1Dlg ��ȭ ����
class CPractice7_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice7_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PRACTICE7_1_DIALOG };

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
	afx_msg void OnLbnSelchangeListStudent();
	afx_msg void OnItemchangedListStudent(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_listStudent;
	CString m_strID;
	CString m_strDept;
	CString m_strName;
	CString m_strSelectedItem;
	afx_msg void OnClickedButtonInsert();
	int m_nSelectedItem;
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnSelchangeComboStyle();
};
