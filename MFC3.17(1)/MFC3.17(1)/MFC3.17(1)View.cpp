
// MFC3.17(1)View.cpp : CMFC3171View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.17(1).h"
#endif

#include "MFC3.17(1)Doc.h"
#include "MFC3.17(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3171View

IMPLEMENT_DYNCREATE(CMFC3171View, CView)

BEGIN_MESSAGE_MAP(CMFC3171View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC3171View 构造/析构

CMFC3171View::CMFC3171View()
{
	// TODO: 在此处添加构造代码

}

CMFC3171View::~CMFC3171View()
{
}

BOOL CMFC3171View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3171View 绘制

void CMFC3171View::OnDraw(CDC* /*pDC*/)
{
	CMFC3171Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC3171View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3171View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3171View 诊断

#ifdef _DEBUG
void CMFC3171View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3171View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3171Doc* CMFC3171View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3171Doc)));
	return (CMFC3171Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3171View 消息处理程序


void CMFC3171View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3171Doc* pDoc = GetDocument();
	pDoc->m_point=point;
	InvalidateRect(NULL,FALSE);
	pDoc->i++;
	CView::OnMouseMove(nFlags, point);
}


void CMFC3171View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3171Doc* pDoc = GetDocument();
	pDoc->a=point.x;
	pDoc->judge=true;
	pDoc->i=0;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC3171View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	CMFC3171Doc* pDoc = GetDocument();
	pDoc->b=point.x;
	if(pDoc->judge){
	
	str.Format(_T("MouseMove发生%d次,横向移动%d个像素发生一次"),pDoc->i,pDoc->b-pDoc->a);
	}
	CClientDC dc(this);
	dc.TextOutW(30,30,str);
	CView::OnLButtonUp(nFlags, point);
}
