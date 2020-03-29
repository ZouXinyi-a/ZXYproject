
// Exp10View.cpp : CExp10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp10.h"
#endif

#include "Exp10Doc.h"
#include "Exp10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp10View

IMPLEMENT_DYNCREATE(CExp10View, CView)

BEGIN_MESSAGE_MAP(CExp10View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CExp10View 构造/析构

CExp10View::CExp10View()
{
	// TODO: 在此处添加构造代码

}

CExp10View::~CExp10View()
{
}

BOOL CExp10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp10View 绘制

void CExp10View::OnDraw(CDC* /*pDC*/)
{
	CExp10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CExp10View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp10View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExp10View 诊断

#ifdef _DEBUG
void CExp10View::AssertValid() const
{
	CView::AssertValid();
}

void CExp10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp10Doc* CExp10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp10Doc)));
	return (CExp10Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp10View 消息处理程序


void CExp10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("左键正被按下"),point);
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	CView::OnLButtonDown(nFlags, point);
}


void CExp10View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("左键正在抬起"),point);
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	CView::OnLButtonUp(nFlags, point);
}
