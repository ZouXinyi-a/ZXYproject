
// MFC1-3.24View.h : CMFC1324View 类的接口
//

#pragma once


class CMFC1324View : public CView
{
protected: // 仅从序列化创建
	CMFC1324View();
	DECLARE_DYNCREATE(CMFC1324View)

// 特性
public:
	CMFC1324Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC1324View();
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
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFC1-3.24View.cpp 中的调试版本
inline CMFC1324Doc* CMFC1324View::GetDocument() const
   { return reinterpret_cast<CMFC1324Doc*>(m_pDocument); }
#endif

