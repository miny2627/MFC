
// Practice11-1Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CPractice111Dlg ��ȭ ����
class CPractice111Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice111Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PRACTICE111_DIALOG };

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
	int m_nYear;
	CSpinButtonCtrl m_spinYear;
	CComboBox m_cbMonth;
	int m_nMonth;
	afx_msg void OnSelchangeComboMonth();
	afx_msg void OnDeltaposSpinYear(NMHDR *pNMHDR, LRESULT *pResult);
};
