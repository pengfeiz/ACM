#include <iostream>
#include <math.h>
using namespace std;
#define MAX 60
#define esp 1e-9

struct gao
{
	double x,y;
}a[MAX];

int n;
double t;

double ll(double x)
{return x*x;}

void dosth(int z,int x,int y,double l1,double l2)
{
	if(z==n-1)
	{
		double l=sqrt(ll(a[z].x-a[x].x)+ll(a[z].y-a[x].y))+sqrt(ll(a[z].x-a[y].x)+ll(a[z].y-a[y].y));
		if(l1+l2+l<t)
			t=l1+l2+l;
		return;
	}
	if(l1+l2-t>-esp)
		return;
	dosth(z+1,z,y,l1+sqrt(ll(a[z].x-a[x].x)+ll(a[z].y-a[x].y)),l2);
	if(fabs(a[z].y-a[z+1].y)>esp)
		dosth(z+1,x,z,l1,l2+sqrt(ll(a[z].x-a[y].x)+ll(a[z].y-a[y].y)));
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		t=99999999.0;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		dosth(1,0,0,0,0);
		printf("%.2lf\n",t);
	}
	return 0;
}
