#pragma once


// CCalCtrl ��ȭ �����Դϴ�.

class CCalCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CCalCtrl)

public:
	CCalCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCalCtrl();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_CAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonPlus();
	afx_msg void OnClickedButtonMinus();
	afx_msg void OnClickedButtonMultiply();
	afx_msg void OnClickedButtonDivide();
	afx_msg void OnRadioOne();
	afx_msg void OnRadioTwo();
	afx_msg void OnClickedButtonOne();
	afx_msg void OnClickedButtonTwo();
	afx_msg void OnClickedButtonThree();
	afx_msg void OnClickedButtonFour();
	afx_msg void OnClickedButtonFive();
	afx_msg void OnClickedButtonSix();
	afx_msg void OnClickedButtonSeven();
	afx_msg void OnClickedButtonEight();
	afx_msg void OnClickedButtonNine();
	afx_msg void OnClickedButtonZero();
	afx_msg void OnClickedButtonBs();
	afx_msg void OnClickedButtonClear();
	void PressNumber(int num);
	int m_num;
	int m_num1;
	int m_num2;
};
