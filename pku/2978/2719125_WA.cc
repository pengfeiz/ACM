#include <iostream>
using namespace std;

int a[6][6];
int b[101];

int main()
{
	int i,j,n,m,k;
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(a,127,sizeof(a));
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		a[b[0]][b[1]]=2;
		for(i=2;i<n;i++)
		{
			for(j=1;j<=m;j++)
				for(k=1;k<=m;k++)
				{
					if(j!=k&&b[i]==k)
					{
						if(a[k][b[i]]>a[j][k])
							a[k][b[i]]=a[j][k];
						if(a[j][b[i]]>a[j][k])
							a[j][b[i]]=a[j][k];
					}
					else if(a[k][b[i]]>a[j][k]+1)
						a[k][b[i]]=a[j][k]+1;
				}
		}
		k=99999999;
		for(j=1;j<=m;j++)
			for(i=1;i<=m;i++)
				if(a[i][j]<k)
					k=a[i][j];
		printf("%d\n",k);
	}
	return 0;
}


