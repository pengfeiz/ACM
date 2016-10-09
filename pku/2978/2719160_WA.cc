#include <iostream>
using namespace std;

int a[6][6];
int aa[6][6];
int b[101];

int main()
{
	int i,j,n,m,k;
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(a,0xff,sizeof(a));
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		a[b[0]][b[1]]=0;
		for(i=2;i<n;i++)
		{
			memset(aa,0xff,sizeof(aa));
			for(j=1;j<=m;j++)
				for(k=1;k<=m;k++)
				{
					if(a[j][k]<0)
						continue;
					if(j!=k&&b[i]==j)
					{
						if(a[k][b[i]]<=a[j][k]+1)
							aa[k][b[i]]=a[j][k]+1;
						if(a[j][b[i]]<=a[j][k]+1)
							aa[j][b[i]]=a[j][k]+1;
					}
					else if(a[k][b[i]]<=a[j][k])
						aa[k][b[i]]=a[j][k];
				}
			memcpy(a,aa,sizeof(a));
		}
		k=99999999;
		for(j=1;j<=m;j++)
			for(i=1;i<=m;i++)
				if(a[i][j]<k&&a[i][j]>=0)
					k=a[i][j];
		printf("%d\n",k);
	}
	return 0;
}


