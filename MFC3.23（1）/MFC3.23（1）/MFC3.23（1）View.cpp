
// MFC3.23��1��View.cpp : CMFC323��1��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.23��1��.h"
#endif

#include "MFC3.23��1��Doc.h"
#include "MFC3.23��1��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC323��1��View

IMPLEMENT_DYNCREATE(CMFC323��1��View, CView)

BEGIN_MESSAGE_MAP(CMFC323��1��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_GradualCircle, &CMFC323��1��View::OnGradualcircle)
	ON_COMMAND(ID_GradualColor, &CMFC323��1��View::OnGradualcolor)
END_MESSAGE_MAP()

// CMFC323��1��View ����/����

CMFC323��1��View::CMFC323��1��View()
{
	// TODO: �ڴ˴���ӹ������
	r=0;
	t=1;
	
}

CMFC323��1��View::~CMFC323��1��View()
{
}

BOOL CMFC323��1��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC323��1��View ����

void CMFC323��1��View::OnDraw(CDC* pDC)
{
	CMFC323��1��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	this->GetClientRect(&rect);

	point.x=(rect.right-rect.left )/2;
	point.y=(rect.bottom-rect.top)/2;

	CRect rect1(point.x-r,point.y-r,point.x+r,point.y+r);
	rect=rect1;

	pDC->Ellipse(rect);

}

void CMFC323��1��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC323��1��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC323��1��View ���

#ifdef _DEBUG
void CMFC323��1��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC323��1��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC323��1��Doc* CMFC323��1��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC323��1��Doc)));
	return (CMFC323��1��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC323��1��View ��Ϣ�������

void CMFC323��1��View::OnGradualcircle()
{
	// TODO: �ڴ���������������
	SetTimer(0,100,NULL);
}
void CMFC323��1��View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	r=t*10;
	t++;
	Invalidate();
	CView::OnTimer(nIDEvent);
}





void CMFC323��1��View::OnGradualcolor()
{
	// TODO: �ڴ���������������
}
