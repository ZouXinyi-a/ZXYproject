
// MFC3.02��3��View.cpp : CMFC302��3��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.02��3��.h"
#endif

#include "MFC3.02��3��Doc.h"
#include "MFC3.02��3��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC302��3��View

IMPLEMENT_DYNCREATE(CMFC302��3��View, CView)

BEGIN_MESSAGE_MAP(CMFC302��3��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC302��3��View ����/����

CMFC302��3��View::CMFC302��3��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC302��3��View::~CMFC302��3��View()
{
}

BOOL CMFC302��3��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC302��3��View ����

void CMFC302��3��View::OnDraw(CDC* /*pDC*/)
{
	CMFC302��3��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC302��3��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC302��3��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC302��3��View ���

#ifdef _DEBUG
void CMFC302��3��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC302��3��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC302��3��Doc* CMFC302��3��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC302��3��Doc)));
	return (CMFC302��3��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC302��3��View ��Ϣ�������


void CMFC302��3��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cr;
	this->GetClientRect(&cr);
	//this->Invalidate();
	CClientDC dc(this);
	dc.Rectangle(cr);
	CView::OnLButtonDown(nFlags, point);
}
