
// MFC3.31（1）View.cpp : CMFC331（1）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.31（1）.h"
#endif

#include "MFC3.31（1）Doc.h"
#include "MFC3.31（1）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC331（1）View

IMPLEMENT_DYNCREATE(CMFC331（1）View, CView)

BEGIN_MESSAGE_MAP(CMFC331（1）View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFC331（1）View 构造/析构

CMFC331（1）View::CMFC331（1）View()
{
	// TODO: 在此处添加构造代码
	s="";
}

CMFC331（1）View::~CMFC331（1）View()
{
}

BOOL CMFC331（1）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC331（1）View 绘制

void CMFC331（1）View::OnDraw(CDC* pDC)
{
	CMFC331（1）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->cr);
}

void CMFC331（1）View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC331（1）View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC331（1）View 诊断

#ifdef _DEBUG
void CMFC331（1）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC331（1）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC331（1）Doc* CMFC331（1）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC331（1）Doc)));
	return (CMFC331（1）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC331（1）View 消息处理程序


void CMFC331（1）View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC331（1）Doc* pDoc = GetDocument();
	CClientDC dc(this);
	s = s + (char) nChar;
	dc.TextOutW(pDoc->cr.left+10, pDoc->cr.top+10, s);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
