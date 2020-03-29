
// Exp8View.h : CExp8View 类的接口
//

#pragma once


class CExp8View : public CView
{
protected: // 仅从序列化创建
	CExp8View();
	DECLARE_DYNCREATE(CExp8View)

// 特性
public:
	CExp8Doc* GetDocument() const;

// 操作
public:
CRect cr;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CExp8View();
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

#ifndef _DEBUG  // Exp8View.cpp 中的调试版本
inline CExp8Doc* CExp8View::GetDocument() const
   { return reinterpret_cast<CExp8Doc*>(m_pDocument); }
#endif

