
// Exercise7_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Exercise7_1.h"
#include "Exercise7_1Dlg.h"
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


// CExercise7_1Dlg ��ȭ ����




CExercise7_1Dlg::CExercise7_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExercise7_1Dlg::IDD, pParent)
	, m_nCount(0)
	, m_nSelectedItem(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strYear = _T("");
	m_strTitle = _T("");
	m_strGrade = _T("");
}

void CExercise7_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_CONTROL, m_treeControl);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_listControl);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_strYear);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	//  DDX_CBString(pDX, IDC_COMBO_GRADE, m_strCategory);
	DDX_CBString(pDX, IDC_COMBO_GRADE, m_strGrade);
}

BEGIN_MESSAGE_MAP(CExercise7_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CExercise7_1Dlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CExercise7_1Dlg::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CExercise7_1Dlg::OnClickedButtonDelete)
//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CONTROL, &CExercise7_1Dlg::OnItemchangedListControl)
ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CONTROL, &CExercise7_1Dlg::OnSelchangedTreeControl)
ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CONTROL, &CExercise7_1Dlg::OnItemchangedListControl)
END_MESSAGE_MAP()


// CExercise7_1Dlg �޽��� ó����

BOOL CExercise7_1Dlg::OnInitDialog()
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
	m_hRoot=m_treeControl.InsertItem(_T("����"),TVI_ROOT,TVI_LAST);
	m_hMovie=m_treeControl.InsertItem(_T("��ȭ"),m_hRoot,TVI_LAST);
	m_hDrama=m_treeControl.InsertItem(_T("���"),m_hRoot,TVI_LAST);

	LPWSTR list[3]={_T("��ǰ��"),_T("���۳⵵"),_T("���")};
	int nWidth[3]={140,120,123};
	
	for(int i=0; i<3; i++)
	{
		m_listControl.InsertColumn(i,list[i],LVCFMT_CENTER,nWidth[i]);
	}

	m_listControl.SetExtendedStyle(m_listControl.GetExtendedStyle()| LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}


void CExercise7_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExercise7_1Dlg::OnPaint()
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
HCURSOR CExercise7_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise7_1Dlg::OnClickedButtonInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	int nCount=m_listControl.GetItemCount();
	CString strCount;

	if(!m_strTitle.IsEmpty() && !m_strYear.IsEmpty() && !m_strGrade.IsEmpty())
	{
		if(m_hSelectedNode==m_hMovie)
		{
			strCount.Format(_T("%d"),nCount+1);
			m_listControl.InsertItem(nCount,m_strTitle);
			for(int i=0; i<50; i++)
			{
				if(m_strTitle==m_productInfo[i].strTitle){
					AfxMessageBox(_T("�ߺ��� ��ǰ�� �ֽ��ϴ�."),MB_OK | MB_ICONWARNING);
					break;
				}
			}
			m_listControl.SetItem(nCount,1,LVIF_TEXT,m_strYear,0,0,0,0);
			m_listControl.SetItem(nCount,2,LVIF_TEXT,m_strGrade,0,0,0,0);

			p.strTitle=m_strTitle;
			p.strGrade=m_strGrade;
			p.strYear=m_strYear;
			p.strCategory=m_strCategory;
			
			m_strTitle.Empty();
			m_strGrade.Empty();
			m_strYear.Empty();

			UpdateData(false);
		}
		else if(m_hSelectedNode==m_hDrama)
		{
			strCount.Format(_T("%d"),nCount+1);
			m_listControl.InsertItem(nCount,m_strTitle);
			for(int i=0; i<50; i++)
			{
				if(m_strTitle==m_productInfo[i].strTitle){
					AfxMessageBox(_T("�ߺ��� ��ǰ�� �ֽ��ϴ�."),MB_OK | MB_ICONWARNING);
					break;
				}
			}
			m_listControl.SetItem(nCount,1,LVIF_TEXT,m_strYear,0,0,0,0);
			m_listControl.SetItem(nCount,2,LVIF_TEXT,m_strGrade,0,0,0,0);

			p.strTitle=m_strTitle;
			p.strGrade=m_strGrade;
			p.strYear=m_strYear;
			
			m_strTitle.Empty();
			m_strGrade.Empty();
			m_strYear.Empty();
			m_strCategory.Empty();

			UpdateData(false);
		}
		else
		{
			AfxMessageBox(_T("��ǰ �帣�� ������ �ּ���."),MB_OK|MB_ICONWARNING);
		}
	}
	else
	{
		AfxMessageBox(_T("��� �׸��� �Է����ּ���."),MB_OK | MB_ICONWARNING);
	}
}


void CExercise7_1Dlg::OnClickedButtonModify()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	if(m_nSelectedItem>=0)
	{
		if(!m_strTitle.IsEmpty() && !m_strYear.IsEmpty() && !m_strGrade.IsEmpty())
		{
			if(m_hSelectedNode==m_hMovie)
		{
			m_strCategory.Format(_T("%d"),m_nSelectedItem+1);
			m_listControl.SetItem(m_nSelectedItem,0,LVIF_TEXT,m_strTitle,0,0,0,0);
			for(int i=0; i<50; i++)
			{
				if(m_strTitle==m_productInfo[i].strTitle){
					AfxMessageBox(_T("�ߺ��� ��ǰ�� �ֽ��ϴ�."),MB_OK | MB_ICONWARNING);
					break;
				}
			}
			m_listControl.SetItem(m_nSelectedItem,1,LVIF_TEXT,m_strYear,0,0,0,0);
			m_listControl.SetItem(m_nSelectedItem,2,LVIF_TEXT,m_strGrade,0,0,0,0);

			p.strTitle=m_strTitle;
			p.strGrade=m_strGrade;
			p.strYear=m_strYear;

			m_strTitle.Empty();
			m_strGrade.Empty();
			m_strYear.Empty();
			m_strCategory.Empty();

			UpdateData(false);
		}
		else if(m_hSelectedNode==m_hDrama)
		{
			m_strCategory.Format(_T("%d"),m_nSelectedItem+1);
			m_listControl.SetItem(m_nSelectedItem,0,LVIF_TEXT,m_strTitle,0,0,0,0);
			for(int i=0; i<50; i++)
			{
				if(m_strTitle==m_productInfo[i].strTitle){
					AfxMessageBox(_T("�ߺ��� ��ǰ�� �ֽ��ϴ�."),MB_OK | MB_ICONWARNING);
					break;
				}
			}
			m_listControl.SetItem(m_nSelectedItem,1,LVIF_TEXT,m_strYear,0,0,0,0);
			m_listControl.SetItem(m_nSelectedItem,2,LVIF_TEXT,m_strGrade,0,0,0,0);

			p.strTitle=m_strTitle;
			p.strGrade=m_strGrade;
			p.strYear=m_strYear;
			
			m_strTitle.Empty();
			m_strGrade.Empty();
			m_strYear.Empty();
			m_strCategory.Empty();

			UpdateData(false);
		}
			else
		{
			AfxMessageBox(_T("��ǰ �帣�� ������ �ּ���."),MB_OK|MB_ICONWARNING);
		}
		}
		else
			{
		AfxMessageBox(_T("��� �׸��� �Է����ּ���."),MB_OK | MB_ICONWARNING);
	}
	}
	else
	{
		AfxMessageBox(_T("�������� �������� �ʾҽ��ϴ�."),MB_OK | MB_ICONWARNING);
	}
}


void CExercise7_1Dlg::OnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(m_nSelectedItem>=0)
	{
		if(AfxMessageBox(_T("���� �����Ͻðڽ��ϱ�?"),MB_YESNO | MB_ICONQUESTION)==IDYES) {
		m_listControl.DeleteItem(m_nSelectedItem);
		m_strTitle.Empty();
		m_strYear.Empty();
		m_strGrade.Empty();
		
		UpdateData(false);
		}
	}
	else
	{
		MessageBox(_T("�������� �������� �ʾҽ��ϴ�."),MB_OK);
	}
}



void CExercise7_1Dlg::OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_hSelectedNode=pNMTreeView->itemNew.hItem;

	UpdateData(false);
	*pResult = 0;
}


void CExercise7_1Dlg::OnItemchangedListControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nSelectedItem=pNMLV->iItem;
	m_strCategory.Format(_T("%d"),m_nSelectedItem+1);

	m_strTitle=m_listControl.GetItemText(m_nSelectedItem,0);
	m_strYear=m_listControl.GetItemText(m_nSelectedItem,1);
	m_strGrade=m_listControl.GetItemText(m_nSelectedItem,2);

	UpdateData(false);
	
	*pResult = 0;
}
