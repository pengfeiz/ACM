#include <iostream>
using namespace std;

#define MAX 201

struct gao
{
	int c,f;
}a[MAX][MAX];

int n,m,t;
int cc[8];
bool q[MAX];

int min(int a,int b)
{return a<b?a:b;}

int find(int x,int d)
{
	if(q[x]||!d)
		return 0;
	if(x==n)
		return d;
	q[x]=true;
	int i,h;
	for(i=0;i<=n;i++)
	{		
		if(a[x][i].c&&(h=find(i,min(d,a[x][i].c-a[x][i].f))))
		{
			a[x][i].f+=h;
			return h;
		}
		if(a[i][x].c&&(h=find(i,min(d,a[i][x].f))))
		{
			a[i][x].f-=h;
			return h;
		}
	}
	return 0;
}

void maxflow()
{
	do
	{
		memset(q,0,sizeof(q));
	}while(find(0,0x7fffffff));
}

int main()
{
	int i,tt,j,l,k;
	scanf("%d",&tt);
	while(tt--)
	{
		memset(a,0,sizeof(a));
		t=0;
		scanf("%d",&m);
		n=7+m+1;
		for(i=1;i<=m;i++)
		{
			memset(cc,0,sizeof(cc));
			for(j=1;j<=7;j++)
				scanf("%d",&cc[j]);
			scanf("%d%d",&l,&k);
			t+=l;
			for(j=1;j<=7;j++)
				if(cc[j])
					a[j][7+i].c=k;
			a[i+7][n].c=l;
			for(j=1;j<=7;j++)
				if(a[0][j].c<k)
					a[0][j].c=k;
		}
		maxflow();
		k=0;
		for(i=0;i<n;i++)
			k+=a[0][i].f;
		if(k==t)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}	
