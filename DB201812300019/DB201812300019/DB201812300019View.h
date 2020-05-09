
// DB201812300019View.h : CDB201812300019View 类的接口
//

#pragma once

class CDB201812300019Set;

class CDB201812300019View : public CRecordView
{
protected: // 仅从序列化创建
	CDB201812300019View();
	DECLARE_DYNCREATE(CDB201812300019View)

public:
	enum{ IDD = IDD_DB201812300019_FORM };
	CDB201812300019Set* m_pSet;

// 特性
public:
	CDB201812300019Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDB201812300019View();
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
	long ID;
	CString name;
	CString number;
	CString age;
	CString phone;
};

#ifndef _DEBUG  // DB201812300019View.cpp 中的调试版本
inline CDB201812300019Doc* CDB201812300019View::GetDocument() const
   { return reinterpret_cast<CDB201812300019Doc*>(m_pDocument); }
#endif

