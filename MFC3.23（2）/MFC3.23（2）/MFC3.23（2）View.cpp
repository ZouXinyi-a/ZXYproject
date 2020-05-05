
// MFC3.23��2��View.cpp : CMFC323��2��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.23��2��.h"
#endif

#include "MFC3.23��2��Doc.h"
#include "MFC3.23��2��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC323��2��View

IMPLEMENT_DYNCREATE(CMFC323��2��View, CView)

BEGIN_MESSAGE_MAP(CMFC323��2��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_GradualColor, &CMFC323��2��View::OnGradualcolor)
END_MESSAGE_MAP()

// CMFC323��2��View ����/����

CMFC323��2��View::CMFC323��2��View()
{
	// TODO: �ڴ˴���ӹ������
	r=0;
	t=1;
	a=0;
	b=0;
	c=0;
}

CMFC323��2��View::~CMFC323��2��View()
{
}

BOOL CMFC323��2��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC323��2��View ����

void CMFC323��2��View::OnDraw(CDC* pDC)
{
	CMFC323��2��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr;
	this->GetClientRect(&cr);
	CPoint point;
	point.x=(cr.right-cr.left )/2;
	point.y=(cr.bottom-cr.top)/2;

	CRect rect1(point.x-r,point.y-r,point.x+r,point.y+r);
	rect=rect1;
	CPen pen;
	a=rand() % 255;
	b=rand() % 255;
	c=rand() % 255;
	pen.CreatePen(PS_SOLID,5,RGB(a,b,c));
	CPen* oldpen = pDC->SelectObject(&pen);
	pDC->Ellipse(rect);
	pen.DeleteObject();
}

void CMFC323��2��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC323��2��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC323��2��View ���

#ifdef _DEBUG
void CMFC323��2��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC323��2��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC323��2��Doc* CMFC323��2��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC323��2��Doc)));
	return (CMFC323��2��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC323��2��View ��Ϣ�������


void CMFC323��2��View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	r=t*10;
	t++;
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMFC323��2��View::OnGradualcolor()
{
	// TODO: �ڴ���������������
	SetTimer(0,100,NULL);
}
