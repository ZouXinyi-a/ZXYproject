
// MFC3.16View.h : CMFC316View ��Ľӿ�
//

#pragma once


class CMFC316View : public CView
{
protected: // �������л�����
	CMFC316View();
	DECLARE_DYNCREATE(CMFC316View)

// ����
public:
	CMFC316Doc* GetDocument() const;

// ����
public:
bool judge;
CPoint begin;
CPoint now;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC316View();
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

#ifndef _DEBUG  // MFC3.16View.cpp �еĵ��԰汾
inline CMFC316Doc* CMFC316View::GetDocument() const
   { return reinterpret_cast<CMFC316Doc*>(m_pDocument); }
#endif

