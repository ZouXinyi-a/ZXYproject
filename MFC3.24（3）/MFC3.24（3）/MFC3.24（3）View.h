
// MFC3.24��3��View.h : CMFC324��3��View ��Ľӿ�
//

#pragma once


class CMFC324��3��View : public CView
{
protected: // �������л�����
	CMFC324��3��View();
	DECLARE_DYNCREATE(CMFC324��3��View)

// ����
public:
	CMFC324��3��Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC324��3��View();
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
	afx_msg void OnShowline();
	afx_msg void OnShowrectangle();
	afx_msg void OnShowellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.24��3��View.cpp �еĵ��԰汾
inline CMFC324��3��Doc* CMFC324��3��View::GetDocument() const
   { return reinterpret_cast<CMFC324��3��Doc*>(m_pDocument); }
#endif

