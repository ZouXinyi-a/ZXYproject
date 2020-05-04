
// MFC3.17(1)View.cpp : CMFC3171View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.17(1).h"
#endif

#include "MFC3.17(1)Doc.h"
#include "MFC3.17(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3171View

IMPLEMENT_DYNCREATE(CMFC3171View, CView)

BEGIN_MESSAGE_MAP(CMFC3171View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC3171View ����/����

CMFC3171View::CMFC3171View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC3171View::~CMFC3171View()
{
}

BOOL CMFC3171View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC3171View ����

void CMFC3171View::OnDraw(CDC* /*pDC*/)
{
	CMFC3171Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC3171View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3171View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3171View ���

#ifdef _DEBUG
void CMFC3171View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3171View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3171Doc* CMFC3171View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3171Doc)));
	return (CMFC3171Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3171View ��Ϣ�������


void CMFC3171View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC3171Doc* pDoc = GetDocument();
	pDoc->m_point=point;
	InvalidateRect(NULL,FALSE);
	pDoc->i++;
	CView::OnMouseMove(nFlags, point);
}


void CMFC3171View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC3171Doc* pDoc = GetDocument();
	pDoc->a=point.x;
	pDoc->judge=true;
	pDoc->i=0;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC3171View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	CMFC3171Doc* pDoc = GetDocument();
	pDoc->b=point.x;
	if(pDoc->judge){
	
	str.Format(_T("MouseMove����%d��,�����ƶ�%d�����ط���һ��"),pDoc->i,pDoc->b-pDoc->a);
	}
	CClientDC dc(this);
	dc.TextOutW(30,30,str);
	CView::OnLButtonUp(nFlags, point);
}
