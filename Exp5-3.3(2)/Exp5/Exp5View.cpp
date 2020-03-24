
// Exp5View.cpp : CExp5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp5.h"
#endif

#include "Exp5Doc.h"
#include "Exp5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp5View

IMPLEMENT_DYNCREATE(CExp5View, CView)

BEGIN_MESSAGE_MAP(CExp5View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CExp5View 构造/析构

CExp5View::CExp5View()
{
	// TODO: 在此处添加构造代码

}

CExp5View::~CExp5View()
{
}

BOOL CExp5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp5View 绘制

void CExp5View::OnDraw(CDC* pDC)
{
	CExp5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString str;
	str.Format(L"%d",pDoc->A);
	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(200,300,pDoc->S);
	pDC->TextOutW(100,300,str);
}

void CExp5View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp5View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExp5View 诊断

#ifdef _DEBUG
void CExp5View::AssertValid() const
{
	CView::AssertValid();
}

void CExp5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp5Doc* CExp5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp5Doc)));
	return (CExp5Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp5View 消息处理程序
