
// Exp5View.cpp : CExp5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Exp5.h"
#endif

#include "Exp5Doc.h"
#include "Exp5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp5View

IMPLEMENT_DYNCREATE(CExp5View, CView)

BEGIN_MESSAGE_MAP(CExp5View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CExp5View ����/����

CExp5View::CExp5View()
{
	// TODO: �ڴ˴���ӹ������

}

CExp5View::~CExp5View()
{
}

BOOL CExp5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExp5View ����

void CExp5View::OnDraw(CDC* pDC)
{
	CExp5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString str;
	str.Format(L"%d",pDoc->A);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->TextOutW(200,300,pDoc->S);
	pDC->TextOutW(100,300,str);
}

void CExp5View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp5View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExp5View ���

#ifdef _DEBUG
void CExp5View::AssertValid() const
{
	CView::AssertValid();
}

void CExp5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp5Doc* CExp5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp5Doc)));
	return (CExp5Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp5View ��Ϣ�������
