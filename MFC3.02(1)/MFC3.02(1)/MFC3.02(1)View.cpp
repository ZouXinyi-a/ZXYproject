
// MFC3.02(1)View.cpp : CMFC3021View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.02(1).h"
#endif

#include "MFC3.02(1)Doc.h"
#include "MFC3.02(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3021View

IMPLEMENT_DYNCREATE(CMFC3021View, CView)

BEGIN_MESSAGE_MAP(CMFC3021View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3021View 构造/析构

CMFC3021View::CMFC3021View()
{
	// TODO: 在此处添加构造代码

}

CMFC3021View::~CMFC3021View()
{
}

BOOL CMFC3021View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3021View 绘制

void CMFC3021View::OnDraw(CDC* /*pDC*/)
{
	CMFC3021Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC3021View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3021View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3021View 诊断

#ifdef _DEBUG
void CMFC3021View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3021View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3021Doc* CMFC3021View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3021Doc)));
	return (CMFC3021Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3021View 消息处理程序


void CMFC3021View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r=rand()%50+50;
	CRect cr(point.x-r,point.y-r,point.x+r,point.y+r);
	CClientDC dc(this);
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
