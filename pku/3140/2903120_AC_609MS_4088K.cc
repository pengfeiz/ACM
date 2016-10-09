#include <iostream>
#include <vector>
using namespace std;
#define maxm 100100

int b[maxm];
int n,m;
vector<int> a[maxm];
__int64 tt,minn,x;


__int64 dfs(int u,int ff)
{
    __int64 t=0,x,yy;
    vector<int>::iterator p;
    for(p=a[u].begin();p<a[u].end();p++)
    {
        if(*p==ff)
            continue;
        x=dfs(*p,u);
        t+=x;
        yy=abs(tt-2*x);
        if(yy<minn)
            minn=yy;
    }
    return t+b[u];
}


int main()
{
    int i,p,q,cc=0;
    vector<int>::iterator pp;
    
    while(scanf("%d%d",&n,&m),n||m)
    {
        minn=(__int64)1e20;
        tt=0;
        for(i=1;i<=n;i++)
        {
            a[i].clear();
            scanf("%d",&b[i]);
            tt+=b[i];
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&p,&q);
            a[p].push_back(q);
            a[q].push_back(p);
        }
        x=dfs(1,0);
        if(x<minn)
            minn=x;
        printf("Case %d: %I64d\n",++cc,minn);
    }
    return 0;
}

