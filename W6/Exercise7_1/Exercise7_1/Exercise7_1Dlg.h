
// Exercise7_1Dlg.h : ��� ����
//

#pragma once


// CExercise7_1Dlg ��ȭ ����
class CExercise7_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CExercise7_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EXERCISE7_1_DIALOG };

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
	typedef struct Product{
	CString strCategory;
	CString strTitle;
	CString strYear;
	CString strGrade;
	}Product;
	Product p,q;
	HTREEITEM m_hRoot;
	HTREEITEM m_hMovie;
	HTREEITEM m_hDrama;
	Product m_productInfo[50];
	int m_nCount;
	int m_nSelectedItem;
	HTREEITEM m_hSelectedNode;
	CTreeCtrl m_treeControl;
	CListCtrl m_listControl;
	CString m_strYear;
	CString m_strTitle;
	CString m_strCategory;
	afx_msg void OnClickedButtonInsert();
	CString m_strGrade;
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonDelete();
//	afx_msg void OnItemchangedListControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnItemchangedListControl(NMHDR *pNMHDR, LRESULT *pResult);
};
