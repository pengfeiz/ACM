#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10002
#define MAX1 501
struct gao
{int x,y;}a[MAX];
struct gao2
{int n,y;}pp;
struct he
{int n;gao2 a[MAX1];}b[MAX1];
struct hehe
{int a,b,l;}d[MAX*1000];
bool com(gao2 a,gao2 b)
{return a.y<b.y;}
bool com2(hehe a,hehe b)
{return a.l<b.l;}
bool com3(int a,int b)
{return a>=b;}
int n,k,m,ml;
bool c[MAX1];
int e[MAX],ll,dd[MAX1][MAX1];
int getroot(int x)
{
	if(x!=e[x])
		e[x]=getroot(e[x]);
	return e[x];
}
void ready()
{
	int i,y;
	int w[MAX1]={0};
	for(i=0;i<MAX1;i++)
		b[i].a[b[i].n].y=99999;
	for(y=0;y<MAX1;y++)
	{
		for(i=0;i<MAX1;i++)
		{
			if(b[i].a[w[i]].y<y)
				w[i]++;	
			dd[i][y]=w[i];
		}
	}
}
int main()
{
	int i,j,x,y,total;
	scanf("%d%d",&n,&k);
	memset(b,0,sizeof(b));
	m=0;
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=n;i++)
	{
		x=a[i].x;
		y=a[i].y;
		b[x].a[b[x].n].y=y;
		b[x].a[b[x].n].n=i;
		b[x].n++;
	}
	for(i=0;i<MAX1;i++)
		sort(b[i].a,b[i].a+b[i].n,com);
	ready();
	for(i=1;i<=n;i++)
	{
		pp.n=i;
		pp.y=a[i].y;
		x=a[i].x;
		y=dd[x][a[i].y];
		if(y<b[x].n-1)
		{
			d[m].a=i;
			d[m].b=b[x].a[y+1].n;
			d[m].l=b[x].a[y+1].y-b[x].a[y].y;
			c[b[x].a[y+1].y]=true;
			m++;
		}
		memset(c,0,sizeof(c));
		for(j=x+1;j<MAX1;j++)
		{
			if(b[j].n)
			{
				y=dd[j][a[i].y];
				if(y<b[j].n&&!c[b[j].a[y].y])
				{
					c[b[j].a[y].y]=true;
					d[m].a=i;
					d[m].b=b[j].a[y].n;
					d[m].l=j-x+b[j].a[y].y-a[i].y;
					m++;
				}
			}
		}
		memset(c,0,sizeof(c));
		for(j=x-1;j>=0;j--)
		{
			if(b[j].n)
			{
				y=dd[j][a[i].y];
				if(y<b[j].n&&!c[b[j].a[y].y])
				{
					c[b[j].a[y].y]=true;
					d[m].a=i;
					d[m].b=b[j].a[y].n;
					d[m].l=x-j+b[j].a[y].y-a[i].y;
					m++;
				}
			}
		}
	}
	total=n;
	sort(d,d+m,com2);
	for(i=1;i<=n;i++)
		e[i]=i;
	ml=0;
	for(i=0;i<m;i++)
	{
		x=d[i].a;
		y=d[i].b;
		x=getroot(x);
		y=getroot(y);
		if(x==y)
			continue;
		e[x]=y;
		total--;
		ll=d[i].l;
		if(total==k)
			break;
	}
	printf("%d\n",ll);
	return 0;
}
