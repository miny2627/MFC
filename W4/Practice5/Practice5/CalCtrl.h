#pragma once


// CCalCtrl 대화 상자입니다.

class CCalCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CCalCtrl)

public:
	CCalCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCalCtrl();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
