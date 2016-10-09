//by small wpt

#include <iostream>
using namespace std;
const int maxn=110;
int p[maxn][maxn],a[maxn][maxn],f[maxn][maxn],num[maxn][maxn];
int r[maxn],punish[maxn];
int m,n,s;
void ini()
{
    int i,j;
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d",&s);
    for(i=0;i<m;i++)
    {
        p[i][0]=0;
        for(j=1;j<=n;j++)
            scanf("%d",&p[i][j]);
        scanf("%d",&r[i]);
        scanf("%d",&punish[i]);
    }
    memset(f,128,sizeof(f));       
    memset(num,-1,sizeof(num));
}
void set()
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<=n;j++)
            a[i][j]=(r[i]-s*j)*p[i][j]-punish[i]*(100-p[i][j]);
}
int get(int i,int j)
{
    int k;
    if(f[i][j]>f[109][109])
        return f[i][j];
    if(i==0)
    {
        f[i][j]=a[i][j];
        num[i][j]=1;
        for(k=0;k<j;k++)
            if(a[i][k]>f[i][j])
            {    
                f[i][j]=a[i][k];
                num[i][j]=0;
                
            }
        return f[i][j];
    }
    if(j==0)
    {
        f[i][j]=0;
        for(k=0;k<=i;k++)
            f[i][j]+=a[k][0];
        num[i][j]=1;
        return f[i][j];
    }
    int tmp;
    f[i][j]=get(i-1,j)+a[i][0];
    num[i][j]=num[i-1][j];
    for(k=1;k<=j;k++)
    {
        tmp=get(i-1,j-k)+a[i][k];
        if(tmp>f[i][j])
        {
            f[i][j]=tmp;
            num[i][j]=num[i-1][j-k];
        }       
        else
            if(tmp==f[i][j])
                if(num[i-1][j-k])
                    num[i][j]=1;
             
            
    }
    return f[i][j];
}
void solve()
{
    int max,i;
    max=get(m-1,n);
    printf("%d\n",max);
    for(i=0;i<=n;i++)
        if(get(m-1,i)==max&&num[m-1][i])
            printf("%d ",i);
    printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ini();
        set();
        solve();
    }    
}
