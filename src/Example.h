#ifndef EXAMPLE_DOT_H
#define EXAMPLE_DOT_H

#include<stdio.h>
#include<stdlib.h>


#ifdef WINDOWS //For Windows


#include<windows.h>

#define CALL_CONV_FOR_QSORT __cdecl

#define STDCALL_CONV __stdcall

#define EXPORTED_FUNC __declspec(dllexport)


#define LOAD_DLL(hmodule, str) \
    ((hmodule=LoadLibrary((str)) ) != INVALID_HANDLE_VALUE)

#define GET_FUNC_PTR(hmodule, str) \
    (GetProcAddress(hmodule, (str)))

#define UNLOAD_DLL(hmodule) FreeLibrary(hmodule);


#else //For POSIX Systems


#include<dlfcn.h>
#define CALL_CONV_FOR_QSORT
#define EXPORTED_FUNC
#define STDCALL_CONV

#define LOAD_DLL(hmodule, str) \
    ((hmodule = dlopen((str), RTLD_LAZY)) != 0)

#define GET_FUNC_PTR(hmodule, str) dlsym(hmodule, (str));

#define UNLOAD_DLL(hmodule) dlclose(hmodule);


#endif

//Function pointer for the exported function
typedef int (STDCALL_CONV *QSORT_FUNC)(double*, int);

#endif

