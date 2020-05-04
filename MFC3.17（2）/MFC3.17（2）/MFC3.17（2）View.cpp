
// MFC3.17（2）View.cpp : CMFC317（2）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.17（2）.h"
#endif

#include "MFC3.17（2）Doc.h"
#include "MFC3.17（2）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC317（2）View

IMPLEMENT_DYNCREATE(CMFC317（2）View, CView)

BEGIN_MESSAGE_MAP(CMFC317（2）View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFC317（2）View 构造/析构

CMFC317（2）View::CMFC317（2）View()
{
	// TODO: 在此处添加构造代码

}

CMFC317（2）View::~CMFC317（2）View()
{
}

BOOL CMFC317（2）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC317（2）View 绘制

void CMFC317（2）View::OnDraw(CDC* pDC)
{
	CMFC317（2）Doc* pDoc = GetDocument();
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
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC317（2）View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC317（2）View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC317（2）View 诊断

#ifdef _DEBUG
void CMFC317（2）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC317（2）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC317（2）Doc* CMFC317（2）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC317（2）Doc)));
	return (CMFC317（2）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC317（2）View 消息处理程序


void CMFC317（2）View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC317（2）Doc* pDoc = GetDocument();
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
