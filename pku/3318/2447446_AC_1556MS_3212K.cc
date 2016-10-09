#include <iostream>
using namespace std;
#define MAX 501

int xx[MAX],yy[MAX],a[MAX][MAX],b[MAX][MAX],c[MAX][MAX],zz[MAX],qq[MAX];
int n;

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int t=15;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
	//		a[i][j]=0;
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
	//		b[i][j]=0;
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&c[i][j]);
	while(t--)
	{
		for(i=1;i<n;i++)
			xx[i]=rand()%10+1;
		memset(yy,0,sizeof(yy));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				yy[i]+=xx[j]*a[j][i];
		memset(qq,0,sizeof(qq));
		memset(zz,0,sizeof(zz));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				qq[i]+=yy[j]*b[j][i];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				zz[i]+=xx[j]*c[j][i];
		for(i=0;i<n;i++)
		{
			if(qq[i]!=zz[i])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}
