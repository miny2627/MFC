
// Practice4-1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPractice41App:
// �� Ŭ������ ������ ���ؼ��� Practice4-1.cpp�� �����Ͻʽÿ�.
//

class CPractice41App : public CWinApp
{
public:
	CPractice41App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPractice41App theApp;