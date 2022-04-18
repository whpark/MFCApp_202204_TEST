
// MFCApp_202204View.cpp : implementation of the CMFCApp202204View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApp_202204.h"
#endif

#include "MFCApp_202204Doc.h"
#include "MFCApp_202204View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApp202204View

IMPLEMENT_DYNCREATE(CMFCApp202204View, CView)

BEGIN_MESSAGE_MAP(CMFCApp202204View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApp202204View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApp202204View construction/destruction

CMFCApp202204View::CMFCApp202204View() noexcept
{
	// TODO: add construction code here

}

CMFCApp202204View::~CMFCApp202204View()
{
}

BOOL CMFCApp202204View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApp202204View drawing

void CMFCApp202204View::OnDraw(CDC* /*pDC*/)
{
	CMFCApp202204Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCApp202204View printing


void CMFCApp202204View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApp202204View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApp202204View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApp202204View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApp202204View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApp202204View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApp202204View diagnostics

#ifdef _DEBUG
void CMFCApp202204View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApp202204View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApp202204Doc* CMFCApp202204View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApp202204Doc)));
	return (CMFCApp202204Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApp202204View message handlers
