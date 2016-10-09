#include <iostream>
using namespace std;
#define MAX 100

int a[MAX];
int b[MAX][MAX];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	n-=1;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			b[i][j]=9999999;
	for(i=0;i<n;i++)
		b[i][i]=0;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
		{
			for(k=j;k<i+j;k++)
				if(b[j][j+i]>b[j][k]+b[k+1][i+j]+a[j]*a[k+1]*a[i+j+1])
					b[j][j+i]=b[j][k]+b[k+1][i+j]+a[j]*a[k+1]*a[i+j+1];
		}
	printf("%d\n",b[0][n-1]);
	return 0;
}