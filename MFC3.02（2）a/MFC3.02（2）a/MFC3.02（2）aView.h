
// MFC3.02��2��aView.h : CMFC302��2��aView ��Ľӿ�
//

#pragma once


class CMFC302��2��aView : public CView
{
protected: // �������л�����
	CMFC302��2��aView();
	DECLARE_DYNCREATE(CMFC302��2��aView)

// ����
public:
	CMFC302��2��aDoc* GetDocument() const;

// ����
public:
CArray<CRect,CRect&> ca;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC302��2��aView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.02��2��aView.cpp �еĵ��԰汾
inline CMFC302��2��aDoc* CMFC302��2��aView::GetDocument() const
   { return reinterpret_cast<CMFC302��2��aDoc*>(m_pDocument); }
#endif

