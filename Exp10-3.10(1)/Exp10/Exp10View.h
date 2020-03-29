
// Exp10View.h : CExp10View 类的接口
//

#pragma once


class CExp10View : public CView
{
protected: // 仅从序列化创建
	CExp10View();
	DECLARE_DYNCREATE(CExp10View)

// 特性
public:
	CExp10Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CExp10View();
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
};

#ifndef _DEBUG  // Exp10View.cpp 中的调试版本
inline CExp10Doc* CExp10View::GetDocument() const
   { return reinterpret_cast<CExp10Doc*>(m_pDocument); }
#endif

