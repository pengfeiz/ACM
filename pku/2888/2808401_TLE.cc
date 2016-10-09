#include<cstdio>
#include<algorithm>

const   int     maxn=14;
const   int     maxm=8300;
bool    graph[maxn][maxn];
int     n,m;
int  point[maxn];
int		goal;

void    init()
{
    int i,u,v;
    
    memset(graph,0,sizeof(graph));
    
    scanf("%d %d\n",&n,&m);
    goal=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&point[i]);
        goal<<=1;
        goal|=1;
    }
    scanf("\n");
    
    
    
    for (i=1;i<=m;i++)
    {    	
        scanf("%d %d\n",&u,&v);
        graph[u][v]=true;
        graph[v][u]=true;
    }
}
struct  qnode
{
    int s,last,current;
    
    qnode(int   ts,int  tl,int  tc):
        s(ts),last(tl),current(tc)
        {
           
        }
   qnode()
   {
       
   }
};
qnode   q[maxn*maxm*maxn];
int     qhead,qtail;
int dist[maxm][maxn][maxn];
int best;
int		count[maxm][maxn][maxn];

void    check(qnode    s,int   v)
{
    qnode   ret;
    int     t;
    
    if ((s.s>>(v-1))&1)
        return;

   		
    ret.s=s.s;
    ret.s|=1<<(v-1);
    ret.last=s.current;
    ret.current=v;  
    t=dist[s.s][s.last][s.current];
    t+=point[v]+point[s.current]*point[v];
    if ((graph[s.last][v])&&(s.last))
        t+=point[s.last]*point[s.current]*point[v];
    
    if (t>dist[ret.s][ret.last][ret.current])
    {
    	if (dist[ret.s][ret.last][ret.current]<0)
    	{
    		qtail++;
        	q[qtail]=ret;
    	}
    	count[ret.s][ret.last][ret.current]=count[s.s][s.last][s.current];
        dist[ret.s][ret.last][ret.current]=t;
    }
    else
    if(t==dist[ret.s][ret.last][ret.current])
    	count[ret.s][ret.last][ret.current]+=count[s.s][s.last][s.current];
}

void    starmain()
{
	int		i,j;
    	
    memset(dist,128,sizeof(dist));
    memset(count,0,sizeof(count));
    
    qhead=1;
    qtail=n;
    for (i=1;i<=n;i++)
    {
        q[i]=qnode(1<<(i-1),0,i);
        dist[1<<(i-1)][0][i]=point[i];
        count[q[i].s][0][i]=1;
    }
    
    while(qhead<=qtail)
    {        
        for (i=1;i<=n;i++)
            if (graph[q[qhead].current][i])
                check(q[qhead],i);
        qhead++;
    }
    
    best=dist[0][0][0];
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (dist[goal][i][j]>best)
				best=dist[goal][i][j];
				
    
    if (best<0)
    {
    	printf("0 0\n");
    	return;
    }
    

    __int64	total=0;
    
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if ((dist[goal][i][j]==best)&&(i!=j))		
				total+=count[goal][i][j];
	if (total==1)	
		printf("%d %I64d\n",best,total);
	else
   printf("%d %I64d\n",best,total/2);
}

int     main()
{
    int t;
    
//    freopen("c:\\in.txt","r",stdin);
    
    scanf("%d\n",&t);
    
    while(t--)
    {
        init();
        if (n==1)
    	{
    		printf("%d 1\n",point[1]);
    		continue;
    	}	
    	if (!m)
    	{
    		printf("0 0\n");
    		continue;
    	}
    	
        starmain();
    }
    
    return(0);
}

