#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1025

int m,t,n;
struct gao
{
	int x,y;
}he[4]={0,1,1,0,0,-1,-1,0};

int z[MAX],y[MAX];
int nn,mm,k;
bool b[34][34];
bool a[MAX][MAX],q[MAX];

bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=m;i++)
		if(a[x][i]&&(!y[i]||find(y[i])))
		{
			if(!y[i])
				t++;
			z[x]=i;
			y[i]=x;
			return true;
		}
	return false;
}


void solve()
{
	int i;
	t=0;
	memset(y,0,sizeof(y));
	memset(z,0,sizeof(z));
	for(i=1;i<=m;i++)
	{
		memset(q,0,sizeof(q));
		find(i);
	}
}


void build()
{
	int i,j,x,y,k;
	if(n%2)
	{
		printf("NO\n");
		return;
	}
	memset(a,0,sizeof(a));
	m=mm*nn;
	for(i=1;i<=nn;i++)
		for(j=1;j<=mm;j++)
		{
			if(b[i][j])
				continue;
			for(k=0;k<4;k++)
			{
				x=i+he[k].x;
				y=j+he[k].y;
				if(x<=0||y<=0||x>nn||y>mm)
					continue;
				if(b[x][y])
					continue;
				a[(i-1)*mm+j][(x-1)*mm+y]=true;
			}
		}
	solve();
	if(t==n)
		printf("YES\n");
}


int main()
{
	int i,x,y;
	scanf("%d%d%d",&nn,&mm,&k);
	n=nn*mm-k;
	memset(b,0,sizeof(b));
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&x,&y);
		b[x][y]=true;
	}
	build();
	return 0;
}