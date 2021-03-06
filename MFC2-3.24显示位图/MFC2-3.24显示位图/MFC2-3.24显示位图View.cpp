
// MFC2-3.24显示位图View.cpp : CMFC2324显示位图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC2-3.24显示位图.h"
#endif

#include "MFC2-3.24显示位图Doc.h"
#include "MFC2-3.24显示位图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2324显示位图View

IMPLEMENT_DYNCREATE(CMFC2324显示位图View, CView)

BEGIN_MESSAGE_MAP(CMFC2324显示位图View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOWMAP, &CMFC2324显示位图View::OnShowmap)
END_MESSAGE_MAP()

// CMFC2324显示位图View 构造/析构

CMFC2324显示位图View::CMFC2324显示位图View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth=BM.bmWidth;
	m_nHeight=BM.bmHeight;
}

CMFC2324显示位图View::~CMFC2324显示位图View()
{
}

BOOL CMFC2324显示位图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC2324显示位图View 绘制

void CMFC2324显示位图View::OnDraw(CDC* pDC)
{
	CMFC2324显示位图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0,0,m_nWidth,m_nHeight,&MemDC,0,0,SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC2324显示位图View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC2324显示位图View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC2324显示位图View 诊断

#ifdef _DEBUG
void CMFC2324显示位图View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2324显示位图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2324显示位图Doc* CMFC2324显示位图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2324显示位图Doc)));
	return (CMFC2324显示位图Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2324显示位图View 消息处理程序


void CMFC2324显示位图View::OnShowmap()
{
	// TODO: 在此添加命令处理程序代码
}
