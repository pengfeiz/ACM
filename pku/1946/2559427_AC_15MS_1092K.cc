#include <iostream>
using namespace std;

const int maxn=21;
const int maxm=101;
int a[maxn][maxm][maxm];
int b[maxm];

int n,e,l;

int main()
{
	int i,j,k,x;
	scanf("%d%d%d",&n,&e,&l);
	memset(a,127,sizeof(a));
	memset(b,127,sizeof(b));
	b[0]=0;
	for(j=0;j<=e;j++)
		a[0][j][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=e;j++)
			for(k=0;k<=l;k++)
			{
				if(a[i][j][k]>b[k]&&j>=k)
					a[i][j][k]=b[k];
				for(x=1;x*x<=j&&x<=k;x++)
				{
					if(a[i][j][k]>a[i][j-x*x][k-x]+1)
						a[i][j][k]=a[i][j-x*x][k-x]+1;
				}
			}
		memset(b,127,sizeof(b));
		for(j=0;j<=e;j++)
			for(k=0;k<=l;k++)
				if(a[i][j][k]<b[k])
					b[k]=a[i][j][k];
	}
	if(b[l]<9999999)
		printf("%d\n",b[l]);
	else
		printf("0\n");
	return 0;
}