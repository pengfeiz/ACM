#include <iostream>
using namespace std;

int a[6][6];
int aa[6][6];
int b[101];

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,n,m,k;
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(a,127,sizeof(a));
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		a[b[0]][b[1]]=0;
		for(i=2;i<n;i++)
		{
			memset(aa,127,sizeof(aa));
			for(j=1;j<=m;j++)
				for(k=1;k<=m;k++)
				{
					if(j!=k&&b[i]==j)
					{
						if(aa[k][b[i]]>a[j][k]+1)
							aa[k][b[i]]=a[j][k]+1;
						if(aa[j][b[i]]>a[j][k]+1)
							aa[j][b[i]]=a[j][k]+1;
						continue;
					}
					if(aa[k][b[i]]>a[j][k])
						aa[k][b[i]]=a[j][k];
				}
			memcpy(a,aa,sizeof(a));
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


