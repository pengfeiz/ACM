#include <iostream>
using namespace std;

#define MAX 2000

#define MAX2 45

int a[MAX2][MAX],b[MAX],in[MAX2],n,m,t,e[MAX2][MAX2],dd[MAX];
bool d[MAX];

struct gao
{
	int x,y;
}ff[MAX];

void dfs(int x)
{
	int i;
	d[x]=true;
	for(i=1;i<MAX2;i++)
		if(e[x][i]&&!d[i])
			dfs(i);
}

void dfs2(int v,int id)
{
	int i;
	for(i=0;i<b[v];i++)
		if(!d[a[v][i]])
		{
			d[a[v][i]]=true;
			dfs2(ff[a[v][i]].x==v?ff[a[v][i]].y:ff[a[v][i]].x,a[v][i]);
		}
	if(id>0)
	{
		if(t)
			printf(" ");
		t++;
		printf("%d",id);
	}
}

int main()
{
	int x,y,num,i,j;
	while(scanf("%d%d",&ff[1].x,&ff[1].y),ff[1].x||ff[1].y)
	{
		x=ff[1].x;
		y=ff[1].y;
		t=n=0;
		m=2;
		scanf("%d",&num);
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(a,0,sizeof(a));
		memset(in,0,sizeof(in));
		memset(b,0,sizeof(b));
		e[x][y]=e[y][x]=true;
		a[x][b[x]++]=num;
		in[x]++;
		a[y][b[y]++]=num;
		in[y]++;
		if(n<x)
			n=x;
		if(n<y)
			n=y;
		while(scanf("%d%d",&ff[m].x,&ff[m].y),ff[m].x||ff[m].y)
		{
			x=ff[m].x;
			y=ff[m].y;
			m++;
			e[x][y]=e[y][x]=true;
			scanf("%d",&num);
			if(n<x)
				n=x;
			if(n<y)
				n=y;
			a[x][b[x]++]=num;
			in[x]++;
			in[y]++;
			a[y][b[y]++]=num;
		}
		for(i=1;i<MAX2;i++)
			if(in[i]%2)
				break;
		for(j=1;j<MAX2;j++)
			if(in[j])
			{
				dfs(j);
				break;
			}
		for(j=1;j<MAX2;j++)
			if(!d[j]&&in[j])
				break;
		if(i<MAX2||j<MAX2)
		{
			printf("Round trip does not exist.\n");
			continue;
		}
		memset(d,0,sizeof(d));
		dfs2(n,0);
		printf("\n");
	}
	return 0;
}






