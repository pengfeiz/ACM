#include <iostream>
using namespace std;

int a[1001],b[1001];
struct gao
{
    int x,y;
}c[1001];

int n;

bool com(gao a,gao b)
{return a.x<b.x;}


int main()
{
    int p,i,j,t=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&c[i].x,&c[i].y);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(c[j].y==c[i].x)
                break;
        a[i]=j;
        b[j]=i;
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