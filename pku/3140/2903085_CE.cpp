#include <iostream>
#include <vector>
using namespace std;
#define maxm 100100

int b[maxm];
bool c[maxm];
int n,m;
vector<int> a[maxm];
__int64 tt,minn,x;


__int64 dfs(int u,int ff)
{
    __int64 t=0,x;
    vector<__int64>::iterator p;
    for(p=a[u].begin();p<a[u].end();p++)
    {
        if(*p==ff)
            continue;
        x=dfs(*p,u);
        t+=x;
        if(abs(tt-2*x)<minn)
            minn=abs(tt-2*x);
    }
    return t+b[u];
}


int main()
{
    freopen("in.txt","r",stdin);
    int i,p,q,cc=0;
    vector<__int64>::iterator pp;
    
    while(scanf("%d%d",&n,&m),n||m)
    {
        minn=(__int64)1e20;
        tt=0;
        for(i=1;i<=n;i++)
        {
            a[i].clear();
            c[i]=false;
            scanf("%d",&b[i]);
            tt+=b[i];
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&p,&q);
            c[p]=true;
            for(pp=a[q].begin();pp<a[q].end();pp++)
            {
                if(*pp==p)
                    break;
            }
            if(pp==a[q].end())
            {
                a[p].push_back(q);
                a[q].push_back(p);
            }
        }
        x=dfs(1,0);
        if(x<minn)
            minn=x;
        printf("Case %d: %I64d\n",++cc,minn);
    }
    return 0;
}
