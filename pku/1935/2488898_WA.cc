#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 50002


struct gao
{
	int to,l;
};

vector<gao> a[MAX];
int n,k;
bool c[MAX];
bool d[MAX];

int dfs(int x,bool &f)
{
	vector<gao>::iterator iter;
	int l1,ll,l,y,ff=0;
	l1=9999999;
	ll=0;
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
			if(l<l1)
				l1=l;
		}
		ll+=l;
		iter++;
	}
	if(ff>1)
		return l1+ll;
	else if(ff==1)
		return ll;
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,x,y,l,h;
	bool f;
	gao p;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		f=false;
		for(i=1;i<=n;i++)
			a[i].clear();
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&l);
			p.to=y;
			p.l=l;
			a[x].push_back(p);
			p.to=x;
			a[y].push_back(p);
		}
		scanf("%d",&h);
		c[h]=d[h]=true;
		for(i=0;i<k;i++)
		{
			scanf("%d",&x);
			d[x]=true;
		}
		l=dfs(h,f);
		printf("%d\n",l);
	}
	return 0;
}


