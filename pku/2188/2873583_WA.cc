#include <iostream>
using namespace std;

int a[1001],b[1001];

int n;

int main()
{
    int p,i,j,t=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&p,&j);
        a[p]=j;
        b[j]=p;
    }
    for(i=n;i>0;i--)
    {
        for(j=a[i];j<i;j++)
        {
            a[b[j+1]]=j;
            b[j+1]=i;
            b[j]=a[i];
            t++;
        }
    }
    printf("%d\n",t);
    return 0;
}