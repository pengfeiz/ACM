#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct poi
{
	double x,y;
}a[656];
double dist[656][656];
int distt[656][656],n;

int main()
{
	int t,i,j,k;
	double r,maxx,x,xx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=0;
		for(i=1;i<=n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
				distt[i][j]=a[i].x*a[j].y-a[j].x*a[i].y;
				dist[i][j]=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
			}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				x=distt[i][j];
				for(k=j+1;k<=n;k++)
				{
					xx=x-distt[i][k]+distt[j][k];
					xx*=xx;
					r=dist[i][k]*dist[j][k]*dist[i][j]/xx;
					if(r>maxx)
						maxx=r;
				}
			}
		}
		printf("%.3lf\n",sqrt(maxx)/2);
	}
	return 0;
}