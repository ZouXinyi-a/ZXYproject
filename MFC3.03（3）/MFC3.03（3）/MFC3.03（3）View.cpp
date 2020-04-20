
// MFC3.03��3��View.cpp : CMFC303��3��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.03��3��.h"
#endif

#include "MFC3.03��3��Doc.h"
#include "MFC3.03��3��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC303��3��View

IMPLEMENT_DYNCREATE(CMFC303��3��View, CView)

BEGIN_MESSAGE_MAP(CMFC303��3��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC303��3��View ����/����

CMFC303��3��View::CMFC303��3��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC303��3��View::~CMFC303��3��View()
{
}

BOOL CMFC303��3��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC303��3��View ����

void CMFC303��3��View::OnDraw(CDC* /*pDC*/)
{
	CMFC303��3��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC303��3��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC303��3��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC303��3��View ���

#ifdef _DEBUG
void CMFC303��3��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC303��3��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC303��3��Doc* CMFC303��3��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC303��3��Doc)));
	return (CMFC303��3��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC303��3��View ��Ϣ�������


void CMFC303��3��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC303��3��Doc* pDoc = GetDocument();//�ĵ���ָ��
	ASSERT_VALID(pDoc);
	if(!pDoc)
		return;
	CString t;
	t.Format(_T("���λ���ǣ�%d,%d��"),point.x,point.y);

	CClientDC dc(this);
	dc.TextOutW(100,200,t);
	++pDoc->count;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC303��3��View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC303��3��Doc* pDoc = GetDocument();//�ĵ���ָ��
	ASSERT_VALID(pDoc);
	if(!pDoc)
		return;
	
	CString s;
	int a=pDoc->count;
	s.Format(_T("�������������Ϊ��count=%d"),a);
	CClientDC dc(this);
	dc.TextOutW(100,300,s);
	CView::OnRButtonDown(nFlags, point);
}
