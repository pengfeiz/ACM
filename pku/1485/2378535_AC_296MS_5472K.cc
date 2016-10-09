#include <iostream>
#include <algorithm>
using namespace std;
#define MAX1 202
#define MAX2 32

int n,m;
int a[MAX1],tim=0;
int d[MAX1][MAX1][MAX2];
int e[MAX1][MAX1];
int t[MAX1][MAX1];

void dosth(int n,int i)
{
	if(i==1)
	{
		printf("Depot %d at restaurant %d serves ",i,e[1][n]);
		if(i==n)
			printf("restaurant %d\n",1);
		else
			printf("restaurants %d to %d\n",1,n);
		return;
	}
	int k;
	for(k=i-1;k<n;k++)
		if(d[1][n][i]==d[1][k][i-1]+d[k+1][n][1])
		{
			dosth(k,i-1);
			printf("Depot %d at restaurant %d serves ",i,e[k+1][n]);
			if(k+1==n)
				printf("restaurant %d\n",n);
			else
				printf("restaurants %d to %d\n",k+1,n);
			return;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,k,tt;
	while(scanf("%d%d",&n,&m),n||m)
	{
		tim++;
		printf("Chain %d\n",tim);
		memset(d,127,sizeof(d));
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				tt=0;
				for(k=i;k<=j;k++)
					tt+=abs(a[i]-a[k]);
				t[i][j]=tt;
				tt=0;
				for(k=i;k<=j;k++)
					tt+=abs(a[j]-a[k]);
				t[j][i]=tt;
			}
		}
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j++)
				for(k=i;k<=j;k++)
					if(d[i][j][1]>t[k][i]+t[k][j])
					{
						d[i][j][1]=t[k][i]+t[k][j];
						e[i][j]=k;
					}
		
		for(i=2;i<=m;i++)
		{
			d[i][i][i]=0;
			for(j=i;j<=n;j++)
				for(k=i-1;k<j;k++)
					if(d[1][j][i]>d[1][k][i-1]+d[k+1][j][1])
						d[1][j][i]=d[1][k][i-1]+d[k+1][j][1];
		}
		dosth(n,m);
		printf("Total distance sum = %d\n\n",d[1][n][m]);
	}
	return 0;
}
