#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX 1002
#define esp 1e-9


struct poi
{
	double x,y;
}a[MAX];

int d[MAX],n,p;
bool u[MAX];


bool com(poi a,poi b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}


void init()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a,a+n,com);
}


double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}

void tubao()
{
	memset(u,0,sizeof(u));
	int i;
	d[1]=p=1;
	d[0]=0;
	u[1]=true;
	for(i=2;i<n;i++)
	{
		while( p && cha( a[d[p]].x-a[d[p-1]].x, a[d[p]].y-a[d[p-1]].y, a[i].x-a[d[p-1]].x, a[i].y-a[d[p-1]].y)>=esp)
			u[d[p--]]=false;
		d[++p]=i;
		u[i]=true;
	}
	for(i=n-1;i>0;i--)
	{
		if(!u[i])
		{
			while(cha( a[d[p]].x-a[d[p-1]].x, a[d[p]].y-a[d[p-1]].y, a[i].x-a[d[p-1]].x, a[i].y-a[d[p-1]].y)>=esp)
				u[d[p--]]=false;
			d[++p]=i;
			u[i]=true;
		}
	}
p--;
}


bool jud(poi a,poi b,poi c)
{
	if(fabs(cha(a.x-b.x,a.y-b.y,b.x-c.x,b.y-c.y))<esp)
		return true;
	return false;
}

void solve()
{
	int i,q=0;
	bool t=true;
	d[p+1]=d[0];
	d[p+2]=d[1];
	memset(u,0,sizeof(u));
	for(i=0;i<=p;i++)
	{
		if(jud(a[d[i]],a[d[i+1]],a[d[i+2]]))
		{
			q++;
			u[i]=u[i+1]=true;
			continue;
		}
		if(u[i])
			continue;
		t=false;
		break;
	}
	if( t && q!=p+1 && p>=5 )
		printf("YES\n");
	else
		printf("NO\n");
}


int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		init();
		tubao();
		solve();
	}
	return 0;
}