#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 201


int a[MAX],b[MAX],n,m,tt;
int root[MAX];

struct gao
{
	int p,q,l;
}x[MAX*MAX];

int minn(int a,int b)
{
	return a<b?a:b;
}

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
		mm=tt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			tt-=a[i];
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			tt+=b[i];
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&p,&q,&l);
			x[i].p=p;
			x[i].q=q;
			x[i].l=l;
		}
		if(tt<0)
		{
			printf("No Solution\n");
			continue;
		}
		for(i=0;i<=n;i++)
			root[i]=i;
		sort(x,x+m,com);
		j=0;
		while(j<m&&judge())
		{
			while(j<m&&getroot(x[j].p)==getroot(x[j].q))
				j++;
			if(j==m)
				break;
			if(mm<x[j].l)
				mm=x[j].l;
			p=getroot(x[j].p);
			q=getroot(x[j].q);
			l=minn(p,q);
			root[p]=root[q]=l;
		}
		if(judge())
			printf("No Solution\n");
		else
			printf("%d\n",mm);
	}
	return 0;
}
