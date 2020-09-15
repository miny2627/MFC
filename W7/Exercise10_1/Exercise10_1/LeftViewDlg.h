#pragma once



// CLeftViewDlg �� ���Դϴ�.

class CLeftViewDlg : public CFormView
{
	DECLARE_DYNCREATE(CLeftViewDlg)

protected:
	CLeftViewDlg();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CLeftViewDlg();

public:
	enum { IDD = IDD_FORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strNodeText;
	CString m_strSelectedNode;
	bool m_bChecked;
	virtual void OnInitialUpdate();
	afx_msg void OnClickedButtonInsert();
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedCheckExpand();
};


