
// MFC3.17(3)View.cpp : CMFC3173View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3.17(3).h"
#endif

#include "MFC3.17(3)Doc.h"
#include "MFC3.17(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3173View

IMPLEMENT_DYNCREATE(CMFC3173View, CView)

BEGIN_MESSAGE_MAP(CMFC3173View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC3173View 构造/析构

CMFC3173View::CMFC3173View()
{
	// TODO: 在此处添加构造代码
	set =true;
	s=true;
	N=5;
	for(int i=0;i<N;i++)
	{
		int t=(i+1)*100;
		CRect rect(t,0,t+20,20);
		cr.Add(rect);
	}
}

CMFC3173View::~CMFC3173View()
{
}

BOOL CMFC3173View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3173View 绘制

void CMFC3173View::OnDraw(CDC* pDC)
{
	CMFC3173Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(set)
	{
		for(int i=0;i<N;i++)
		{
			SetTimer(i,rand()%400+100,NULL);
			set=false;
		}
		
	}
	// TODO: 在此处为本机数据添加绘制代码
	for(int i=0;i<N;i++)
	{
		pDC->Ellipse(cr[i]);
	}
}

void CMFC3173View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC3173View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC3173View 诊断

#ifdef _DEBUG
void CMFC3173View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3173View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3173Doc* CMFC3173View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3173Doc)));
	return (CMFC3173Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3173View 消息处理程序


void CMFC3173View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i=nIDEvent;
	CRect rect;
	this->GetClientRect(&rect);
	if(s)
	{
		if(rect.bottom>=cr[i].bottom)
		{
			cr[i].top+=10;
			cr[i].bottom+=10;
		}
		else s=false;
	}
	else
	{
		if(rect.top<=cr[i].top)
		{
			cr[i].top-=10;
			cr[i].bottom-=10;
		}
		else s=true;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
