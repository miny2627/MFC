
// Exercise5_1.h : Exercise5_1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CExercise5_1App:
// �� Ŭ������ ������ ���ؼ��� Exercise5_1.cpp�� �����Ͻʽÿ�.
//

class CExercise5_1App : public CWinAppEx
{
public:
	CExercise5_1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExercise5_1App theApp;
