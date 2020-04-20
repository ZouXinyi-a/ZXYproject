
// MFC3.02(1)View.h : CMFC3021View ��Ľӿ�
//

#pragma once


class CMFC3021View : public CView
{
protected: // �������л�����
	CMFC3021View();
	DECLARE_DYNCREATE(CMFC3021View)

// ����
public:
	CMFC3021Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC3021View();
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

#ifndef _DEBUG  // MFC3.02(1)View.cpp �еĵ��԰汾
inline CMFC3021Doc* CMFC3021View::GetDocument() const
   { return reinterpret_cast<CMFC3021Doc*>(m_pDocument); }
#endif

