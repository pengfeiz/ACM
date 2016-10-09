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
int n,k;
bool c[MAX];
bool d[MAX];

int dfs(int x,bool &f,int &l3)
{
	vector<gao>::iterator iter;
	int l1,ll,l,y,ff=0,l2;
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
		l=dfs(y,he,l2)+iter->l;
		l2+=iter->l;
		if(!he)
		{
			l=0;
			iter++;
			continue;
		}
		else
		{
			ff++;
			f=true;
			if(l2>l1)
			{
				ll+=l1;
				l1=l2;
			}
			else
				ll+=l2;
		}
		ll+=l;
		iter++;
	}
	if(ff>1)
	{
		l3=l1;
		return ll;
	}
	else if(ff==1)
	{
		l3=ll;
		return ll;
	}
	l3=0;
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,x,y,l,h,l3;
	bool f;
	gao p;
	while(scanf("%d%d",&n,&k)==2)
//	scanf("%d%d",&n,&k);
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
		l=dfs(h,f,l3);
		printf("%d\n",l);
	}
	return 0;
}


