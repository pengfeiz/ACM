#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAX 100005
#define esp 1e-8


struct poi
{
	double x,y;
}a[MAX];


int n,d[MAX],p;
bool u[MAX];


bool com(poi a,poi b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}


bool init()
{
	int i;
	scanf("%d",&n);
	if(!n)
		return false;
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,com);
	return true;
}

bool cha(double x1,double y1,double x2,double y2)
{
	double x;
	x=x1*y2-x2*y1;
	if(x>esp)
		return true;
	return false;
}

void tubao()
{
	int i;
	memset(u,0,sizeof(u));
	d[1]=1;
	d[2]=p=2;
	u[2]=true;
	for(i=3;i<=n;i++)
	{
		while( p>1 && cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y))
			u[d[p--]]=false;
		d[++p]=i;
		u[i]=true;
	}
	for(i=n;i>1;i--)
	{
		if(!u[i])
		{
			while(cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y))
				u[d[p--]]=false;
			d[++p]=i;
			u[i]=true;
		}
	}
}


void slove()
{
	int i;
	double s=0,w=0,ss;
	d[p+2]=d[2];
	d[p+1]=d[1];
	for(i=1;i<=p;i++)
	{
		ss=-(a[d[i]].x*a[d[i+1]].y + a[d[i+1]].x*a[d[i+2]].y + a[d[i+2]].x*a[d[i]].y - a[d[i]].y*a[d[i+1]].x - a[d[i+1]].y*a[d[i+2]].x - a[d[i]].x*a[d[i+2]].y)/2;
		if(s<ss)
			s=ss;
	}
	for(i=3;i<=p;i++)
		w+=a[d[1]].x*a[d[i]].y+a[d[2]].x*a[d[1]].y+a[d[i]].x*a[d[2]].y-a[d[1]].x*a[d[2]].y-a[d[2]].x*a[d[i]].y-a[d[i]].x*a[d[1]].y;
	w/=2;
	w-=s;
	printf("%.2lf\n",w);
}
		
int main()
{
	while(init())
	{
		tubao();
		slove();
	}
	return 0;
}