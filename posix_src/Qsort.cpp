#include "Example.h"

static int CALL_CONV_FOR_QSORT CmpFn(const void* v1, const void *v2)
{
    double a = *(double *)v1;
    double b = *(double *)v2;

    return (a > b)? 1 : (b > a)? -1 : 0;
}

extern "C" EXPORTED_FUNC void STDCALL_CONV QSORT(double *arr,  int nelem)
{
    qsort(arr, nelem, sizeof(double), CmpFn);
}

