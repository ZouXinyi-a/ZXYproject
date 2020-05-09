
// MFC4.13(3)View.cpp : CMFC4133View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4.13(3).h"
#endif

#include "MFC4.13(3)Doc.h"
#include "MFC4.13(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4133View

IMPLEMENT_DYNCREATE(CMFC4133View, CView)

BEGIN_MESSAGE_MAP(CMFC4133View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC4133View 构造/析构

CMFC4133View::CMFC4133View()
{
	// TODO: 在此处添加构造代码
	judge=true;
	m_move=true;
	set=true;
	m_LorR=true;
}

CMFC4133View::~CMFC4133View()
{
}

BOOL CMFC4133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4133View 绘制

void CMFC4133View::OnDraw(CDC* pDC)
{
	CMFC4133Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (judge) {
		CRect rc;
		this->GetClientRect(&rc);
		point.x = 0;
		point.y = (rc.bottom - rc.top) / 2;

		rect.left = point.x;
		rect.top = point.y - 20;
		rect.right = point.x + 40;
		rect.bottom = point.y + 20;

		judge = false;
	}
	if (set) {
		SetTimer(0, 50, NULL);
		set = false;
	}
	pDC->Ellipse(rect);
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFC4133View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC4133View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC4133View 诊断

#ifdef _DEBUG
void CMFC4133View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4133View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4133Doc* CMFC4133View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4133Doc)));
	return (CMFC4133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4133View 消息处理程序


void CMFC4133View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	this->GetClientRect(&cr);
	if (m_LorR && m_move) {
		if ((rect.right <= cr.right)) {
			rect.left += 10;
			rect.right += 10;
		}
		else m_LorR = false;
	}
	else if(m_move) {
		if ((rect.left >= cr.left)) {
			rect.left -= 10;
			rect.right -= 10;
		}
		else m_LorR = true;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMFC4133View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_move = false;;
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC4133View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_move = true;
	CView::OnLButtonDown(nFlags, point);
}
