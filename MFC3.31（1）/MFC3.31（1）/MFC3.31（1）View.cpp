
// MFC3.31��1��View.cpp : CMFC331��1��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.31��1��.h"
#endif

#include "MFC3.31��1��Doc.h"
#include "MFC3.31��1��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC331��1��View

IMPLEMENT_DYNCREATE(CMFC331��1��View, CView)

BEGIN_MESSAGE_MAP(CMFC331��1��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFC331��1��View ����/����

CMFC331��1��View::CMFC331��1��View()
{
	// TODO: �ڴ˴���ӹ������
	s="";
}

CMFC331��1��View::~CMFC331��1��View()
{
}

BOOL CMFC331��1��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC331��1��View ����

void CMFC331��1��View::OnDraw(CDC* pDC)
{
	CMFC331��1��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->cr);
}

void CMFC331��1��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC331��1��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC331��1��View ���

#ifdef _DEBUG
void CMFC331��1��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC331��1��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC331��1��Doc* CMFC331��1��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC331��1��Doc)));
	return (CMFC331��1��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC331��1��View ��Ϣ�������


void CMFC331��1��View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC331��1��Doc* pDoc = GetDocument();
	CClientDC dc(this);
	s = s + (char) nChar;
	dc.TextOutW(pDoc->cr.left+10, pDoc->cr.top+10, s);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
