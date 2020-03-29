
// Exp10View.cpp : CExp10View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exp10.h"
#endif

#include "Exp10Doc.h"
#include "Exp10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp10View

IMPLEMENT_DYNCREATE(CExp10View, CView)

BEGIN_MESSAGE_MAP(CExp10View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CExp10View ����/����

CExp10View::CExp10View()
{
	// TODO: �ڴ˴���ӹ������

}

CExp10View::~CExp10View()
{
}

BOOL CExp10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExp10View ����

void CExp10View::OnDraw(CDC* /*pDC*/)
{
	CExp10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CExp10View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp10View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExp10View ���

#ifdef _DEBUG
void CExp10View::AssertValid() const
{
	CView::AssertValid();
}

void CExp10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp10Doc* CExp10View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp10Doc)));
	return (CExp10Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp10View ��Ϣ�������


void CExp10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s;
	s.Format(_T("�����������"),point);
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	CView::OnLButtonDown(nFlags, point);
}


void CExp10View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s;
	s.Format(_T("�������̧��"),point);
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	CView::OnLButtonUp(nFlags, point);
}
