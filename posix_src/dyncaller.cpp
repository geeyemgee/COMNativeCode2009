#include<stdio.h>
#include<dlfcn.h>

typedef int (*BIN_FUNCTION) (int, int);

int main(int argc, char ** argv)
{
    void *handle = dlopen("libArith.so", RTLD_LAZY);

    if(handle == 0)
    {
        printf("Failed to load library");
        return 1;
    }

    BIN_FUNCTION bn = (BIN_FUNCTION)dlsym(handle, "Add");
    BIN_FUNCTION mul_fun = (BIN_FUNCTION)dlsym(handle, "Mul");
    if(bn == 0)
    {
        printf("Failed to retrieve the Add function from library");
        return 1;
    }
    if(mul_fun == 0)
    {
        printf("Couldn't retrieve Mul function from the library");
    }

    int nc = (*bn) (10, 10);
    printf("Value of Add(10, 10) is: %d", nc);

    int m_res = (*mul_fun) (9, 90);
    printf("Value of Mul(9, 90) is: %d", m_res);

    return 0;
}
