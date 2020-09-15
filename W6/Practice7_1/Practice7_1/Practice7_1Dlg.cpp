
// Practice7_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Practice7_1.h"
#include "Practice7_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPractice7_1Dlg ��ȭ ����




CPractice7_1Dlg::CPractice7_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPractice7_1Dlg::IDD, pParent)
	, m_nSelectedItem(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strID = _T("");
	m_strDept = _T("");
	m_strName = _T("");
	m_strSelectedItem = _T("");
}

void CPractice7_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STUDENT, m_listStudent);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_SELECTED_ITEM, m_strSelectedItem);
}

BEGIN_MESSAGE_MAP(CPractice7_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST_STUDENT, &CPractice7_1Dlg::OnLbnSelchangeListStudent)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_STUDENT, &CPractice7_1Dlg::OnItemchangedListStudent)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CPractice7_1Dlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CPractice7_1Dlg::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CPractice7_1Dlg::OnClickedButtonDelete)
	ON_CBN_SELCHANGE(IDC_COMBO_STYLE, &CPractice7_1Dlg::OnSelchangeComboStyle)
END_MESSAGE_MAP()


// CPractice7_1Dlg �޽��� ó����

BOOL CPractice7_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	LPWSTR list[4]={_T("����"),_T("�а�"),_T("�й�"),_T("�̸�")};
	int nWidth[4]={50,160,120,120};

	for(int i=0; i<4; i++)
	{
		m_listStudent.InsertColumn(i, list[i], LVCFMT_CENTER,nWidth[i]);
	}

	m_listStudent.SetExtendedStyle(m_listStudent.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	((CComboBox*) GetDlgItem(IDC_COMBO_STYLE))->SetCurSel(0);

	((CButton*) GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
	((CButton*) GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CPractice7_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CPractice7_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CPractice7_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPractice7_1Dlg::OnLbnSelchangeListStudent()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CPractice7_1Dlg::OnItemchangedListStudent(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nSelectedItem=pNMLV->iItem;

	m_strSelectedItem.Format(_T("%d"),m_nSelectedItem+1);
	m_strDept=m_listStudent.GetItemText(m_nSelectedItem,1);
	m_strID=m_listStudent.GetItemText(m_nSelectedItem,2);
	m_strName=m_listStudent.GetItemText(m_nSelectedItem,3);

	((CButton*) GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(true);
	((CButton*) GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(true);

	UpdateData(false);

	*pResult = 0;
}


void CPractice7_1Dlg::OnClickedButtonInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nCount=m_listStudent.GetItemCount();
	CString strCount;

	UpdateData(true);
	if(!m_strDept.IsEmpty() && !m_strID.IsEmpty() && !m_strName.IsEmpty())
	{
		strCount.Format(_T("%d"),nCount+1);
		m_listStudent.InsertItem(nCount,strCount);
		m_listStudent.SetItem(nCount,1,LVIF_TEXT, m_strDept,0,0,0,0);
		m_listStudent.SetItem(nCount,2,LVIF_TEXT, m_strID,0,0,0,0);
		m_listStudent.SetItem(nCount,3,LVIF_TEXT, m_strName,0,0,0,0);
		
		m_strDept.Empty();
		m_strID.Empty();
		m_strName.Empty();

		((CButton*) GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
		((CButton*) GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

		UpdateData(false);
	}
	else
	{
		MessageBox(_T("��� �׸��� �Է��� �ּ���"),_T("���"),MB_OK);
	}

}


void CPractice7_1Dlg::OnClickedButtonModify()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	CString strDept,strID,strName,strIndex;
	strDept=m_strDept;
	strID=m_strID;
	strName=m_strName;

	if(m_nSelectedItem>=0)
	{
		if(!m_strDept.IsEmpty() && !m_strID.IsEmpty() && !m_strName.IsEmpty())
		{
			strIndex.Format(_T("%d"),m_nSelectedItem+1);
			m_listStudent.SetItem(m_nSelectedItem,0,LVIF_TEXT,strIndex,0,0,0,0);
			m_listStudent.SetItem(m_nSelectedItem,1,LVIF_TEXT,strDept,0,0,0,0);
			m_listStudent.SetItem(m_nSelectedItem,2,LVIF_TEXT,strID,0,0,0,0);
			m_listStudent.SetItem(m_nSelectedItem,3,LVIF_TEXT,strName,0,0,0,0);

			m_strDept.Empty();
			m_strID.Empty();
			m_strName.Empty();

			((CButton*) GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
			((CButton*) GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

			UpdateData(false);
		}
		else
		{
			MessageBox(_T("��� �׸��� �Է��� �ּ���."),_T("���"),MB_OK);
		}
	}
	else
	{
		MessageBox(_T("�������� �������� �ʾҽ��ϴ�."),_T("���"),MB_OK);
	}
}


void CPractice7_1Dlg::OnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(m_nSelectedItem>=0)
	{
		m_listStudent.DeleteItem(m_nSelectedItem);

		for(int i=m_nSelectedItem-1; i<m_listStudent.GetItemCount(); i++)
		{
			CString strIndex;
			strIndex.Format(_T("%d"),i+1);
			m_listStudent.SetItemText(i,0,strIndex);
		}
		m_strDept.Empty();
		m_strID.Empty();
		m_strName.Empty();

		((CButton*) GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
		((CButton*) GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

		UpdateData(false);
	}
	else
	{
		MessageBox(_T("�������� �������� �ʾҽ��ϴ�."),_T("���"),MB_OK);
	}
}


void CPractice7_1Dlg::OnSelchangeComboStyle()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int numSel=((CComboBox*) GetDlgItem(IDC_COMBO_STYLE))->GetCurSel();
	long setStyle;

	setStyle=GetWindowLong(m_listStudent.m_hWnd,GWL_STYLE);
	setStyle &=~LVS_TYPEMASK;

	switch(numSel)
	{
	case 0:
		setStyle |= LVS_REPORT;
		break;
	case 1:
		setStyle |=LVS_LIST;
		break;
	case 2:
		setStyle |=LVS_SMALLICON;
		break;
	case 3:
		setStyle |=LVS_ICON;
		break;
	}
	SetWindowLong(m_listStudent.m_hWnd,GWL_STYLE,setStyle);
}
