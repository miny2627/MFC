
// Exercise12_1View.cpp : CExercise12_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Exercise12_1.h"
#endif

#include "Exercise12_1Doc.h"
#include "Exercise12_1View.h"
#include "PRODUCT.h"
#include "ORDERLIST.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise12_1View

IMPLEMENT_DYNCREATE(CExercise12_1View, CFormView)

BEGIN_MESSAGE_MAP(CExercise12_1View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CExercise12_1View::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CExercise12_1View::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CExercise12_1View::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CExercise12_1View::OnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_CALC, &CExercise12_1View::OnClickedButtonCalc)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ORDER, &CExercise12_1View::OnItemchangedListOrder)
END_MESSAGE_MAP()

// CExercise12_1View 생성/소멸

CExercise12_1View::CExercise12_1View()
	: CFormView(CExercise12_1View::IDD)
	, m_strDate(_T(""))
	, m_nSelectedItem(0)
	, m_strSelected(_T(""))
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_strNumber = _T("");
	m_strSum = _T("");
	m_timeDate = COleDateTime::GetCurrentTime();
}

CExercise12_1View::~CExercise12_1View()
{
}

void CExercise12_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ORDER, m_listOrder);
	DDX_Text(pDX, IDC_EDIT_NUMBER, m_strNumber);
	DDX_Text(pDX, IDC_EDIT_SUM, m_strSum);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_timeDate);
	DDX_Control(pDX, IDC_COMBO_CODE, m_comboCode);
}

BOOL CExercise12_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CExercise12_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	LPWSTR list[5]={_T("코드번호"),_T("품목"),_T("수량"),_T("단가"),_T("요청기한")};
	int nWidth[5]={100,150,119,119,150};
	
	for(int i=0; i<5; i++)
	{
		m_listOrder.InsertColumn(i,list[i],LVCFMT_CENTER,nWidth[i]);
	}

	m_listOrder.SetExtendedStyle(m_listOrder.GetExtendedStyle()| LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

}

void CExercise12_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExercise12_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExercise12_1View 진단

#ifdef _DEBUG
void CExercise12_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CExercise12_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CExercise12_1Doc* CExercise12_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExercise12_1Doc)));
	return (CExercise12_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExercise12_1View 메시지 처리기


void CExercise12_1View::OnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);

	CPRODUCT<CPRODUCTModeAccessor> productData;
	CORDERLIST<CORDERLISTModeAccessor> orderData;

	int nCount=0;
	int index=0;
	index=m_comboCode.GetCurSel();
	productData.m_ID=index+1;

	m_strDate.Format(_T("%04d-%02d-%02d"),m_timeDate.GetYear(), m_timeDate.GetMonth(), m_timeDate.GetDay());

	if(productData.OpenAll()==S_OK)
	{
		if(index!=CB_ERR)
		{
			while((productData.MoveLast() | productData.MoveFirst() | productData.MoveNext() | productData.MovePrev() )==S_OK)
			{
				if(!m_strNumber.IsEmpty())
				{
					m_listOrder.InsertItem(nCount,productData.m_Code);
				
					m_listOrder.SetItem(nCount,1,LVIF_TEXT,productData.m_NProduct,0,0,0,0);
					m_listOrder.SetItem(nCount,2,LVIF_TEXT,m_strNumber,0,0,0,0);
					m_listOrder.SetItem(nCount,3,LVIF_TEXT,productData.m_Price,0,0,0,0);
					m_listOrder.SetItem(nCount,4,LVIF_TEXT,m_strDate,0,0,0,0);
					++nCount;
					orderData.Insert();

					m_strNumber.Empty();
					m_strDate.Empty();

					UpdateData(false);
				}
				else{
					AfxMessageBox(_T("구매 수량을 입력해 주세요."),MB_OK);
					break;
				}
			}
		}
			else
				AfxMessageBox(_T("코드 번호를 선택하지 않았습니다."),MB_OK);
		}
	else
		AfxMessageBox(_T("데이터베이스 접속 실패"));
}


void CExercise12_1View::OnClickedButtonModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);

	CString strNumber;
	strNumber=m_strNumber;

	if(m_nSelectedItem>=0)
	{
		if(!m_strNumber.IsEmpty())
		{
			AfxMessageBox(_T("수정되었습니다."),MB_OK);

			m_listOrder.SetItem(m_nSelectedItem,2,LVIF_TEXT,strNumber,0,0,0,0);
			m_strNumber.Empty();
			
			UpdateData(false);
		}
		else
			AfxMessageBox(_T("구매 수량을 입력해 주세요."),MB_OK);
	}
	else
	{
		AfxMessageBox(_T("아이템을 선택하지 않았습니다."),MB_OK);
	}

}


void CExercise12_1View::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	if(m_nSelectedItem>=0)
	{
		AfxMessageBox(_T("삭제되었습니다."),MB_OK);
		m_listOrder.DeleteItem(m_nSelectedItem);
		m_strNumber.Empty();

		UpdateData(false);
	}
	else
	{
		MessageBox(_T("아이템을 선택하지 않았습니다."),MB_OK);
	}
}


void CExercise12_1View::OnClickedButtonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_listOrder.DeleteAllItems();
}


void CExercise12_1View::OnClickedButtonCalc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	int sum=0; 
	for(int i=0; i<m_listOrder.GetItemCount(); i++)
	{
		CString p = m_listOrder.GetItemText(i, 3);
		CString num=m_listOrder.GetItemText(i,2);
		int price=_ttoi(p);
		int n=_ttoi(num);
		sum+=n*price;
	}
	m_strSum.Format(_T("%d"),sum);
	UpdateData(false);
}


void CExercise12_1View::OnItemchangedListOrder(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem=pNMLV->iItem;
	
	m_strNumber=m_listOrder.GetItemText(m_nSelectedItem,2);

	UpdateData(false);

	*pResult = 0;
}
