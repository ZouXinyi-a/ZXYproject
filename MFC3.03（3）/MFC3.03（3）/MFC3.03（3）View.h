
// MFC3.03��3��View.h : CMFC303��3��View ��Ľӿ�
//

#pragma once


class CMFC303��3��View : public CView
{
protected: // �������л�����
	CMFC303��3��View();
	DECLARE_DYNCREATE(CMFC303��3��View)

// ����
public:
	CMFC303��3��Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC303��3��View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.03��3��View.cpp �еĵ��԰汾
inline CMFC303��3��Doc* CMFC303��3��View::GetDocument() const
   { return reinterpret_cast<CMFC303��3��Doc*>(m_pDocument); }
#endif

