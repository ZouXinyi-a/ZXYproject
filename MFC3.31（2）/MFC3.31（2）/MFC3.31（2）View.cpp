
// MFC3.31��2��View.cpp : CMFC331��2��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.31��2��.h"
#endif

#include "MFC3.31��2��Doc.h"
#include "MFC3.31��2��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC331��2��View

IMPLEMENT_DYNCREATE(CMFC331��2��View, CView)

BEGIN_MESSAGE_MAP(CMFC331��2��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFC331��2��View ����/����

CMFC331��2��View::CMFC331��2��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC331��2��View::~CMFC331��2��View()
{
}

BOOL CMFC331��2��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC331��2��View ����

void CMFC331��2��View::OnDraw(CDC* /*pDC*/)
{
	CMFC331��2��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC331��2��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC331��2��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC331��2��View ���

#ifdef _DEBUG
void CMFC331��2��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC331��2��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC331��2��Doc* CMFC331��2��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC331��2��Doc)));
	return (CMFC331��2��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC331��2��View ��Ϣ�������

void CMFC331��2��View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	str=str+(char)nChar;
	dc.TextOutW(point1.x,point1.y,str);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
void CMFC331��2��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point2);
	str.Empty();
	point1=point2;
	CView::OnLButtonDown(nFlags, point);
}



