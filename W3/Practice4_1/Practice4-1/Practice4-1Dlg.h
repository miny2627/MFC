
// Practice4-1Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CPractice41Dlg ��ȭ ����
class CPractice41Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice41Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PRACTICE41_DIALOG };

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
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnClickedCheck2();
	afx_msg void OnBnClickedButton3();
//	CString m_strEdit;
	CString m_strEdit;
	CListBox m_listBox;
	CComboBox m_cbListItem;
	void UpdateComboBox(void);
	afx_msg void OnRadio1();
//	afx_msg void OnRadio2();
	bool m_bChecked[2];
	afx_msg void OnClickedCheck1();
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonInsert();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnRadio2();
};
