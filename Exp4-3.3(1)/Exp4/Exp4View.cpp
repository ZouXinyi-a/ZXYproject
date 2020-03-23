
// Exp4View.cpp : CExp4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp4.h"
#endif

#include "Exp4Doc.h"
#include "Exp4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp4View

IMPLEMENT_DYNCREATE(CExp4View, CView)

BEGIN_MESSAGE_MAP(CExp4View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp4View 构造/析构

CExp4View::CExp4View()
{
	// TODO: 在此处添加构造代码

}

CExp4View::~CExp4View()
{
}

BOOL CExp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp4View 绘制

void CExp4View::OnDraw(CDC* /*pDC*/)
{
	CExp4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CExp4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExp4View 诊断

#ifdef _DEBUG
void CExp4View::AssertValid() const
{
	CView::AssertValid();
}

void CExp4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp4Doc* CExp4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp4Doc)));
	return (CExp4Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp4View 消息处理程序


void CExp4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s,str;
	int a;
	a=2;
	s.Format(_T("我是邹欣怡"),point.x);
	str.Format(L"%d",a);
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	dc.TextOutW(100,300,str);
	CView::OnLButtonDown(nFlags, point);
}
