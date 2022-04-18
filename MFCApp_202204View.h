
// MFCApp_202204View.h : interface of the CMFCApp202204View class
//

#pragma once


class CMFCApp202204View : public CView
{
protected: // create from serialization only
	CMFCApp202204View() noexcept;
	DECLARE_DYNCREATE(CMFCApp202204View)

// Attributes
public:
	CMFCApp202204Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCApp202204View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCApp_202204View.cpp
inline CMFCApp202204Doc* CMFCApp202204View::GetDocument() const
   { return reinterpret_cast<CMFCApp202204Doc*>(m_pDocument); }
#endif

