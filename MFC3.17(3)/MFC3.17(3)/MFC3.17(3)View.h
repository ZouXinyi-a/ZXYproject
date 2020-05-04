
// MFC3.17(3)View.h : CMFC3173View ��Ľӿ�
//

#pragma once


class CMFC3173View : public CView
{
protected: // �������л�����
	CMFC3173View();
	DECLARE_DYNCREATE(CMFC3173View)

// ����
public:
	CMFC3173Doc* GetDocument() const;

// ����
public:
	int N;
	CArray <CRect , CRect>cr;
	bool set;
	bool s;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC3173View();
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
};

#ifndef _DEBUG  // MFC3.17(3)View.cpp �еĵ��԰汾
inline CMFC3173Doc* CMFC3173View::GetDocument() const
   { return reinterpret_cast<CMFC3173Doc*>(m_pDocument); }
#endif

