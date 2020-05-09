
// MFC4.13(3)View.h : CMFC4133View ��Ľӿ�
//

#pragma once


class CMFC4133View : public CView
{
protected: // �������л�����
	CMFC4133View();
	DECLARE_DYNCREATE(CMFC4133View)

// ����
public:
	CMFC4133Doc* GetDocument() const;

// ����
public:
	CPoint point;
	CRect rect;
	bool set;
bool judge;
bool m_move,m_LorR;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC4133View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4.13(3)View.cpp �еĵ��԰汾
inline CMFC4133Doc* CMFC4133View::GetDocument() const
   { return reinterpret_cast<CMFC4133Doc*>(m_pDocument); }
#endif

