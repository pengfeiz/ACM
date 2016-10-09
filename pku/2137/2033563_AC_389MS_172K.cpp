#include <iostream>
#include <math.h>
using namespace std;
#define MAX1 101
#define MAX2 41
struct gao
{
	double x,y;
}a[MAX1][MAX2],q[MAX2];
double c[MAX2],d[MAX2];
int b[MAX1];
int main()
{
	int n,i,j,k,f,y;
	double min,ss;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		for(j=0;j<b[i];j++)
			scanf("%lf%lf",&a[i][j].x,&a[i][j].y);
	}
	memcpy(q,a[0],sizeof(a[0]));
	y=b[0];
	b[0]=1;
	ss=999999;
	for(f=0;f<y;f++)
	{
		memset(c,0,sizeof(c));
		a[0][0].x=q[f].x;
		a[0][0].y=q[f].y;
		for(i=1;i<=n;i++)
		{
			memset(d,0,sizeof(d));
			for(j=0;j<b[i%n];j++)
			{
				min=999999;
				for(k=0;k<b[i-1];k++)
					if(c[k]+sqrt(pow(a[i%n][j].x-a[i-1][k].x,2)+pow(a[i%n][j].y-a[i-1][k].y,2))<min)
						min=c[k]+sqrt(pow(a[i%n][j].x-a[i-1][k].x,2)+pow(a[i%n][j].y-a[i-1][k].y,2));
				d[j]=min;
			}
			memcpy(c,d,sizeof(d));
		}
		if(ss>c[0])
			ss=c[0];
	}
	ss=floor(ss*100);
	printf("%.0lf\n",ss);
	return 0;
}


					
