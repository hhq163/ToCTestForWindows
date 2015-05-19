
// ToCTestClientView.cpp : CToCTestClientView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CToCTestClientView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CToCTestClientView 构造/析构

CToCTestClientView::CToCTestClientView()
{
	// TODO: 在此处添加构造代码

}

CToCTestClientView::~CToCTestClientView()
{
}

BOOL CToCTestClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CToCTestClientView 绘制

void CToCTestClientView::OnDraw(CDC* /*pDC*/)
{
	CToCTestClientDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CToCTestClientView 打印


void CToCTestClientView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CToCTestClientView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CToCTestClientView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CToCTestClientView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CToCTestClientView 诊断

#ifdef _DEBUG
void CToCTestClientView::AssertValid() const
{
	CView::AssertValid();
}

void CToCTestClientView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToCTestClientDoc* CToCTestClientView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToCTestClientDoc)));
	return (CToCTestClientDoc*)m_pDocument;
}
#endif //_DEBUG


// CToCTestClientView 消息处理程序
