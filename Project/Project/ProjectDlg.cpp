
// ProjectDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Project.h"
#include "ProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CProjectDlg 대화 상자




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


// CProjectDlg 메시지 처리기

BOOL CProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	LPWSTR list[6]={_T("날짜"),_T("내역"),_T("수입"),_T("지출"), _T("잔액"), _T("비고")};
	int nWidth[6]={150,250,150,150,150,300};
	
	for(int i=0; i<6; i++)
	{
		m_listAccount.InsertColumn(i,list[i],LVCFMT_CENTER,nWidth[i]);
	}

	m_listAccount.SetExtendedStyle(m_listAccount.GetExtendedStyle()| LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_hRoot=m_treeAccount.InsertItem(_T("연도"),TVI_ROOT,TVI_LAST);
	m_fYear=m_treeAccount.InsertItem(_T("2017"),m_hRoot,TVI_LAST);
	m_sYear=m_treeAccount.InsertItem(_T("2018"),m_hRoot,TVI_LAST);

	m_bChecked[0] = true;
	m_bChecked[1] = true;

	((CButton *)GetDlgItem(IDC_CHECK_INCOME))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_CHECK_EXPENSE))->SetCheck(1);

	UpdateData(true);
	m_strDate.Format(_T("%04d-%02d-%02d"), m_timeDate.GetYear(),m_timeDate.GetMonth(), m_timeDate.GetDay());

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

static int nCount=0;

void CProjectDlg::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_strDate.Format(_T("%04d-%02d-%02d"), m_timeDate.GetYear(),m_timeDate.GetMonth(), m_timeDate.GetDay());
	UpdateData(true);
	int in=0;

	if(m_hSelected!=m_hRoot)
	{
		if(m_nSelectedItem>=0)
		{
			if(AfxMessageBox(_T("정말 삭제하시겠습니까?"),MB_YESNO | MB_ICONQUESTION)==IDYES) {
				for (int i = 0; i < nCount; i++)
				{
					if(productData[i].strContent==m_listAccount.GetItemText(m_nSelectedItem,1))
					{
						in = i;
						break;
					}
				}

				// 삭제할 항목 구조체에서 정리
				for (int i = in; i <= nCount; i++)
				{
					// 삭제 되지 않은 항목 연속적으로 배열
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
						// 구조체 배열의 크기 감소
						nCount--;
					}

				}
				// 리스트에서 선택된 아이템 삭제
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
			MessageBox(_T("아이템을 선택하지 않았습니다."),MB_OK);
		}
	}
}


void CProjectDlg::OnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
			AfxMessageBox(_T("연도를 선택해주세요,"));
	}
	else
	{
		MessageBox(_T("모든 항목을 입력해 주세요"),MB_OK);
	}
}


void CProjectDlg::OnClickedButtonModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
				MessageBox(_T("모든 항목을 입력해 주세요."),MB_OK);
			}
		}
		else
		{
			MessageBox(_T("아이템을 선택하지 않았습니다."),MB_OK);
		}
	}
	else
			AfxMessageBox(_T("연도를 선택해주세요,"));

}


void CProjectDlg::OnClickedButtonSearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
		AfxMessageBox(_T("시작일이 더 큽니다."));
}


void CProjectDlg::OnItemchangedListAccount(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	 if(m_bChecked[0] == false) 
		 m_bChecked[0] = true;
	else m_bChecked[0] = false;

}


void CProjectDlg::OnClickedCheckExpense()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
