
// MFC3.17(1)View.h : CMFC3171View 类的接口
//

#pragma once


class CMFC3171View : public CView
{
protected: // 仅从序列化创建
	CMFC3171View();
	DECLARE_DYNCREATE(CMFC3171View)

// 特性
public:
	CMFC3171Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3171View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3.17(1)View.cpp 中的调试版本
inline CMFC3171Doc* CMFC3171View::GetDocument() const
   { return reinterpret_cast<CMFC3171Doc*>(m_pDocument); }
#endif

