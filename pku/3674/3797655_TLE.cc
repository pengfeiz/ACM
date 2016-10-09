#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct gao
{
	int x,y,n;
}a[301],b[25],c[6];

bool f[301];
bool ff[26];
int maxx;
bool com1(gao a,gao b)
{
	return a.x>b.x;
}
bool com2(gao a,gao b)
{
	return a.y>b.y;
}

void solve(int t)
{
	int i,tt;
	if(t==6)
	{
		tt=c[0].x*10;
		for(i=1;i<6;i++)
			tt+=c[i].x*(c[i-1].y+10);
		if(tt>maxx)
			maxx=tt;
		return;
	}
	for(i=0;i<n;i++)
		if(!ff[i])
		{
			c[t].x=b[i].x;
			c[t].y=b[i].y;
			ff[i]=true;
			solve(t+1);
			ff[i]=false;
		}
}

int main()
{
	int i,j;
	maxx=0;
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].x/=10;
		a[i].n=i;
	}
	memset(ff,0,sizeof(ff));

	if(n<=25&&n>=6)
	{
		for(i=0;i<n;i++)
		{
			b[i].x=a[i].x;
			b[i].y=a[i].y;
			b[i].n=i;
			f[a[i].n]=true;
		}
		solve(0);
	}
	else if(n>25)
	{
		sort(a,a+n,com1);
		for(i=0;i<12;i++)
		{
			b[i].x=a[i].x;
			b[i].y=a[i].y;
			b[i].n=i;
			f[a[i].n]=true;
		}
		sort(a,a+n,com2);
		for(j=0;j<25;j++)
		{
			if(f[a[i].n])
				continue;
			b[i].x=a[i].x;
			b[i].y=a[i].y;
			b[i].n=i;
			i++;
		}
		n=25;
		solve(0);
	}
	printf("%d\n",maxx);
	return 0;
}
