#pragma once


// CSecondView ���Դϴ�.

class CSecondView : public CView
{
	DECLARE_DYNCREATE(CSecondView)

public:
	CSecondView();           
	virtual ~CSecondView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


