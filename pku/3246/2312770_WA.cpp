#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 100005

struct poi
{
	__int64 x,y;
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
		scanf("%I64d%I64d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,com);
	return true;
}

bool cha(__int64 x1,__int64 y1,__int64 x2,__int64 y2)
{
	if(x1*y2>x2*y1)
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
	__int64 w=0,ss,s=0;
	d[p+2]=d[2];
	d[p+1]=d[1];
	for(i=1;i<=p;i++)
	{
		ss=-(a[d[i]].x*a[d[i+1]].y + a[d[i+1]].x*a[d[i+2]].y + a[d[i+2]].x*a[d[i]].y - a[d[i]].y*a[d[i+1]].x - a[d[i+1]].y*a[d[i+2]].x - a[d[i]].x*a[d[i+2]].y);
		if(s<ss)
			s=ss;
	}
	for(i=2;i<p;i++)
		w+=abs(a[d[1]].x*a[d[i]].y+a[d[i+1]].x*a[d[1]].y+a[d[i]].x*a[d[i+1]].y-a[d[1]].x*a[d[i+1]].y-a[d[i+1]].x*a[d[i]].y-a[d[i]].x*a[d[1]].y);
	w-=s;
	if(w%2)
		printf("%I64d.50\n",w/2);
	else
		printf("%I64d\n",w/2);
}
		
int main()
{
//	freopen("in.txt","r",stdin);
	while(init())
	{
		tubao();
		slove();
	}
	return 0;
}