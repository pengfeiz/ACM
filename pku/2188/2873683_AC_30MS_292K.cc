#include <iostream>
using namespace std;

int a[1002],b[1002];
struct gao
{
    int x,y;
}c[1002];

int n;


int main()
{
    int i,j,t;
    while(scanf("%d",&n)!=EOF)
    {
        t=0;
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
                swap(b[j+1],b[j]);
                a[i]=j+1;
                t++;
            }
        }
        printf("%d\n",t);
    }
    return 0;
}
