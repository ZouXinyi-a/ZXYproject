
// MFC3.24��3��View.cpp : CMFC324��3��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.24��3��.h"
#endif

#include "MFC3.24��3��Doc.h"
#include "MFC3.24��3��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC324��3��View

IMPLEMENT_DYNCREATE(CMFC324��3��View, CView)

BEGIN_MESSAGE_MAP(CMFC324��3��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOWLINE, &CMFC324��3��View::OnShowline)
	ON_COMMAND(ID_SHOWRECTANGLE, &CMFC324��3��View::OnShowrectangle)
	ON_COMMAND(ID_SHOWELLIPSE, &CMFC324��3��View::OnShowellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC324��3��View ����/����

CMFC324��3��View::CMFC324��3��View()
{
	// TODO: �ڴ˴���ӹ������
	
}

CMFC324��3��View::~CMFC324��3��View()
{
}

BOOL CMFC324��3��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC324��3��View ����

void CMFC324��3��View::OnDraw(CDC* /*pDC*/)
{
	CMFC324��3��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC324��3��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC324��3��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC324��3��View ���

#ifdef _DEBUG
void CMFC324��3��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC324��3��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC324��3��Doc* CMFC324��3��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC324��3��Doc)));
	return (CMFC324��3��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC324��3��View ��Ϣ�������

int set;
CRect cr;
void CMFC324��3��View::OnShowline()
{
	// TODO: �ڴ���������������
	CClientDC dc(this);
	set = 1;
	CPen pen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = dc.SelectObject(&pen);
}
CPoint point1,point2;

void CMFC324��3��View::OnShowrectangle()
{
	// TODO: �ڴ���������������

	set=2;
}


void CMFC324��3��View::OnShowellipse()
{
	// TODO: �ڴ���������������
	set=3;
}


void CMFC324��3��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	point1.x = point.x;
	point1.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC324��3��View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	point2.x = point.x;
	point2.y = point.y;
	switch (set) {
	case 1:
		dc.MoveTo(point2.x, point2.y);
		dc.LineTo(point1.x, point1.y);
		break;
	case 2:
		cr.left = point1.x;
		cr.top = point1.y;
		cr.right = point2.x;
		cr.bottom = point2.y;
		dc.Rectangle(cr);
		break;
	case 3:
		cr.left = point1.x;
		cr.top = point1.y;
		cr.right = point2.x;
		cr.bottom = point2.y;
		dc.Ellipse(cr);
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}
