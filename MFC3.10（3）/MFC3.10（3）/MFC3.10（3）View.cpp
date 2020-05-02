
// MFC3.10（3）View.cpp : CMFC310（3）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.10（3）.h"
#endif

#include "MFC3.10（3）Doc.h"
#include "MFC3.10（3）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC310（3）View

IMPLEMENT_DYNCREATE(CMFC310（3）View, CView)

BEGIN_MESSAGE_MAP(CMFC310（3）View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC310（3）View 构造/析构

CMFC310（3）View::CMFC310（3）View()
{
	// TODO: 在此处添加构造代码

}

CMFC310（3）View::~CMFC310（3）View()
{
}

BOOL CMFC310（3）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC310（3）View 绘制

void CMFC310（3）View::OnDraw(CDC* pDC)
{

	CMFC310（3）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect_A(30,30,200,200);
	CRect rect_B(260,30,360,200);
	CRect rect_C(100,260,310,360);
	pDC->Rectangle(&rect_A);
	pDC->Rectangle(&rect_B);
	pDC->Rectangle(&rect_C);
	CString strA,strB,strC;
	strA=_T("A");
	strB=_T("B");
	strC=_T("C");
	pDC->TextOutW(30,30,strA);
	pDC->TextOutW(260,30,strB);
	pDC->TextOutW(110,260,strC);
	pDoc->A=rect_A;
	pDoc->B=rect_B;
	pDoc->C=rect_C;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC310（3）View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC310（3）View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC310（3）View 诊断

#ifdef _DEBUG
void CMFC310（3）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC310（3）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC310（3）Doc* CMFC310（3）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC310（3）Doc)));
	return (CMFC310（3）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC310（3）View 消息处理程序


void CMFC310（3）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFC310（3）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//在矩形A中显示随机数
	if((point.y>=pDoc->A.top)&&(point.y<=pDoc->A.bottom)
		&&(point.x>=pDoc->A.left)&&(point.x<=pDoc->A.right))
	{
		pDoc->a=rand()%100+1;
		CString str;
		str.Format(_T("%d"),pDoc->a);
		CClientDC dc(this);
		dc.TextOutW(point.x,point.y,str);
	}
	//在矩形B中显示随机数
	else if((point.y>=pDoc->B.top)&&(point.y<=pDoc->B.bottom)
		&&(point.x>=pDoc->B.left)&&(point.x<=pDoc->B.right))
	{
		pDoc->b=rand()%100+1;
		CString str;
		str.Format(_T("%d"),pDoc->b);
		CClientDC dc(this);
		dc.TextOutW(point.x,point.y,str);
	}
	//在矩形C中显示随机数
	else if((point.y>=pDoc->C.top)&&(point.y<=pDoc->C.bottom)
		&&(point.x>=pDoc->C.left)&&(point.x<=pDoc->C.right))
	{
		int a=pDoc->a+pDoc->b;
		CString str;
		str.Format(_T("%d"),a);
		CClientDC dc(this);
		dc.TextOutW(point.x,point.y,str);
	}
	else{
		CString str;
		str.Format(_T("点击无效"));
		CClientDC dc(this);
		dc.TextOutW(point.x,point.y,str);
	}
	CView::OnLButtonDown(nFlags, point);
}
