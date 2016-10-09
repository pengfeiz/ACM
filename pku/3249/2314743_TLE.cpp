#include <iostream>
#include <vector>
using namespace std;

#define MAX 100002


bool in[MAX],out[MAX];
int cost[MAX],dist[MAX];
int n,m;


std::vector<int> a[MAX];


void init()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&cost[i]);
		in[i]=out[i]=false;
		dist[i]=-1;		
	}
	cost[0]=dist[0]=cost[n+1]=0;
	dist[n+1]=-1;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		out[x]=true;
		in[y]=true;
	}
	for(i=1;i<=n;i++)
	{
		if(!in[i])
			a[0].push_back(i);
		if(!out[i])
			a[i].push_back(n+1);
	}
}

void solve(int x,int l)
{
	std::vector<int>::iterator iter;
	for(iter=a[x].begin();iter!=a[x].end();iter++)
	{
		if(dist[x]+cost[*iter]>dist[*iter])
		{
			dist[*iter]=dist[x]+cost[*iter];
			solve(*iter,dist[*iter]);
		}
	}
}

void outt()
{
	int	i;	
	printf("%d\n",dist[n+1]);
	for(i=0;i<=n+1;i++)
		a[i].clear();
}

int main()
{
	while(!feof(stdin))
	{
		init();
		solve(0,0);
		outt();
	}
	return 0;
}