#pragma once
#include "calctrl.h"


// CCalPane

class CCalPane : public CDockablePane
{
	DECLARE_DYNAMIC(CCalPane)

public:
	CCalPane();
	virtual ~CCalPane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CCalCtrl m_ctrlCal;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


