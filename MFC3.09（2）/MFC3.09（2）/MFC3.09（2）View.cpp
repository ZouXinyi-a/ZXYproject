
// MFC3.09（2）View.cpp : CMFC309（2）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.09（2）.h"
#endif

#include "MFC3.09（2）Doc.h"
#include "MFC3.09（2）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC309（2）View

IMPLEMENT_DYNCREATE(CMFC309（2）View, CView)

BEGIN_MESSAGE_MAP(CMFC309（2）View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC309（2）View 构造/析构

CMFC309（2）View::CMFC309（2）View()
{
	// TODO: 在此处添加构造代码

}

CMFC309（2）View::~CMFC309（2）View()
{
}

BOOL CMFC309（2）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC309（2）View 绘制

void CMFC309（2）View::OnDraw(CDC* pDC)
{
	CMFC309（2）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for(int i=0;i<pDoc->ca.GetSize();i++)
		pDC->Ellipse(pDoc->ca.GetAt(i));
}

void CMFC309（2）View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC309（2）View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC309（2）View 诊断

#ifdef _DEBUG
void CMFC309（2）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC309（2）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC309（2）Doc* CMFC309（2）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC309（2）Doc)));
	return (CMFC309（2）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC309（2）View 消息处理程序


void CMFC309（2）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r1=rand()%50+5;
	int r2=rand()%60+25;
	CRect cr(point.x-r1,point.y-r2,point.x+r1,point.y+r2);
	CMFC309（2）Doc* pDoc = GetDocument();
	pDoc->ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
