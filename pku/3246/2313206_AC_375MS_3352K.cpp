#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 100010
#define esp 1e-7

struct poi
{
	__int64 x,y;
}a[MAX],aa[MAX],a2[MAX],a3[MAX];


int n,nn,d[MAX],p,q,dd[MAX],c[MAX],qq;
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

void tubao(poi a[],int d[],int &p,int n)
{
	int i;
	memset(u,0,(n+2)*sizeof(bool));
	if(n>0)
		d[1]=p=1;
	if(n>1)
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
	if(u[1])
		p--;
}


void slove()
{
	int i,m,j,pp;
	bool t;
	__int64 w=0,ss,s=0;
	d[p+2]=d[2];
	d[p+1]=d[1];
	for(i=1;i<=p;i++)
	{
		ss=-(a[d[i]].x*a[d[i+1]].y + a[d[i+1]].x*a[d[i+2]].y + a[d[i+2]].x*a[d[i]].y - a[d[i]].y*a[d[i+1]].x - a[d[i+1]].y*a[d[i+2]].x - a[d[i]].x*a[d[i+2]].y);
		t=cha(a[d[i+1]].x-a[d[i]].x,a[d[i+1]].y-a[d[i]].y,a[d[i+2]].x-a[d[i]].x,a[d[i+2]].y-a[d[i]].y);
		m=0;
		for(j=1;j<=qq;j++)
		{
			if(fabs(a3[j].x-a[d[i+1]].x)<esp&&fabs(a3[j].y-a[d[i+1]].y)<esp)
				continue;
			if(cha(a3[j].x-a[d[i]].x,a3[j].y-a[d[i]].y,a[d[i+2]].x-a[d[i]].x,a[d[i+2]].y-a[d[i]].y)==t)
			{
				m++;
				a2[m].x=a3[j].x;
				a2[m].y=a3[j].y;
			}
		}
		pp=0;
		tubao(a2,c,pp,m);
		for(j=2;j<pp;j++)
			ss+=(a2[c[1]].x*a2[c[j]].y + a2[c[j]].x*a2[c[j+1]].y + a2[c[j+1]].x*a2[c[1]].y - a2[c[1]].y*a2[c[j]].x - a2[c[j]].y*a2[c[j+1]].x - a2[c[1]].x*a2[c[j+1]].y);
		if(s<ss)
			s=ss;
	}
	for(i=2;i<p;i++)
		w+=-(a[d[1]].x*a[d[i]].y+a[d[i+1]].x*a[d[1]].y+a[d[i]].x*a[d[i+1]].y-a[d[1]].x*a[d[i+1]].y-a[d[i+1]].x*a[d[i]].y-a[d[i]].x*a[d[1]].y);
	w-=s;
	if(w%2)
		printf("%I64d.50\n",w/2);
	else		
		printf("%I64d.00\n",w/2);
}
		
int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(init())
	{
		tubao(a,d,p,n);
		nn=0;
		for(i=2;i<=n;i++)
			if(!u[i])
			{
				nn++;
				aa[nn].x=a[i].x;
				aa[nn].y=a[i].y;
			}
		tubao(aa,dd,q,nn);
		for(i=1;i<=q;i++)
		{
			a3[i].x=aa[dd[i]].x;
			a3[i].y=aa[dd[i]].y;
		}
		for(i=1;i<=p;i++)
		{
			a3[i+q].x=a[d[i]].x;
			a3[i+q].y=a[d[i]].y;
		}
		qq=q+p;
		sort(a3+1,a3+1+qq,com);
		slove();
	}
	return 0;
}