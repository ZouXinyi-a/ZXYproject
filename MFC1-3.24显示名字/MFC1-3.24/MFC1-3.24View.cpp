
// MFC1-3.24View.cpp : CMFC1324View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC1-3.24.h"
#endif

#include "MFC1-3.24Doc.h"
#include "MFC1-3.24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC1324View

IMPLEMENT_DYNCREATE(CMFC1324View, CView)

BEGIN_MESSAGE_MAP(CMFC1324View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOWNAME, &CMFC1324View::OnShowname)
END_MESSAGE_MAP()

// CMFC1324View 构造/析构

CMFC1324View::CMFC1324View()
{
	// TODO: 在此处添加构造代码

}

CMFC1324View::~CMFC1324View()
{
}

BOOL CMFC1324View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC1324View 绘制

void CMFC1324View::OnDraw(CDC* /*pDC*/)
{
	CMFC1324Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC1324View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC1324View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC1324View 诊断

#ifdef _DEBUG
void CMFC1324View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC1324View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC1324Doc* CMFC1324View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC1324Doc)));
	return (CMFC1324Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC1324View 消息处理程序


void CMFC1324View::OnShowname()
{
	CString s=_T("邹欣怡");
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	// TODO: 在此添加命令处理程序代码
}
