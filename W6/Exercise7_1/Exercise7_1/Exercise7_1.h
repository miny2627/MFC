
// Exercise7_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CExercise7_1App:
// �� Ŭ������ ������ ���ؼ��� Exercise7_1.cpp�� �����Ͻʽÿ�.
//

class CExercise7_1App : public CWinApp
{
public:
	CExercise7_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CExercise7_1App theApp;