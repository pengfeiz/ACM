#include<cstdio>
#include<algorithm>

const   int     maxn=100001;
const   int     maxm=1000001;

struct  mnode
{
    int     v;
    mnode   *next;
};

mnode   mem[maxm*2];
int     mtail;
mnode   *graph[maxn];

int      n,m;
__int64 w[maxn];
__int64 tot,ans;

void    gadd(int    u,int   v)
{
    mtail++;
    mem[mtail].v=v;
    mem[mtail].next=graph[u];
    graph[u]=&mem[mtail];
}

bool    marked[maxn];

void    init()
{
    int i,u,v;
    
    mtail=0;
    memset(graph,0,sizeof(graph));
    memset(marked,0,sizeof(marked));
    tot=0;
    
    scanf("%d %d\n",&n,&m);

    if (n+m==0)
        exit(0);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&w[i]);
        tot+=w[i];
    }
    scanf("\n");
    for (i=1;i<=m;i++)
    {
        scanf("%d %d\n",&u,&v);
        gadd(u,v);
        gadd(v,u);
    }
    
    ans=(__int64)1e20;

}

__int64 dfs(int v)
{
    mnode   *iter;
    __int64 total;
 
    total=w[v];
    marked[v]=true;
    
    for (iter=graph[v];iter;iter=iter->next)
        if (!marked[iter->v])
            total+=dfs(iter->v);
    ans<?=abs(tot-total-total);
    return(total);
}
int     cc;

int     main()
{
 //   freopen("in.txt","r",stdin);
    cc=0;
    
    while(true)
    {
        cc++;
        init();
        dfs(1);
        printf("Case %d: %I64d\n",cc,ans);
    }
    return(0);
}