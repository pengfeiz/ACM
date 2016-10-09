#include <iostream>
using namespace std;

#define MAX 2000

#define MAX2 45

int a[MAX2][MAX],b[MAX],in[MAX2],n,m,t,dd[MAX];
bool d[MAX];

struct gao
{
	int x,y;
}ff[MAX];


void dfs2(int v,int id)
{
	int i;
	for(i=0;i<b[v];i++)
		if(!d[a[v][i]])
		{
			d[a[v][i]]=true;
			dfs2(ff[a[v][i]].x==v?ff[a[v][i]].y:ff[a[v][i]].x,a[v][i]);
		}
	if(t)
		printf(" ");
	t++;
	printf("%d",id);
}

int main()
{
	int x,y,num,i;
	while(scanf("%d%d",&ff[1].x,&ff[1].y),ff[1].x||ff[1].y)
	{
		x=ff[1].x;
		y=ff[1].y;
		t=n=0;
		m=2;
		scanf("%d",&num);
		memset(a,0,sizeof(a));
		memset(in,0,sizeof(in));
		memset(b,0,sizeof(b));
		a[x][b[x]++]=num;
		n=n>ff[1].x?n:ff[1].x;
		n=n>ff[1].y?n:ff[1].y;
		in[x]++;
		a[y][b[y]++]=num;
		in[y]++;
		while(scanf("%d%d",&ff[m].x,&ff[m].y),ff[m].x||ff[m].y)
		{
			x=ff[m].x;
			y=ff[m].y;
			scanf("%d",&num);
			a[x][b[x]++]=num;
			a[y][b[y]++]=num;
			in[x]++;
			in[y]++;
			n=n>ff[m].x?n:ff[m].x;
			n=n>ff[m].y?n:ff[m].y;
			m++;
		}
		for(i=1;i<MAX2;i++)
			if(in[i]%2)
				break;
		if(i<MAX2)
		{
			printf("Round trip does not exist.\n");
			continue;
		}
		memset(d,0,sizeof(d));
		d[n]=true;
		dfs2(ff[n].x,n);
		printf("\n");
	}
	return 0;
}






