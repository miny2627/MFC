
// Exercise4_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CExercise4_1App:
// �� Ŭ������ ������ ���ؼ��� Exercise4_1.cpp�� �����Ͻʽÿ�.
//

class CExercise4_1App : public CWinApp
{
public:
	CExercise4_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CExercise4_1App theApp;