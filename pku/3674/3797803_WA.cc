#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct gao
{
	int x,y,n;
}a[301],b[50];

bool f[301];
int maxx;

bool com1(gao a,gao b)
{
	if(a.x!=b.x)
		return a.x>b.x;
	return a.y>b.y;
}
bool com2(gao a,gao b)
{
	if(a.y!=b.y)
		return a.y>b.y;
	return a.x>b.x;
}

void solve(int t,int v,int num)
{
	int i;
	if(t==6||t==n)
	{
		if(num>maxx)
			maxx=num;
		return;
	}
	for(i=0;i<n;i++)
		if(!f[i])
		{
			f[i]=true;
			solve(t+1,b[i].y+10,num+v*b[i].x);
			f[i]=false;
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

	if(n<=25)
	{
		for(i=0;i<n;i++)
		{
			b[i].x=a[i].x;
			b[i].y=a[i].y;
			b[i].n=i;
		}
		solve(0,10,0);
	}
	else if(n>25)
	{
		sort(a,a+n,com2);
		for(i=0;i<10;i++)
		{
			b[i].x=a[i].x;
			b[i].y=a[i].y;
			b[i].n=i;
			f[a[i].n]=true;
		}
		sort(a,a+n,com1);
		for(j=0;j<25;j++)
		{
			if(f[a[j].n])
				continue;
			b[i].x=a[i].x;
			b[i].y=a[i].y;
			b[i].n=i++;
		}
		n=25;
		memset(f,0,sizeof(f));
		solve(0,10,0);
	}
	printf("%d\n",maxx);
//	getchar();
//	getchar();
	return 0;
}
