#include<iostream>
#include<math.h>
using namespace std;
#define Maxn 100001
//#define Maxm 100001
int w[Maxn],n,m;
__int64 sum,max=-999999999;
int color[Maxn];  
struct node
{
	int v;     //邻接点,或者出度值
	int d;  //入度值

	struct node *next;
};
struct node graph[Maxn];
void Insert(int a,int b)
{
	struct node *p;
	p=(node*)malloc(sizeof(node));
	p->v=b;
	graph[a].v++;
	graph[b].d++;
	p->next=graph[a].next;
	graph[a].next=p;
}

void dfs(int s)
{
	
    if(graph[s].v==0)
	{
         if(max<sum)
			 max=sum;
	}
	struct node *p;
	p=(node*)malloc(sizeof(node));
	p=graph[s].next;
	while(p!=NULL)
	{
		
		if(color[p->v]==0)
		{
			sum+=w[p->v];
		   color[p->v]=1;
		   dfs(p->v);
		   color[p->v]=0;
		   sum-=w[p->v];
		}
      p=p->next;
	}
	color[s]=2;
	free(p);
}
void liffeng()
{
     int i;
	 memset(color,0,sizeof(color));
	 
	 for(i=1;i<=n;i++)
	 {
		 if(color[i]!=2&&graph[i].d==0)
		 {
			 sum=w[i];
			 dfs(i);
		 }
	 }
	printf("%I64d\n",max);
}
void makemap()
{
	int i,a,b;

	freopen("in.txt","r",stdin);

   while(cin>>n>>m)
   {
		for(i=1;i<=n;i++)
			 graph[i].d=graph[i].v=0;
		for(i=1;i<=n;i++)
			cin>>w[i];
		
		for(i=1;i<=m;i++)
		{
			cin>>a>>b;
			Insert(a,b);
		//	delet();
		}
		liffeng();
   }

}
int main()
{
	makemap();
	
	return 0;
}