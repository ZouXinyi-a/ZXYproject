
// DB201812300019View.cpp : CDB201812300019View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDB201812300019View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDB201812300019View ����/����

CDB201812300019View::CDB201812300019View()
	: CRecordView(CDB201812300019View::IDD)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CDB201812300019View::~CDB201812300019View()
{
}

void CDB201812300019View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
}

BOOL CDB201812300019View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB201812300019View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB201812300019Set;
	CRecordView::OnInitialUpdate();

}


// CDB201812300019View ��ӡ


void CDB201812300019View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDB201812300019View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDB201812300019View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDB201812300019View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CDB201812300019View ���

#ifdef _DEBUG
void CDB201812300019View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB201812300019View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB201812300019Doc* CDB201812300019View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB201812300019Doc)));
	return (CDB201812300019Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB201812300019View ���ݿ�֧��
CRecordset* CDB201812300019View::OnGetRecordset()
{
	return m_pSet;
}



// CDB201812300019View ��Ϣ�������
