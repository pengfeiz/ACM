#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1024

struct gao
{
	int x,y,l;
}d[MAX*MAX];


bool c[MAX];
int root[MAX],m;
int n;


bool com(gao a,gao b)
{
	if(a.l!=b.l)
		return a.l<b.l;
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}

int getroot(int a)
{
	int x;
	if(root[a]==a)
		return a;
	x=getroot(root[a]);
	root[a]=x;
	return x;
}

int main()
{
	int tt,i,j,kk,l,x,y,t;
	scanf("%d",&tt);
	for(kk=1;kk<=tt;kk++)
	{
		m=0;
		printf("Case %d:\n",kk);
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&l);
				if(i<j&&l)
				{
					d[m].x=i;
					d[m].y=j;
					d[m].l=l;
					m++;
				}
				getchar();
			}
		for(i=1;i<=n;i++)
			root[i]=i;
		sort(d,d+m,com);
		t=0;
		for(i=0;i<m;i++)
		{
			x=getroot(d[i].x);
			y=getroot(d[i].y);
			if(x==y)
				continue;
			else
			{
				printf("%c-%c %d\n",d[i].x+'A'-1,d[i].y+'A'-1,d[i].l);
				if(x>y)
					root[y]=x;
				else
					root[x]=y;
			}
		}
	}
	return 0;
}