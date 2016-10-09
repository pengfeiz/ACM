#include <iostream>
#include <cmath>
using namespace std;

__int64 a[2001];
__int64 b[2001];
__int64 n,s,f,l;

int main()
{
    __int64 i,j,x,p;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
        scanf("%I64d",&b[i]);
    scanf("%I64d%I64d%I64d",&s,&f,&l);
    memset(a,0,sizeof(a));
    s--;
    for(i=0;i<n;i++)
    {
        if((b[i]+s)<f||(b[i]-s)>(f+l-1))
            continue;
        for(j=0;j<l;j++)
        {
            x=f+j-b[i];
            if(abs(x)>s)
                continue;
            if((abs(x)&1)!=(s&1))
                continue;
            p=(x+s)/2;
            if((s&p)==p)
                a[j]++;
        }
    }
    for(i=0;i<l;i++)
    {
        a[i]=a[i]&1;
        if(i)
            printf(" ");
        printf("%I64d",a[i]);
    }
    printf("\n");
    return 0;
}
