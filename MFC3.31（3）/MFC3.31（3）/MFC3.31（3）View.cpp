
// MFC3.31（3）View.cpp : CMFC331（3）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.31（3）.h"
#endif

#include "MFC3.31（3）Doc.h"
#include "MFC3.31（3）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC331（3）View

IMPLEMENT_DYNCREATE(CMFC331（3）View, CView)

BEGIN_MESSAGE_MAP(CMFC331（3）View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC331（3）View 构造/析构

CMFC331（3）View::CMFC331（3）View()
{
	// TODO: 在此处添加构造代码
	str1="";
	str2="";
	point.x=605;
	point.y=205;
	flag=0;h=0;
	x=605;
	rect.left =600;
	rect.top =200;
	rect.right =800;
	rect.bottom =225;

}

CMFC331（3）View::~CMFC331（3）View()
{
}

BOOL CMFC331（3）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC331（3）View 绘制

void CMFC331（3）View::OnDraw(CDC* pDC)
{
	CMFC331（3）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(rect);
	if (flag) {
		for (int i = 0;i < flag;i++)
			pDC->TextOutW(605, 203 + (i*h), m[i]);
	}
}

void CMFC331（3）View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC331（3）View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC331（3）View 诊断

#ifdef _DEBUG
void CMFC331（3）View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC331（3）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC331（3）Doc* CMFC331（3）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC331（3）Doc)));
	return (CMFC331（3）Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC331（3）View 消息处理程序


void CMFC331（3）View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	char c = nChar;
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	h = tm.tmHeight;
	str2 = str1;
	str1 += c;
	CSize z = x += 9;
	if (x >= rect.right) {
		m.Add(str2);
		flag += 1;
		str1.Empty();
		cpoint.y += tm.tmHeight;
		rect.bottom += tm.tmHeight;
		Invalidate();
		x = 605;
	}
	dc.TextOut(cpoint.x, cpoint.y, str1);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC331（3）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	str1.Empty();
	cpoint = point;
	CView::OnLButtonDown(nFlags, point);
}
