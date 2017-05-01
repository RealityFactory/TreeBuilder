// conname.cpp : implementation file
//

#include "stdafx.h"
#include "TreeBuilder.h"
#include "conname.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// conname dialog


conname::conname(CWnd* pParent /*=NULL*/)
	: CDialog(conname::IDD, pParent)
{
	//{{AFX_DATA_INIT(conname)
	m_conn = _T("");
	//}}AFX_DATA_INIT
}


void conname::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(conname)
	DDX_Text(pDX, IDC_CONN, m_conn);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(conname, CDialog)
	//{{AFX_MSG_MAP(conname)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// conname message handlers
