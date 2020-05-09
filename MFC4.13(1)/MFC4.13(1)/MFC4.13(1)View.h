
// MFC4.13(1)View.h : CMFC4131View 类的接口
//

#pragma once


class CMFC4131View : public CView
{
protected: // 仅从序列化创建
	CMFC4131View();
	DECLARE_DYNCREATE(CMFC4131View)

// 特性
public:
	CMFC4131Doc* GetDocument() const;

// 操作
public:
bool m_bl;
CRect r;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4.13(1)View.cpp 中的调试版本
inline CMFC4131Doc* CMFC4131View::GetDocument() const
   { return reinterpret_cast<CMFC4131Doc*>(m_pDocument); }
#endif

