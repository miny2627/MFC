
// Practice 11_3Dlg.h : ��� ����
//

#pragma once
#include "CalculateRoot.h"
#include "c:\users\lg\documents\my\practice 11_3\rootdll\calculateroot.h"


// CPractice11_3Dlg ��ȭ ����
class CPractice11_3Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice11_3Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PRACTICE11_3_DIALOG };

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
	CCalculateRoot m_calcRoot;
	afx_msg void OnClickedButtonCalcRoot();
	afx_msg void OnClickedButtonClear();
};
