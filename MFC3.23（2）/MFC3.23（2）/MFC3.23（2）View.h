
// MFC3.23��2��View.h : CMFC323��2��View ��Ľӿ�
//

#pragma once


class CMFC323��2��View : public CView
{
protected: // �������л�����
	CMFC323��2��View();
	DECLARE_DYNCREATE(CMFC323��2��View)

// ����
public:
	CMFC323��2��Doc* GetDocument() const;

// ����
public:
	int r;
	int t;
	CRect rect;
	CPoint point;
	int a,b,c;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC323��2��View();
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
	afx_msg void OnGradualcolor();
};

#ifndef _DEBUG  // MFC3.23��2��View.cpp �еĵ��԰汾
inline CMFC323��2��Doc* CMFC323��2��View::GetDocument() const
   { return reinterpret_cast<CMFC323��2��Doc*>(m_pDocument); }
#endif

