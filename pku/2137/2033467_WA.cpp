#include <iostream>
#include <math.h>
using namespace std;
#define MAX1 101
#define MAX2 41
struct gao
{
	double x,y;
}a[MAX1][MAX2];
double c[MAX2],d[MAX2];
int b[MAX1];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,k;
	double min;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		for(j=0;j<b[i];j++)
			scanf("%lf%lf",&a[i][j].x,&a[i][j].y);
	}
	b[n]=b[0];
	memcpy(a[n],a[0],sizeof(a[0]));
	for(i=1;i<=n;i++)
	{
		memset(d,0,sizeof(d));
		for(j=0;j<b[i];j++)
		{
			min=999999;
			for(k=0;k<b[i-1];k++)
				if(c[k]+sqrt(pow(a[i][j].x-a[i-1][k].x,2)+pow(a[i][j].y-a[i-1][k].y,2))<min)
					min=c[k]+sqrt(pow(a[i][j].x-a[i-1][k].x,2)+pow(a[i][j].y-a[i-1][k].y,2));
			d[j]=min;
		}
		memcpy(c,d,sizeof(d));
	}
	min=999999;
	for(i=0;i<b[n];i++)
		if(c[i]<min)
			min=c[i];
	min=floor(min*100);
	printf("%.0lf\n",min);
	return 0;
}


					
