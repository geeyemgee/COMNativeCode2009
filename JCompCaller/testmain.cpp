
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
#include <windows.h>
#include "oaidl.h"
#include "ocidl.h"

#include "..\\Jcomp\\JComp\\Test.h"
#include "..\\Jcomp\\JComp\\JComp_i.c"

int CallVtableWithStaticCLSID ()
{
HRESULT res;
IUnknown *ppv=0;
CLSID clsid;
res = CLSIDFromProgID(L"JComp.Test",&clsid);
#if 0
res = CoCreateInstance(CLSID_BenHello,0,CLSCTX_SERVER,IID_IUnknown,(void **)&ppv);
#else
res = CoCreateInstance(clsid,0,CLSCTX_SERVER,IID_IUnknown,(void **)&ppv);
#endif
if ( res != S_OK )
{
return 1;
}
ITest *ben=0;
res = ppv->QueryInterface(IID_ITest,(void **)&ben);
if ( res != S_OK )
     return 1;
ben->Yell2 (L"Hello...");
ben->Release ();
}

#if 0
void CallIDispatch()
{
HRESULT res;
IDispatch *ppv=0;
CLSID clsid;
res = CLSIDFromProgID(L"ATLHello.BenHello",&clsid);
res = CoCreateInstance(clsid,0,CLSCTX_SERVER,IID_IDispatch,(void **)&ppv);
if ( res != S_OK )
{
return ;
}
TCHAR *names = _T("Say") ;
DISPID dispid;
res= ppv->GetIDsOfNames(IID_NULL,&names,1,LOCALE_USER_DEFAULT,&dispid);
DISPPARAMS ds={NULL,NULL,0,0};
if (res == S_OK )
res = ppv->Invoke(dispid,IID_NULL,LOCALE_USER_DEFAULT,DISPATCH_METHOD,&ds,0,0,0);
ppv->Release();
}

#endif

int main( int argc , char **argv )
{
   CoInitialize(NULL);
   CallVtableWithStaticCLSID();
   CoUninitialize();

   getchar();

}


