
// Exp8View.h : CExp8View ��Ľӿ�
//

#pragma once


class CExp8View : public CView
{
protected: // �������л�����
	CExp8View();
	DECLARE_DYNCREATE(CExp8View)

// ����
public:
	CExp8Doc* GetDocument() const;

// ����
public:
CRect cr;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExp8View();
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

#ifndef _DEBUG  // Exp8View.cpp �еĵ��԰汾
inline CExp8Doc* CExp8View::GetDocument() const
   { return reinterpret_cast<CExp8Doc*>(m_pDocument); }
#endif

