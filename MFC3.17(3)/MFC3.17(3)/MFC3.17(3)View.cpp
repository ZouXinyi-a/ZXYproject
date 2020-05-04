
// MFC3.17(3)View.cpp : CMFC3173View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC3173View ����/����

CMFC3173View::CMFC3173View()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC3173View ����

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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CMFC3173View ���

#ifdef _DEBUG
void CMFC3173View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3173View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3173Doc* CMFC3173View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3173Doc)));
	return (CMFC3173Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3173View ��Ϣ�������


void CMFC3173View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
