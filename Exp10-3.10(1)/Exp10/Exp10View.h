
// Exp10View.h : CExp10View ��Ľӿ�
//

#pragma once


class CExp10View : public CView
{
protected: // �������л�����
	CExp10View();
	DECLARE_DYNCREATE(CExp10View)

// ����
public:
	CExp10Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExp10View();
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
};

#ifndef _DEBUG  // Exp10View.cpp �еĵ��԰汾
inline CExp10Doc* CExp10View::GetDocument() const
   { return reinterpret_cast<CExp10Doc*>(m_pDocument); }
#endif

