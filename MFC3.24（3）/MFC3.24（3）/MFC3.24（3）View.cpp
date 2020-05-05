
// MFC3.24（3）View.cpp : CMFC324（3）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.24（3）.h"
#endif

#include "MFC3.24（3）Doc.h"
#include "MFC3.24（3）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC324（3）View

IMPLEMENT_DYNCREATE(CMFC324（3）View, CView)

BEGIN_MESSAGE_MAP(CMFC324（3）View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOWLINE, &CMFC324（3）View::OnShowline)
	ON_COMMAND(ID_SHOWRECTANGLE, &CMFC324（3）View::OnShowrectangle)
	ON_COMMAND(ID_SHOWELLIPSE, &CMFC324（3）View::OnShowellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC324（3）View 构造/析构

CMFC324（3）View::CMFC324（3）View()
{
	// TODO: 在此处添加构造代码
	
}

CMFC324（3）View::~CMFC324（3）View()
{
}

BOOL CMFC324（3）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC324（3）View 绘制

void CMFC324（3）View::OnDraw(CDC* /*pDC*/)
{
	CMFC324（3）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC324（3）View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC324（3）View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC324（3）View 诊断

#ifdef _DEBUG
void CMFC324（3）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC324（3）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC324（3）Doc* CMFC324（3）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC324（3）Doc)));
	return (CMFC324（3）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC324（3）View 消息处理程序

int set;
CRect cr;
void CMFC324（3）View::OnShowline()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	set = 1;
	CPen pen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = dc.SelectObject(&pen);
}
CPoint point1,point2;

void CMFC324（3）View::OnShowrectangle()
{
	// TODO: 在此添加命令处理程序代码

	set=2;
}


void CMFC324（3）View::OnShowellipse()
{
	// TODO: 在此添加命令处理程序代码
	set=3;
}


void CMFC324（3）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	point1.x = point.x;
	point1.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC324（3）View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	point2.x = point.x;
	point2.y = point.y;
	switch (set) {
	case 1:
		dc.MoveTo(point2.x, point2.y);
		dc.LineTo(point1.x, point1.y);
		break;
	case 2:
		cr.left = point1.x;
		cr.top = point1.y;
		cr.right = point2.x;
		cr.bottom = point2.y;
		dc.Rectangle(cr);
		break;
	case 3:
		cr.left = point1.x;
		cr.top = point1.y;
		cr.right = point2.x;
		cr.bottom = point2.y;
		dc.Ellipse(cr);
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}
