
// MFC4.13(1)View.cpp : CMFC4131View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.13(1).h"
#endif

#include "MFC4.13(1)Doc.h"
#include "MFC4.13(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4131View

IMPLEMENT_DYNCREATE(CMFC4131View, CView)

BEGIN_MESSAGE_MAP(CMFC4131View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC4131View ����/����

CMFC4131View::CMFC4131View()
{
	// TODO: �ڴ˴���ӹ������
	m_bl=true;
}

CMFC4131View::~CMFC4131View()
{
}

BOOL CMFC4131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC4131View ����

void CMFC4131View::OnDraw(CDC* pDC)
{
	CMFC4131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//CBrush brush(RGB(114,200,134));
	//pDC->FillRect(&r,&brush);
	pDC->Rectangle(&pDoc->rect);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

}

void CMFC4131View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4131View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4131View ���

#ifdef _DEBUG
void CMFC4131View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4131Doc* CMFC4131View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4131Doc)));
	return (CMFC4131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4131View ��Ϣ�������


void CMFC4131View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bl=true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC4131View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bl=false;
	CView::OnLButtonUp(nFlags, point);
}


void CMFC4131View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		CMFC4131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (m_bl) {
		pDoc->rect.top = point.y - 100;
		pDoc->rect.left = point.x - 200;
		pDoc->rect.bottom = point.y + 100;
		pDoc->rect.right = point.x + 200;

		CClientDC dc(this);
		dc.Rectangle(&pDoc->rect);
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
