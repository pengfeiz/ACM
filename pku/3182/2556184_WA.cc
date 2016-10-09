#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxn=10201;

struct gao
{
	int x,y;
}a[maxn],aa[maxn],z[4]={0,1,1,0,0,-1,-1,0};


int d[maxn],n,m1,m2,p;
bool u[maxn];
char s[56];


bool com(gao a,gao b)
{return a.y!=b.y?a.y<b.y:a.x<b.x;}
bool cha(int x1,int y1,int x2,int y2)
{return x1*y2-x2*y1>0;}


void tubao()
{
	int i;
	memset(u,0,sizeof(u));
	u[1]=true;
	p=1;
	d[0]=0;
	d[1]=1;
	for(i=2;i<n;i++)
	{
		while(p&&cha(a[d[p]].x-a[d[p-1]].x,a[d[p]].y-a[d[p-1]].y,a[i].x-a[d[p]].x,a[i].y-a[d[p]].y))
			u[d[p--]]=false;
		d[++p]=i;
		u[i]=true;
	}
	for(i=n-1;i>=0;i--)
	{
		if(!u[i])
		{
			while(cha(a[d[p]].x-a[d[p-1]].x,a[d[p]].y-a[d[p-1]].y,a[i].x-a[d[p]].x,a[i].y-a[d[p]].y))
				u[d[p--]]=false;
			d[++p]=i;
			u[i]=true;
		}
	}
}


int maxx(int a,int b)
{return a>b?a:b;}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,l,x,y,nn,xx,yy;
	scanf("%d%d",&m1,&m2);
	for(i=1;i<=m1;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=m2;j++)
		{
			if(s[j]=='X')
			{
				aa[n].x=i;
				aa[n].y=j;
				n++;
			}
			else if(s[j]=='*')
			{
				x=i;
				y=j;
			}
		}
	}
	nn=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<4;i++)
		{
			xx=aa[j].x+z[i].x;
            yy=aa[j].y+z[i].y;
			if(xx<0||xx>m1+1||yy<0||yy>m2+1)
				continue;
			a[nn].x=xx;
			a[nn++].y=yy;
        }
	}
	a[nn].x=x;
	a[nn].y=y;
	nn++;
	a[nn].x=a[nn].y=-1;
	n=0;
	sort(a,a+nn,com);
	for(i=0;i<nn;i++)
		if(a[i].x!=a[i+1].x||a[i].y!=a[i+1].y)
		{
			a[n].x=a[i].x;
			a[n++].y=a[i].y;
		}
	tubao();
	l=0;
	d[p]=d[0];
	for(i=0;i<p;i++)
		l+=maxx(abs(a[d[i]].x-a[d[i+1]].x),abs(a[d[i]].y-a[d[i+1]].y));
	xx=999999;
	for(i=0;i<p;i++)
		if(xx>maxx(abs(x-a[d[i]].x),abs(y-a[d[i]].y)))
			xx=maxx(abs(x-a[d[i]].x),abs(y-a[d[i]].y));
	printf("%d\n",l+2*xx);
	return 0;
}
