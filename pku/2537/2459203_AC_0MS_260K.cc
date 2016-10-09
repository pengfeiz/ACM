#include <iostream>
#include <math.h>
using namespace std;
#define MAX 101

int main()
{
	double a[MAX][10],tt;
	int i,j,k,n;
	while(scanf("%d%d",&k,&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		tt=0;
		for(i=0;i<=k;i++)
			a[1][i]=100.0;
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			{
				if(j>0)
					a[i][j]+=a[i-1][j-1];
				if(j<k)
					a[i][j]+=a[i-1][j+1];
				a[i][j]+=a[i-1][j];
			}
		}
		for(i=0;i<=k;i++)
			tt+=a[n][i];
		tt/=pow((k+1)*1.0,n*1.0);
		printf("%.5lf\n",tt);
	}
	return 0;
}