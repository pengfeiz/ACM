#include <iostream>
#include <math.h>
using namespace std;
#define MAX 101
int main()
{
	double a[MAX][MAX][2],tt,max,judge;
	int nn,n,i,j,k,p;
	cin>>nn;
	while(nn-->0)
	{
		tt=max=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i][0][0]);
			for(j=1;j<=a[i][0][0];j++)
				scanf("%lf%lf",&a[i][j][0],&a[i][j][1]);
		}
		for(i=0;i<n;i++)
			for(j=1;j<a[i][0][0];j++)
				for(k=j+1;k<=a[i][0][0];k++)
					if(a[i][j][1]>a[i][k][1])
					{
						swap(a[i][j][1],a[i][k][1]);
						swap(a[i][j][0],a[i][k][0]);
					}
		for(i=max=0;i<n;i++)
		{
			for(j=1;j<=a[i][0][0];j++)
			{
				tt=a[i][j][1];
				for(k=0;k<n;k++)
				{
					if(i==k)
						continue;
					for(p=1;p<=a[k][0][0];p++)
					{
						if(a[k][p][0]>=a[i][j][0])
						{
							judge=a[k][p][1];
							break;
						}
					}
					if(p<=a[k][0][0])
						tt+=judge;
					else break;
				}
				if(k==n&&max<a[i][j][0]/tt)
					max=a[i][j][0]/tt;
			}
		}
		printf("%.3lf\n",max);
	}
	return 0;
}




