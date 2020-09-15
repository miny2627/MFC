
// Exercise11_1Dlg.h : ��� ����
//

#pragma once
#include "Calculator.h"
#include "c:\users\lg\documents\my\mfc\exercise11_1\calcdll\calculator.h"


// CExercise11_1Dlg ��ȭ ����
class CExercise11_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CExercise11_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EXERCISE11_1_DIALOG };

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
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonSub();
	afx_msg void OnClickedButtonMul();
	afx_msg void OnClickedButtonDiv();
	afx_msg void OnClickedButtonBack();
	afx_msg void OnClickedButtonClear();
	Calculator m_calc;
	afx_msg void OnClickedButtonOne();
	afx_msg void OnClickedButtonZero();
	afx_msg void OnClickedButtonTwo();
	afx_msg void OnClickedButtonThree();
	afx_msg void OnClickedButtonFour();
	afx_msg void OnClickedButtonFive();
	afx_msg void OnClickedButtonSix();
	afx_msg void OnClickedButtonSeven();
	afx_msg void OnClickedButtonEight();
	afx_msg void OnClickedButtonNine();
	afx_msg void OnClickedRadioNum1();
	afx_msg void OnRadioNum2();
	int m_num;
	void PressNumber(int num);
};
