
// MFC3.09��2��View.cpp : CMFC309��2��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.09��2��.h"
#endif

#include "MFC3.09��2��Doc.h"
#include "MFC3.09��2��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC309��2��View

IMPLEMENT_DYNCREATE(CMFC309��2��View, CView)

BEGIN_MESSAGE_MAP(CMFC309��2��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC309��2��View ����/����

CMFC309��2��View::CMFC309��2��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC309��2��View::~CMFC309��2��View()
{
}

BOOL CMFC309��2��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC309��2��View ����

void CMFC309��2��View::OnDraw(CDC* pDC)
{
	CMFC309��2��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for(int i=0;i<pDoc->ca.GetSize();i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
}

void CMFC309��2��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC309��2��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC309��2��View ���

#ifdef _DEBUG
void CMFC309��2��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC309��2��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC309��2��Doc* CMFC309��2��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC309��2��Doc)));
	return (CMFC309��2��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC309��2��View ��Ϣ�������


void CMFC309��2��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int r1=rand()%50+5;
	int r2=rand()%60+25;
	CRect cr(point.x-r1,point.y-r2,point.x+r1,point.y+r2);
	CMFC309��2��Doc* pDoc = GetDocument();
	pDoc->ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
