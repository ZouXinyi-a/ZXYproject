
// MFC3.23��1��View.h : CMFC323��1��View ��Ľӿ�
//

#pragma once


class CMFC323��1��View : public CView
{
protected: // �������л�����
	CMFC323��1��View();
	DECLARE_DYNCREATE(CMFC323��1��View)

// ����
public:
	CMFC323��1��Doc* GetDocument() const;

// ����
public:
	int r;
	int t;
	CRect rect;
	CPoint point;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC323��1��View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnGradualcircle();
	afx_msg void OnGradualcolor();
};

#ifndef _DEBUG  // MFC3.23��1��View.cpp �еĵ��԰汾
inline CMFC323��1��Doc* CMFC323��1��View::GetDocument() const
   { return reinterpret_cast<CMFC323��1��Doc*>(m_pDocument); }
#endif

