
// Exp8View.cpp : CExp8View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exp8.h"
#endif

#include "Exp8Doc.h"
#include "Exp8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp8View

IMPLEMENT_DYNCREATE(CExp8View, CView)

BEGIN_MESSAGE_MAP(CExp8View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp8View ����/����

CExp8View::CExp8View()
{
	// TODO: �ڴ˴���ӹ������
	
}

CExp8View::~CExp8View()
{
}

BOOL CExp8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExp8View ����

void CExp8View::OnDraw(CDC* pDC)
{
	CExp8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CExp8View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp8View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExp8View ���

#ifdef _DEBUG
void CExp8View::AssertValid() const
{
	CView::AssertValid();
}

void CExp8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp8Doc* CExp8View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp8Doc)));
	return (CExp8Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp8View ��Ϣ�������


void CExp8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CRect cr;
	this->GetClientRect(&cr);
	this->Invalidate();
	//CClientDC dc(this);
	//dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
