// HobbyCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise5_1.h"
#include "HobbyCtrl.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Exercise5_1Doc.h"
#include "Exercise5_1View.h"


// CHobbyCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHobbyCtrl, CDialogEx)

CHobbyCtrl::CHobbyCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHobbyCtrl::IDD, pParent)
	, m_strName(_T(""))
	, m_bSex(true)
{

}

CHobbyCtrl::~CHobbyCtrl()
{
}

void CHobbyCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Control(pDX, IDC_COMBO_SEX, m_cbSex);
	DDX_Control(pDX, IDC_LIST_HOBBY, m_listHobby);
}


BEGIN_MESSAGE_MAP(CHobbyCtrl, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_SEX, &CHobbyCtrl::OnSelchangeComboSex)
	ON_COMMAND(IDC_RADIO_MALE, &CHobbyCtrl::OnRadioMale)
	ON_COMMAND(IDC_RADIO_FEMALE, &CHobbyCtrl::OnRadioFemale)
	ON_LBN_SELCHANGE(IDC_LIST_HOBBY, &CHobbyCtrl::OnSelchangeListHobby)
	ON_BN_CLICKED(IDC_CHECK_READING, &CHobbyCtrl::OnClickedCheckReading)
	ON_BN_CLICKED(IDC_CHECK_SPORTS, &CHobbyCtrl::OnClickedCheckSports)
	ON_BN_CLICKED(IDC_CHECK_FISHING, &CHobbyCtrl::OnClickedCheckFishing)
//	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CHobbyCtrl::OnClickedButtonResult)
ON_BN_CLICKED(IDC_BUTTON_RESULT, &CHobbyCtrl::OnClickedButtonResult)
ON_EN_CHANGE(IDC_EDIT_NAME, &CHobbyCtrl::OnChangeEditName)
END_MESSAGE_MAP()


// CHobbyCtrl �޽��� ó�����Դϴ�.


BOOL CHobbyCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_bChecked[0]=IsDlgButtonChecked(IDC_CHECK_READING);
	m_bChecked[1]=IsDlgButtonChecked(IDC_CHECK_FISHING);
	m_bChecked[2]=IsDlgButtonChecked(IDC_CHECK_SPORTS);

	m_bChecked[0]=false;
	m_bChecked[1]=false;
	m_bChecked[2]=false;

	m_listHobby.AddString(_T("����"));
	m_listHobby.AddString(_T("����"));
	m_listHobby.AddString(_T("�"));

	m_cbSex.SetCurSel(0);
	CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO_MALE);
	pButton->SetCheck(true);


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CHobbyCtrl::OnSelchangeComboSex()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int index=m_cbSex.GetCurSel();
	CString m_strCombo;

	CButton* pButton1 = (CButton*)GetDlgItem(IDC_RADIO_FEMALE);
	CButton* pButton2 = (CButton*)GetDlgItem(IDC_RADIO_MALE);
	m_cbSex.GetLBText(index,m_strCombo);

	if(index!=CB_ERR)
	{
		if(m_strCombo=="����")
		{
			pButton1->SetCheck(true);
			pButton2->SetCheck(false);
		}
		else
		{
			pButton1->SetCheck(false);
			pButton2->SetCheck(true);
		}	
	}	
}


void CHobbyCtrl::OnRadioMale()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_cbSex.SetCurSel(0);
}


void CHobbyCtrl::OnRadioFemale()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_cbSex.SetCurSel(1);
}


void CHobbyCtrl::OnSelchangeListHobby()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int index=m_listHobby.GetCurSel();
	
	if (index == 0) 
	{ 
		m_bChecked[0] = ((CButton*)GetDlgItem(IDC_CHECK_READING))->GetCheck(); 
		((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(!m_bChecked[0]);
	}
	else if (index == 1) 
	{ 
		m_bChecked[1] = ((CButton*)GetDlgItem(IDC_CHECK_FISHING))->GetCheck(); 
		((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(!m_bChecked[1]);
	}
	else if (index == 2) 
	{ 
		m_bChecked[2] = ((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->GetCheck(); 
		((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(!m_bChecked[2]);
	}
	
}


void CHobbyCtrl::OnClickedCheckReading()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bChecked[0]= ((CButton*)GetDlgItem(IDC_CHECK_READING))->GetCheck();
		if(m_bChecked[0])
		{
			m_listHobby.SetSel(0);
		}
		else m_listHobby.SetSel(0,false);
	
}


void CHobbyCtrl::OnClickedCheckSports()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bChecked[2]= ((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->GetCheck();
		if(m_bChecked[2])
		{
			m_listHobby.SetSel(2);
		}
		else m_listHobby.SetSel(2,false);
}


void CHobbyCtrl::OnClickedCheckFishing()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bChecked[1]= ((CButton*)GetDlgItem(IDC_CHECK_FISHING))->GetCheck();
		if(m_bChecked[1])
		{
			m_listHobby.SetSel(1);
		}
		else m_listHobby.SetSel(1,false);
}



void CHobbyCtrl::OnClickedButtonResult()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame *pFrame=(CMainFrame *)AfxGetMainWnd();
	CExercise5_1View* pView=(CExercise5_1View*)pFrame->GetActiveView();

	int index1=m_cbSex.GetCurSel();
	CString str1;
	m_cbSex.GetLBText(index1,str1);

	int count=m_listHobby.GetSelCount();
	CArray <int,int*> m_arr;
	m_arr.SetSize(count);
	m_listHobby.GetSelItems(count,m_arr.GetData());
	CString str,str2[3];

	for (int i = 0; i <m_arr.GetSize(); i++)
    {
	  m_listHobby.GetText(m_arr[i],str2[i]);
	  str+=str2[i]+_T(" ");
	}

	pView->m_strName=m_strName;
	pView->m_strSex=str1;
	pView->m_strHobby=str;

	pView->Invalidate();
}


void CHobbyCtrl::OnChangeEditName()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	GetDlgItemText(IDC_EDIT_NAME,m_strName);
}
