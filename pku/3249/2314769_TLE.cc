#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX 100002


bool out[MAX];
int cost[MAX],dist[MAX],in[MAX];
int n,m;


std::vector<int> a[MAX];
std::list<int> q;


void init()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&cost[i]);
		in[i]=out[i]=0;
		dist[i]=-1;		
	}
	cost[0]=dist[0]=cost[n+1]=0;
	dist[n+1]=-1;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		out[x]=true;
		in[y]++;
	}
	for(i=1;i<=n;i++)
	{
		if(!in[i])
		{
			a[0].push_back(i);
			in[i]=1;
		}
		if(!out[i])
			a[i].push_back(n+1);
	}
	q.clear();
	q.push_back(0);
}

void solve()
{
	std::vector<int>::iterator iter;
	int	v;
	while(!q.empty())
	{
		v=*q.begin();
		q.pop_front();
		iter=a[v].begin();
		while(iter!=a[v].end())
		{
			in[*iter]--;
			if(dist[v]+cost[*iter]>dist[*iter])
				dist[*iter]=dist[v]+cost[*iter];
			if(!in[*iter])
				q.push_back(*iter);
			iter++;
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
		solve();
		outt();
	}
	return 0;
}