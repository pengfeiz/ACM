#include <iostream>
using namespace std;
int main()
{
    int i;
    float n[12],t=0;
    for(i=0;i<12;i++)
    cin>>n[i];
    for(i=0;i<12;i++)
    t+=n[i];
    t=t/12;
    printf("$%.2f\n",t);
    return 0;
}
    
