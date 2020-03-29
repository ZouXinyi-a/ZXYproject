
// Exp11View.h : CExp11View 类的接口
//

#pragma once


class CExp11View : public CView
{
protected: // 仅从序列化创建
	CExp11View();
	DECLARE_DYNCREATE(CExp11View)

// 特性
public:
	CExp11Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CExp11View();
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
};

#ifndef _DEBUG  // Exp11View.cpp 中的调试版本
inline CExp11Doc* CExp11View::GetDocument() const
   { return reinterpret_cast<CExp11Doc*>(m_pDocument); }
#endif

