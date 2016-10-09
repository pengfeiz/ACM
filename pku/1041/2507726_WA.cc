#include <iostream>
using namespace std;

#define MAX 2000

#define MAX2 45

int a[MAX2][MAX],b[MAX],in[MAX2],n;
bool c[MAX][MAX],d[MAX];

int main()
{
	int x,y,num,i,j,k,t;
	while(scanf("%d%d",&x,&y),x||y)
	{
		n=0;
		scanf("%d",&num);
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(in,0,sizeof(in));
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		a[x][b[x]++]=num;
		in[x]++;
		a[y][b[y]++]=num;
		in[y]++;
		while(scanf("%d%d",&x,&y),x||y)
		{
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
		if(i<MAX2)
		{
			printf("Round trip does not exist.\n");
			continue;
		}
		for(i=1;i<MAX2;i++)
			for(j=0;j<b[i];j++)
				for(k=j+1;k<b[i];k++)
					c[a[i][j]][a[i][k]]=c[a[i][k]][a[i][j]]=true;
		t=1;
		printf("1");
		d[1]=true;
		i=1;
		while(t<n)
		{
			t++;
			for(j=1;j<=n;j++)
				if(c[i][j]&&!d[j])
					break;
				d[i]=true;
			i=j;
			printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}