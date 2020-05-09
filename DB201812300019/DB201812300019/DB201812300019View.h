
// DB201812300019View.h : CDB201812300019View ��Ľӿ�
//

#pragma once

class CDB201812300019Set;

class CDB201812300019View : public CRecordView
{
protected: // �������л�����
	CDB201812300019View();
	DECLARE_DYNCREATE(CDB201812300019View)

public:
	enum{ IDD = IDD_DB201812300019_FORM };
	CDB201812300019Set* m_pSet;

// ����
public:
	CDB201812300019Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDB201812300019View();
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
	long ID;
	CString name;
	CString number;
	CString age;
	CString phone;
};

#ifndef _DEBUG  // DB201812300019View.cpp �еĵ��԰汾
inline CDB201812300019Doc* CDB201812300019View::GetDocument() const
   { return reinterpret_cast<CDB201812300019Doc*>(m_pDocument); }
#endif

