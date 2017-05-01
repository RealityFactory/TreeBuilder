// TreeBuilderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TreeBuilder.h"
#include "TreeBuilderDlg.h"
#include "convEdit.h"
#include "conname.h"
#include "custom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeBuilderDlg dialog

CTreeBuilderDlg::CTreeBuilderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeBuilderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTreeBuilderDlg)
	m_editflag1 = _T("");
	m_editflag2 = _T("");
	m_editflag3 = _T("");
	m_editflag4 = _T("");
	m_flagstate1 = -1;
	m_coname = _T("");
	m_flagstate2 = -1;
	m_flagstate3 = -1;
	m_flagstate4 = -1;
	m_editattr1 = _T("");
	m_editattr2 = _T("");
	m_editattr6 = _T("");
	m_editattr7 = _T("");
	m_attrstate1 = -1;
	m_attrstate2 = -1;
	m_attrstate3 = -1;
	m_attrstate4 = -1;
	m_editval1 = _T("");
	m_editval2 = _T("");
	m_editval6 = _T("");
	m_editval7 = _T("");
	m_fail = _T("");
	m_modflag1 = _T("");
	m_modflag2 = _T("");
	m_modflag3 = _T("");
	m_modflag4 = _T("");
	m_modflagstate1 = -1;
	m_modflagstate2 = -1;
	m_modflagstate3 = -1;
	m_modflagstate4 = -1;
	m_modattr1 = _T("");
	m_modattr2 = _T("");
	m_modattr3 = _T("");
	m_modattr4 = _T("");
	m_modval1 = _T("");
	m_modval2 = _T("");
	m_modval3 = _T("");
	m_modval4 = _T("");
	m_speak = _T("");
	m_reply1 = _T("");
	m_reply2 = _T("");
	m_reply3 = _T("");
	m_reply4 = _T("");
	m_reply5 = _T("");
	m_reply6 = _T("");
	m_replycon1 = _T("");
	m_replycon2 = _T("");
	m_replycon3 = _T("");
	m_replycon4 = _T("");
	m_replycon5 = _T("");
	m_replycon6 = _T("");
	m_replyexit1 = FALSE;
	m_replyexit2 = FALSE;
	m_replyexit3 = FALSE;
	m_replyexit4 = FALSE;
	m_replyexit5 = FALSE;
	m_replyexit6 = FALSE;
	m_speed = _T("");
	ConPtr = -1;
	m_soundfile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeBuilderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreeBuilderDlg)
	DDX_Control(pDX, IDC_SPEED, m_speedbox);
	DDX_Control(pDX, IDC_REPLYCON6, m_replycontext6);
	DDX_Control(pDX, IDC_REPLYCON5, m_replycontext5);
	DDX_Control(pDX, IDC_REPLYCON4, m_replycontext4);
	DDX_Control(pDX, IDC_REPLYCON3, m_replycontext3);
	DDX_Control(pDX, IDC_REPLYCON2, m_replycontext2);
	DDX_Control(pDX, IDC_REPLYCON1, m_replycontext1);
	DDX_Control(pDX, IDC_REPLY6, m_replytext6);
	DDX_Control(pDX, IDC_REPLY5, m_replytext5);
	DDX_Control(pDX, IDC_REPLY4, m_replytext4);
	DDX_Control(pDX, IDC_REPLY3, m_replytext3);
	DDX_Control(pDX, IDC_REPLY2, m_replytext2);
	DDX_Control(pDX, IDC_REPLY1, m_replytext1);
	DDX_Control(pDX, IDC_SPEAK, m_speaktext);
	DDX_Control(pDX, IDC_FAIL, m_failname);
	DDX_Control(pDX, IDC_CONLIST1, m_conlist1);
	DDX_Control(pDX, IDC_CONVLIST, m_convlist);
	DDX_Text(pDX, IDC_EDITFLAG1, m_editflag1);
	DDV_MaxChars(pDX, m_editflag1, 2);
	DDX_Text(pDX, IDC_EDITFLAG2, m_editflag2);
	DDV_MaxChars(pDX, m_editflag2, 2);
	DDX_Text(pDX, IDC_EDITFLAG3, m_editflag3);
	DDV_MaxChars(pDX, m_editflag3, 2);
	DDX_Text(pDX, IDC_EDITFLAG4, m_editflag4);
	DDV_MaxChars(pDX, m_editflag4, 2);
	DDX_Radio(pDX, IDC_RADIOFLAG1, m_flagstate1);
	DDX_Text(pDX, IDC_CONAME, m_coname);
	DDX_Radio(pDX, IDC_RADIOFLAG3, m_flagstate2);
	DDX_Radio(pDX, IDC_RADIOFLAG4, m_flagstate3);
	DDX_Radio(pDX, IDC_RADIOFLAG5, m_flagstate4);
	DDX_Text(pDX, IDC_EDITATTR1, m_editattr1);
	DDX_Text(pDX, IDC_EDITATTR2, m_editattr2);
	DDX_Text(pDX, IDC_EDITATTR6, m_editattr6);
	DDX_Text(pDX, IDC_EDITATTR7, m_editattr7);
	DDX_Radio(pDX, IDC_RADIOEQ1, m_attrstate1);
	DDX_Radio(pDX, IDC_RADIOEQ2, m_attrstate2);
	DDX_Radio(pDX, IDC_RADIOEQ3, m_attrstate3);
	DDX_Radio(pDX, IDC_RADIOEQ4, m_attrstate4);
	DDX_Text(pDX, IDC_EDITVAL1, m_editval1);
	DDX_Text(pDX, IDC_EDITVAL2, m_editval2);
	DDX_Text(pDX, IDC_EDITVAL6, m_editval6);
	DDX_Text(pDX, IDC_EDITVAL7, m_editval7);
	DDX_CBString(pDX, IDC_FAIL, m_fail);
	DDX_Text(pDX, IDC_EDITFLAG5, m_modflag1);
	DDX_Text(pDX, IDC_EDITFLAG6, m_modflag2);
	DDX_Text(pDX, IDC_EDITFLAG7, m_modflag3);
	DDX_Text(pDX, IDC_EDITFLAG8, m_modflag4);
	DDX_Radio(pDX, IDC_RADIOFLAG2, m_modflagstate1);
	DDX_Radio(pDX, IDC_RADIOFLAG6, m_modflagstate2);
	DDX_Radio(pDX, IDC_RADIOFLAG7, m_modflagstate3);
	DDX_Radio(pDX, IDC_RADIOFLAG8, m_modflagstate4);
	DDX_Text(pDX, IDC_EDITATTR3, m_modattr1);
	DDX_Text(pDX, IDC_EDITATTR4, m_modattr2);
	DDX_Text(pDX, IDC_EDITATTR8, m_modattr3);
	DDX_Text(pDX, IDC_EDITATTR9, m_modattr4);
	DDX_Text(pDX, IDC_EDITVAL3, m_modval1);
	DDX_Text(pDX, IDC_EDITVAL4, m_modval2);
	DDX_Text(pDX, IDC_EDITVAL8, m_modval3);
	DDX_Text(pDX, IDC_EDITVAL9, m_modval4);
	DDX_CBString(pDX, IDC_SPEAK, m_speak);
	DDX_CBString(pDX, IDC_REPLY1, m_reply1);
	DDX_CBString(pDX, IDC_REPLY2, m_reply2);
	DDX_CBString(pDX, IDC_REPLY3, m_reply3);
	DDX_CBString(pDX, IDC_REPLY4, m_reply4);
	DDX_CBString(pDX, IDC_REPLY5, m_reply5);
	DDX_CBString(pDX, IDC_REPLY6, m_reply6);
	DDX_CBString(pDX, IDC_REPLYCON1, m_replycon1);
	DDX_CBString(pDX, IDC_REPLYCON2, m_replycon2);
	DDX_CBString(pDX, IDC_REPLYCON3, m_replycon3);
	DDX_CBString(pDX, IDC_REPLYCON4, m_replycon4);
	DDX_CBString(pDX, IDC_REPLYCON5, m_replycon5);
	DDX_CBString(pDX, IDC_REPLYCON6, m_replycon6);
	DDX_Check(pDX, IDC_REPLYEXIT1, m_replyexit1);
	DDX_Check(pDX, IDC_REPLYEXIT2, m_replyexit2);
	DDX_Check(pDX, IDC_REPLYEXIT3, m_replyexit3);
	DDX_Check(pDX, IDC_REPLYEXIT4, m_replyexit4);
	DDX_Check(pDX, IDC_REPLYEXIT5, m_replyexit5);
	DDX_Check(pDX, IDC_REPLYEXIT6, m_replyexit6);
	DDX_Text(pDX, IDC_SPEED, m_speed);
	DDX_Text(pDX, IDC_SOUNDFILE, m_soundfile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTreeBuilderDlg, CDialog)
	//{{AFX_MSG_MAP(CTreeBuilderDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDCONV, OnAddconv)
	ON_BN_CLICKED(IDC_EDITCONV, OnEditconv)
	ON_BN_CLICKED(IDC_DELCONV, OnDelconv)
	ON_BN_CLICKED(IDC_SAVECONV, OnSaveconv)
	ON_BN_CLICKED(IDC_ADDCON, OnAddcon)
	ON_NOTIFY(NM_CLICK, IDC_CONLIST1, OnClickConlist1)
	ON_EN_CHANGE(IDC_EDITFLAG1, OnChangeEditflag1)
	ON_EN_CHANGE(IDC_EDITFLAG2, OnChangeEditflag2)
	ON_EN_CHANGE(IDC_EDITFLAG3, OnChangeEditflag3)
	ON_EN_CHANGE(IDC_EDITFLAG4, OnChangeEditflag4)
	ON_BN_CLICKED(IDC_RADIOFLAG1, OnRadioflag1)
	ON_BN_CLICKED(IDC_RADIOFLAG3, OnRadioflag3)
	ON_BN_CLICKED(IDC_RADIOFLAG5, OnRadioflag5)
	ON_BN_CLICKED(IDC_RADIOFLAG4, OnRadioflag4)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	ON_EN_CHANGE(IDC_EDITATTR1, OnChangeEditattr1)
	ON_EN_CHANGE(IDC_EDITATTR2, OnChangeEditattr2)
	ON_EN_CHANGE(IDC_EDITATTR6, OnChangeEditattr6)
	ON_EN_CHANGE(IDC_EDITATTR7, OnChangeEditattr7)
	ON_BN_CLICKED(IDC_RADIOEQ1, OnRadioeq1)
	ON_BN_CLICKED(IDC_RADIOGT1, OnRadiogt1)
	ON_BN_CLICKED(IDC_RADIOLT1, OnRadiolt1)
	ON_BN_CLICKED(IDC_RADIONEQ1, OnRadioneq1)
	ON_BN_CLICKED(IDC_RADIOEQ2, OnRadioeq2)
	ON_BN_CLICKED(IDC_RADIOEQ3, OnRadioeq3)
	ON_BN_CLICKED(IDC_RADIOEQ4, OnRadioeq4)
	ON_BN_CLICKED(IDC_RADIOGT2, OnRadiogt2)
	ON_BN_CLICKED(IDC_RADIOGT3, OnRadiogt3)
	ON_BN_CLICKED(IDC_RADIOGT4, OnRadiogt4)
	ON_BN_CLICKED(IDC_RADIOLT2, OnRadiolt2)
	ON_BN_CLICKED(IDC_RADIOLT3, OnRadiolt3)
	ON_BN_CLICKED(IDC_RADIOLT4, OnRadiolt4)
	ON_BN_CLICKED(IDC_RADIONEQ2, OnRadioneq2)
	ON_BN_CLICKED(IDC_RADIONEQ3, OnRadioneq3)
	ON_BN_CLICKED(IDC_RADIONEQ4, OnRadioneq4)
	ON_EN_CHANGE(IDC_EDITVAL1, OnChangeEditval1)
	ON_EN_CHANGE(IDC_EDITVAL2, OnChangeEditval2)
	ON_EN_CHANGE(IDC_EDITVAL6, OnChangeEditval6)
	ON_EN_CHANGE(IDC_EDITVAL7, OnChangeEditval7)
	ON_CBN_SELCHANGE(IDC_FAIL, OnSelchangeFail)
	ON_EN_CHANGE(IDC_EDITFLAG5, OnChangeEditflag5)
	ON_EN_CHANGE(IDC_EDITFLAG6, OnChangeEditflag6)
	ON_EN_CHANGE(IDC_EDITFLAG7, OnChangeEditflag7)
	ON_EN_CHANGE(IDC_EDITFLAG8, OnChangeEditflag8)
	ON_BN_CLICKED(IDC_RADIOFLAG2, OnRadioflag2)
	ON_BN_CLICKED(IDC_RADIOFLAG6, OnRadioflag6)
	ON_BN_CLICKED(IDC_RADIOFLAG7, OnRadioflag7)
	ON_BN_CLICKED(IDC_RADIOFLAG8, OnRadioflag8)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO7, OnRadio7)
	ON_BN_CLICKED(IDC_RADIO8, OnRadio8)
	ON_BN_CLICKED(IDC_RADIO9, OnRadio9)
	ON_EN_CHANGE(IDC_EDITATTR3, OnChangeEditattr3)
	ON_EN_CHANGE(IDC_EDITATTR4, OnChangeEditattr4)
	ON_EN_CHANGE(IDC_EDITATTR8, OnChangeEditattr8)
	ON_EN_CHANGE(IDC_EDITATTR9, OnChangeEditattr9)
	ON_EN_CHANGE(IDC_EDITVAL3, OnChangeEditval3)
	ON_EN_CHANGE(IDC_EDITVAL4, OnChangeEditval4)
	ON_EN_CHANGE(IDC_EDITVAL8, OnChangeEditval8)
	ON_EN_CHANGE(IDC_EDITVAL9, OnChangeEditval9)
	ON_CBN_SELCHANGE(IDC_SPEAK, OnSelchangeSpeak)
	ON_CBN_SELCHANGE(IDC_REPLY1, OnSelchangeReply1)
	ON_CBN_SELCHANGE(IDC_REPLY2, OnSelchangeReply2)
	ON_CBN_SELCHANGE(IDC_REPLY3, OnSelchangeReply3)
	ON_CBN_SELCHANGE(IDC_REPLY4, OnSelchangeReply4)
	ON_CBN_SELCHANGE(IDC_REPLY5, OnSelchangeReply5)
	ON_CBN_SELCHANGE(IDC_REPLY6, OnSelchangeReply6)
	ON_CBN_SELCHANGE(IDC_REPLYCON1, OnSelchangeReplycon1)
	ON_CBN_SELCHANGE(IDC_REPLYCON2, OnSelchangeReplycon2)
	ON_CBN_SELCHANGE(IDC_REPLYCON3, OnSelchangeReplycon3)
	ON_CBN_SELCHANGE(IDC_REPLYCON4, OnSelchangeReplycon4)
	ON_CBN_SELCHANGE(IDC_REPLYCON5, OnSelchangeReplycon5)
	ON_CBN_SELCHANGE(IDC_REPLYCON6, OnSelchangeReplycon6)
	ON_BN_CLICKED(IDC_REPLYEXIT1, OnReplyexit1)
	ON_BN_CLICKED(IDC_REPLYEXIT2, OnReplyexit2)
	ON_BN_CLICKED(IDC_REPLYEXIT3, OnReplyexit3)
	ON_BN_CLICKED(IDC_REPLYEXIT4, OnReplyexit4)
	ON_BN_CLICKED(IDC_REPLYEXIT5, OnReplyexit5)
	ON_BN_CLICKED(IDC_REPLYEXIT6, OnReplyexit6)
	ON_BN_CLICKED(IDC_DELCON, OnDelcon)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_LOAD, OnLoad)
	ON_BN_CLICKED(IDC_SCRIPT, OnScript)
	ON_EN_CHANGE(IDC_SPEED, OnChangeSpeed)
	ON_BN_CLICKED(IDC_SNDBUTTON, OnSndbutton)
	ON_EN_CHANGE(IDC_SOUNDFILE, OnChangeSoundfile)
	ON_BN_CLICKED(IDC_CUSTOM, OnCustom)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeBuilderDlg message handlers

BOOL CTreeBuilderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	_chdir("..");
	_getcwd(m_currentdir, 512);

	LoadConv();
	m_conlist1.SetHeadings( _T("Name,119") );
	m_conlist1.LoadColumnInfo();
	ConData.SetSize(0);
	m_failname.ReadOnly();
	m_failname.AddString(" ");
	m_speaktext.ReadOnly();
	m_replytext1.ReadOnly();
	m_replytext2.ReadOnly();
	m_replytext3.ReadOnly();
	m_replytext4.ReadOnly();
	m_replytext5.ReadOnly();
	m_replytext6.ReadOnly();
	m_replycontext1.ReadOnly();
	m_replycontext2.ReadOnly();
	m_replycontext3.ReadOnly();
	m_replycontext4.ReadOnly();
	m_replycontext5.ReadOnly();
	m_replycontext6.ReadOnly();
	m_replycontext1.AddString(" ");
	m_replycontext2.AddString(" ");
	m_replycontext3.AddString(" ");
	m_replycontext4.AddString(" ");
	m_replycontext5.AddString(" ");
	m_replycontext6.AddString(" ");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTreeBuilderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTreeBuilderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CTreeBuilderDlg::LoadConv()
{
	FILE *fdInput = NULL;
	char szInputLine[256];
	CString readinfo, keyname, text;

	Text.SetSize(0);

	if((fdInput = fopen("install\\conversation.txt", "rt")) == NULL)
	{
		m_convlist.SetHeadings( _T("Name,100;Text,358") );
		m_convlist.LoadColumnInfo();
		return;
	}

	keyname = "";
	text = "";

	while(fgets(szInputLine, 256, fdInput) != NULL)
	{
		if(strlen(szInputLine) <= 1)
			readinfo = "";
		else
			readinfo = szInputLine;

		if (readinfo != "" && readinfo[0] != ';')
		{
			readinfo.TrimRight();
			if (readinfo[0] == '[' && readinfo[readinfo.GetLength()-1] == ']')
			{
				if(keyname!="" && text!="")
				{
					Text.SetSize(Text.GetSize()+1);
					int keynum = Text.GetSize()-1;
					Text[keynum].Name = keyname;
					Text[keynum].Text = text;
				}
				keyname = readinfo;
				keyname.TrimLeft('[');
				keyname.TrimRight(']');
				text = "";
			}
			else
			{
				if(readinfo=="<CR>")
				{
					text+=" ";
					text.SetAt(text.GetLength()-1, (char)1);
				}
				else
				{
					if(text!="" && text[text.GetLength()-1]!=1)
						text+=" ";
					text+=readinfo;
				}
			}
		}
	}
	if(keyname!="" && text!="")
	{
		Text.SetSize(Text.GetSize()+1);
		int keynum = Text.GetSize()-1;
		Text[keynum].Name = keyname;
		Text[keynum].Text = text;
	}
	fclose(fdInput);
	m_convlist.SetHeadings( _T("Name,100;Text,358") );
	m_convlist.LoadColumnInfo();
	int size = Text.GetSize();
	if(size<1)
		return;
	m_replytext1.AddString(" ");
	m_replytext2.AddString(" ");
	m_replytext3.AddString(" ");
	m_replytext4.AddString(" ");
	m_replytext5.AddString(" ");
	m_replytext6.AddString(" ");
	for(int i=0;i<size;i++)
	{
		(void)m_convlist.AddItem( _T(Text[i].Name), _T(Text[i].Text) );
		m_speaktext.AddString(Text[i].Name);
		m_replytext1.AddString(Text[i].Name);
		m_replytext2.AddString(Text[i].Name);
		m_replytext3.AddString(Text[i].Name);
		m_replytext4.AddString(Text[i].Name);
		m_replytext5.AddString(Text[i].Name);
		m_replytext6.AddString(Text[i].Name);
	}

}

// Add Conversation to list

void CTreeBuilderDlg::OnAddconv() 
{
	convEdit dlg(NULL);

	dlg.m_cname = "";
	dlg.m_ctext = "";
	if(dlg.DoModal())
	{
		if(dlg.m_cname != "" && dlg.m_ctext != "")
		{
			(void)m_convlist.AddItem( _T(dlg.m_cname), _T(dlg.m_ctext) );
			m_speaktext.AddString(dlg.m_cname);
			m_replytext1.AddString(dlg.m_cname);
			m_replytext2.AddString(dlg.m_cname);
			m_replytext3.AddString(dlg.m_cname);
			m_replytext4.AddString(dlg.m_cname);
			m_replytext5.AddString(dlg.m_cname);
			m_replytext6.AddString(dlg.m_cname);
		}
	}
}

// Edit Conversation text

void CTreeBuilderDlg::OnEditconv() 
{
	POSITION pos = m_convlist.GetFirstSelectedItemPosition();
	if(pos)
	{
		int nItem = m_convlist.GetNextSelectedItem(pos);
		convEdit dlg(NULL);
		dlg.m_cname = m_convlist.GetItemText(nItem, 0);
		dlg.m_ctext = m_convlist.GetItemText(nItem, 1);
		if(dlg.DoModal())
		{
			if(dlg.m_cname != "" && dlg.m_ctext != "")
			{
				//m_convlist.SetItemText(nItem, 0, dlg.m_cname);
				m_convlist.SetItemText(nItem, 1, dlg.m_ctext);
			}
		}
	}
}

// Delete conversation from list

void CTreeBuilderDlg::OnDelconv() 
{
	POSITION pos = m_convlist.GetFirstSelectedItemPosition();
	if(pos)
	{
		int nItem = m_convlist.GetNextSelectedItem(pos);
		CString name = "Really Delete the Item named " + m_convlist.GetItemText(nItem, 0);
		if(AfxMessageBox(name, MB_YESNO)==IDYES)
		{
			int keynum = ConData.GetSize();
			
			for(int i=0;i<keynum;i++)
			{
				if(ConData[i].SpeakText==m_convlist.GetItemText(nItem, 0))
					ConData[i].SpeakText = " ";
				if(ConData[i].ReplyText1==m_convlist.GetItemText(nItem, 0))
					ConData[i].ReplyText1 = " ";
				if(ConData[i].ReplyText2==m_convlist.GetItemText(nItem, 0))
					ConData[i].ReplyText2 = " ";
				if(ConData[i].ReplyText3==m_convlist.GetItemText(nItem, 0))
					ConData[i].ReplyText3 = " ";
				if(ConData[i].ReplyText4==m_convlist.GetItemText(nItem, 0))
					ConData[i].ReplyText4 = " ";
				if(ConData[i].ReplyText5==m_convlist.GetItemText(nItem, 0))
					ConData[i].ReplyText5 = " ";
				if(ConData[i].ReplyText6==m_convlist.GetItemText(nItem, 0))
					ConData[i].ReplyText6 = " ";
			}

			CString LB;
			int index = m_speaktext.FindStringExact(-1, m_convlist.GetItemText(nItem, 0));
			m_speaktext.GetLBText(index, LB);
			if(LB==m_convlist.GetItemText(nItem, 0))
				m_speak = "";
			m_speaktext.DeleteString(index);
			index = m_replytext1.FindStringExact(-1, m_convlist.GetItemText(nItem, 0));
			m_replytext1.GetLBText(index, LB);
			if(LB==m_convlist.GetItemText(nItem, 0))
				m_reply1 = "";
			m_replytext1.DeleteString(index);
			index = m_replytext2.FindStringExact(-1, m_convlist.GetItemText(nItem, 0));
			m_replytext2.GetLBText(index, LB);
			if(LB==m_convlist.GetItemText(nItem, 0))
				m_reply2 = "";
			m_replytext2.DeleteString(index);
			index = m_replytext3.FindStringExact(-1, m_convlist.GetItemText(nItem, 0));
			m_replytext3.GetLBText(index, LB);
			if(LB==m_convlist.GetItemText(nItem, 0))
				m_reply3 = "";
			m_replytext3.DeleteString(index);
			index = m_replytext4.FindStringExact(-1, m_convlist.GetItemText(nItem, 0));
			m_replytext4.GetLBText(index, LB);
			if(LB==m_convlist.GetItemText(nItem, 0))
				m_reply4 = "";
			m_replytext4.DeleteString(index);
			index = m_replytext5.FindStringExact(-1, m_convlist.GetItemText(nItem, 0));
			m_replytext5.GetLBText(index, LB);
			if(LB==m_convlist.GetItemText(nItem, 0))
				m_reply5 = "";
			m_replytext5.DeleteString(index);
			index = m_replytext6.FindStringExact(-1, m_convlist.GetItemText(nItem, 0));
			m_replytext6.GetLBText(index, LB);
			if(LB==m_convlist.GetItemText(nItem, 0))
				m_reply6 = "";
			m_replytext6.DeleteString(index);
			m_convlist.DeleteItem(nItem);
			UpdateData(FALSE);
		}
	}
}

// Save to Conversation.txt

void CTreeBuilderDlg::OnSaveconv() 
{
	FILE *fdOutput = NULL;
	TCHAR m_dir[512];
	strcpy(m_dir, m_currentdir);
	strcat(m_dir, "\\install\\conversation.txt");
	int size = m_convlist.GetItemCount( );
	if(size>0)
	{
		if((fdOutput = fopen(m_dir, "wt")) == NULL)
			return;
		CString name, text, line;
		for(int i=0;i<size;i++)
		{
			name = m_convlist.GetItemText(i, 0);
			text = m_convlist.GetItemText(i, 1);
			name = "[" + name;
			name +="]";
			fputs(name, fdOutput);
			fputs("\n", fdOutput);
			int lastsp = -1;
			int linestart = 0;
			int start = 0;
			line = "";
			while(start<text.GetLength())
			{
				if(text.Mid(start,1)=="\n")
				{
					if(line!="")
					{
						fputs(line, fdOutput);
						fputs("\n", fdOutput);
					}
					linestart = start+1;
					line = "";
					lastsp = -1;
					start +=1;
				}
				else
				{
					if(text.Mid(start,1)==" ")
						lastsp = start;
					line += text.Mid(start,1);
					if(line.GetLength()>=90)
					{
						if(lastsp!=-1 && lastsp>linestart)
						{
							line = text.Mid(linestart, lastsp-linestart);
							start = lastsp;
						}
						linestart = start+1;
						fputs(line, fdOutput);
						fputs("\n", fdOutput);
						line = "";
						lastsp = -1;
					}
					start +=1;
				}
			}
			if(line!="")
			{
				fputs(line, fdOutput);
				fputs("\n", fdOutput);
			}

			fputs("\n", fdOutput);
		}
		fclose(fdOutput);
		AfxMessageBox("Conversation Text Saved", MB_OK);
	}
}

// Add conversation name to list

void CTreeBuilderDlg::OnAddcon() 
{
	conname dlg(NULL);
	
	if(dlg.DoModal())
	{
		if(dlg.m_conn != "")
		{
			int max = m_conlist1.GetItemCount();
			if(max>0)
			{
				for(int i=0;i<max;i++)
				{
					if(m_conlist1.GetItemText(i, 0)==dlg.m_conn)
					{
						AfxMessageBox("Duplicate Conversation Name", MB_OK);
						return;
					}
				}
			}
			(void)m_conlist1.AddItem( _T(dlg.m_conn));

			m_failname.AddString(dlg.m_conn);
			m_replycontext1.AddString(dlg.m_conn);
			m_replycontext2.AddString(dlg.m_conn);
			m_replycontext3.AddString(dlg.m_conn);
			m_replycontext4.AddString(dlg.m_conn);
			m_replycontext5.AddString(dlg.m_conn);
			m_replycontext6.AddString(dlg.m_conn);

			ConData.SetSize(ConData.GetSize()+1);
			int keynum = ConData.GetSize()-1;
			ConData[keynum].Name = dlg.m_conn;
			for(int i=0;i<4;i++)
			{
				ConData[keynum].Flag[i] = -1;
				ConData[keynum].FlagState[i] = 1;
				ConData[keynum].Attribute[i] = "";
				ConData[keynum].AttrTest[i] = 0;
				ConData[keynum].AttrAmount[i] = 0;
				ConData[keynum].ModFlag[i] = -1;
				ConData[keynum].ModFlagState[i] = 1;
				ConData[keynum].ModAttribute[i] = "";
				ConData[keynum].ModAttrAmount[i] = 0;
			}
			ConData[keynum].FailName = "";
			ConData[keynum].SpeakText = "";
			ConData[keynum].SpeakFile = "";
			ConData[keynum].SpeakSpeed = 0;
			ConData[keynum].ReplyText1 = "";
			ConData[keynum].ReplyText2 = "";
			ConData[keynum].ReplyText3 = "";
			ConData[keynum].ReplyText4 = "";
			ConData[keynum].ReplyText5 = "";
			ConData[keynum].ReplyText6 = "";
			ConData[keynum].ReplyCon1 = "";
			ConData[keynum].ReplyCon2 = "";
			ConData[keynum].ReplyCon3 = "";
			ConData[keynum].ReplyCon4 = "";
			ConData[keynum].ReplyCon5 = "";
			ConData[keynum].ReplyCon6 = "";
			ConData[keynum].ReplyExit1 = FALSE;
			ConData[keynum].ReplyExit2 = FALSE;
			ConData[keynum].ReplyExit3 = FALSE;
			ConData[keynum].ReplyExit4 = FALSE;
			ConData[keynum].ReplyExit5 = FALSE;
			ConData[keynum].ReplyExit6 = FALSE;
			ConData[keynum].Background = "";
			ConData[keynum].Icon = "";
			ConData[keynum].IconX = -1;
			ConData[keynum].IconY = -1;
			ConData[keynum].SpeakX = -1;
			ConData[keynum].SpeakY = -1;
			ConData[keynum].SpeakWidth = -1;
			ConData[keynum].SpeakHeight = -1;
			ConData[keynum].SpeakFont = -1;
			ConData[keynum].ReplyX = -1;
			ConData[keynum].ReplyY = -1;
			ConData[keynum].ReplyWidth = -1;
			ConData[keynum].ReplyHeight = -1;
			ConData[keynum].ReplyFont = -1;
		}
	}
}

// Select Conversation from list and setup all data

void CTreeBuilderDlg::OnClickConlist1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i;
	POSITION pos = m_conlist1.GetFirstSelectedItemPosition();
	if(pos)
	{
		int nItem = m_conlist1.GetNextSelectedItem(pos);
		CString name = m_conlist1.GetItemText(nItem, 0);
		m_coname = name;
		int keynum = ConData.GetSize();
		for(i=0;i<keynum;i++)
		{
			if(ConData[i].Name==name)
				break;
		}

		ConPtr = i;
		//
		// Flag testing
		//
		m_editflag1 = "";
		m_flagstate1 = 1;
		if(ConData[i].Flag[0]!=-1)
		{
			m_editflag1.Format("%d", ConData[i].Flag[0]);
			m_flagstate1 = ConData[i].FlagState[0];
		}
		m_editflag2 = "";
		m_flagstate2 = 1;
		if(ConData[i].Flag[1]!=-1)
		{
			m_editflag2.Format("%d", ConData[i].Flag[1]);
			m_flagstate2 = ConData[i].FlagState[1];
		}
		m_editflag3 = "";
		m_flagstate3 = 1;
		if(ConData[i].Flag[2]!=-1)
		{
			m_editflag3.Format("%d", ConData[i].Flag[2]);
			m_flagstate3 = ConData[i].FlagState[2];
		}
		m_editflag4 = "";
		m_flagstate4 = 1;
		if(ConData[i].Flag[3]!=-1)
		{
			m_editflag4.Format("%d", ConData[i].Flag[3]);
			m_flagstate4 = ConData[i].FlagState[3];
		}

		// 
		// Attribute testing
		//
		m_editattr1 = ConData[i].Attribute[0];
		m_attrstate1 = ConData[i].AttrTest[0];
		m_editval1.Format("%d", ConData[i].AttrAmount[0]);
		m_editattr2 = ConData[i].Attribute[1];
		m_attrstate2 = ConData[i].AttrTest[1];
		m_editval2.Format("%d", ConData[i].AttrAmount[1]);
		m_editattr6 = ConData[i].Attribute[2];
		m_attrstate3 = ConData[i].AttrTest[2];
		m_editval6.Format("%d", ConData[i].AttrAmount[2]);
		m_editattr7 = ConData[i].Attribute[3];
		m_attrstate4 = ConData[i].AttrTest[3];
		m_editval7.Format("%d", ConData[i].AttrAmount[3]);

		m_fail = ConData[i].FailName;

		// Flag modifications

		m_modflag1 = "";
		m_modflagstate1 = 1;
		if(ConData[i].ModFlag[0]!=-1)
		{
			m_modflag1.Format("%d", ConData[i].ModFlag[0]);
			m_modflagstate1 = ConData[i].ModFlagState[0];
		}
		m_modflag2 = "";
		m_modflagstate2 = 1;
		if(ConData[i].ModFlag[1]!=-1)
		{
			m_modflag2.Format("%d", ConData[i].ModFlag[1]);
			m_modflagstate2 = ConData[i].ModFlagState[1];
		}
		m_modflag3 = "";
		m_modflagstate3 = 1;
		if(ConData[i].ModFlag[2]!=-1)
		{
			m_modflag3.Format("%d", ConData[i].ModFlag[2]);
			m_modflagstate3 = ConData[i].ModFlagState[2];
		}
		m_modflag4 = "";
		m_modflagstate4 = 1;
		if(ConData[i].ModFlag[3]!=-1)
		{
			m_modflag4.Format("%d", ConData[i].ModFlag[3]);
			m_modflagstate4 = ConData[i].ModFlagState[3];
		}

		// 
		// Attribute modification
		//
		m_modattr1 = ConData[i].ModAttribute[0];
		m_modval1.Format("%d", ConData[i].ModAttrAmount[0]);
		m_modattr2 = ConData[i].ModAttribute[1];
		m_modval2.Format("%d", ConData[i].ModAttrAmount[1]);
		m_modattr3 = ConData[i].ModAttribute[2];
		m_modval3.Format("%d", ConData[i].ModAttrAmount[2]);
		m_modattr4 = ConData[i].ModAttribute[3];
		m_modval4.Format("%d", ConData[i].ModAttrAmount[3]);

		m_speak = ConData[i].SpeakText;
		m_soundfile = ConData[i].SpeakFile;
		m_speed.Format("%d", ConData[i].SpeakSpeed);
		m_reply1 = ConData[i].ReplyText1;
		m_reply2 = ConData[i].ReplyText2;
		m_reply3 = ConData[i].ReplyText3;
		m_reply4 = ConData[i].ReplyText4;
		m_reply5 = ConData[i].ReplyText5;
		m_reply6 = ConData[i].ReplyText6;
		m_replycon1 = ConData[i].ReplyCon1;
		m_replycon2 = ConData[i].ReplyCon2;
		m_replycon3 = ConData[i].ReplyCon3;
		m_replycon4 = ConData[i].ReplyCon4;
		m_replycon5 = ConData[i].ReplyCon5;
		m_replycon6 = ConData[i].ReplyCon6;
		m_replyexit1 = ConData[i].ReplyExit1;
		m_replyexit2 = ConData[i].ReplyExit2;
		m_replyexit3 = ConData[i].ReplyExit3;
		m_replyexit4 = ConData[i].ReplyExit4;
		m_replyexit5 = ConData[i].ReplyExit5;
		m_replyexit6 = ConData[i].ReplyExit6;
		Background = ConData[i].Background;
		Icon = ConData[i].Icon;
		SpeakX = ConData[i].SpeakX;
		SpeakY = ConData[i].SpeakY;
		SpeakWidth = ConData[i].SpeakWidth;
		SpeakHeight = ConData[i].SpeakHeight;
		SpeakFont = ConData[i].SpeakFont;
		ReplyX = ConData[i].ReplyX;
		ReplyY = ConData[i].ReplyY;
		ReplyWidth = ConData[i].ReplyWidth;
		ReplyHeight = ConData[i].ReplyHeight;
		ReplyFont = ConData[i].ReplyFont;
		
		UpdateData(FALSE);
	}
	
	*pResult = 0;
}

//********************************************
//
// Conditional Testing Flag Number changing
//
//********************************************

void CTreeBuilderDlg::OnChangeEditflag1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		if(m_editflag1=="")
		{
			ConData[ConPtr].Flag[0] = -1;
			return;
		}
		int flag = _ttoi(m_editflag1);
		if(flag>=0)
			ConData[ConPtr].Flag[0] = flag;
	}
}

void CTreeBuilderDlg::OnChangeEditflag2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		if(m_editflag2=="")
		{
			ConData[ConPtr].Flag[1] = -1;
			return;
		}
		int flag = _ttoi(m_editflag2);
		if(flag>=0)
			ConData[ConPtr].Flag[1] = flag;
	}
}

void CTreeBuilderDlg::OnChangeEditflag3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		if(m_editflag3=="")
		{
			ConData[ConPtr].Flag[2] = -1;
			return;
		}
		int flag = _ttoi(m_editflag3);
		if(flag>=0)
			ConData[ConPtr].Flag[2] = flag;
	}
}

void CTreeBuilderDlg::OnChangeEditflag4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		if(m_editflag4=="")
		{
			ConData[ConPtr].Flag[3] = -1;
			return;
		}
		int flag = _ttoi(m_editflag4);
		if(flag>=0)
			ConData[ConPtr].Flag[3] = flag;
	}
}

//********************************************
//
// Conditional Testing Flag State changing
//
//********************************************
void CTreeBuilderDlg::OnRadioflag1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].FlagState[0] = m_flagstate1;
	}
}

void CTreeBuilderDlg::OnRadioflag3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].FlagState[1] = m_flagstate2;
	}	
}

void CTreeBuilderDlg::OnRadioflag5() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].FlagState[3] = m_flagstate4;
	}	
}

void CTreeBuilderDlg::OnRadioflag4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].FlagState[2] = m_flagstate3;
	}	
}


void CTreeBuilderDlg::OnRadio2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].FlagState[0] = m_flagstate1;
	}	
}

void CTreeBuilderDlg::OnRadio4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].FlagState[1] = m_flagstate2;
	}	
}

void CTreeBuilderDlg::OnRadio5() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].FlagState[2] = m_flagstate3;
	}		
}

void CTreeBuilderDlg::OnRadio6() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].FlagState[3] = m_flagstate4;
	}	
}

//********************************************
//
// Conditional Testing Attribute name change
//
//********************************************

void CTreeBuilderDlg::OnChangeEditattr1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].Attribute[0] = m_editattr1;
	}
}

void CTreeBuilderDlg::OnChangeEditattr2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].Attribute[1] = m_editattr2;
	}
}

void CTreeBuilderDlg::OnChangeEditattr6() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].Attribute[2] = m_editattr6;
	}
}

void CTreeBuilderDlg::OnChangeEditattr7() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].Attribute[3] = m_editattr7;
	}
}

//********************************************
//
// Conditional Testing Attribute test
//
//********************************************

void CTreeBuilderDlg::OnRadioeq1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[0] = m_attrstate1;
	}	
}

void CTreeBuilderDlg::OnRadiogt1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[0] = m_attrstate1;
	}	
}

void CTreeBuilderDlg::OnRadiolt1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[0] = m_attrstate1;
	}	
}

void CTreeBuilderDlg::OnRadioneq1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[0] = m_attrstate1;
	}	
}

void CTreeBuilderDlg::OnRadioeq2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[1] = m_attrstate2;
	}	
}

void CTreeBuilderDlg::OnRadioeq3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[2] = m_attrstate3;
	}	
}

void CTreeBuilderDlg::OnRadioeq4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[3] = m_attrstate4;
	}	
}

void CTreeBuilderDlg::OnRadiogt2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[1] = m_attrstate2;
	}	
}

void CTreeBuilderDlg::OnRadiogt3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[2] = m_attrstate3;
	}	
}

void CTreeBuilderDlg::OnRadiogt4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[3] = m_attrstate4;
	}	
}

void CTreeBuilderDlg::OnRadiolt2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[1] = m_attrstate2;
	}	
}

void CTreeBuilderDlg::OnRadiolt3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[2] = m_attrstate3;
	}
}

void CTreeBuilderDlg::OnRadiolt4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[3] = m_attrstate4;
	}	
}

void CTreeBuilderDlg::OnRadioneq2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[1] = m_attrstate2;
	}	
}

void CTreeBuilderDlg::OnRadioneq3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[2] = m_attrstate3;
	}	
}

void CTreeBuilderDlg::OnRadioneq4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrTest[3] = m_attrstate4;
	}
}

//********************************************
//
// Conditional Testing Attribute amount
//
//********************************************

void CTreeBuilderDlg::OnChangeEditval1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrAmount[0] = _ttoi(m_editval1);
	}
}

void CTreeBuilderDlg::OnChangeEditval2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrAmount[1] = _ttoi(m_editval2);
	}
}

void CTreeBuilderDlg::OnChangeEditval6() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrAmount[2] = _ttoi(m_editval6);
	}
}

void CTreeBuilderDlg::OnChangeEditval7() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].AttrAmount[3] = _ttoi(m_editval7);
	}
}

//*************************************************
//
// Conditional Testing Conversation Name on Failure
//
//*************************************************

void CTreeBuilderDlg::OnSelchangeFail() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_failname.GetCurSel();
		m_failname.GetLBText(index, ConData[ConPtr].FailName);
	}	
}

//********************************************
//
// Modification Flag Number changing
//
//********************************************

void CTreeBuilderDlg::OnChangeEditflag5() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		if(m_modflag1=="")
		{
			ConData[ConPtr].ModFlag[0] = -1;
			return;
		}
		int flag = _ttoi(m_modflag1);
		if(flag>=0)
			ConData[ConPtr].ModFlag[0] = flag;
	}
}

void CTreeBuilderDlg::OnChangeEditflag6() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		if(m_modflag2=="")
		{
			ConData[ConPtr].ModFlag[1] = -1;
			return;
		}
		int flag = _ttoi(m_modflag2);
		if(flag>=0)
			ConData[ConPtr].ModFlag[1] = flag;
	}
}

void CTreeBuilderDlg::OnChangeEditflag7() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		if(m_modflag3=="")
		{
			ConData[ConPtr].ModFlag[2] = -1;
			return;
		}
		int flag = _ttoi(m_modflag3);
		if(flag>=0)
			ConData[ConPtr].ModFlag[2] = flag;
	}
}

void CTreeBuilderDlg::OnChangeEditflag8() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		if(m_modflag4=="")
		{
			ConData[ConPtr].ModFlag[3] = -1;
			return;
		}
		int flag = _ttoi(m_modflag4);
		if(flag>=0)
			ConData[ConPtr].ModFlag[3] = flag;
	}
}

//********************************************
//
// Modification Flag State changing
//
//********************************************

void CTreeBuilderDlg::OnRadioflag2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModFlagState[0] = m_modflagstate1;
	}	
}

void CTreeBuilderDlg::OnRadioflag6() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModFlagState[1] = m_modflagstate2;
	}		
}

void CTreeBuilderDlg::OnRadioflag7() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModFlagState[2] = m_modflagstate3;
	}	
}

void CTreeBuilderDlg::OnRadioflag8() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModFlagState[3] = m_modflagstate4;
	}	
}

void CTreeBuilderDlg::OnRadio3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModFlagState[0] = m_modflagstate1;
	}		
}

void CTreeBuilderDlg::OnRadio7() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModFlagState[1] = m_modflagstate2;
	}	
}

void CTreeBuilderDlg::OnRadio8() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModFlagState[2] = m_modflagstate3;
	}	
}

void CTreeBuilderDlg::OnRadio9() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModFlagState[3] = m_modflagstate4;
	}	
}

//********************************************
//
// Modification Attribute name
//
//********************************************

void CTreeBuilderDlg::OnChangeEditattr3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModAttribute[0] = m_modattr1;
	}
}

void CTreeBuilderDlg::OnChangeEditattr4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModAttribute[1] = m_modattr2;
	}
}

void CTreeBuilderDlg::OnChangeEditattr8() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModAttribute[2] = m_modattr3;
	}
}

void CTreeBuilderDlg::OnChangeEditattr9() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModAttribute[3] = m_modattr4;
	}
}

//********************************************
//
// Modification Attribute amount
//
//********************************************

void CTreeBuilderDlg::OnChangeEditval3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModAttrAmount[0] = _ttoi(m_modval1);
	}	
}

void CTreeBuilderDlg::OnChangeEditval4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModAttrAmount[1] = _ttoi(m_modval2);
	}	
}

void CTreeBuilderDlg::OnChangeEditval8() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModAttrAmount[2] = _ttoi(m_modval3);
	}
}

void CTreeBuilderDlg::OnChangeEditval9() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ModAttrAmount[3] = _ttoi(m_modval4);
	}
}

//********************************************
//
// Pawn Speak Text
//
//********************************************

void CTreeBuilderDlg::OnSelchangeSpeak() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_speaktext.GetCurSel();
		m_speaktext.GetLBText(index, ConData[ConPtr].SpeakText);
	}		
}

//********************************************
//
// Player Reply Text
//
//********************************************

void CTreeBuilderDlg::OnSelchangeReply1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replytext1.GetCurSel();
		m_replytext1.GetLBText(index, ConData[ConPtr].ReplyText1);
	}		
}

void CTreeBuilderDlg::OnSelchangeReply2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replytext2.GetCurSel();
		m_replytext2.GetLBText(index, ConData[ConPtr].ReplyText2);
	}		
}

void CTreeBuilderDlg::OnSelchangeReply3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replytext3.GetCurSel();
		m_replytext3.GetLBText(index, ConData[ConPtr].ReplyText3);
	}		
}

void CTreeBuilderDlg::OnSelchangeReply4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replytext4.GetCurSel();
		m_replytext4.GetLBText(index, ConData[ConPtr].ReplyText4);
	}		
}

void CTreeBuilderDlg::OnSelchangeReply5() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replytext5.GetCurSel();
		m_replytext5.GetLBText(index, ConData[ConPtr].ReplyText5);
	}		
}

void CTreeBuilderDlg::OnSelchangeReply6() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replytext6.GetCurSel();
		m_replytext6.GetLBText(index, ConData[ConPtr].ReplyText6);
	}		
}

//********************************************
//
// Player Reply Conversation name
//
//********************************************

void CTreeBuilderDlg::OnSelchangeReplycon1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replycontext1.GetCurSel();
		m_replycontext1.GetLBText(index, ConData[ConPtr].ReplyCon1);
	}	
}

void CTreeBuilderDlg::OnSelchangeReplycon2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replycontext2.GetCurSel();
		m_replycontext2.GetLBText(index, ConData[ConPtr].ReplyCon2);
	}	
}

void CTreeBuilderDlg::OnSelchangeReplycon3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replycontext3.GetCurSel();
		m_replycontext3.GetLBText(index, ConData[ConPtr].ReplyCon3);
	}
}

void CTreeBuilderDlg::OnSelchangeReplycon4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replycontext4.GetCurSel();
		m_replycontext4.GetLBText(index, ConData[ConPtr].ReplyCon4);
	}	
}

void CTreeBuilderDlg::OnSelchangeReplycon5() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replycontext5.GetCurSel();
		m_replycontext5.GetLBText(index, ConData[ConPtr].ReplyCon5);
	}	
}

void CTreeBuilderDlg::OnSelchangeReplycon6() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		int index = m_replycontext6.GetCurSel();
		m_replycontext6.GetLBText(index, ConData[ConPtr].ReplyCon6);
	}	
}

//********************************************
//
// Player Reply Exit flag
//
//********************************************

void CTreeBuilderDlg::OnReplyexit1() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ReplyExit1 = m_replyexit1;
	}	
}

void CTreeBuilderDlg::OnReplyexit2() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ReplyExit2 = m_replyexit2;
	}
}

void CTreeBuilderDlg::OnReplyexit3() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ReplyExit3 = m_replyexit3;
	}	
}

void CTreeBuilderDlg::OnReplyexit4() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ReplyExit4 = m_replyexit4;
	}	
}

void CTreeBuilderDlg::OnReplyexit5() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ReplyExit5 = m_replyexit5;
	}	
}

void CTreeBuilderDlg::OnReplyexit6() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].ReplyExit6 = m_replyexit6;
	}	
}

//********************************************
//
// Delete Conversation
//
//********************************************

void CTreeBuilderDlg::OnDelcon() 
{
	POSITION pos = m_conlist1.GetFirstSelectedItemPosition();
	if(pos)
	{
		int nItem = m_conlist1.GetNextSelectedItem(pos);
		CString name = "Really Delete the Conversation named " + m_conlist1.GetItemText(nItem, 0);
		if(AfxMessageBox(name, MB_YESNO)==IDYES)
		{
			int keynum = ConData.GetSize();
			
			for(int i=0;i<keynum;i++)
			{
				if(ConData[i].FailName==m_conlist1.GetItemText(nItem, 0))
					ConData[i].FailName = " ";
				if(ConData[i].ReplyCon1==m_conlist1.GetItemText(nItem, 0))
					ConData[i].ReplyCon1 = " ";
				if(ConData[i].ReplyCon2==m_conlist1.GetItemText(nItem, 0))
					ConData[i].ReplyCon2 = " ";
				if(ConData[i].ReplyCon3==m_conlist1.GetItemText(nItem, 0))
					ConData[i].ReplyCon3 = " ";
				if(ConData[i].ReplyCon4==m_conlist1.GetItemText(nItem, 0))
					ConData[i].ReplyCon4 = " ";
				if(ConData[i].ReplyCon5==m_conlist1.GetItemText(nItem, 0))
					ConData[i].ReplyCon5 = " ";
				if(ConData[i].ReplyCon6==m_conlist1.GetItemText(nItem, 0))
					ConData[i].ReplyCon6 = " ";
			}
			for(i=0;i<keynum;i++)
			{
				if(ConData[i].Name==m_conlist1.GetItemText(nItem, 0))
				{
					ConData.RemoveAt(i,1);
					break;
				}
			}
			int index = m_failname.FindStringExact(-1, m_conlist1.GetItemText(nItem, 0));
			m_failname.DeleteString(index);
			index = m_replycontext1.FindStringExact(-1, m_conlist1.GetItemText(nItem, 0));
			m_replycontext1.DeleteString(index);
			index = m_replycontext2.FindStringExact(-1, m_conlist1.GetItemText(nItem, 0));
			m_replycontext2.DeleteString(index);
			index = m_replycontext3.FindStringExact(-1, m_conlist1.GetItemText(nItem, 0));
			m_replycontext3.DeleteString(index);
			index = m_replycontext4.FindStringExact(-1, m_conlist1.GetItemText(nItem, 0));
			m_replycontext4.DeleteString(index);
			index = m_replycontext5.FindStringExact(-1, m_conlist1.GetItemText(nItem, 0));
			m_replycontext5.DeleteString(index);
			index = m_replycontext6.FindStringExact(-1, m_conlist1.GetItemText(nItem, 0));
			m_replycontext6.DeleteString(index);
			m_conlist1.DeleteItem(nItem);

			m_editflag1 = "";
			m_flagstate1 = 1;
			m_editflag2 = "";
			m_flagstate2 = 1;
			m_editflag3 = "";
			m_flagstate3 = 1;
			m_editflag4 = "";
			m_flagstate4 = 1;
			m_editattr1 = "";
			m_attrstate1 = 0;
			m_editval1 = "0";;
			m_editattr2 = "";
			m_attrstate2 = 0;
			m_editval2 = "";
			m_editattr6 = "";
			m_attrstate3 = 0;
			m_editval6 = "";
			m_editattr7 = "";
			m_attrstate4 = 0;
			m_editval7 = "";
			m_fail = "";
			m_modflag1 = _T("");
			m_modflag2 = _T("");
			m_modflag3 = _T("");
			m_modflag4 = _T("");
			m_modflagstate1 = 0;
			m_modflagstate2 = 0;
			m_modflagstate3 = 0;
			m_modflagstate4 = 0;
			m_modattr1 = _T("");
			m_modattr2 = _T("");
			m_modattr3 = _T("");
			m_modattr4 = _T("");
			m_modval1 = _T("");
			m_modval2 = _T("");
			m_modval3 = _T("");
			m_modval4 = _T("");
			m_speak = _T("");
			m_soundfile = _T("");
			m_reply1 = _T("");
			m_reply2 = _T("");
			m_reply3 = _T("");
			m_reply4 = _T("");
			m_reply5 = _T("");
			m_reply6 = _T("");
			m_replycon1 = _T("");
			m_replycon2 = _T("");
			m_replycon3 = _T("");
			m_replycon4 = _T("");
			m_replycon5 = _T("");
			m_replycon6 = _T("");
			m_replyexit1 = FALSE;
			m_replyexit2 = FALSE;
			m_replyexit3 = FALSE;
			m_replyexit4 = FALSE;
			m_replyexit5 = FALSE;
			m_replyexit6 = FALSE;
			ConPtr = -1;
			m_coname = "";
			m_fail = "";
			
			UpdateData(FALSE);
		}
	}	
}

//********************************************
//
// Save Conversation Tree
//
//********************************************

void CTreeBuilderDlg::OnSave() 
{
	int size = ConData.GetSize();
	if(size>0)
	{
		CFileDialog dlgFile(FALSE);
		TCHAR m_dir[512];
		strcpy(m_dir, m_currentdir);
		strcat(m_dir, "\\install");
		dlgFile.m_ofn.lpstrInitialDir = m_dir;
		//dlgFile.m_ofn.lpstrFile = filename;
		
		CString title, strFilter, strDefault;
		VERIFY(title.LoadString(AFX_IDS_SAVEFILE));
		
		// append the files filter
		strFilter = _T("Conversation Files (*.tre)");
		strFilter += (TCHAR)'\0';   // next string please
		strFilter += _T("*.tre");
		strFilter += (TCHAR)'\0';   // last string
		dlgFile.m_ofn.nMaxCustFilter++;

		dlgFile.m_ofn.lpstrDefExt = "tre";
		
		dlgFile.m_ofn.lpstrFilter = strFilter;
		dlgFile.m_ofn.lpstrTitle = title;
		dlgFile.m_ofn.Flags |= OFN_OVERWRITEPROMPT;
		dlgFile.m_ofn.hwndOwner = AfxGetMainWnd()->GetSafeHwnd();
		
		if (dlgFile.DoModal() == IDOK)
		{
			POSITION pos = dlgFile.GetStartPosition();
			if(pos != NULL)
			{
				CString FileName = dlgFile.GetPathName();
				FILE *f = fopen(FileName, "wb");
				if (!f) 
				{
					AfxMessageBox("Error opening " + FileName);
					return;
				}
				fwrite(&size, sizeof(int), 1, f);
				char temp[256];
				for(int i=0;i<size;i++)
				{
					strcpy(temp, ConData[i].Name);
					fwrite(&temp, sizeof(char), 255, f);
					for(int j=0;j<4;j++)
					{
						fwrite(&ConData[i].Flag[j], sizeof(int), 1, f);
						fwrite(&ConData[i].FlagState[j], sizeof(int), 1, f);
						strcpy(temp, ConData[i].Attribute[j]);
						fwrite(&temp, sizeof(char), 255, f);
						fwrite(&ConData[i].AttrTest[j], sizeof(int), 1, f);
						fwrite(&ConData[i].AttrAmount[j], sizeof(int), 1, f);
						fwrite(&ConData[i].ModFlag[j], sizeof(int), 1, f);
						fwrite(&ConData[i].ModFlagState[j], sizeof(int), 1, f);
						strcpy(temp, ConData[i].ModAttribute[j]);
						fwrite(&temp, sizeof(char), 255, f);
						fwrite(&ConData[i].ModAttrAmount[j], sizeof(int), 1, f);
					}
					strcpy(temp, ConData[i].FailName);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].SpeakText);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyText1);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyText2);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyText3);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyText4);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyText5);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyText6);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyCon1);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyCon2);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyCon3);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyCon4);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyCon5);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].ReplyCon6);
					fwrite(&temp, sizeof(char), 255, f);
					fwrite(&ConData[i].ReplyExit1, sizeof(BOOL), 1, f);
					fwrite(&ConData[i].ReplyExit2, sizeof(BOOL), 1, f);
					fwrite(&ConData[i].ReplyExit3, sizeof(BOOL), 1, f);
					fwrite(&ConData[i].ReplyExit4, sizeof(BOOL), 1, f);
					fwrite(&ConData[i].ReplyExit5, sizeof(BOOL), 1, f);
					fwrite(&ConData[i].ReplyExit6, sizeof(BOOL), 1, f);
					fwrite(&ConData[i].SpeakSpeed, sizeof(int), 1, f);
					strcpy(temp, ConData[i].SpeakFile);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].Background);
					fwrite(&temp, sizeof(char), 255, f);
					strcpy(temp, ConData[i].Icon);
					fwrite(&temp, sizeof(char), 255, f);
					fwrite(&ConData[i].IconX, sizeof(int), 1, f);
					fwrite(&ConData[i].IconY, sizeof(int), 1, f);
					fwrite(&ConData[i].ReplyX, sizeof(int), 1, f);
					fwrite(&ConData[i].ReplyY, sizeof(int), 1, f);
					fwrite(&ConData[i].ReplyWidth, sizeof(int), 1, f);
					fwrite(&ConData[i].ReplyHeight, sizeof(int), 1, f);
					fwrite(&ConData[i].ReplyFont, sizeof(int), 1, f);
					fwrite(&ConData[i].SpeakX, sizeof(int), 1, f);
					fwrite(&ConData[i].SpeakY, sizeof(int), 1, f);
					fwrite(&ConData[i].SpeakWidth, sizeof(int), 1, f);
					fwrite(&ConData[i].SpeakHeight, sizeof(int), 1, f);
					fwrite(&ConData[i].SpeakFont, sizeof(int), 1, f);
				}
				fclose(f);
			}
		}
		chdir(m_currentdir);
	}
}

//********************************************
//
// Load Conversation Tree
//
//********************************************

void CTreeBuilderDlg::OnLoad() 
{
	CFileDialog dlgFile(TRUE);
	TCHAR m_dir[512];
	strcpy(m_dir, m_currentdir);
	strcat(m_dir, "\\install");
	dlgFile.m_ofn.lpstrInitialDir = m_dir;
	
	CString title, strFilter, strDefault;
	VERIFY(title.LoadString(AFX_IDS_OPENFILE));
	
	// append the files filter
	strFilter = _T("Conversation Files (*.tre)");
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.tre");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;
	
	dlgFile.m_ofn.lpstrDefExt = "tre";

	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	dlgFile.m_ofn.hwndOwner = AfxGetMainWnd()->GetSafeHwnd();
	
	if (dlgFile.DoModal() == IDOK)
	{
		POSITION pos = dlgFile.GetStartPosition();
		if(pos != NULL)
		{
			CString FileName = dlgFile.GetPathName();
			FILE *f = fopen(FileName, "rb");
			if (!f) 
			{
				AfxMessageBox("Error opening " + FileName);
				return;
			}

			m_conlist1.DeleteAllItems();
			m_replycontext1.ResetContent();
			m_replycontext2.ResetContent();
			m_replycontext3.ResetContent();
			m_replycontext4.ResetContent();
			m_replycontext5.ResetContent();
			m_replycontext6.ResetContent();
			m_replycontext1.AddString(" ");
			m_replycontext2.AddString(" ");
			m_replycontext3.AddString(" ");
			m_replycontext4.AddString(" ");
			m_replycontext5.AddString(" ");
			m_replycontext6.AddString(" ");
			m_failname.ResetContent();
			m_failname.AddString(" ");
			ConData.SetSize(0);

			int size;
			fread(&size, sizeof(int), 1, f);
			char temp[256];
			for(int i=0;i<size;i++)
			{
				fread(&temp, sizeof(char), 255, f);
				ConData.SetSize(ConData.GetSize()+1);
				ConData[i].Name = temp;
				(void)m_conlist1.AddItem( _T(temp));
				(void)m_replycontext1.AddString( _T(temp));
				(void)m_replycontext2.AddString( _T(temp));
				(void)m_replycontext3.AddString( _T(temp));
				(void)m_replycontext4.AddString( _T(temp));
				(void)m_replycontext5.AddString( _T(temp));
				(void)m_replycontext6.AddString( _T(temp));
				(void)m_failname.AddString( _T(temp));

				for(int j=0;j<4;j++)
				{
					fread(&ConData[i].Flag[j], sizeof(int), 1, f);
					fread(&ConData[i].FlagState[j], sizeof(int), 1, f);
					fread(&temp, sizeof(char), 255, f);
					ConData[i].Attribute[j] = temp;
					fread(&ConData[i].AttrTest[j], sizeof(int), 1, f);
					fread(&ConData[i].AttrAmount[j], sizeof(int), 1, f);
					fread(&ConData[i].ModFlag[j], sizeof(int), 1, f);
					fread(&ConData[i].ModFlagState[j], sizeof(int), 1, f);
					fread(&temp, sizeof(char), 255, f);
					ConData[i].ModAttribute[j] = temp;
					fread(&ConData[i].ModAttrAmount[j], sizeof(int), 1, f);
				}
				fread(&temp, sizeof(char), 255, f);
				ConData[i].FailName = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].SpeakText = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyText1 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyText2 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyText3 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyText4 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyText5 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyText6 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyCon1 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyCon2 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyCon3 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyCon4 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyCon5 = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].ReplyCon6 = temp;
				fread(&ConData[i].ReplyExit1, sizeof(BOOL), 1, f);
				fread(&ConData[i].ReplyExit2, sizeof(BOOL), 1, f);
				fread(&ConData[i].ReplyExit3, sizeof(BOOL), 1, f);
				fread(&ConData[i].ReplyExit4, sizeof(BOOL), 1, f);
				fread(&ConData[i].ReplyExit5, sizeof(BOOL), 1, f);
				fread(&ConData[i].ReplyExit6, sizeof(BOOL), 1, f);
				fread(&ConData[i].SpeakSpeed, sizeof(int), 1, f);
				fread(&temp, sizeof(char), 255, f);
				ConData[i].SpeakFile = temp;
/*				
				ConData[i].Background = "";
				ConData[i].Icon = "";
				ConData[i].IconX = -1;
				ConData[i].IconY = -1;
				ConData[i].SpeakX = -1;
				ConData[i].SpeakY = -1;
				ConData[i].SpeakWidth = -1;
				ConData[i].SpeakHeight = -1;
				ConData[i].SpeakFont = -1;
				ConData[i].ReplyX = -1;
				ConData[i].ReplyY = -1;
				ConData[i].ReplyWidth = -1;
				ConData[i].ReplyHeight = -1;
				ConData[i].ReplyFont = -1;
*/
				fread(&temp, sizeof(char), 255, f);
				ConData[i].Background = temp;
				fread(&temp, sizeof(char), 255, f);
				ConData[i].Icon = temp;
				fread(&ConData[i].IconX, sizeof(int), 1, f);
				fread(&ConData[i].IconY, sizeof(int), 1, f);
				fread(&ConData[i].ReplyX, sizeof(int), 1, f);
				fread(&ConData[i].ReplyY, sizeof(int), 1, f);
				fread(&ConData[i].ReplyWidth, sizeof(int), 1, f);
				fread(&ConData[i].ReplyHeight, sizeof(int), 1, f);
				fread(&ConData[i].ReplyFont, sizeof(int), 1, f);
				fread(&ConData[i].SpeakX, sizeof(int), 1, f);
				fread(&ConData[i].SpeakY, sizeof(int), 1, f);
				fread(&ConData[i].SpeakWidth, sizeof(int), 1, f);
				fread(&ConData[i].SpeakHeight, sizeof(int), 1, f);
				fread(&ConData[i].SpeakFont, sizeof(int), 1, f);

				UpdateData(FALSE);
			}
			fclose(f);
		}
	}
	chdir(m_currentdir);
}

//********************************************
//
// Make Script
//
//********************************************

void CTreeBuilderDlg::OnScript() 
{
	int size = ConData.GetSize();
	if(size>0)
	{
		CFileDialog dlgFile(FALSE);
		TCHAR m_dir[512];
		strcpy(m_dir, m_currentdir);
		strcat(m_dir, "\\scripts");
		dlgFile.m_ofn.lpstrInitialDir = m_dir;
		
		CString title, strFilter, strDefault;
		VERIFY(title.LoadString(AFX_IDS_SAVEFILE));
		
		// append the files filter
		strFilter = _T("Conversation Script (*.s)");
		strFilter += (TCHAR)'\0';   // next string please
		strFilter += _T("*.s");
		strFilter += (TCHAR)'\0';   // last string
		dlgFile.m_ofn.nMaxCustFilter++;

		dlgFile.m_ofn.lpstrDefExt = "s";
		
		dlgFile.m_ofn.lpstrFilter = strFilter;
		dlgFile.m_ofn.lpstrTitle = title;
		dlgFile.m_ofn.Flags |= OFN_OVERWRITEPROMPT;
		dlgFile.m_ofn.hwndOwner = AfxGetMainWnd()->GetSafeHwnd();
		
		if (dlgFile.DoModal() == IDOK)
		{
			POSITION pos = dlgFile.GetStartPosition();
			if(pos != NULL)
			{
				CString FileName = dlgFile.GetPathName();
				FILE *f = fopen(FileName, "wt");
				if (!f) 
				{
					AfxMessageBox("Error opening " + FileName);
					return;
				}

				fputs("{\n\n", f);
				for(int i=0;i<size;i++)
				{
					fputs("  ", f);
					fputs(ConData[i].Name, f);
					fputs("[ ()\n  {\n", f);
					int indent = 1;

					// Flag test
					bool fif = false;
					for(int j=0;j<4;j++)
					{
						if(ConData[i].Flag[j]!=-1)
						{
							if(!fif)
							{
								Indent(indent, f);
								fputs("if(", f);
								if(ConData[i].FlagState[j]==1)
									fputs("not ", f);
								fputs("GetFlag(", f);
								fif = true;
							}
							else
							{
								fputs(" and ", f);
								if(ConData[i].FlagState[j]==1)
									fputs("not ", f);
								fputs("GetFlag(", f);
							}
							char temp[64];
							itoa(ConData[i].Flag[j], &temp[0], 10);
							fputs(temp, f);
							fputs(")", f);
						}
					}
					if(fif)
					{
						fputs(")\n", f);
						Indent(indent, f);
						fputs("{\n", f);
						indent+=1;
					}
					// Attribute Test
					bool aif = false;
					for(j=0;j<4;j++)
					{
						if(ConData[i].Attribute[j]!="")
						{
							if(!aif)
							{
								Indent(indent, f);
								fputs("if(GetAttribute(\"", f);
								aif = true;
							}
							else
							{
								fputs(" and GetAttribute(\"", f);
							}
							fputs(ConData[i].Attribute[j], f);
							fputs("\")", f);
							switch(ConData[i].AttrTest[j])
							{
							case 0:
								fputs("=", f);
								break;
							case 1:
								fputs("!=", f);
								break;
							case 2:
								fputs(">", f);
								break;
							case 3:
								fputs("<", f);
								break;
							}
							char temp[64];
							itoa(ConData[i].AttrAmount[j], &temp[0], 10);
							fputs(temp, f);
						}
					}
					if(aif)
					{
						fputs(")\n", f);
						Indent(indent, f);
						fputs("{\n", f);
						indent+=1;
					}
					// Flag Modify
					for(j=0;j<4;j++)
					{
						if(ConData[i].ModFlag[j]!=-1)
						{
							Indent(indent, f);
							fputs("SetFlag(", f);
							char temp[64];
							itoa(ConData[i].ModFlag[j], &temp[0], 10);
							fputs(temp, f);
							if(ConData[i].ModFlagState[j]==0)
								fputs(", true", f);
							else
								fputs(", false", f);
							fputs(");\n", f);
						}
					}
					// Attribute Modify
					for(j=0;j<4;j++)
					{
						if(ConData[i].ModAttribute[j]!="")
						{
							Indent(indent, f);
							fputs("ModifyAttribute(\"", f);
							fputs(ConData[i].ModAttribute[j], f);
							fputs("\",", f);
							char temp[64];
							itoa(ConData[i].ModAttrAmount[j], &temp[0], 10);
							fputs(temp, f);
							fputs(");\n", f);
						}
					}
					// Custom background
					if(ConData[i].Background!="")
					{
						Indent(indent, f);
						fputs("CustomBackground(\"", f);
						fputs(ConData[i].Background, f);
						fputs("\");\n", f);
					}
					// Custom Icon
					if(ConData[i].Icon!="" || ConData[i].IconX!=-1 || ConData[i].IconY!=-1)
					{
						Indent(indent, f);
						fputs("CustomIcon(\"", f);
						if(ConData[i].Icon!="")
							fputs(ConData[i].Icon, f);
						fputs("\", ", f);
						char temp[64];
						itoa(ConData[i].IconX, &temp[0], 10);
						fputs(temp, f);
						fputs(", ", f);
						itoa(ConData[i].IconY, &temp[0], 10);
						fputs(temp, f);
						fputs(");\n", f);
					}
					// Custom Speak Box
					if(ConData[i].SpeakX!=-1 || ConData[i].SpeakY!=-1
						|| ConData[i].SpeakWidth!=-1|| ConData[i].SpeakHeight!=-1
						|| ConData[i].SpeakFont!=-1)
					{
						Indent(indent, f);
						fputs("CustomSpeak(", f);
						char temp[64];
						itoa(ConData[i].SpeakX, &temp[0], 10);
						fputs(temp, f);
						fputs(", ", f);
						itoa(ConData[i].SpeakY, &temp[0], 10);
						fputs(temp, f);
						fputs(", ", f);
						itoa(ConData[i].SpeakWidth, &temp[0], 10);
						fputs(temp, f);
						fputs(", ", f);
						itoa(ConData[i].SpeakHeight, &temp[0], 10);
						fputs(temp, f);
						fputs(", ", f);
						itoa(ConData[i].SpeakFont, &temp[0], 10);
						fputs(temp, f);
						fputs(");\n", f);
					}
					// Custom Reply Box
					if(ConData[i].ReplyX!=-1 || ConData[i].ReplyY!=-1
						|| ConData[i].ReplyWidth!=-1|| ConData[i].ReplyHeight!=-1
						|| ConData[i].ReplyFont!=-1)
					{
						Indent(indent, f);
						fputs("CustomReply(", f);
						char temp[64];
						itoa(ConData[i].ReplyX, &temp[0], 10);
						fputs(temp, f);
						fputs(", ", f);
						itoa(ConData[i].ReplyY, &temp[0], 10);
						fputs(temp, f);
						fputs(", ", f);
						itoa(ConData[i].ReplyWidth, &temp[0], 10);
						fputs(temp, f);
						fputs(", ", f);
						itoa(ConData[i].ReplyHeight, &temp[0], 10);
						fputs(temp, f);
						fputs(", ", f);
						itoa(ConData[i].ReplyFont, &temp[0], 10);
						fputs(temp, f);
						fputs(");\n", f);
					}
					// Speak
					ConData[i].SpeakText.TrimLeft();
					if(ConData[i].SpeakText!="")
					{
						Indent(indent, f);
						fputs("Speak(\"", f);
						fputs(ConData[i].SpeakText, f);
						fputs("\",\"", f);
						fputs(ConData[i].SpeakFile, f);
						fputs("\");\n", f);
					}

					// Replys
					int reply = 1;
					CString RCon[6];
					BOOL RExit[6];
					char temp[64];
					ConData[i].ReplyText1.TrimLeft();
					if(ConData[i].ReplyText1!="")
					{
						RCon[reply-1] = ConData[i].ReplyCon1;
						RExit[reply-1] = ConData[i].ReplyExit1;
						Indent(indent, f);
						fputs("Reply(", f);
						itoa(reply, &temp[0], 10);
						fputs(temp, f);
						fputs(",\"", f);
						fputs(ConData[i].ReplyText1, f);
						fputs("\");\n", f);
						reply +=1;
					}
					ConData[i].ReplyText2.TrimLeft();
					if(ConData[i].ReplyText2!="")
					{
						RCon[reply-1] = ConData[i].ReplyCon2;
						RExit[reply-1] = ConData[i].ReplyExit2;
						Indent(indent, f);
						fputs("Reply(", f);
						itoa(reply, &temp[0], 10);
						fputs(temp, f);
						fputs(",\"", f);
						fputs(ConData[i].ReplyText2, f);
						fputs("\");\n", f);
						reply +=1;
					}
					ConData[i].ReplyText3.TrimLeft();
					if(ConData[i].ReplyText3!="")
					{
						RCon[reply-1] = ConData[i].ReplyCon3;
						RExit[reply-1] = ConData[i].ReplyExit3;
						Indent(indent, f);
						fputs("Reply(", f);
						itoa(reply, &temp[0], 10);
						fputs(temp, f);
						fputs(",\"", f);
						fputs(ConData[i].ReplyText3, f);
						fputs("\");\n", f);
						reply +=1;
					}
					ConData[i].ReplyText4.TrimLeft();
					if(ConData[i].ReplyText4!="")
					{
						RCon[reply-1] = ConData[i].ReplyCon4;
						RExit[reply-1] = ConData[i].ReplyExit4;
						Indent(indent, f);
						fputs("Reply(", f);
						itoa(reply, &temp[0], 10);
						fputs(temp, f);
						fputs(",\"", f);
						fputs(ConData[i].ReplyText4, f);
						fputs("\");\n", f);
						reply +=1;
					}
					ConData[i].ReplyText5.TrimLeft();
					if(ConData[i].ReplyText5!="")
					{
						RCon[reply-1] = ConData[i].ReplyCon5;
						RExit[reply-1] = ConData[i].ReplyExit5;
						Indent(indent, f);
						fputs("Reply(", f);
						itoa(reply, &temp[0], 10);
						fputs(temp, f);
						fputs(",\"", f);
						fputs(ConData[i].ReplyText5, f);
						fputs("\");\n", f);
						reply +=1;
					}
					ConData[i].ReplyText6.TrimLeft();
					if(ConData[i].ReplyText6!="")
					{
						RCon[reply-1] = ConData[i].ReplyCon6;
						RExit[reply-1] = ConData[i].ReplyExit6;
						Indent(indent, f);
						fputs("Reply(", f);
						itoa(reply, &temp[0], 10);
						fputs(temp, f);
						fputs(",\"", f);
						fputs(ConData[i].ReplyText6, f);
						fputs("\");\n", f);
						reply +=1;
					}

					// switch
					if(reply>1)
					{
						Indent(indent, f);
						fputs("switch(Conversation(", f);
						itoa(ConData[i].SpeakSpeed, &temp[0], 10);
						fputs(temp, f);
						fputs("))\n", f);
						Indent(indent, f);
						fputs("{\n", f);
						indent+=1;
						for(int k=1;k<reply;k++)
						{
							Indent(indent, f);
							fputs("case ", f);
							itoa(k, &temp[0], 10);
							fputs(temp, f);
							fputs("\n", f);
							Indent(indent, f);
							fputs("{\n", f);
							RCon[k-1].TrimLeft();
							indent+=1;
							Indent(indent, f);
							fputs("NewConversation(\"", f);
							if(RCon[k-1]!="")
								fputs(RCon[k-1], f);
							fputs("\",", f);
							if(RExit[k-1]==TRUE)
								fputs("false);\n", f);
							else
								fputs("true);\n", f);
							indent-=1;
							Indent(indent, f);
							fputs("}\n", f);
						}
						indent-=1;
						Indent(indent, f);
						fputs("}\n", f);
					}
					else
					{
						Indent(indent, f);
						fputs("Conversation(", f);
						itoa(ConData[i].SpeakSpeed, &temp[0], 10);
						fputs(temp, f);
						fputs(");\n", f);
					}


					// Finish order
					if(aif)
					{
						indent-=1;
						Indent(indent, f);
						fputs("}\n", f);
						Indent(indent, f);
						fputs("else\n", f);
						Indent(indent, f);
						fputs("{\n", f);
						indent+=1;
						if(ConData[i].FailName!=" ")
						{
							Indent(indent, f);
							fputs("NewConversation(\"", f);
							fputs(ConData[i].FailName, f);
							fputs("\", true);\n", f);
						}
						indent-=1;
						Indent(indent, f);
						fputs("}\n", f);
					}
					if(fif)
					{
						indent-=1;
						Indent(indent, f);
						fputs("}\n", f);
						Indent(indent, f);
						fputs("else\n", f);
						Indent(indent, f);
						fputs("{\n", f);
						indent+=1;
						if(ConData[i].FailName!=" ")
						{
							Indent(indent, f);
							fputs("NewConversation(\"", f);
							fputs(ConData[i].FailName, f);
							fputs("\", true);\n", f);
						}
						indent-=1;
						Indent(indent, f);
						fputs("}\n", f);
					}

					fputs("  } ]\n\n", f);

				}
				fputs("}\n\n", f);
				fclose(f);
			}
		}
		chdir(m_currentdir);
	}	
}

void CTreeBuilderDlg::Indent(int indent, FILE *f)
{
	fputs("  ", f);
	for(int i=0;i<indent;i++)
		fputs("    ", f);
}

//********************************************
//
// Change Speak Speed
//
//********************************************

void CTreeBuilderDlg::OnChangeSpeed() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].SpeakSpeed = atoi(m_speed);
	}
}

void CTreeBuilderDlg::OnSndbutton() 
{
	if(ConPtr!=-1)
	{
		CFileDialog dlgFile(TRUE);
		TCHAR m_dir[512];
		strcpy(m_dir, m_currentdir);
		strcat(m_dir, "\\media\\audio");
		dlgFile.m_ofn.lpstrInitialDir = m_dir;
		//dlgFile.m_ofn.lpstrFile = filename;
		
		CString title, strFilter, strDefault;
		VERIFY(title.LoadString(AFX_IDS_OPENFILE));
		
		// append the files filter
		strFilter = _T("Wav Files (*.wav)");
		strFilter += (TCHAR)'\0';   // next string please
		strFilter += _T("*.wav");
		strFilter += (TCHAR)'\0';   // last string
		dlgFile.m_ofn.nMaxCustFilter++;
		strFilter += _T("MP3 Files (*.mp3)");
		strFilter += (TCHAR)'\0';   // next string please
		strFilter += _T("*.mp3");
		dlgFile.m_ofn.nMaxCustFilter++;
		strFilter += (TCHAR)'\0';   // last string
		strFilter += (TCHAR)'\0'; 
		
		dlgFile.m_ofn.lpstrDefExt = "wav";
		
		dlgFile.m_ofn.lpstrFilter = strFilter;
		dlgFile.m_ofn.lpstrTitle = title;
		dlgFile.m_ofn.hwndOwner = AfxGetMainWnd()->GetSafeHwnd();
		
		if (dlgFile.DoModal() == IDOK)
		{
			POSITION pos = dlgFile.GetStartPosition();
			if(pos != NULL)
			{
				CString FileName = dlgFile.GetFileName();
				ConData[ConPtr].SpeakFile = FileName;
				m_soundfile = FileName;
				
				UpdateData(FALSE);
			}
		}
		chdir(m_currentdir);
	}
}

void CTreeBuilderDlg::OnChangeSoundfile() 
{
	if(ConPtr!=-1)
	{
		UpdateData(TRUE);
		ConData[ConPtr].SpeakFile = m_soundfile;
	}
}

void CTreeBuilderDlg::OnCustom() 
{
	if(ConPtr!=-1)
	{
		custom dlg(NULL);
		strcpy(dlg.m_currentdir, m_currentdir);
		dlg.m_back = ConData[ConPtr].Background;
		dlg.m_icon = ConData[ConPtr].Icon;
		dlg.m_replyfont = "";
		if(ConData[ConPtr].ReplyFont!=-1)
			dlg.m_replyfont.Format("%d", ConData[ConPtr].ReplyFont);
		dlg.m_replyx = "";
		if(ConData[ConPtr].ReplyX!=-1)
			dlg.m_replyx.Format("%d", ConData[ConPtr].ReplyX);
		dlg.m_replyy = "";
		if(ConData[ConPtr].ReplyY!=-1)
			dlg.m_replyy.Format("%d", ConData[ConPtr].ReplyY);
		dlg.m_replywidth = "";
		if(ConData[ConPtr].ReplyWidth!=-1)
			dlg.m_replywidth.Format("%d", ConData[ConPtr].ReplyWidth);
		dlg.m_replyheight = "";
		if(ConData[ConPtr].ReplyHeight!=-1)
			dlg.m_replyheight.Format("%d", ConData[ConPtr].ReplyHeight);

		dlg.m_speakfont = "";
		if(ConData[ConPtr].SpeakFont!=-1)
			dlg.m_speakfont.Format("%d", ConData[ConPtr].SpeakFont);
		dlg.m_speakx = "";
		if(ConData[ConPtr].SpeakX!=-1)
			dlg.m_speakx.Format("%d", ConData[ConPtr].SpeakX);
		dlg.m_speaky = "";
		if(ConData[ConPtr].SpeakY!=-1)
			dlg.m_speaky.Format("%d", ConData[ConPtr].SpeakY);
		dlg.m_speakwidth = "";
		if(ConData[ConPtr].SpeakWidth!=-1)
			dlg.m_speakwidth.Format("%d", ConData[ConPtr].SpeakWidth);
		dlg.m_speakheight = "";
		if(ConData[ConPtr].SpeakHeight!=-1)
			dlg.m_speakheight.Format("%d", ConData[ConPtr].SpeakHeight);

		dlg.m_iconx = "";
		if(ConData[ConPtr].IconX!=-1)
			dlg.m_iconx.Format("%d", ConData[ConPtr].IconX);
		dlg.m_icony = "";
		if(ConData[ConPtr].IconY!=-1)
			dlg.m_icony.Format("%d", ConData[ConPtr].IconY);

		if (dlg.DoModal() == IDOK) 
		{
			ConData[ConPtr].Background = dlg.m_back;
			ConData[ConPtr].Icon = dlg.m_icon;

			ConData[ConPtr].SpeakX = -1;
			dlg.m_speakx.TrimRight();
			if(dlg.m_speakx!="")
				ConData[ConPtr].SpeakX = _ttoi(dlg.m_speakx);
			ConData[ConPtr].SpeakY = -1;
			dlg.m_speaky.TrimRight();
			if(dlg.m_speaky!="")
				ConData[ConPtr].SpeakY = _ttoi(dlg.m_speaky);
			ConData[ConPtr].SpeakWidth = -1;
			dlg.m_speakwidth.TrimRight();
			if(dlg.m_speakwidth!="")
				ConData[ConPtr].SpeakWidth = _ttoi(dlg.m_speakwidth);
			ConData[ConPtr].SpeakHeight = -1;
			dlg.m_speakheight.TrimRight();
			if(dlg.m_speakheight!="")
				ConData[ConPtr].SpeakHeight = _ttoi(dlg.m_speakheight);
			ConData[ConPtr].SpeakFont = -1;
			dlg.m_speakfont.TrimRight();
			if(dlg.m_speakfont!="")
				ConData[ConPtr].SpeakFont = _ttoi(dlg.m_speakfont);
			ConData[ConPtr].ReplyX = -1;
			dlg.m_replyx.TrimRight();
			if(dlg.m_replyx!="")
				ConData[ConPtr].ReplyX = _ttoi(dlg.m_replyx);
			ConData[ConPtr].ReplyY = -1;
			dlg.m_replyy.TrimRight();
			if(dlg.m_replyy!="")
				ConData[ConPtr].ReplyY = _ttoi(dlg.m_replyy);
			ConData[ConPtr].ReplyWidth = -1;
			dlg.m_replywidth.TrimRight();
			if(dlg.m_replywidth!="")
				ConData[ConPtr].ReplyWidth = _ttoi(dlg.m_replywidth);
			ConData[ConPtr].ReplyHeight = -1;
			dlg.m_replyheight.TrimRight();
			if(dlg.m_replyheight!="")
				ConData[ConPtr].ReplyHeight = _ttoi(dlg.m_replyheight);
			ConData[ConPtr].ReplyFont = -1;
			dlg.m_replyfont.TrimRight();
			if(dlg.m_replyfont!="")
				ConData[ConPtr].ReplyFont = _ttoi(dlg.m_replyfont);
			ConData[ConPtr].IconX = -1;
			dlg.m_iconx.TrimRight();
			if(dlg.m_iconx!="")
				ConData[ConPtr].IconX = _ttoi(dlg.m_iconx);
			ConData[ConPtr].IconY = -1;
			dlg.m_icony.TrimRight();
			if(dlg.m_icony!="")
				ConData[ConPtr].IconY = _ttoi(dlg.m_icony);
		}
	}
}
