#include <iostream>
using namespace std;

#define MAX 2000

#define MAX2 45

int a[MAX2][MAX],b[MAX],in[MAX2],n,t,e[MAX2][MAX2];
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
	if(id>=0)
		printf("%d ",id);
}

int main()
{
	int x,y,num,i,j,m,nn;
	while(scanf("%d%d",&ff[0].x,&ff[0].y),ff[0].x||ff[0].y)
	{
		x=ff[0].x;
		y=ff[0].y;
		m=1;
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
		n=nn=num;
		in[y]++;
		while(scanf("%d%d",&ff[m].x,&ff[m].y),ff[m].x||ff[m].y)
		{
			x=ff[m].x;
			y=ff[m].y;
			m++;
			e[x][y]=e[y][x]=true;
			scanf("%d",&num);
			if(num<nn)
				nn=num;
			if(num>n)
				n=num;
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
		for(i=1;i<MAX2;i++)
		{
			if(in[i])
			{
				dfs2(i,-1);
				break;
			}
		}
		printf("\n");
	}
	return 0;
}






