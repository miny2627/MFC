#pragma once
#include "hobbyctrl.h"


// CHobbyPane

class CHobbyPane : public CDockablePane
{
	DECLARE_DYNAMIC(CHobbyPane)

public:
	CHobbyPane();
	virtual ~CHobbyPane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CHobbyCtrl m_ctrlHobby;
};


