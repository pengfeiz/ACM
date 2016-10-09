#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001

struct gao
{
	int x,y,l;
}z[4]={0,1,0,1,0,0,-1,0,0,0,-1,0},d[MAX],dd[MAX],a[MAX];


int n,n1,n2;
bool c[MAX];

bool com(gao a,gao b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}


int bfs(int x)
{
	int s,i,j,q;
	gao p;
	n1=1;
	c[x]=true;
	d[0].x=a[x].x;
	d[0].y=a[x].y;
	s=a[x].l;
	while(n1)
	{
		n2=0;
		for(i=0;i<n1;i++)
		{
			for(j=0;j<4;j++)
			{
				p.x=d[i].x+z[j].x;
				p.y=d[i].y+z[j].y;
				q=lower_bound(a,a+n,p,com)-a;
				if(q==n)
					continue;
				if(a[q].x!=p.x||a[q].y!=p.y)
					continue;
				if(c[q])
					continue;
				c[q]=true;
				s+=a[q].l;
				dd[n2].x=p.x;
				dd[n2].y=p.y;
				n2++;
			}
		}
		n1=n2;
		for(i=0;i<n1;i++)
		{
			d[i].x=dd[i].x;
			d[i].y=dd[i].y;
		}
	}
	return s;
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i,maxx,q;
	while(scanf("%d",&n),n)
	{
		maxx=0;
		for(i=0;i<n;i++)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l);
		sort(a,a+n,com);
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)
		{
			if(!c[i])
			{
				q=bfs(i);
				if(q>maxx)
					maxx=q;
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}