
// Exercise7_1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Exercise7_1.h"
#include "Exercise7_1Dlg.h"
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


// CExercise7_1Dlg 대화 상자




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


// CExercise7_1Dlg 메시지 처리기

BOOL CExercise7_1Dlg::OnInitDialog()
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
	m_hRoot=m_treeControl.InsertItem(_T("영상물"),TVI_ROOT,TVI_LAST);
	m_hMovie=m_treeControl.InsertItem(_T("영화"),m_hRoot,TVI_LAST);
	m_hDrama=m_treeControl.InsertItem(_T("드라마"),m_hRoot,TVI_LAST);

	LPWSTR list[3]={_T("제품명"),_T("제작년도"),_T("등급")};
	int nWidth[3]={140,120,123};
	
	for(int i=0; i<3; i++)
	{
		m_listControl.InsertColumn(i,list[i],LVCFMT_CENTER,nWidth[i]);
	}

	m_listControl.SetExtendedStyle(m_listControl.GetExtendedStyle()| LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CExercise7_1Dlg::OnPaint()
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
HCURSOR CExercise7_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise7_1Dlg::OnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
					AfxMessageBox(_T("중복된 작품이 있습니다."),MB_OK | MB_ICONWARNING);
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
					AfxMessageBox(_T("중복된 작품이 있습니다."),MB_OK | MB_ICONWARNING);
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
			AfxMessageBox(_T("작품 장르를 선택해 주세요."),MB_OK|MB_ICONWARNING);
		}
	}
	else
	{
		AfxMessageBox(_T("모든 항목을 입력해주세요."),MB_OK | MB_ICONWARNING);
	}
}


void CExercise7_1Dlg::OnClickedButtonModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
					AfxMessageBox(_T("중복된 작품이 있습니다."),MB_OK | MB_ICONWARNING);
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
					AfxMessageBox(_T("중복된 작품이 있습니다."),MB_OK | MB_ICONWARNING);
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
			AfxMessageBox(_T("작품 장르를 선택해 주세요."),MB_OK|MB_ICONWARNING);
		}
		}
		else
			{
		AfxMessageBox(_T("모든 항목을 입력해주세요."),MB_OK | MB_ICONWARNING);
	}
	}
	else
	{
		AfxMessageBox(_T("아이템을 선택하지 않았습니다."),MB_OK | MB_ICONWARNING);
	}
}


void CExercise7_1Dlg::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_nSelectedItem>=0)
	{
		if(AfxMessageBox(_T("정말 삭제하시겠습니까?"),MB_YESNO | MB_ICONQUESTION)==IDYES) {
		m_listControl.DeleteItem(m_nSelectedItem);
		m_strTitle.Empty();
		m_strYear.Empty();
		m_strGrade.Empty();
		
		UpdateData(false);
		}
	}
	else
	{
		MessageBox(_T("아이템을 선택하지 않았습니다."),MB_OK);
	}
}



void CExercise7_1Dlg::OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_hSelectedNode=pNMTreeView->itemNew.hItem;

	UpdateData(false);
	*pResult = 0;
}


void CExercise7_1Dlg::OnItemchangedListControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem=pNMLV->iItem;
	m_strCategory.Format(_T("%d"),m_nSelectedItem+1);

	m_strTitle=m_listControl.GetItemText(m_nSelectedItem,0);
	m_strYear=m_listControl.GetItemText(m_nSelectedItem,1);
	m_strGrade=m_listControl.GetItemText(m_nSelectedItem,2);

	UpdateData(false);
	
	*pResult = 0;
}
