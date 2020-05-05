
// MFC3.23（2）View.cpp : CMFC323（2）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.23（2）.h"
#endif

#include "MFC3.23（2）Doc.h"
#include "MFC3.23（2）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC323（2）View

IMPLEMENT_DYNCREATE(CMFC323（2）View, CView)

BEGIN_MESSAGE_MAP(CMFC323（2）View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_GradualColor, &CMFC323（2）View::OnGradualcolor)
END_MESSAGE_MAP()

// CMFC323（2）View 构造/析构

CMFC323（2）View::CMFC323（2）View()
{
	// TODO: 在此处添加构造代码
	r=0;
	t=1;
	a=0;
	b=0;
	c=0;
}

CMFC323（2）View::~CMFC323（2）View()
{
}

BOOL CMFC323（2）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC323（2）View 绘制

void CMFC323（2）View::OnDraw(CDC* pDC)
{
	CMFC323（2）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(&cr);
	CPoint point;
	point.x=(cr.right-cr.left )/2;
	point.y=(cr.bottom-cr.top)/2;

	CRect rect1(point.x-r,point.y-r,point.x+r,point.y+r);
	rect=rect1;
	CPen pen;
	a=rand() % 255;
	b=rand() % 255;
	c=rand() % 255;
	pen.CreatePen(PS_SOLID,5,RGB(a,b,c));
	CPen* oldpen = pDC->SelectObject(&pen);
	pDC->Ellipse(rect);
	pen.DeleteObject();
}

void CMFC323（2）View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC323（2）View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC323（2）View 诊断

#ifdef _DEBUG
void CMFC323（2）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC323（2）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC323（2）Doc* CMFC323（2）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC323（2）Doc)));
	return (CMFC323（2）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC323（2）View 消息处理程序


void CMFC323（2）View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	r=t*10;
	t++;
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMFC323（2）View::OnGradualcolor()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(0,100,NULL);
}
