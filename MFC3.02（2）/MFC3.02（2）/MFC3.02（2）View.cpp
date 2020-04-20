
// MFC3.02��2��View.cpp : CMFC302��2��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.02��2��.h"
#endif

#include "MFC3.02��2��Doc.h"
#include "MFC3.02��2��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC302��2��View

IMPLEMENT_DYNCREATE(CMFC302��2��View, CView)

BEGIN_MESSAGE_MAP(CMFC302��2��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC302��2��View ����/����

CMFC302��2��View::CMFC302��2��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC302��2��View::~CMFC302��2��View()
{
}

BOOL CMFC302��2��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC302��2��View ����

void CMFC302��2��View::OnDraw(CDC* /*pDC*/)
{
	CMFC302��2��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC302��2��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC302��2��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC302��2��View ���

#ifdef _DEBUG
void CMFC302��2��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC302��2��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC302��2��Doc* CMFC302��2��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC302��2��Doc)));
	return (CMFC302��2��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC302��2��View ��Ϣ�������
