#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 50003


struct gao
{
	__int64 to,l;
};

vector<gao> a[MAX];
__int64 n,k,maxx;
bool c[MAX];
bool d[MAX];

__int64 dfs(__int64 x,bool &f,__int64 l3)
{
	vector<gao>::iterator iter;
	__int64 l1,ll,l,y;
	l1=ll=0;
	bool he,ff=false;
	if(d[x])
	{
		if(l3>maxx)
			maxx=l3;
		f=true;
	}
	iter=a[x].begin();
	while(iter!=a[x].end())
	{
		he=false;
		y=iter->to;
		if(c[y])
		{
			iter++;
			continue;
		}
		c[y]=true;
		l=dfs(y,he,l3+iter->l)+iter->l;
		if(!he)
		{
			iter++;
			continue;
		}
		ff=f=true;
		ll+=l;
		iter++;
	}
	if(ff)
		return ll;
	return 0;
}

int main()

{
//	freopen("in.txt","r",stdin);
	__int64 i,x,y,l,h,l3;
	bool f;
	gao p;
	while(scanf("%d%d",&n,&k)==2)
//	scanf("%I64d%I64d",&n,&k);
	{
		maxx=0;
		f=false;
		for(i=1;i<=n;i++)
			a[i].clear();
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(i=1;i<n;i++)
		{
			scanf("%I64d%I64d%I64d",&x,&y,&l);
//			x=1;y=i+1;l=1;
			p.to=y;
			p.l=l;
			a[x].push_back(p);
			p.to=x;
			a[y].push_back(p);
		}
		scanf("%I64d",&h);
		c[h]=d[h]=true;
		for(i=0;i<k;i++)
		{
			scanf("%I64d",&x);
			d[x]=true;
		}
		l3=0;
		l=dfs(h,f,l3);
		printf("%I64d\n",2*l-maxx);
	}
	return 0;
}


