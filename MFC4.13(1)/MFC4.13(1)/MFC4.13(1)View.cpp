
// MFC4.13(1)View.cpp : CMFC4131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4.13(1).h"
#endif

#include "MFC4.13(1)Doc.h"
#include "MFC4.13(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4131View

IMPLEMENT_DYNCREATE(CMFC4131View, CView)

BEGIN_MESSAGE_MAP(CMFC4131View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC4131View 构造/析构

CMFC4131View::CMFC4131View()
{
	// TODO: 在此处添加构造代码
	m_bl=true;
}

CMFC4131View::~CMFC4131View()
{
}

BOOL CMFC4131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4131View 绘制

void CMFC4131View::OnDraw(CDC* pDC)
{
	CMFC4131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//CBrush brush(RGB(114,200,134));
	//pDC->FillRect(&r,&brush);
	pDC->Rectangle(&pDoc->rect);
	// TODO: 在此处为本机数据添加绘制代码

}

void CMFC4131View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4131View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4131View 诊断

#ifdef _DEBUG
void CMFC4131View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4131Doc* CMFC4131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4131Doc)));
	return (CMFC4131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4131View 消息处理程序


void CMFC4131View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_bl=true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC4131View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_bl=false;
	CView::OnLButtonUp(nFlags, point);
}


void CMFC4131View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
		CMFC4131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (m_bl) {
		pDoc->rect.top = point.y - 100;
		pDoc->rect.left = point.x - 200;
		pDoc->rect.bottom = point.y + 100;
		pDoc->rect.right = point.x + 200;

		CClientDC dc(this);
		dc.Rectangle(&pDoc->rect);
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
