//保存在d[]里 序列从1-p

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAX 10003

struct poi
{
	int x,y;
}a[MAX];


int n,d[MAX],p;
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
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,com);
}

bool cha(int x1,int y1,int x2,int y2)
{
	int x;
	x=x1*y2-x2*y1;
	if(x>0)
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
	for(i=n;i>0;i--)
	{
		if(!u[i])
		{
			while(cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y))
				u[d[p--]]=false;
			d[++p]=i;
			u[i]=true;
		}
	}
	p--;
}

//计算三角形面积
double compute(poi a,poi b,poi c)
{return (a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);}

int main()
{
	int i;
	int s=0;
	init();
	tubao();
	for(i=2;i<=p-1;i++)
		s+=compute(a[d[1]],a[d[i]],a[d[i+2]]);
	printf("%d\n",abs(s/50));
	return 0;
}