#include<iostream>
#include <algorithm>

using namespace std;

#define Max 501
int a[Max][Max],b[Max][Max],c[Max][Max],xx[Max],y[Max],z[Max],xy[Max],n;
int main()
{
	int i,j,nn;
//	freopen("Big Matrix.in","r",stdin);
//	freopen("Big Matrix.out","w",stdout);

	int t=1;
	//scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&b[i][j]);

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&c[i][j]);
	
		memset(xy,0,sizeof(xy));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));

		for(i=0;i<n;i++)
			xx[i]=rand()%10+rand()%10+1;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				y[i]+=xx[j]*a[j][i];

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				xy[i]+=y[j]*b[j][i];

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				z[i]+=xx[j]*c[j][i];

		for(i=0;i<n;i++)
		{
			if(xy[i]!=z[i])
			{	
				printf("NO\n");
				break;
			}
		}
		if(i==n)
			printf("YES\n");
	}
	return 0;
}

