#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 5001
#define MAX2 100002


struct gao
{
	int to,l1,l2;
};


struct hehe
{
	int x,y,l;
}c[MAX2];


int n,r;
vector<gao> a[MAX];
gao dist[MAX];
bool mark[MAX];


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
	p.l1=p.l2=100000000;
	c[r].x=-1;
	c[r].y=-1;
	for(i=0;i<=r;i++)
	{
		if(c[i].x==x&&c[i].y==y)
		{
			if(c[i].l<p.l1)
			{
				p.l2=p.l1;
				p.l1=c[i].l;
			}
			if(3*c[i].l<p.l2)
				p.l2=3*c[i].l;
		}
		else
		{
			p.to=y;
			a[x].push_back(p);
			p.to=x;
			a[y].push_back(p);
			p.l1=c[i].l;
			p.l2=3*c[i].l;
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
		dist[i].l1=dist[i].l2=100000000;
	dist[1].l1=0;
	mark[1]=true;
	i=1;
	while(i!=n)
	{
		iter=a[i].begin();
		while(iter!=a[i].end())
		{
			j=iter->to;
			ll=dist[i].l1+iter->l1;
			if(ll<dist[j].l1)
			{
				dist[j].l2=dist[j].l1;
				dist[j].l1=ll;
			}
			else if(ll<dist[j].l2&&ll>dist[j].l1)
				dist[j].l2=ll;
			if(dist[i].l2+iter->l1<dist[j].l2)
				dist[j].l2=dist[i].l2+iter->l1;
			if(dist[i].l1+iter->l2<dist[j].l2)
				dist[j].l2=dist[i].l1+iter->l2;
			iter++;
		}
		i=n;
		for(j=1;j<n;j++)
			if(!mark[j]&&dist[j].l1<dist[i].l1)
				i=j;
		mark[i]=true;
	}
	printf("%d\n",dist[n].l2);
}


int main()
{
//	freopen("in.txt","r",stdin);
	init();
	solve();
	return 0;
}