
// Exercise14_1Dlg.h : ��� ����
//

#pragma once


// CExercise14_1Dlg ��ȭ ����
class CExercise14_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CExercise14_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EXERCISE14_1_DIALOG };

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
	CIPAddressCtrl m_IPAddress;
	CListBox m_listChat;
	int m_nChatMode;
	CString m_strMyIP;
	CString m_strOtherIP;
	afx_msg void OnClickedRadioServer();
	afx_msg void OnRadioClient();
	afx_msg void OnClickedButtonConnect();
	afx_msg void OnClickedButtonSend();
	void ReceiveData(CString strReceive);
	void Accept(CString strSock);
};
