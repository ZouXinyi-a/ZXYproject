
// MFC1-3.24View.h : CMFC1324View ��Ľӿ�
//

#pragma once


class CMFC1324View : public CView
{
protected: // �������л�����
	CMFC1324View();
	DECLARE_DYNCREATE(CMFC1324View)

// ����
public:
	CMFC1324Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC1324View();
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
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFC1-3.24View.cpp �еĵ��԰汾
inline CMFC1324Doc* CMFC1324View::GetDocument() const
   { return reinterpret_cast<CMFC1324Doc*>(m_pDocument); }
#endif

