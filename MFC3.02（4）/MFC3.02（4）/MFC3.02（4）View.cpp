
// MFC3.02��4��View.cpp : CMFC302��4��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.02��4��.h"
#endif

#include "MFC3.02��4��Doc.h"
#include "MFC3.02��4��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC302��4��View

IMPLEMENT_DYNCREATE(CMFC302��4��View, CView)

BEGIN_MESSAGE_MAP(CMFC302��4��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC302��4��View ����/����

CMFC302��4��View::CMFC302��4��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC302��4��View::~CMFC302��4��View()
{
}

BOOL CMFC302��4��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC302��4��View ����

void CMFC302��4��View::OnDraw(CDC* pDC)
{
	CMFC302��4��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr;
	this->GetClientRect(cr);
	CBrush newbrush(RGB(100,0,0));
	CBrush *poldbrush;
	poldbrush=pDC->SelectObject(&newbrush);
	pDC->Ellipse(cr);
}

void CMFC302��4��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC302��4��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC302��4��View ���

#ifdef _DEBUG
void CMFC302��4��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC302��4��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC302��4��Doc* CMFC302��4��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC302��4��Doc)));
	return (CMFC302��4��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC302��4��View ��Ϣ�������


void CMFC302��4��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
}
