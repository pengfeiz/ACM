#include<cstdio>
#include<algorithm>

const   int     maxn=26;
const   int     maxm=21;

struct  enode
{
    int     u,v,c;
};

enode   edge[maxm];
int     etail;

struct  mnode
{
    int     v;
    mnode   *next;
};

mnode   mem[maxm*2];
int     mtail;
mnode   *graph[maxn];
int     n,m,ans,cc;

bool    marked[maxm];


void    init()
{
    int i;
    
    memset(marked,0,sizeof(marked));
    
    scanf("%d %d\n",&n,&m);
    if (n+m==0)
        exit(0);
    
    etail=m;
    for (i=1;i<=m;i++)
        scanf("%d %d %d\n",&edge[i].u,&edge[i].v,&edge[i].c);
    
    ans=0x7fffffff;
}

void    gadd(int    u,int   v)
{
    mtail++;
    mem[mtail].v=v;
    mem[mtail].next=graph[u];
    graph[u]=&mem[mtail];
}

int     low[maxn];
int     dfn[maxn];
int     p,tt;

bool    cal1(int v,int  parents)
{
    mnode   *iter;
    
    p++;
    dfn[v]=p;
    low[v]=p;
    
    for (iter=graph[v];iter;iter=iter->next)
        if (iter->v!=parents)
        {
            if (!dfn[iter->v])
                cal1(iter->v,v);
            if (low[iter->v]<low[v])
                low[v]=low[iter->v];            
        }
    
    if (low[v]>=dfn[v])        
        tt++;
    return(tt<=1);
}

bool    check()
{
    int i;
    
    memset(graph,0,sizeof(graph));
    memset(dfn,0,sizeof(dfn));
    tt=0;
    mtail=0;
    p=0;
    
    for (i=1;i<=etail;i++)
        if (marked[i])
        {
            gadd(edge[i].u,edge[i].v);
            gadd(edge[i].v,edge[i].u);
        }
    if (cal1(1,0))
    {
        tt=0;
        for (i=1;i<=n;i++)
            if (dfn[i])
                tt++;
        if (n==tt)
            return(true);
    }
    return(false);
}


void    dfs(int p,int   total)
{

    if (p>etail)
    {
        if ((check())&&(total<ans))
            ans=total;
        return;
    }
    
    marked[p]=true;
    dfs(p+1,total+edge[p].c);
    
    marked[p]=false;
    dfs(p+1,total);
}
int     main()
{
    
    cc=0;
    while(true)
    {
        cc++;
        init();
        dfs(1,0);
        if (ans^0x7fffffff)
            printf("The minimal cost for test case %d is %d.\n",cc,ans);
        else
            printf("There is no reliable net possible for test case %d.\n",cc);
    }
    return(0);
}

