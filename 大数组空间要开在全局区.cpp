#include <iostream>
#include <stdlib.h>
using namespace std;
//大于10^6的数组空间要开在全局区,若开在局部区会包内存错 
int a[1000000];  //right

int main()
{
//    int a[1000000];  //报告内存错误 
    system("pause");
    return 0;
}
