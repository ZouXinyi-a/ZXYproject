
// MFC1-3.24View.cpp : CMFC1324View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC1-3.24.h"
#endif

#include "MFC1-3.24Doc.h"
#include "MFC1-3.24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC1324View

IMPLEMENT_DYNCREATE(CMFC1324View, CView)

BEGIN_MESSAGE_MAP(CMFC1324View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOWNAME, &CMFC1324View::OnShowname)
END_MESSAGE_MAP()

// CMFC1324View ����/����

CMFC1324View::CMFC1324View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC1324View::~CMFC1324View()
{
}

BOOL CMFC1324View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC1324View ����

void CMFC1324View::OnDraw(CDC* /*pDC*/)
{
	CMFC1324Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC1324View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC1324View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC1324View ���

#ifdef _DEBUG
void CMFC1324View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC1324View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC1324Doc* CMFC1324View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC1324Doc)));
	return (CMFC1324Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC1324View ��Ϣ�������


void CMFC1324View::OnShowname()
{
	CString s=_T("������");
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	// TODO: �ڴ���������������
}
