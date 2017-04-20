#include "StdAfx.h"
#include "myDialog.h"
#include "DwgDatabaseUtil.h"

myDialog::myDialog(CWnd* pParent):CAcUiDialog(myDialog::IDD, pParent)
{
}


myDialog::~myDialog(void)
{
}

void myDialog::DoDataExchange(CDataExchange* pDX)
{
	CAcUiDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(myDialog, CAcUiDialog)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &myDialog::OnBnClickedButtonPoint)
END_MESSAGE_MAP()

void myDialog::OnBnClickedButtonPoint()
{
	BeginEditorCommand();
	//Call this method to indicate an AutoCAD interactive command is starting.  

	int colorIndex=GetLineColor();

	ads_point pt,pt2;
	CString str;

	BOOL bCancel=TRUE;
	str.Format(IDS_STRINGDIALOG_FIRP);
	if (acedGetPoint(NULL, str, pt)==RTNORM)
	{
		//Gets user input for a point. 
		bCancel=FALSE;
		str.Format(IDS_STRINGDIALOG_POINT2);
		while(acedGetPoint(pt, str, pt2)==RTNORM)
		{
			AcDbLine* pLine=new AcDbLine(asPnt3d(pt), asPnt3d(pt2));
			if (colorIndex!=-1)
			{
				pLine->setColorIndex(colorIndex);
			}
			AcDbObjectId entId = CDwgDatabaseUtil::PostToModalSpace(pLine);
			if (entId==AcDbObjectId::kNull)
			{
				delete pLine;
			}
			pt[X]=pt2[X];
			pt[Y]=pt2[Y];
			pt[Z]=pt2[Z];
		}
	}


	CompleteEditorCommand();
	//Call this method upon return from an interactive command that was completed in the Drawing Editor. 

	// TODO: 在此添加控件通知处理程序代码
}

int myDialog::GetLineColor()
{

	int colorIndex=-1;
	CString str;

	str.Format(IDS_STRINGDIALOG_SETCOLOR);
	int rc=acedGetInt(str, &colorIndex);
	if (rc!=RTNORM)
	{
		return colorIndex;
	}

	if(colorIndex<0 || colorIndex > 255)
	{
		str.Format(IDS_STRINGDIALOG_INVALID);
		acutPrintf(str);
		colorIndex=-1;
	}

	return colorIndex;
}

