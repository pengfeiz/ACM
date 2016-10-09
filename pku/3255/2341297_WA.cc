#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 5001
#define MAX2 100002


struct gao
{
	int to,l[2];
};


struct hehe
{
	int x,y,l;
}c[MAX2];


int n,r;
vector<gao> a[MAX];
gao dist[MAX];
int mark[MAX];


bool com(hehe x,hehe y)
{
	if(x.x!=y.x)
		return x.x<y.x;
	return x.y<y.y;
}


void init()
{
	int x,y,i;
	gao p;
	scanf("%d%d",&n,&r);
	for(i=0;i<r;i++)
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].l);
	sort(c,c+r,com);
	x=c[0].x;
	y=c[0].y;
	p.l[0]=p.l[1]=1000000000;
	c[r].x=-1;
	c[r].y=-1;
	for(i=0;i<=r;i++)
	{
		if(c[i].x==x&&c[i].y==y)
		{
			if(c[i].l<p.l[0])
			{
				p.l[1]=p.l[0];
				p.l[0]=c[i].l;
			}
			if(3*c[i].l<p.l[1])
				p.l[1]=3*c[i].l;
		}
		else
		{
			p.to=y;
			a[x].push_back(p);
			p.to=x;
			a[y].push_back(p);
			p.l[0]=c[i].l;
			p.l[1]=3*c[i].l;
			x=c[i].x;
			y=c[i].y;
		}
	}
}


void solve()
{
	int i,j,ll;
	std::vector<gao>::iterator iter;
	memset(mark,0,sizeof(mark));
	for(i=1;i<=n;i++)
		dist[i].l[0]=dist[i].l[1]=1000000000;
	dist[1].l[0]=0;
	mark[1]=1;
	i=1;
	while(mark[n]<2)
	{
		iter=a[i].begin();
		while(iter!=a[i].end())
		{
			j=iter->to;
			ll=dist[i].l[0]+iter->l[0];
			if(ll<dist[j].l[0])
			{
				dist[j].l[1]=dist[j].l[0];
				dist[j].l[0]=ll;
			}
			else if(ll<dist[j].l[1]&&ll>dist[j].l[0])
				dist[j].l[1]=ll;
			if(dist[i].l[1]+iter->l[0]<dist[j].l[1])
				dist[j].l[1]=dist[i].l[1]+iter->l[0];
			if(dist[i].l[0]+iter->l[1]<dist[j].l[1])
				dist[j].l[1]=dist[i].l[0]+iter->l[1];
			iter++;
		}
		i=n;
		for(j=1;j<=n;j++)
			if(mark[j]<2&&dist[j].l[mark[j]]<dist[i].l[mark[i]])
				i=j;
		mark[i]++;
	}
	printf("%d\n",dist[n].l[1]);
}


int main()
{
//	freopen("in.txt","r",stdin);
	init();
	solve();
	return 0;
}