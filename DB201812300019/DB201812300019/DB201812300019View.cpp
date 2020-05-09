
// DB201812300019View.cpp : CDB201812300019View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB201812300019.h"
#endif

#include "DB201812300019Set.h"
#include "DB201812300019Doc.h"
#include "DB201812300019View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB201812300019View

IMPLEMENT_DYNCREATE(CDB201812300019View, CRecordView)

BEGIN_MESSAGE_MAP(CDB201812300019View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDB201812300019View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDB201812300019View 构造/析构

CDB201812300019View::CDB201812300019View()
	: CRecordView(CDB201812300019View::IDD)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CDB201812300019View::~CDB201812300019View()
{
}

void CDB201812300019View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
}

BOOL CDB201812300019View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB201812300019View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB201812300019Set;
	CRecordView::OnInitialUpdate();

}


// CDB201812300019View 打印


void CDB201812300019View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDB201812300019View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDB201812300019View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDB201812300019View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDB201812300019View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDB201812300019View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDB201812300019View 诊断

#ifdef _DEBUG
void CDB201812300019View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB201812300019View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB201812300019Doc* CDB201812300019View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB201812300019Doc)));
	return (CDB201812300019Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB201812300019View 数据库支持
CRecordset* CDB201812300019View::OnGetRecordset()
{
	return m_pSet;
}



// CDB201812300019View 消息处理程序
