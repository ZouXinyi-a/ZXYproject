
// MFC4.13(1)View.h : CMFC4131View ��Ľӿ�
//

#pragma once


class CMFC4131View : public CView
{
protected: // �������л�����
	CMFC4131View();
	DECLARE_DYNCREATE(CMFC4131View)

// ����
public:
	CMFC4131Doc* GetDocument() const;

// ����
public:
bool m_bl;
CRect r;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC4131View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4.13(1)View.cpp �еĵ��԰汾
inline CMFC4131Doc* CMFC4131View::GetDocument() const
   { return reinterpret_cast<CMFC4131Doc*>(m_pDocument); }
#endif

