
// ProjectDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Project.h"
#include "ProjectDlg.h"
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


// CProjectDlg ��ȭ ����




CProjectDlg::CProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProjectDlg::IDD, pParent)
	, m_nSelectedItem(0)
	, m_strBalance(_T(""))
	, m_strSelected(_T(""))
	, m_strItemText(_T(""))
	, m_strDate(_T(""))
	, m_nTotalInSum(0)
	, m_nTotalExSum(0)
	, nIndex(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strNote = _T("");
	m_strIncome = _T("");
	m_strExpen = _T("");
	m_strContent = _T("");
	m_strDate = _T("");
	m_timeDate = COleDateTime::GetCurrentTime();
	m_timeFirst = COleDateTime::GetCurrentTime();
	m_timeSecond = COleDateTime::GetCurrentTime();
}

void CProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_listAccount);
	DDX_Control(pDX, IDC_TREE_ACCOUNT, m_treeAccount);
	DDX_Text(pDX, IDC_EDIT_NOTE, m_strNote);
	DDX_Text(pDX, IDC_EDIT_INCOME, m_strIncome);
	DDX_Text(pDX, IDC_EDIT_EXPENDITURE, m_strExpen);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_strContent);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_timeDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_FIRST, m_timeFirst);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_SECOND, m_timeSecond);
}

BEGIN_MESSAGE_MAP(CProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CUSTOMDRAW,IDC_LIST_ACCOUNT,OnCustomdrawList)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CProjectDlg::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CProjectDlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CProjectDlg::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CProjectDlg::OnClickedButtonSearch)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ACCOUNT, &CProjectDlg::OnItemchangedListAccount)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_ACCOUNT, &CProjectDlg::OnSelchangedTreeAccount)
	ON_BN_CLICKED(IDC_CHECK_INCOME, &CProjectDlg::OnClickedCheckIncome)
	ON_BN_CLICKED(IDC_CHECK_EXPENSE, &CProjectDlg::OnClickedCheckExpense)
END_MESSAGE_MAP()


// CProjectDlg �޽��� ó����

BOOL CProjectDlg::OnInitDialog()
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
	LPWSTR list[6]={_T("��¥"),_T("����"),_T("����"),_T("����"), _T("�ܾ�"), _T("���")};
	int nWidth[6]={150,250,150,150,150,300};
	
	for(int i=0; i<6; i++)
	{
		m_listAccount.InsertColumn(i,list[i],LVCFMT_CENTER,nWidth[i]);
	}

	m_listAccount.SetExtendedStyle(m_listAccount.GetExtendedStyle()| LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_hRoot=m_treeAccount.InsertItem(_T("����"),TVI_ROOT,TVI_LAST);
	m_fYear=m_treeAccount.InsertItem(_T("2017"),m_hRoot,TVI_LAST);
	m_sYear=m_treeAccount.InsertItem(_T("2018"),m_hRoot,TVI_LAST);

	m_bChecked[0] = true;
	m_bChecked[1] = true;

	((CButton *)GetDlgItem(IDC_CHECK_INCOME))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_CHECK_EXPENSE))->SetCheck(1);

	UpdateData(true);
	m_strDate.Format(_T("%04d-%02d-%02d"), m_timeDate.GetYear(),m_timeDate.GetMonth(), m_timeDate.GetDay());

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProjectDlg::OnPaint()
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
HCURSOR CProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

static int nCount=0;

void CProjectDlg::OnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strDate.Format(_T("%04d-%02d-%02d"), m_timeDate.GetYear(),m_timeDate.GetMonth(), m_timeDate.GetDay());
	UpdateData(true);
	int in=0;

	if(m_hSelected!=m_hRoot)
	{
		if(m_nSelectedItem>=0)
		{
			if(AfxMessageBox(_T("���� �����Ͻðڽ��ϱ�?"),MB_YESNO | MB_ICONQUESTION)==IDYES) {
				for (int i = 0; i < nCount; i++)
				{
					if(productData[i].strContent==m_listAccount.GetItemText(m_nSelectedItem,1))
					{
						in = i;
						break;
					}
				}

				// ������ �׸� ����ü���� ����
				for (int i = in; i <= nCount; i++)
				{
					// ���� ���� ���� �׸� ���������� �迭
					if (i < nCount)
					{
						productData[i - 1].strCategory = productData[i].strCategory;
						productData[i - 1].strDate = productData[i].strDate;
						productData[i - 1].strContent = productData[i].strContent;
						productData[i - 1].strIncome = productData[i].strIncome;
						productData[i - 1].strExpense = productData[i].strExpense;
						productData[i - 1].strNote = productData[i].strNote;
					}
					else
					{
						// ����ü �迭�� ũ�� ����
						nCount--;
					}

				}
				// ����Ʈ���� ���õ� ������ ����
				m_listAccount.DeleteItem(m_nSelectedItem);
				RemainMoney2();

				for(int i=in; i<=nCount;i++)
				{
					if(i<nCount)
					{
						productData[i - 1].strBalance = productData[i].strBalance;
					}
					else
						nCount--;
				}
				UpdateData(false);
			}
		}
		else
		{
			MessageBox(_T("�������� �������� �ʾҽ��ϴ�."),MB_OK);
		}
	}
}


void CProjectDlg::OnClickedButtonInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int n=m_listAccount.GetItemCount();

	UpdateData(true);
	m_strDate.Format(_T("%04d-%02d-%02d"), m_timeDate.GetYear(),m_timeDate.GetMonth(), m_timeDate.GetDay());

	if(!m_strDate.IsEmpty() && !m_strContent.IsEmpty() && (!m_strIncome.IsEmpty() || !m_strExpen.IsEmpty()))
	{
		if(m_hSelected!=m_hRoot) 
		{
			m_listAccount.InsertItem(n,m_strDate);
			m_listAccount.SetItem(n,1,LVIF_TEXT, m_strContent,0,0,0,0);
			m_listAccount.SetItem(n,2,LVIF_TEXT, m_strIncome,0,0,0,0);
			m_listAccount.SetItem(n,3,LVIF_TEXT, m_strExpen,0,0,0,0);
			m_listAccount.SetItem(n,5,LVIF_TEXT, m_strNote,0,0,0,0);
		
			RemainMoney2();

			productData[nCount].strCategory = m_treeAccount.GetItemText(m_hSelected);
			productData[nCount].strDate=m_strDate;
			productData[nCount].strContent=m_strContent;
			productData[nCount].strIncome=m_strIncome;
			productData[nCount].strExpense=m_strExpen;
			productData[nCount].strBalance=m_strBalance;
			productData[nCount].strNote=m_strNote;

			m_strDate.Empty();
			m_strContent.Empty();
			m_strIncome.Empty();
			m_strExpen.Empty();
			m_strNote.Empty();

			((CButton*) GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
			((CButton*) GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

			UpdateData(false);
			nCount++;
		}
		else
			AfxMessageBox(_T("������ �������ּ���,"));
	}
	else
	{
		MessageBox(_T("��� �׸��� �Է��� �ּ���"),MB_OK);
	}
}


void CProjectDlg::OnClickedButtonModify()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);

	CString strIndex, strDate, strContent, strIncome, strExpen,strNote;
	m_strDate.Format(_T("%04d-%02d-%02d"), m_timeDate.GetYear(),m_timeDate.GetMonth(), m_timeDate.GetDay());
	int in=0;

	strContent=m_strContent;
	strDate=m_strDate;
	strIncome=m_strIncome;
	strExpen=m_strExpen;
	strNote=m_strNote;

	if(m_hSelected!=m_hRoot)
	{
		if(m_nSelectedItem>=0)
		{
			if(!m_strDate.IsEmpty() && !m_strContent.IsEmpty() && (!m_strIncome.IsEmpty() || !m_strExpen.IsEmpty()))
			{
				for(int i=0; i<nCount; i++)
				{
					if(productData[i].strContent==m_strContent)
					{
						in=i;
						break;
					}
				}
				
				productData[in].strDate=m_strDate;
				productData[in].strContent=m_strContent;
				productData[in].strIncome=m_strIncome;
				productData[in].strExpense=m_strExpen;
				productData[in].strNote=m_strNote;
				productData[in].strCategory = m_treeAccount.GetItemText(m_hSelected);
				
				m_listAccount.SetItem(m_nSelectedItem,0,LVIF_TEXT,strDate,0,0,0,0);
				m_listAccount.SetItem(m_nSelectedItem,1,LVIF_TEXT,strContent,0,0,0,0);
				m_listAccount.SetItem(m_nSelectedItem,2,LVIF_TEXT,strIncome,0,0,0,0);
				m_listAccount.SetItem(m_nSelectedItem,3,LVIF_TEXT,strExpen,0,0,0,0);
				m_listAccount.SetItem(m_nSelectedItem,5,LVIF_TEXT,strNote,0,0,0,0);
		
				//m_strDate.Empty();
				m_strContent.Empty();
				m_strIncome.Empty();
				m_strExpen.Empty();
				m_strNote.Empty();

				((CButton*) GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
				((CButton*) GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

				RemainMoney2();
				productData[in].strBalance=m_strBalance;

				UpdateData(false);
			}
			else
			{
				MessageBox(_T("��� �׸��� �Է��� �ּ���."),MB_OK);
			}
		}
		else
		{
			MessageBox(_T("�������� �������� �ʾҽ��ϴ�."),MB_OK);
		}
	}
	else
			AfxMessageBox(_T("������ �������ּ���,"));

}


void CProjectDlg::OnClickedButtonSearch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);

	int index=-1;
	nIndex=index;
	
	if(m_timeFirst<=m_timeSecond)
	{
		for(int i=0; i<m_listAccount.GetItemCount(); i++)
		{
			CString str=m_listAccount.GetItemText(i,0);
			m_timeDate.ParseDateTime(str);
			
			if(m_timeFirst-COleDateTimeSpan(1)<=m_timeDate && m_timeDate<=m_timeSecond)
			{
				index=i;
				m_listAccount.SetSelectionMark(index);
				m_listAccount.SetItemState(index,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
				m_listAccount.EnsureVisible(index,true);
				m_listAccount.SetFocus();
			}
			else
			{
				index=-1;
			}
			
			UpdateData(false);
		}
	}
	else
		AfxMessageBox(_T("�������� �� Ů�ϴ�."));
}


void CProjectDlg::OnItemchangedListAccount(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nSelectedItem=pNMLV->iItem;
	
	m_strDate=m_listAccount.GetItemText(m_nSelectedItem,0);
	m_timeDate.ParseDateTime(m_strDate);
	m_strContent=m_listAccount.GetItemText(m_nSelectedItem,1);
	m_strIncome=m_listAccount.GetItemText(m_nSelectedItem,2);
	m_strExpen=m_listAccount.GetItemText(m_nSelectedItem,3);
	m_strNote=m_listAccount.GetItemText(m_nSelectedItem,5);

	((CButton*) GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(true);
	((CButton*) GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(true);

	UpdateData(false);


	*pResult = 0;
}

void CProjectDlg::OnSelchangedTreeAccount(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CTreeCtrl* pTree = (CTreeCtrl*) GetDlgItem(IDC_TREE_ACCOUNT);
	int nCount_search=0;
	m_listAccount.DeleteAllItems();

	m_hSelected = pNMTreeView->itemNew.hItem;
	
	if(m_hSelected==m_fYear)
	{
		for(int i=0; i<nCount; i++)
		{
			if(productData[i].strCategory == m_treeAccount.GetItemText(m_fYear))
			{
				m_listAccount.InsertItem(nCount_search,productData[i].strDate);
				m_listAccount.SetItem(nCount_search,1,LVIF_TEXT,productData[i].strContent,0,0,0,0);
				m_listAccount.SetItem(nCount_search,2,LVIF_TEXT,productData[i].strIncome,0,0,0,0);
				m_listAccount.SetItem(nCount_search,3,LVIF_TEXT,productData[i].strExpense,0,0,0,0);
				m_listAccount.SetItem(nCount_search,4,LVIF_TEXT,productData[i].strBalance,0,0,0,0);
				m_listAccount.SetItem(nCount_search,5,LVIF_TEXT,productData[i].strNote,0,0,0,0);
				nCount_search++;
			}
		}
	}
	else if(m_hSelected==m_sYear)
	{
		for(int i=0; i<nCount; i++)
		{
			if(productData[i].strCategory == m_treeAccount.GetItemText(m_sYear)) 
			{
				m_hChildItem=pTree->GetChildItem(m_hSelected);
				m_strSelected=pTree->GetItemText(m_hChildItem);
				
				m_listAccount.InsertItem(nCount_search,productData[i].strDate);
				m_listAccount.SetItem(nCount_search,1,LVIF_TEXT,productData[i].strContent,0,0,0,0);
				m_listAccount.SetItem(nCount_search,2,LVIF_TEXT,productData[i].strIncome,0,0,0,0);
				m_listAccount.SetItem(nCount_search,3,LVIF_TEXT,productData[i].strExpense,0,0,0,0);
				m_listAccount.SetItem(nCount_search,4,LVIF_TEXT,productData[i].strBalance,0,0,0,0);
				m_listAccount.SetItem(nCount_search,5,LVIF_TEXT,productData[i].strNote,0,0,0,0);
				nCount_search++;
			}
		}
	}

	*pResult = 0;
}


void CProjectDlg::OnClickedCheckIncome()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	 if(m_bChecked[0] == false) 
		 m_bChecked[0] = true;
	else m_bChecked[0] = false;

}


void CProjectDlg::OnClickedCheckExpense()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(m_bChecked[1] == false)
		m_bChecked[1] = true;
	else m_bChecked[1] = false;
}

void CProjectDlg::OnCustomdrawList(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLVCUSTOMDRAW* pLVCD=reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);

	if(pLVCD->nmcd.dwDrawStage==CDDS_PREPAINT)
	{
		*pResult=CDRF_NOTIFYITEMDRAW;
		return;
	}
	else if(pLVCD->nmcd.dwDrawStage==CDDS_ITEMPREPAINT)
	{
		*pResult=CDRF_NOTIFYSUBITEMDRAW;
		return;
		
	}
	else if(pLVCD->nmcd.dwDrawStage==CDDS_ITEMPREPAINT|CDDS_SUBITEM)
	{
		int nSubItem=pLVCD->iSubItem;
		int nRowItem=pLVCD->nmcd.dwItemSpec;
		
		if(pLVCD->iSubItem==2) {
			if(m_bChecked[0]==false)
			{
				pLVCD->clrTextBk=RGB(255,255,255);
				pLVCD->clrText=RGB(0,0,0);
			}
			else {
				pLVCD->clrTextBk=RGB(255,192,203);
				pLVCD->clrText=RGB(0,0,0);
			}
		}
		else if(pLVCD->iSubItem==3) {
			if(m_bChecked[1]==false)
			{
				pLVCD->clrTextBk=RGB(255,255,255);
				pLVCD->clrText=RGB(0,0,0);
			}
			else{ 
				pLVCD->clrText=RGB(0,0,0);
				pLVCD->clrTextBk=RGB(152,251,152);
			}
		}
		else{
			pLVCD->clrTextBk=RGB(255,255,255);
			pLVCD->clrText=RGB(0,0,0);
		}
		*pResult=CDRF_NEWFONT;
		return;
	}
	*pResult=0;
}

void CProjectDlg::RemainMoney2(void)
{
	int RemainMoney = 0;
	m_nTotalInSum = 0;
	m_nTotalExSum = 0;


	for(int i=0; i<m_listAccount.GetItemCount(); i++)
	{
		CString str1 = m_listAccount.GetItemText(i, 2);
		m_nTotalInSum += _ttoi(str1);
		CString str2 = m_listAccount.GetItemText(i, 3);
		m_nTotalExSum += _ttoi(str2);
		RemainMoney = m_nTotalInSum - m_nTotalExSum;
		m_strBalance.Format(_T("%d"), RemainMoney);
		m_listAccount.SetItem(i,4,LVIF_TEXT, m_strBalance,0,0,0,0);
	}
}
