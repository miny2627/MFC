// LeftViewDlg.cpp : 구현 파일입니다.
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


// CLeftViewDlg 진단입니다.

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


// CLeftViewDlg 메시지 처리기입니다.


void CLeftViewDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	m_strSelectedNode=_T("루트 노드");
	UpdateData(false);
	((CButton*)GetDlgItem(IDC_CHECK_EXPAND))->SetCheck(true);

}


void CLeftViewDlg::OnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	if(!m_strNodeText.IsEmpty())
	{
		CExercise10_1View *pView=(CExercise10_1View*) this->GetNextWindow();
		pView->GetTreeCtrl().InsertItem(m_strNodeText,pView->m_hSelectedNode,TVI_LAST);
		pView->GetTreeCtrl().Expand(pView->m_hSelectedNode,TVE_EXPAND);
	}
	else
	{
		AfxMessageBox(_T("입력 노드의 텍스트를 입력하세요."));
	}
	m_strNodeText.Empty();
	UpdateData(false);
}


void CLeftViewDlg::OnClickedButtonModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
			AfxMessageBox(_T("루트 노드는 수정해서는 안 됩니다."));
		}
	}
	else
	{
		AfxMessageBox(_T("수정 노드의 텍스트를 입력하세요."));
	}
	m_strNodeText.Empty();
	UpdateData(false);
}


void CLeftViewDlg::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CExercise10_1View *pView=(CExercise10_1View*) this->GetNextWindow();
	if(pView->m_hSelectedNode!=pView->m_hRoot)
	{
		if(AfxMessageBox(_T("정말 삭제하시겠습니까?"),MB_YESNO | MB_ICONQUESTION)==IDYES)
		{
			pView->GetTreeCtrl().DeleteItem(pView->m_hSelectedNode);
		}
	}
	else
	{
		AfxMessageBox(_T("루트 노드는 삭제해서는 안 됩니다."));
	}
}


void CLeftViewDlg::OnClickedCheckExpand()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bChecked=false;
	CExercise10_1View *pView=(CExercise10_1View*) this->GetNextWindow();
	pView->GetTreeCtrl().Expand(pView->m_hRoot,TVE_TOGGLE);
	pView->m_hSelectedNode=pView->m_hRoot;
	m_strSelectedNode=_T("루트 노드");
	UpdateData(false);
}
