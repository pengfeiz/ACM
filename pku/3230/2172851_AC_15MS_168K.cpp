#include <iostream>
using namespace std;

#define MAX 100

int a[MAX][MAX],b[MAX][MAX],d[MAX][MAX],n,m;

int main()
{
	int i,j,k,t;
	while(scanf("%d%d",&n,&m),n||m)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&b[i][j]);
		for(i=0;i<m;i++)
			d[0][i]=b[0][i]-a[0][i];
		for(i=1;i<m;i++)
			for(j=0;j<n;j++)
			{
				t=-999999;
				for(k=0;k<n;k++)
					if(t<d[i-1][k]+b[i][j]-a[k][j])
						t=d[i-1][k]+b[i][j]-a[k][j];
				d[i][j]=t;
			}
		t=-999999;
		for(i=0;i<n;i++)
			if(d[m-1][i]>t)
				t=d[m-1][i];
		printf("%d\n",t);
	}
	return 0;
}



