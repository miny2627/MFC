#pragma once
#include "afxwin.h"


// CHobbyCtrl ��ȭ �����Դϴ�.

class CHobbyCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CHobbyCtrl)

public:
	CHobbyCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHobbyCtrl();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_TEXTOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CComboBox m_cbSex;
	CListBox m_listHobby;
	virtual BOOL OnInitDialog();
	bool m_bSex;
	bool m_bChecked[3];
	afx_msg void OnSelchangeComboSex();
	afx_msg void OnRadioMale();
	afx_msg void OnRadioFemale();
	afx_msg void OnSelchangeListHobby();
	afx_msg void OnClickedCheckReading();
	afx_msg void OnClickedCheckSports();
	afx_msg void OnClickedCheckFishing();
//	afx_msg void OnClickedButtonResult();
	afx_msg void OnClickedButtonResult();
	afx_msg void OnChangeEditName();
};
