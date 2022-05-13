#include<windows.h>
#include<iostream>

using namespace std;

#include "Test1.h"

int main(int argc, char **argv)
{
    fprintf(stdout, "Add(2,3):%d\nSub(4,5):%d\nMul(4,3):%d\nDiv(66,2):%d\n", Add(2,3), Sub(4,5), Mul(4,3), Div(66,2));

    return 0;
}