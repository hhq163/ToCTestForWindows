
// ToCTestClientView.cpp : CToCTestClientView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ToCTestClient.h"
#endif

#include "ToCTestClientDoc.h"
#include "ToCTestClientView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CToCTestClientView

IMPLEMENT_DYNCREATE(CToCTestClientView, CView)

BEGIN_MESSAGE_MAP(CToCTestClientView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CToCTestClientView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CToCTestClientView ����/����

CToCTestClientView::CToCTestClientView()
{
	// TODO: �ڴ˴���ӹ������

}

CToCTestClientView::~CToCTestClientView()
{
}

BOOL CToCTestClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CToCTestClientView ����

void CToCTestClientView::OnDraw(CDC* /*pDC*/)
{
	CToCTestClientDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CToCTestClientView ��ӡ


void CToCTestClientView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CToCTestClientView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CToCTestClientView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CToCTestClientView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CToCTestClientView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CToCTestClientView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CToCTestClientView ���

#ifdef _DEBUG
void CToCTestClientView::AssertValid() const
{
	CView::AssertValid();
}

void CToCTestClientView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToCTestClientDoc* CToCTestClientView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToCTestClientDoc)));
	return (CToCTestClientDoc*)m_pDocument;
}
#endif //_DEBUG


// CToCTestClientView ��Ϣ�������
