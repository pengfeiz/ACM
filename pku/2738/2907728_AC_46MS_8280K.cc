#include <iostream>
using namespace std;

#define maxn 1010


int a[maxn][maxn][2];
int b[maxn];
int n;

int main()
{
  //  freopen("in.txt","r",stdin);
    int i,j,k,maxx,cc=0,tt;
    while(scanf("%d",&n),n)
    {
        tt=0;
        maxx=-99999999;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            tt+=b[i];
        }
        memset(a,0xff,sizeof(a));
        a[1][1][0]=a[1][n][1]=0;
        for(i=1;i<=n/2;i++)
            for(j=1;j<=n;j++)
            {
                for(k=0;k<=1;k++)
                {
                    if(a[i][j][k]<0)
                        continue;
                    if(k==0)
                    {
                        if(b[j+1]>=b[n-2*i+j+1])
                        {
                            if(a[i+1][j+2][0]<=a[i][j][k]+b[j])
                                a[i+1][j+2][0]=a[i][j][k]+b[j];
                            if(a[i+1][n-2*i+j+1][1]<=a[i][j][k]+b[j])
                                a[i+1][n-2*i+j+1][1]=a[i][j][k]+b[j];
                        }
                        else
                        {
                            if(a[i+1][j+1][0]<=a[i][j][k]+b[j])
                                a[i+1][j+1][0]=a[i][j][k]+b[j];
                            if(a[i+1][n-2*i+j][1]<a[i][j][k]+b[j])
                                a[i+1][n-2*i+j][1]=a[i][j][k]+b[j];
                        }
                    }
                    else
                    {
                        if(b[j-1]>b[2*i-n+j-1])
                        {
                            if(a[i+1][2*i-1-n+j][0]<a[i][j][k]+b[j])
                                a[i+1][2*i-1-n+j][0]=a[i][j][k]+b[j];
                            if(a[i+1][j-2][1]<a[i][j][k]+b[j])
                                a[i+1][j-2][1]=a[i][j][k]+b[j];
                        }
                        else
                        {
                            if(a[i+1][2*i-n+j][0]<a[i][j][k]+b[j])
                                a[i+1][2*i-n+j][0]=a[i][j][k]+b[j];
                            if(a[i+1][j-1][1]<a[i][j][k]+b[j])
                                a[i+1][j-1][1]=a[i][j][k]+b[j];                        }
                    }
                }
            }
        for(i=1;i<=n;i++)
        {
            if(a[n/2+1][i][0]>maxx)
                maxx=a[n/2+1][i][0];
            if(a[n/2+1][i][1]>maxx)
                maxx=a[n/2+1][i][1];
        }
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",++cc,2*maxx-tt);
    }
    return 0;
}

