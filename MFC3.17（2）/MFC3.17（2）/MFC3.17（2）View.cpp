
// MFC3.17��2��View.cpp : CMFC317��2��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC3.17��2��.h"
#endif

#include "MFC3.17��2��Doc.h"
#include "MFC3.17��2��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC317��2��View

IMPLEMENT_DYNCREATE(CMFC317��2��View, CView)

BEGIN_MESSAGE_MAP(CMFC317��2��View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFC317��2��View ����/����

CMFC317��2��View::CMFC317��2��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC317��2��View::~CMFC317��2��View()
{
}

BOOL CMFC317��2��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC317��2��View ����

void CMFC317��2��View::OnDraw(CDC* pDC)
{
	CMFC317��2��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	/*this->GetClientRect(pDoc->m_rect);
	CPoint cpoint;
	cpoint.x=pDoc->m_rect.left+(pDoc->m_rect.right-pDoc->m_rect.left)/2;
	cpoint.y=pDoc->m_rect.top+(pDoc->m_rect.bottom-pDoc->m_rect.top)/2;

	CClientDC dc(this);
	dc.Rectangle(cpoint.x-100,cpoint.y-100,cpoint.x+100,cpoint.y+100);
	*/
	pDC->Rectangle(pDoc->m_rect);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFC317��2��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC317��2��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC317��2��View ���

#ifdef _DEBUG
void CMFC317��2��View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC317��2��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC317��2��Doc* CMFC317��2��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC317��2��Doc)));
	return (CMFC317��2��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC317��2��View ��Ϣ�������


void CMFC317��2��View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC317��2��Doc* pDoc = GetDocument();
	CRect clientRect;
	GetClientRect(&clientRect);
	switch(nChar)
	{
	case VK_LEFT:
		{
			if(pDoc->m_rect.left>0)
			{
			pDoc->m_rect.left-=5;
			pDoc->m_rect.right-=5;
			}
			break;
		}
	case VK_RIGHT:
		{
			if(pDoc->m_rect.right<=(clientRect.right-clientRect.left))
			{
			pDoc->m_rect.left+=5;
			pDoc->m_rect.right+=5;
			}
			break;
		}
	case VK_UP:
		{
			if(pDoc->m_rect.top>0)
			{
			pDoc->m_rect.top-=5;
			pDoc->m_rect.bottom-=5;
			}
			break;
		}
	case VK_DOWN:
		{
			if(pDoc->m_rect.bottom<=(clientRect.bottom-clientRect.top))
			{
			pDoc->m_rect.top+=5;
			pDoc->m_rect.bottom+=5;
			}
			break;
		}
	case VK_HOME:
		{
			pDoc->m_rect.left-=5;
			pDoc->m_rect.top-=5;
			break;
		}

	case VK_END:
		{
			pDoc->m_rect.right-=5;
			pDoc->m_rect.bottom-=5;
			break;
		}
	}
	InvalidateRect(NULL,TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
