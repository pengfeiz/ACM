#include <iostream>
#include <cmath>
using namespace std;

int a[2001];
int b[2001];
int n,s,f,l;

int main()
{
    int i,j,x,p;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    scanf("%d%d%d",&s,&f,&l);
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
            if(abs(x)&1!=s&1)
                continue;
            p=(x+s)/2;
            if((s&p)==p)
                a[j]++;
        }
    }
    for(i=0;i<l;i++)
    {
        if(i)
            printf(" ");
        printf("%d",a[i]&1);
    }
    printf("\n");
    return 0;
}
