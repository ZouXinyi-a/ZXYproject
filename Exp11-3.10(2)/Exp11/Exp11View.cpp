
// Exp11View.cpp : CExp11View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp11.h"
#endif

#include "Exp11Doc.h"
#include "Exp11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp11View

IMPLEMENT_DYNCREATE(CExp11View, CView)

BEGIN_MESSAGE_MAP(CExp11View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp11View 构造/析构

CExp11View::CExp11View()
{
	// TODO: 在此处添加构造代码

}

CExp11View::~CExp11View()
{
}

BOOL CExp11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp11View 绘制

void CExp11View::OnDraw(CDC* /*pDC*/)
{
	CExp11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CExp11View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp11View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExp11View 诊断

#ifdef _DEBUG
void CExp11View::AssertValid() const
{
	CView::AssertValid();
}

void CExp11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp11Doc* CExp11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp11Doc)));
	return (CExp11Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp11View 消息处理程序


void CExp11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExp11Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("A+B=%d"),pDoc->A+pDoc->B);
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	CView::OnLButtonDown(nFlags, point);
}
