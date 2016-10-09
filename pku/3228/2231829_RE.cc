#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 201
#define min(a,b) a<b?a:b

int a[MAX],b[MAX],n,m;
int root[MAX];

struct gao
{
	int p,q,l;
}x[MAX*MAX];

bool com(gao a,gao b)
{
	return a.l<b.l;
}

int getroot(int x)
{
	int foot;
	if(x==root[x])
		return x;
	foot=getroot(root[x]);
	root[x]=foot;
	return foot;
}	

bool judge()
{
	int i;
	int c[MAX];
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++)
	{
		c[getroot(i)]-=a[i];
		c[getroot(i)]+=b[i];
	}
	for(i=1;i<=n;i++)
		if(c[i]<0)
			return true;
	return false;
}

int main()
{
	int i,j,p,q,l,mm;
	while(scanf("%d",&n),n)
	{
		mm=0;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&p,&q,&l);
			x[i].p=p;
			x[i].q=q;
			x[i].l=l;
		}
		for(i=0;i<=n;i++)
			root[i]=i;
		sort(x,x+m,com);
		j=0;
		while(judge())
		{
			while(root[x[j].p]==root[x[j].q])
				j++;
			p=x[j].p;
			q=x[j].q;
			l=min(p,q);
			root[p]=root[l];
			root[q]=root[l];
			if(mm<x[j].l)
				mm=x[j].l;
			getroot(p);
			getroot(q);
		}
		printf("%d\n",mm);
	}
	return 0;
}