#include <iostream>
using namespace std;

#define MAX 2000

#define MAX2 45

int a[MAX2][MAX],b[MAX],in[MAX2],m,t;
bool d[MAX];

struct gao
{
	int x,y;
}ff[MAX];


void dfs(int v,int id)
{
	int i;
	for(i=0;i<b[v];i++)
		if(!d[a[v][i]])
		{
			d[a[v][i]]=true;
			dfs(ff[a[v][i]].x==v?ff[a[v][i]].y:ff[a[v][i]].x,a[v][i]);
		}
	if(t)
		printf(" ");
	t++;
	printf("%d",id);
}

int main()
{
	int x,y,num,i;
	while(scanf("%d%d",&x,&y),x||y)
	{
		t=0;
		m=2;
		scanf("%d",&num);
		memset(a,0,sizeof(a));
		memset(in,0,sizeof(in));
		memset(b,0,sizeof(b));
		a[x][b[x]++]=num;
		a[y][b[y]++]=num;
		ff[num].x=x;
		ff[num].y=y;
		in[x]++;
		in[y]++;
		while(scanf("%d%d",&x,&y),x||y)
		{
			scanf("%d",&num);
			a[x][b[x]++]=num;
			a[y][b[y]++]=num;
			ff[num].x=x;
			ff[num].y=y;
			in[x]++;
			in[y]++;
			m++;
		}
		for(i=1;i<MAX2;i++)
			if(in[i]&1)
				break;
		if(i<MAX2)
		{
			printf("Round trip does not exist.\n");
			continue;
		}
		memset(d,0,sizeof(d));
		d[1]=true;
		dfs(ff[1].y,1);
		printf("\n");
	}
	return 0;
}