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
long    long  w[maxn];
long    long tot,ans;

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
        scanf("%lld",&w[i]);
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

long    long   dfs(int v)
{
    mnode   *iter;
    long    long     total;
 
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
  //  freopen("in.txt","r",stdin);
    cc=0;
    
    while(true)
    {
        cc++;
        init();
        dfs(1);
        printf("Case %d: %lld\n",cc,ans);
    }
    return(0);
}