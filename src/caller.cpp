#include "Example.h"

int main(int argc, char ** argv)
{
    if(argc == 1)
    {
        fprintf(stderr, "No commandline args");
        return -1;
    }

    int numarr = argc - 1;
    double *arr = (double *) malloc(numarr * sizeof(double));

    if(arr == 0)
    {
        fprintf(stderr, "memory initialization failed");
        return -1;
    }

    double *parr = arr;
    char **nums = &argv[1];

    while (numarr--)
    {
        *parr++ = atof(*nums++);
    }

    QSORT_FUNC sorter;

#ifdef WINDOWS
    HMODULE hmodule;
    const char* dllname = "QSORT.dll";
#else
    void *hmodule;
    const char* dllname = "./libQSort.so";
#endif

    if(!LOAD_DLL(hmodule, dllname))
    {
        fprintf(stderr, "Failed to load %s\n", dllname);
        return -1;
    }

    sorter = (QSORT_FUNC) GET_FUNC_PTR(hmodule, "QSORT");
    if(sorter == 0)
    {
        fprintf(stderr, "Failed to retrieve function pointer. QUitting");
        return -2;
    }

    (*sorter)(arr, argc-1);

    int num = 0;
    while(num < argc - 1)
    {
        fprintf(stdout, "%g\n", arr[num++]);
    }

    free(arr);

    UNLOAD_DLL(hmodule);

    return 0;
}










