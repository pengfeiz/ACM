#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1002][1002];
int b[1002];
int c[1002];

int main()
{
    freopen("/home/star6/in","r",stdin);
    int i,j,maxx;
    while(scanf("%d",&n),n)
    {
        maxx=-99999999;
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&c[i]);
        sort(b+1,b+1+n);
        sort(c+1,c+1+n);
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                a[i][j]-99999999;
        a[0][0]=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
            {
                if(b[i]>c[j])
                {
                    if(a[i][j]<a[i-1][j-1]+200)
                        a[i][j]=a[i-1][j-1]+200;
                }
                else if(b[i]<c[j])
                {
                    if(a[i][j-1]<a[i-1][j-1]-200)
                        a[i][j-1]=a[i-1][j-1]-200;
                }
                else
                {
                    if(a[i][j]<a[i-1][j-1])
                        a[i][j]=a[i-1][j-1];
                    if(b[i]==c[n-i+j])
                    {
                        if(a[i][j-1]<a[i-1][j-1])
                            a[i][j-1]=a[i-1][j-1];
                    }
                    else if(b[i]<c[n-i+j])
                    {
                        if(a[i][j-1]<a[i-1][j-1]-200)
                            a[i][j-1]=a[i-1][j-1]-200;
                    }
                }
            }
        for(i=0;i<=n;i++)
            if(a[n][i]>maxx)
                maxx=a[n][i];
        printf("%d\n",maxx);
    }
    return 0;
}
