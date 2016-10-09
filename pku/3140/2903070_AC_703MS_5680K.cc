#include <iostream>
#include <vector>
using namespace std;
#define maxm 100100

__int64 b[maxm];
bool c[maxm];
__int64 n,m;
vector<__int64> a[maxm];
__int64 tt,minn,x;


__int64 dfs(__int64 u,__int64 ff)
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
 //   freopen("in.txt","r",stdin);
    __int64 i,p,q,cc=0;
    vector<__int64>::iterator pp;
    
    while(scanf("%I64d%I64d",&n,&m),n||m)
    {
        minn=(__int64)1e20;
        tt=0;
        for(i=1;i<=n;i++)
        {
            a[i].clear();
            c[i]=false;
            scanf("%I64d",&b[i]);
            tt+=b[i];
        }
        for(i=0;i<m;i++)
        {
            scanf("%I64d%I64d",&p,&q);
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
        printf("Case %I64d: %I64d\n",++cc,minn);
    }
    return 0;
}
