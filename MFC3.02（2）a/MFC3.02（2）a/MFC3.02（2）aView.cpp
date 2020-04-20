
// MFC3.02（2）aView.cpp : CMFC302（2）aView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.02（2）a.h"
#endif

#include "MFC3.02（2）aDoc.h"
#include "MFC3.02（2）aView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC302（2）aView

IMPLEMENT_DYNCREATE(CMFC302（2）aView, CView)

BEGIN_MESSAGE_MAP(CMFC302（2）aView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC302（2）aView 构造/析构

CMFC302（2）aView::CMFC302（2）aView()
{
	// TODO: 在此处添加构造代码
	ca.SetSize(256);
}

CMFC302（2）aView::~CMFC302（2）aView()
{
}

BOOL CMFC302（2）aView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC302（2）aView 绘制

void CMFC302（2）aView::OnDraw(CDC* pDC)
{
	CMFC302（2）aDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	for(int i=0;i<ca.GetSize();i++)
		pDC->Ellipse(ca.GetAt(i));
}

void CMFC302（2）aView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC302（2）aView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC302（2）aView 诊断

#ifdef _DEBUG
void CMFC302（2）aView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC302（2）aView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC302（2）aDoc* CMFC302（2）aView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC302（2）aDoc)));
	return (CMFC302（2）aDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC302（2）aView 消息处理程序


void CMFC302（2）aView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r=rand()%50+50;
	CRect  cr(point.x-r,point.y-r,point.x+r,point.y+r);
	ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
