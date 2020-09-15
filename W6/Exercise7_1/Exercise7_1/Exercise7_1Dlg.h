
// Exercise7_1Dlg.h : 헤더 파일
//

#pragma once


// CExercise7_1Dlg 대화 상자
class CExercise7_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CExercise7_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EXERCISE7_1_DIALOG };

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
