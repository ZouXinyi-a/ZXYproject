
// MFC3.10��3��View.cpp : CMFC310��3��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.10��3��.h"
#endif

#include "MFC3.10��3��Doc.h"
#include "MFC3.10��3��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC310��3��View

IMPLEMENT_DYNCREATE(CMFC310��3��View, CView)

BEGIN_MESSAGE_MAP(CMFC310��3��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC310��3��View ����/����

CMFC310��3��View::CMFC310��3��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC310��3��View::~CMFC310��3��View()
{
}

BOOL CMFC310��3��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC310��3��View ����

void CMFC310��3��View::OnDraw(CDC* pDC)
{

	CMFC310��3��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect_A(30,30,200,200);
	CRect rect_B(260,30,360,200);
	CRect rect_C(100,260,310,360);
	pDC->Rectangle(&rect_A);
	pDC->Rectangle(&rect_B);
	pDC->Rectangle(&rect_C);
	CString strA,strB,strC;
	strA=_T("A");
	strB=_T("B");
	strC=_T("C");
	pDC->TextOutW(30,30,strA);
	pDC->TextOutW(260,30,strB);
	pDC->TextOutW(110,260,strC);
	pDoc->A=rect_A;
	pDoc->B=rect_B;
	pDoc->C=rect_C;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC310��3��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC310��3��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC310��3��View ���

#ifdef _DEBUG
void CMFC310��3��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC310��3��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC310��3��Doc* CMFC310��3��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC310��3��Doc)));
	return (CMFC310��3��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC310��3��View ��Ϣ�������


void CMFC310��3��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFC310��3��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//�ھ���A����ʾ�����
	if((point.y>=pDoc->A.top)&&(point.y<=pDoc->A.bottom)
		&&(point.x>=pDoc->A.left)&&(point.x<=pDoc->A.right))
	{
		pDoc->a=rand()%100+1;
		CString str;
		str.Format(_T("%d"),pDoc->a);
		CClientDC dc(this);
		dc.TextOutW(point.x,point.y,str);
	}
	//�ھ���B����ʾ�����
	else if((point.y>=pDoc->B.top)&&(point.y<=pDoc->B.bottom)
		&&(point.x>=pDoc->B.left)&&(point.x<=pDoc->B.right))
	{
		pDoc->b=rand()%100+1;
		CString str;
		str.Format(_T("%d"),pDoc->b);
		CClientDC dc(this);
		dc.TextOutW(point.x,point.y,str);
	}
	//�ھ���C����ʾ�����
	else if((point.y>=pDoc->C.top)&&(point.y<=pDoc->C.bottom)
		&&(point.x>=pDoc->C.left)&&(point.x<=pDoc->C.right))
	{
		int a=pDoc->a+pDoc->b;
		CString str;
		str.Format(_T("%d"),a);
		CClientDC dc(this);
		dc.TextOutW(point.x,point.y,str);
	}
	else{
		CString str;
		str.Format(_T("�����Ч"));
		CClientDC dc(this);
		dc.TextOutW(point.x,point.y,str);
	}
	CView::OnLButtonDown(nFlags, point);
}
