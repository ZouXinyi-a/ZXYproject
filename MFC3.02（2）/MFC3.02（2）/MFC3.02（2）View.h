
// MFC3.02��2��View.h : CMFC302��2��View ��Ľӿ�
//

#pragma once


class CMFC302��2��View : public CView
{
protected: // �������л�����
	CMFC302��2��View();
	DECLARE_DYNCREATE(CMFC302��2��View)

// ����
public:
	CMFC302��2��Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC302��2��View();
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
};

#ifndef _DEBUG  // MFC3.02��2��View.cpp �еĵ��԰汾
inline CMFC302��2��Doc* CMFC302��2��View::GetDocument() const
   { return reinterpret_cast<CMFC302��2��Doc*>(m_pDocument); }
#endif

