#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

struct gao
{
	int x,y,l;
}a[MAX],b[MAX*MAX];

int n,m,t;

int root[MAX];

int ll(int a)
{return a*a;}
int dis(gao a,gao b)
{return ll(a.x-b.x)+ll(a.y-b.y);}
bool com(gao a,gao b)
{return a.l<b.l;}
int getroot(int x)
{
	int roo;
	if(root[x]==x)
		return x;
	roo=getroot(root[x]);
	root[x]=roo;
	return roo;
}
	
int main()
{
	int i,j,x,y;
	scanf("%d",&n);
	t=0;
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			b[t].x=i;
			b[t].y=j;
			b[t].l=dis(a[i],a[j]);
			t++;
		}
	for(i=1;i<=n;i++)
		root[i]=i;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x=getroot(x);
		y=getroot(y);
		if(x<y)
			root[y]=x;
		else
			root[x]=y;
	}
	sort(b,b+t,com);
	for(i=0;i<t;i++)
	{
		x=getroot(b[i].x);
		y=getroot(b[i].y);
		if(x==y)
			continue;
		else
		{
			printf("%d %d\n",b[i].x,b[i].y);
			if(x>y)
				root[x]=y;
			else
				root[y]=x;
		}
	}
	return 0;
}
