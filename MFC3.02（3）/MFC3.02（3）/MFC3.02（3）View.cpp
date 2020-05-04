
// MFC3.02（3）View.cpp : CMFC302（3）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.02（3）.h"
#endif

#include "MFC3.02（3）Doc.h"
#include "MFC3.02（3）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC302（3）View

IMPLEMENT_DYNCREATE(CMFC302（3）View, CView)

BEGIN_MESSAGE_MAP(CMFC302（3）View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC302（3）View 构造/析构

CMFC302（3）View::CMFC302（3）View()
{
	// TODO: 在此处添加构造代码

}

CMFC302（3）View::~CMFC302（3）View()
{
}

BOOL CMFC302（3）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC302（3）View 绘制

void CMFC302（3）View::OnDraw(CDC* /*pDC*/)
{
	CMFC302（3）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC302（3）View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC302（3）View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC302（3）View 诊断

#ifdef _DEBUG
void CMFC302（3）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC302（3）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC302（3）Doc* CMFC302（3）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC302（3）Doc)));
	return (CMFC302（3）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC302（3）View 消息处理程序


void CMFC302（3）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	this->GetClientRect(&cr);
	//this->Invalidate();
	CClientDC dc(this);
	dc.Rectangle(cr);
	CView::OnLButtonDown(nFlags, point);
}
