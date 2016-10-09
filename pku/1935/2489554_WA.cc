#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 50003


struct gao
{
	int to,l;
};

vector<gao> a[MAX];
int n,k,maxx,l;
bool c[MAX];
bool d[MAX];

bool dfs(int x,int ll)
{
	vector<gao>::iterator iter;
	int y;
	bool ff=false;
	if(d[x])
	{
		if(ll>maxx)
			maxx=ll;
		ff=true;
	}
	iter=a[x].begin();
	while(iter!=a[x].end())
	{
		y=iter->to;
		if(c[y])
		{
			iter++;
			continue;
		}
		c[y]=true;
		if(dfs(y,ll+iter->l))
		{
			l+=iter->l;
			ff=true;
			iter++;
		}
	}
	if(ff)
		return true;
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,x,y,h;
	gao p;
	while(scanf("%d%d",&n,&k)==2)
//	scanf("%I64d%I64d",&n,&k);
	{
		maxx=0;
		for(i=1;i<=n;i++)
			a[i].clear();
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&l);
//			x=1;y=i+1;l=1;
			p.to=y;
			p.l=l;
			a[x].push_back(p);
			p.to=x;
			a[y].push_back(p);
		}
		l=0;
		scanf("%d",&h);
		c[h]=d[h]=true;
		for(i=0;i<k;i++)
		{
			scanf("%d",&x);
			d[x]=true;
		}
		dfs(h,0);
		printf("%d\n",2*l-maxx);
	}
	return 0;
}


