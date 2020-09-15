// LeftViewDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise10_1.h"
#include "LeftViewDlg.h"
#include "Exercise10_1Doc.h"
#include "Exercise10_1View.h"


// CLeftViewDlg

IMPLEMENT_DYNCREATE(CLeftViewDlg, CFormView)

CLeftViewDlg::CLeftViewDlg()
	: CFormView(CLeftViewDlg::IDD)
	, m_bChecked(false)
{

	m_strNodeText = _T("");
	m_strSelectedNode = _T("");
}

CLeftViewDlg::~CLeftViewDlg()
{
}

void CLeftViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strNodeText);
	DDX_Text(pDX, IDC_EDIT_SELECT, m_strSelectedNode);
}

BEGIN_MESSAGE_MAP(CLeftViewDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CLeftViewDlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CLeftViewDlg::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CLeftViewDlg::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_CHECK_EXPAND, &CLeftViewDlg::OnClickedCheckExpand)
END_MESSAGE_MAP()


// CLeftViewDlg �����Դϴ�.

#ifdef _DEBUG
void CLeftViewDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftViewDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftViewDlg �޽��� ó�����Դϴ�.


void CLeftViewDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
	m_strSelectedNode=_T("��Ʈ ���");
	UpdateData(false);
	((CButton*)GetDlgItem(IDC_CHECK_EXPAND))->SetCheck(true);

}


void CLeftViewDlg::OnClickedButtonInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	if(!m_strNodeText.IsEmpty())
	{
		CExercise10_1View *pView=(CExercise10_1View*) this->GetNextWindow();
		pView->GetTreeCtrl().InsertItem(m_strNodeText,pView->m_hSelectedNode,TVI_LAST);
		pView->GetTreeCtrl().Expand(pView->m_hSelectedNode,TVE_EXPAND);
	}
	else
	{
		AfxMessageBox(_T("�Է� ����� �ؽ�Ʈ�� �Է��ϼ���."));
	}
	m_strNodeText.Empty();
	UpdateData(false);
}


void CLeftViewDlg::OnClickedButtonModify()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	if(!m_strNodeText.IsEmpty())
	{
		CExercise10_1View *pView=(CExercise10_1View*) this->GetNextWindow();
		if(pView->m_hSelectedNode!=pView->m_hRoot)
		{
			pView->GetTreeCtrl().SetItemText(pView->m_hSelectedNode,m_strNodeText);
			m_strSelectedNode=m_strNodeText;
		}
		else
		{
			AfxMessageBox(_T("��Ʈ ���� �����ؼ��� �� �˴ϴ�."));
		}
	}
	else
	{
		AfxMessageBox(_T("���� ����� �ؽ�Ʈ�� �Է��ϼ���."));
	}
	m_strNodeText.Empty();
	UpdateData(false);
}


void CLeftViewDlg::OnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CExercise10_1View *pView=(CExercise10_1View*) this->GetNextWindow();
	if(pView->m_hSelectedNode!=pView->m_hRoot)
	{
		if(AfxMessageBox(_T("���� �����Ͻðڽ��ϱ�?"),MB_YESNO | MB_ICONQUESTION)==IDYES)
		{
			pView->GetTreeCtrl().DeleteItem(pView->m_hSelectedNode);
		}
	}
	else
	{
		AfxMessageBox(_T("��Ʈ ���� �����ؼ��� �� �˴ϴ�."));
	}
}


void CLeftViewDlg::OnClickedCheckExpand()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bChecked=false;
	CExercise10_1View *pView=(CExercise10_1View*) this->GetNextWindow();
	pView->GetTreeCtrl().Expand(pView->m_hRoot,TVE_TOGGLE);
	pView->m_hSelectedNode=pView->m_hRoot;
	m_strSelectedNode=_T("��Ʈ ���");
	UpdateData(false);
}
