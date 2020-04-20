
// MFC3.02(1)View.cpp : CMFC3021View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.02(1).h"
#endif

#include "MFC3.02(1)Doc.h"
#include "MFC3.02(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3021View

IMPLEMENT_DYNCREATE(CMFC3021View, CView)

BEGIN_MESSAGE_MAP(CMFC3021View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3021View ����/����

CMFC3021View::CMFC3021View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC3021View::~CMFC3021View()
{
}

BOOL CMFC3021View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC3021View ����

void CMFC3021View::OnDraw(CDC* /*pDC*/)
{
	CMFC3021Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC3021View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3021View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3021View ���

#ifdef _DEBUG
void CMFC3021View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3021View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3021Doc* CMFC3021View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3021Doc)));
	return (CMFC3021Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3021View ��Ϣ�������


void CMFC3021View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int r=rand()%50+50;
	CRect cr(point.x-r,point.y-r,point.x+r,point.y+r);
	CClientDC dc(this);
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
