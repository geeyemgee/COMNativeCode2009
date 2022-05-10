#include<stdio.h>

extern "C" int Add(int, int);
extern "C" int Mul(int, int);

int main(int argc, char** argv)
{
    printf("Hello World\t%d\t%d\n", Add(100, 1), Mul(20,5));
    return 0;
}
