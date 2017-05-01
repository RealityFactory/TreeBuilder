// custom.cpp : implementation file
//

#include "stdafx.h"
#include "TreeBuilder.h"
#include "custom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// custom dialog


custom::custom(CWnd* pParent /*=NULL*/)
	: CDialog(custom::IDD, pParent)
{
	//{{AFX_DATA_INIT(custom)
	m_back = _T("");
	m_icon = _T("");
	m_replyx = _T("");
	m_replyy = _T("");
	m_replyfont = _T("");
	m_replyheight = _T("");
	m_replywidth = _T("");
	m_speakfont = _T("");
	m_speakheight = _T("");
	m_speakwidth = _T("");
	m_speakx = _T("");
	m_speaky = _T("");
	m_iconx = _T("");
	m_icony = _T("");
	//}}AFX_DATA_INIT
}


void custom::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(custom)
	DDX_Text(pDX, IDC_BACK, m_back);
	DDX_Text(pDX, IDC_ICON1, m_icon);
	DDX_Text(pDX, IDC_REPLYX, m_replyx);
	DDX_Text(pDX, IDC_REPLYY, m_replyy);
	DDX_Text(pDX, IDC_REPLYFONT, m_replyfont);
	DDX_Text(pDX, IDC_REPLYHEIGHT, m_replyheight);
	DDX_Text(pDX, IDC_REPLYWIDTH, m_replywidth);
	DDX_Text(pDX, IDC_SPEAKFONT, m_speakfont);
	DDX_Text(pDX, IDC_SPEAKHEIGHT, m_speakheight);
	DDX_Text(pDX, IDC_SPEAKWIDTH, m_speakwidth);
	DDX_Text(pDX, IDC_SPEAKX, m_speakx);
	DDX_Text(pDX, IDC_SPEAKY, m_speaky);
	DDX_Text(pDX, IDC_ICONX, m_iconx);
	DDX_Text(pDX, IDC_ICONY, m_icony);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(custom, CDialog)
	//{{AFX_MSG_MAP(custom)
	ON_BN_CLICKED(IDC_BACKBUTTON, OnBackbutton)
	ON_BN_CLICKED(IDC_ICONBUTTON, OnIconbutton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// custom message handlers

void custom::OnBackbutton() 
{
	CFileDialog dlgFile(TRUE);
	TCHAR m_dir[512];
	strcpy(m_dir, m_currentdir);
	strcat(m_dir, "\\media\\bitmaps\\conversation");
	dlgFile.m_ofn.lpstrInitialDir = m_dir;
	
	CString title, strFilter, strDefault;
	VERIFY(title.LoadString(AFX_IDS_OPENFILE));
	
	// append the files filter
	strFilter = _T("Bitmap Files (*.bmp)");
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.bmp");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	
	dlgFile.m_ofn.lpstrDefExt = "bmp";
	
	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	dlgFile.m_ofn.hwndOwner = AfxGetMainWnd()->GetSafeHwnd();
	
	if (dlgFile.DoModal() == IDOK)
	{
		POSITION pos = dlgFile.GetStartPosition();
		if(pos != NULL)
		{
			CString FileName = dlgFile.GetFileName();
			m_back = FileName;
			
			UpdateData(FALSE);
		}
	}
	chdir(m_currentdir);
}

void custom::OnIconbutton() 
{
	CFileDialog dlgFile(TRUE);
	TCHAR m_dir[512];
	strcpy(m_dir, m_currentdir);
	strcat(m_dir, "\\media\\bitmaps\\conversation");
	dlgFile.m_ofn.lpstrInitialDir = m_dir;
	
	CString title, strFilter, strDefault;
	VERIFY(title.LoadString(AFX_IDS_OPENFILE));
	
	// append the files filter
	strFilter = _T("Bitmap Files (*.bmp)");
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.bmp");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	
	dlgFile.m_ofn.lpstrDefExt = "bmp";
	
	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	dlgFile.m_ofn.hwndOwner = AfxGetMainWnd()->GetSafeHwnd();
	
	if (dlgFile.DoModal() == IDOK)
	{
		POSITION pos = dlgFile.GetStartPosition();
		if(pos != NULL)
		{
			CString FileName = dlgFile.GetFileName();
			m_icon = FileName;
			
			UpdateData(FALSE);
		}
	}
	chdir(m_currentdir);	
}
