#include <iostream>
using namespace std;

const int maxn=301;

int a[maxn][maxn];

int b[maxn],m,n;

int main()
{
	int i,j,k,maxx;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=999999;
	while(m--)
	{
		scanf("%d",&k);
		for(i=0;i<k;i++)
			scanf("%d",&b[i]);
		for(i=0;i<k;i++)
			for(j=i+1;j<k;j++)
				a[b[i]][b[j]]=a[b[j]][b[i]]=1;
	}
	for(i=1;i<=n;i++)
		a[i][i]=0;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(a[i][j]>a[i][k]+a[k][j])
					a[i][j]=a[i][k]+a[j][k];
	maxx=99999999;
	for(i=1;i<=n;i++)
	{
		k=0;
		for(j=1;j<=n;j++)
			k+=a[i][j];
		if(k<maxx)
			maxx=k;
	}
	printf("%d\n",maxx*100/(n-1));
	return 0;
}