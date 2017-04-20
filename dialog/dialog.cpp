
#include "StdAfx.h"

#if defined(_DEBUG) && !defined(AC_FULL_DEBUG)
#error _DEBUG should not be defined
#endif

#include "AcExtensionModule.h"

#include "myDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern "C" HWND adsw_acadMainWnd();
AC_IMPLEMENT_EXTENSION_MODULE(theArxDLL);

HINSTANCE m_hResourceDll=NULL;

HMODULE m_hAppModule;
HMODULE m_hResModule;

void dialog();
void initApp();
void unloadApp();
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode, void*);

static HMODULE _loadResLib(HMODULE hModule)
{
	TCHAR buffer[1024];
	HMODULE resHandle=NULL;
	int iRet=GetModuleFileName(hModule, buffer, 1024);
	if (iRet>0)
	{
		CString moduleName=buffer;
		moduleName=moduleName.Left(moduleName.GetLength()-4)+ _T("Res.dll");

		m_hResourceDll = AfxLoadLibrary(moduleName);
		//acutPrintf(moduleName);
		if (m_hResourceDll)  
		{  
			theArxDLL.AttachInstance(m_hResourceDll); 
		}
		else
		{
			acutPrintf(_T("\nAfxLoadLibrary fail"));
		}
	}

	return resHandle;
}

AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
	switch(msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(appId);
		acrxDynamicLinker->registerAppMDIAware(appId);

		initApp();

		//acutPrintf(_T("\nkInitAppMsg"));


		break;
	case AcRx::kUnloadAppMsg:
		unloadApp();
		
		//acutPrintf(_T("\nkUnloadAppMsg"));

		break;
	case AcRx::kInitDialogMsg:
		break;
	default:
		break;
	}
	return AcRx::kRetOK;
}


void dialog()
{
	//acutPrintf(_T("dialog"));
	myDialog l_testDialog(CWnd::FromHandle(adsw_acadMainWnd()));
	l_testDialog.DoModal();
}

void initApp()
{
	CAcModuleResourceOverride resOverride;

	acedRegCmds->addCommand(_T("DIALOG"), _T("DIALOG"), _T("DIALOG"), ACRX_CMD_MODAL, dialog,
		NULL, -1, theArxDLL.ModuleResourceInstance());
}

void unloadApp()
{
	acedRegCmds->removeGroup(_T("DIALOG"));
}

extern "C" int APIENTRY
	DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);
	m_hAppModule=hInstance;
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		
		//acutPrintf(_T("\nDLL_PROCESS_ATTACH"));
		m_hResourceDll = _loadResLib(hInstance); 

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		//acutPrintf(_T("\nDLL_PROCESS_DETACH"));

		theArxDLL.DetachInstance();  
		if (m_hResourceDll)  
		{
			AfxFreeLibrary(m_hResourceDll);
			m_hResourceDll=NULL;
		}
	}
	return 1;   // ok
}


