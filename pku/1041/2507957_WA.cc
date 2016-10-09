#include <iostream>
using namespace std;

#define MAX 2000

#define MAX2 45

int a[MAX2][MAX],b[MAX],in[MAX2],n,t,e[MAX2][MAX2];
bool c[MAX][MAX],d[MAX];

void dfs(int x)
{
	int i;
	d[x]=true;
	for(i=1;i<MAX2;i++)
		if(e[x][i]&&!d[i])
			dfs(i);
}

int main()
{
	int x,y,num,i,j,k,m;
	while(scanf("%d%d",&x,&y),x||y)
	{
		m=1;
		scanf("%d",&num);
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(a,0,sizeof(a));
		memset(in,0,sizeof(in));
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		e[x][y]=e[y][x]=true;
		a[x][b[x]++]=num;
		in[x]++;
		a[y][b[y]++]=num;
		n=num;
		in[y]++;
		while(scanf("%d%d",&x,&y),x||y)
		{
			m++;
			e[x][y]=e[y][x]=true;
			scanf("%d",&num);
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
			for(j=0;j<b[i];j++)
				for(k=j+1;k<b[i];k++)
					c[a[i][j]][a[i][k]]=c[a[i][k]][a[i][j]]=true;
		t=1;
		printf("%d",n);
		d[1]=true;
		i=n;
		while(t<m)
		{
			t++;
			for(j=1;j<=n;j++)
				if(c[i][j]&&!d[j])
					break;
			d[j]=true;
			i=j;
			printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}