
// Practice7_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPractice7_1App:
// �� Ŭ������ ������ ���ؼ��� Practice7_1.cpp�� �����Ͻʽÿ�.
//

class CPractice7_1App : public CWinApp
{
public:
	CPractice7_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPractice7_1App theApp;