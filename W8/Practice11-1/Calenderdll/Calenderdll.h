// Calenderdll.h : Calenderdll DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalenderdllApp
// �� Ŭ������ ������ ������ Calenderdll.cpp�� �����Ͻʽÿ�.
//

class CCalenderdllApp : public CWinApp
{
public:
	CCalenderdllApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
