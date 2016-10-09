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
__int64 n,k;
bool c[MAX];
bool d[MAX];

__int64 dfs(__int64 x,bool &f)
{
	vector<gao>::iterator iter;
	__int64 l1,ll,l,y,ff=0;
	l1=ll=0;
	bool he;
	if(d[x])
		f=true;
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
		l=dfs(y,he)+iter->l;
		if(!he)
			l=0;
		else
		{
			ff++;
			f=true;
			if(l>l1)
				l1=l;
		}
		ll+=l;
		iter++;
	}
	if(ff>1)
		return 2*ll-l1;
	else if(ff==1)
		return ll;
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	__int64 i,x,y,l,h;
	bool f;
	gao p;
	while(scanf("%I64d%I64d",&n,&k)==2)
	{
		f=false;
		for(i=1;i<=n;i++)
			a[i].clear();
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(i=1;i<n;i++)
		{
			scanf("%I64d%I64d%I64d",&x,&y,&l);
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
		l=dfs(h,f);
		printf("%I64d\n",l);
	}
	return 0;
}


