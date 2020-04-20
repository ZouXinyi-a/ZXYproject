
// MFC3.02（4）View.cpp : CMFC302（4）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.02（4）.h"
#endif

#include "MFC3.02（4）Doc.h"
#include "MFC3.02（4）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC302（4）View

IMPLEMENT_DYNCREATE(CMFC302（4）View, CView)

BEGIN_MESSAGE_MAP(CMFC302（4）View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC302（4）View 构造/析构

CMFC302（4）View::CMFC302（4）View()
{
	// TODO: 在此处添加构造代码

}

CMFC302（4）View::~CMFC302（4）View()
{
}

BOOL CMFC302（4）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC302（4）View 绘制

void CMFC302（4）View::OnDraw(CDC* pDC)
{
	CMFC302（4）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(cr);
	CBrush newbrush(RGB(100,0,0));
	CBrush *poldbrush;
	poldbrush=pDC->SelectObject(&newbrush);
	pDC->Ellipse(cr);
}

void CMFC302（4）View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC302（4）View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC302（4）View 诊断

#ifdef _DEBUG
void CMFC302（4）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC302（4）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC302（4）Doc* CMFC302（4）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC302（4）Doc)));
	return (CMFC302（4）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC302（4）View 消息处理程序


void CMFC302（4）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}
