#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 50003


struct gao
{int to,l;};

vector<gao> a[MAX];
int n,k,maxx,l;
bool c[MAX],d[MAX];

bool dfs(int x,int ll)
{
	vector<gao>::iterator iter;
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
		if(!c[iter->to])
		{
			c[iter->to]=true;
			if(dfs(iter->to,ll+iter->l))
			{
				l+=iter->l;
				ff=true;
			}
		}
		iter++;
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
//	while(scanf("%d%d",&n,&h)==2)
	{
	scanf("%I64d%I64d",&n,&k);
	for(i=1;i<=n;i++)
		a[i].clear();
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&h);
		p.to=y;
		p.l=h;
		a[x].push_back(p);
		p.to=x;
		a[y].push_back(p);
	}
	maxx=l=0;
	scanf("%d",&k);
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


