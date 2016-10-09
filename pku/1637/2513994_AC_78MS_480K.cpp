#include <iostream>
#include <vector>
using namespace std;
#define MAX 202

struct gao
{
	int c,f;
}a[MAX][MAX];

int in[MAX],way[MAX];
bool f,q[MAX];

int n,m;


int min(int a,int b)
{return a<b?a:b;}

int find(int x,int d)
{
	if(q[x]||!d)
		return 0;
	if(x==n)
		return d;
	q[x]=true;
	int t,i;
	for(i=0;i<=n;i++)
	{
		if(a[x][i].c&&(t=find(i,min(d,a[x][i].c-a[x][i].f))))
		{
			a[x][i].f+=t;
			return t;
		}
		if(a[i][x].c&&(t=find(i,min(d,a[i][x].f))))
		{
			a[i][x].f-=t;
			return t;
		}
	}
	return 0;
}


void maxflow()
{
	do
	{
		memset(q,0,sizeof(q));
	}while(find(0,0xfffffff));
}


int main()
{
//	freopen("in.txt","r",stdin);
	int tt,i,x,y,bb;
	gao p;
	scanf("%d",&tt);
	while(tt--)
	{
		f=true;
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		memset(in,0,sizeof(in));
		memset(way,0,sizeof(way));
		p.c=1;
		p.f=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&bb);
			if(bb==1)
			{
				in[x]++;
				in[y]--;
			}
			else
			{
				a[x][y].c++;
				a[y][x].c++;
				way[x]++;
				way[y]++;
			}
		}
		for(i=1;f&&i<=n;i++)
		{
			if(abs(in[i])>way[i])
				f=false;
			if((abs(in[i])+way[i])&1)
				f=false;
		}
		if(f)
		{
			x=y=0;
			for(i=1;i<=n;i++)
			{
				if(in[i]>0)
				{
					x+=in[i];
					a[0][i].c+=in[i];
				}
				else if(in[i]<0)
					a[i][n+1].c+=-in[i];
			}
			n++;
			maxflow();
			for(i=0;i<=n;i++)
				y+=a[0][i].f;
			if(x!=y)
				f=false;
		}
		if(f)
			printf("possible\n");
		else
			printf("impossible\n");
	}
	return 0;
}