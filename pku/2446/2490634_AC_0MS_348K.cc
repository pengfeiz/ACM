#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1100

int m,t,n;
struct gao
{
	int x,y;
}he[4]={0,1,1,0,0,-1,-1,0};

vector<int> a[MAX];
int z[MAX],y[MAX];
int nn,mm,k;
bool b[34][34];
bool q[MAX];

bool find(int x)
{
	vector<int>::iterator p;
	if(q[x])
		return false;
	q[x]=true;
	p=a[x].begin();
	while(p!=a[x].end())
	{
		if((!y[*p]||find(y[*p])))
		{
			if(!y[*p])
				t++;
			z[x]=*p;
			y[*p]=x;
			return true;
		}
		p++;
	}
	return false;
}


void solve()
{
	int i;
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
	else if(n==nn*mm&&(nn*mm)%2==0)
	{
		printf("YES\n");
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
				a[(i-1)*mm+j].push_back((x-1)*mm+y);
			}
		}
	solve();
	if(t==n)
		printf("YES\n");
	else
		printf("NO\n");
}


int main()
{
	int i,x,y;
	scanf("%d%d%d",&nn,&mm,&k);
	n=nn*mm-k;
	memset(b,0,sizeof(b));
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&y,&x);
		b[x][y]=true;
	}
	build();
	return 0;
}