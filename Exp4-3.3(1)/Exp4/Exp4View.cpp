
// Exp4View.cpp : CExp4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exp4.h"
#endif

#include "Exp4Doc.h"
#include "Exp4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp4View

IMPLEMENT_DYNCREATE(CExp4View, CView)

BEGIN_MESSAGE_MAP(CExp4View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp4View ����/����

CExp4View::CExp4View()
{
	// TODO: �ڴ˴���ӹ������

}

CExp4View::~CExp4View()
{
}

BOOL CExp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExp4View ����

void CExp4View::OnDraw(CDC* /*pDC*/)
{
	CExp4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CExp4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExp4View ���

#ifdef _DEBUG
void CExp4View::AssertValid() const
{
	CView::AssertValid();
}

void CExp4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp4Doc* CExp4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp4Doc)));
	return (CExp4Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp4View ��Ϣ�������


void CExp4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s,str;
	int a;
	a=2;
	s.Format(_T("����������"),point.x);
	str.Format(L"%d",a);
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	dc.TextOutW(100,300,str);
	CView::OnLButtonDown(nFlags, point);
}
