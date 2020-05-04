
// MFC3.17(1)View.h : CMFC3171View ��Ľӿ�
//

#pragma once


class CMFC3171View : public CView
{
protected: // �������л�����
	CMFC3171View();
	DECLARE_DYNCREATE(CMFC3171View)

// ����
public:
	CMFC3171Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC3171View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.17(1)View.cpp �еĵ��԰汾
inline CMFC3171Doc* CMFC3171View::GetDocument() const
   { return reinterpret_cast<CMFC3171Doc*>(m_pDocument); }
#endif

