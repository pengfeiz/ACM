#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 200001

struct gao
{
	int x,y;
}a[MAX];

bool x[MAX],y[MAX];
bool com1(gao a,gao b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
bool com2(gao a,gao b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}
	
int main()
{
	int t,tt;
	int l,n,m,i;
	scanf("%d",&t);
	while(t--)
	{
		tt=0;
		scanf("%d%d%d",&n,&m,&l);
		for(i=1;i<=n;i++)
			x[i]=false;
		for(i=1;i<=m;i++)
			y[i]=false;
		for(i=1;i<=l;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			x[a[i].x]=true;
			y[a[i].y]=true;
		}
		for(i=1;i<=n;i++)
			if(!x[i])
				tt++;
		for(i=1;i<=m;i++)
			if(!y[i])
				tt++;

		sort(a,a+l,com1);
		a[l+1].x=a[l].x;
		a[l+1].y=999999;
		a[0].x=0;
		a[0].y=m;
		for(i=0;i<=l;i++)
		{
			if(a[i].x!=a[i+1].x)
			{
				if(a[i+1].y>2)
					tt++;
				if(a[i].y<m-1)
					tt++;
			}
			else if(a[i+1].y-a[i].y>2)
				tt++;
		}
		sort(a,a+l,com2);
		a[l+1].y=a[l].y;
		a[l+1].x=999999;
		a[0].y=0;
		a[0].x=m;
		for(i=0;i<=l;i++)
		{
			if(a[i].y!=a[i+1].y)
			{
				if(a[i+1].x>2)
					tt++;
				if(a[i].x<n-1)
					tt++;
			}
			else if(a[i+1].x-a[i].x>2)
				tt++;
		}
		printf("%d\n",tt);
	}
	return 0;
}


			