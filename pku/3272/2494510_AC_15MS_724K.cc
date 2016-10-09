#include <iostream>
#include <vector>
using namespace std;
#define MAX 5002

struct gao
{
	int x,y;
}g[MAX*10];
vector<int> b[MAX],bb[MAX];
int n,m,t,maxx,p,q;
int in[MAX],out[MAX],d[MAX],dd[MAX],a[MAX];

void bfs()
{
	vector<int>::iterator iter;
	int i;
	while(p<q)
	{
		for(i=p;i<q;i++)
		{
			iter=b[a[i]].begin();
			while(iter!=b[a[i]].end())
			{
				d[*iter]+=d[a[i]];
				in[*iter]--;
				if(!in[*iter])
					a[q++]=*iter;
				iter++;
			}
		}
		p=q;
	}
}
void bfs2()
{
	vector<int>::iterator iter;
	int i;
	while(p<q)
	{
		for(i=p;i<q;i++)
		{
			iter=bb[a[i]].begin();
			while(iter!=bb[a[i]].end())
			{
				dd[*iter]+=dd[a[i]];
				out[*iter]--;
				if(!out[*iter])
					a[q++]=*iter;
				iter++;
			}
		}
		p=q;
	}
}

int main()
{
	int i,x,y;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&g[i].x,&g[i].y);
		x=g[i].x;
		y=g[i].y;
		in[y]++;
		out[x]++;
		b[x].push_back(y);
		bb[y].push_back(x);
	}
	p=q=0;
	memset(d,0,sizeof(d));
	for(i=1;i<n;i++)
	{
		if(!in[i])
		{
			a[q++]=i;
			d[i]=1;
		}
	}
	bfs();
	p=q=0;
	memset(dd,0,sizeof(dd));
	a[q++]=n;
	dd[n]=1;
	bfs2();
	maxx=0;
	for(i=0;i<m;i++)
		if(maxx<d[g[i].x]*dd[g[i].y])
			maxx=d[g[i].x]*dd[g[i].y];
	printf("%d\n",maxx);
	return 0;
}
