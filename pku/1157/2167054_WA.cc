#include <iostream>
using namespace std;
#define MAX 101

int a[MAX][MAX],b[MAX][MAX];

int maxx(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int n,m,i,j,k,ma;
	scanf("%d%d",&n,&m);
	ma=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(k=0;k<j;k++)
				b[i][j]=maxx(b[i][j],b[i-1][k]+a[i][j]);
			if(ma<b[i][j])
				ma=b[i][j];
		}
	}
	printf("%d\n",ma);
	return 0;
}

