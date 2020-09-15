// LeftViewDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Practice10_2.h"
#include "LeftViewDlg.h"

#include "MainFrm.h"
#include "Practice10_2Doc.h"

// CLeftViewDlg

IMPLEMENT_DYNCREATE(CLeftViewDlg, CFormView)

CLeftViewDlg::CLeftViewDlg()
	: CFormView(CLeftViewDlg::IDD)
	, m_nSex(0)
{

	m_strDept = _T("");
	m_strName = _T("");
}

CLeftViewDlg::~CLeftViewDlg()
{
}

void CLeftViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}

BEGIN_MESSAGE_MAP(CLeftViewDlg, CFormView)
	ON_COMMAND(IDC_RADIO_MALE, &CLeftViewDlg::OnRadioMale)
	ON_COMMAND(IDC_RADIO_FEMALE, &CLeftViewDlg::OnRadioFemale)
	ON_BN_CLICKED(IDC_CHECK_READING, &CLeftViewDlg::OnClickedCheckReading)
	ON_BN_CLICKED(IDC_CHECK_SPORTS, &CLeftViewDlg::OnClickedCheckSports)
	ON_BN_CLICKED(IDC_CHECK_FISHING, &CLeftViewDlg::OnClickedCheckFishing)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CLeftViewDlg::OnClickedButtonOk)
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
	((CComboBox*)GetDlgItem(IDC_COMBO_DEPT))->SetCurSel(2);
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(1);
	m_nSex=0;
	m_bHobby[0]=m_bHobby[1]=m_bHobby[2]=false;
}


void CLeftViewDlg::OnRadioMale()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSex=0;
}


void CLeftViewDlg::OnRadioFemale()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nSex=1;
}


void CLeftViewDlg::OnClickedCheckReading()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bHobby[0]=!m_bHobby[0];
}


void CLeftViewDlg::OnClickedCheckSports()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bHobby[1]=!m_bHobby[1];
}


void CLeftViewDlg::OnClickedCheckFishing()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bHobby[2]=!m_bHobby[2];
}


void CLeftViewDlg::OnClickedButtonOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	CMainFrame* pFrame=(CMainFrame*)AfxGetMainWnd();
	CPractice10_2Doc* pDoc=(CPractice10_2Doc*)pFrame->GetActiveDocument();

	pDoc->m_strHobby.Empty();

	if(m_strName.IsEmpty())
	{
		AfxMessageBox(_T("�̸��� �Է��ϼ���."));
	}
	else
	{
		pDoc->m_strDept=m_strDept;
		pDoc->m_strName=m_strName;
		if(m_nSex==0)
			pDoc->m_strSex=_T("����");
		else
			pDoc->m_strSex=_T("����");
		if(m_bHobby[0])
			pDoc->m_strHobby+=_T("����");
		if(m_bHobby[1])
			pDoc->m_strHobby+=_T("�");
		if(m_bHobby[2])
			pDoc->m_strHobby+=_T("����");
	}
	UpdateData(false);
}
