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
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		b[i][0]=-9999999;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			b[i][j]=maxx(b[i-1][j-1]+a[i][j],b[i][j-1]);
	printf("%d\n",b[n][m]);
	return 0;
}

