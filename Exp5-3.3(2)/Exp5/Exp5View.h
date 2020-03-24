
// Exp5View.h : CExp5View 类的接口
//

#pragma once


class CExp5View : public CView
{
protected: // 仅从序列化创建
	CExp5View();
	DECLARE_DYNCREATE(CExp5View)

// 特性
public:
	CExp5Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CExp5View();
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
};

#ifndef _DEBUG  // Exp5View.cpp 中的调试版本
inline CExp5Doc* CExp5View::GetDocument() const
   { return reinterpret_cast<CExp5Doc*>(m_pDocument); }
#endif

