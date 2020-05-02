
// MFC3.16View.cpp : CMFC316View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.16.h"
#endif

#include "MFC3.16Doc.h"
#include "MFC3.16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC316View

IMPLEMENT_DYNCREATE(CMFC316View, CView)

BEGIN_MESSAGE_MAP(CMFC316View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC316View 构造/析构

CMFC316View::CMFC316View()
{
	// TODO: 在此处添加构造代码

}

CMFC316View::~CMFC316View()
{
}

BOOL CMFC316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC316View 绘制

void CMFC316View::OnDraw(CDC* /*pDC*/)
{
	CMFC316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC316View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC316View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC316View 诊断

#ifdef _DEBUG
void CMFC316View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC316Doc* CMFC316View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC316Doc)));
	return (CMFC316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC316View 消息处理程序

void CMFC316View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(judge)
	{
		CClientDC dc(this);
		CString str;
		str.Format(_T("X = %d Y = %d"),point.x,point.y);
		dc.TextOutW(20,20,str);

		CBrush brush = dc.GetBkColor();
		CBrush *newbrush = dc.SelectObject(&brush);

		int oldMove = dc.SetROP2(R2_NOTXORPEN);

		dc.Rectangle(&CRect(begin,now));
		dc.Rectangle(&CRect(begin,point));

		now = point;

		dc.SelectObject(newbrush);
		dc.SetROP2(oldMove);
	}
	CView::OnMouseMove(nFlags, point);
}

void CMFC316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	judge=true;
	begin = point;
	now = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC316View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(judge){
		judge = false;
	}
	CView::OnLButtonUp(nFlags, point);
}


