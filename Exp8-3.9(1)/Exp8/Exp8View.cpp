
// Exp8View.cpp : CExp8View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp8.h"
#endif

#include "Exp8Doc.h"
#include "Exp8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp8View

IMPLEMENT_DYNCREATE(CExp8View, CView)

BEGIN_MESSAGE_MAP(CExp8View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp8View 构造/析构

CExp8View::CExp8View()
{
	// TODO: 在此处添加构造代码
	
}

CExp8View::~CExp8View()
{
}

BOOL CExp8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp8View 绘制

void CExp8View::OnDraw(CDC* pDC)
{
	CExp8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}

void CExp8View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp8View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExp8View 诊断

#ifdef _DEBUG
void CExp8View::AssertValid() const
{
	CView::AssertValid();
}

void CExp8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp8Doc* CExp8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp8Doc)));
	return (CExp8Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp8View 消息处理程序


void CExp8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CRect cr;
	this->GetClientRect(&cr);
	this->Invalidate();
	//CClientDC dc(this);
	//dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
