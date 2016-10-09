#include <iostream>
#include <vector>

using namespace std;

#define MAX 5002


struct gao
{
	int l1,l2;
};


int n,r;
gao a[MAX][MAX];
gao dist[MAX];
bool mark[MAX],d[MAX][MAX];


void init()
{
	int x,y,l,i,j;
	scanf("%d%d",&n,&r);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			a[i][j].l1=a[i][j].l2=0x7fffffff;
			d[i][j]=false;
		}
	while(r--)
	{
		scanf("%d%d%d",&x,&y,&l);
		if(l<a[x][y].l1)
		{
			d[x][y]=d[y][x]=true;
			a[x][y].l2=a[x][y].l1;
			a[x][y].l1=l;
			a[y][x].l2=a[y][x].l1;
			a[y][x].l1=l;
		}
		if(3*l<a[x][y].l2)
		{
			a[x][y].l2=3*l;
			a[y][x].l2=3*l;
		}
	}
}


void solve()
{
	int i,j,ll;
	memset(mark,0,sizeof(mark));
	memset(dist,127,sizeof(dist));
	dist[1].l1=0;
	mark[1]=true;
	i=1;
	while(i!=n)
	{
		for(j=1;j<=n;j++)
		{
			if(d[i][j])
			{
				ll=dist[i].l1+a[i][j].l1;
				if(ll<dist[j].l1)
				{
					dist[j].l2=dist[j].l1;
					dist[j].l1=ll;
				}
				else if(ll<dist[j].l2&&ll>dist[j].l1)
					dist[j].l2=ll;
				if(dist[i].l2+a[i][j].l1<dist[j].l2)
					dist[j].l2=dist[i].l2+a[i][j].l1;
				if(dist[i].l1+a[i][j].l2<dist[j].l2)
					dist[j].l2=dist[i].l1+a[i][j].l2;
			}
		}
		i=n;
		for(j=1;j<=n;j++)
			if(!mark[j]&&dist[j].l1<dist[i].l2)
			{
				i=j;
				break;
			}
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