#include <iostream>
using namespace std;
#define MAX 1050
int a[MAX][MAX],b[MAX][MAX];
int c[MAX][MAX]={0};
int main()
{
	int n,p,m,i,j,k;
	scanf("%d%d%d",&n,&p,&m);
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<p;i++)
		for(j=0;j<m;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(k=0;k<p;k+=10)
				c[i][j]+=(a[i][k]*b[k][j]+a[i][k+1]*b[k+1][j]+a[i][k+2]*b[k+2][j]+a[i][k+3]*b[k+3][j]+a[i][k+4]*b[k+4][j]+a[i][k+5]*b[k+5][j]+a[i][k+6]*b[k+6][j]+a[i][k+7]*b[k+7][j]+a[i][k+8]*b[k+8][j]+a[i][k+9]*b[k+9][j]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d",&k);
			if(k!=c[i][j])
			{
				printf("No\n%d %d\n%d\n",i+1,j+1,c[i][j]);
				return 0;
			}
		}
	printf("Yes\n");
	return 0;
}
				