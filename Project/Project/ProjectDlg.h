
// ProjectDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CProjectDlg ��ȭ ����
class CProjectDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CProjectDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROJECT_DIALOG };

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
	afx_msg void OnCustomdrawList(NMHDR* pNMHDR,LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listAccount;
	CTreeCtrl m_treeAccount;
	HTREEITEM m_hRoot;
	HTREEITEM m_fYear;
	HTREEITEM m_sYear;
	CString m_strNote;
	CString m_strIncome;
	CString m_strExpen;
	CString m_strContent;
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedButtonInsert();
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonSearch();
	afx_msg void OnItemchangedListAccount(NMHDR *pNMHDR, LRESULT *pResult);
	int m_nSelectedItem;
	CString m_strBalance;
	CString m_strSelected;
	afx_msg void OnSelchangedTreeAccount(NMHDR *pNMHDR, LRESULT *pResult);
	HTREEITEM m_hSelected;
	HTREEITEM m_hChildItem;
	CString m_strItemText;
	afx_msg void OnClickedCheckIncome();
	afx_msg void OnClickedCheckExpense();
	bool m_bChecked[2];
	CString m_strDate;
	COleDateTime m_timeDate;
	int m_nTotalInSum;
	int m_nTotalExSum;
	void RemainMoney2(void);
	COleDateTime m_timeFirst;
	COleDateTime m_timeSecond;
	int nIndex;
	Product productData[100];
};
