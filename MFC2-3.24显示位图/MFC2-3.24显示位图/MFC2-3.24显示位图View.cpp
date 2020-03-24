
// MFC2-3.24��ʾλͼView.cpp : CMFC2324��ʾλͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC2-3.24��ʾλͼ.h"
#endif

#include "MFC2-3.24��ʾλͼDoc.h"
#include "MFC2-3.24��ʾλͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2324��ʾλͼView

IMPLEMENT_DYNCREATE(CMFC2324��ʾλͼView, CView)

BEGIN_MESSAGE_MAP(CMFC2324��ʾλͼView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOWMAP, &CMFC2324��ʾλͼView::OnShowmap)
END_MESSAGE_MAP()

// CMFC2324��ʾλͼView ����/����

CMFC2324��ʾλͼView::CMFC2324��ʾλͼView()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth=BM.bmWidth;
	m_nHeight=BM.bmHeight;
}

CMFC2324��ʾλͼView::~CMFC2324��ʾλͼView()
{
}

BOOL CMFC2324��ʾλͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC2324��ʾλͼView ����

void CMFC2324��ʾλͼView::OnDraw(CDC* pDC)
{
	CMFC2324��ʾλͼDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0,0,m_nWidth,m_nHeight,&MemDC,0,0,SRCCOPY);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC2324��ʾλͼView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC2324��ʾλͼView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC2324��ʾλͼView ���

#ifdef _DEBUG
void CMFC2324��ʾλͼView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2324��ʾλͼView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2324��ʾλͼDoc* CMFC2324��ʾλͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2324��ʾλͼDoc)));
	return (CMFC2324��ʾλͼDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2324��ʾλͼView ��Ϣ�������


void CMFC2324��ʾλͼView::OnShowmap()
{
	// TODO: �ڴ���������������
}
