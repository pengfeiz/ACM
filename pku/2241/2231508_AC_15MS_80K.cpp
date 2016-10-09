#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200

struct gao
{
	double x,y,z;
}a[MAX];

bool com(gao a,gao b)
{
	return a.x<b.x;
}

void give(int k,double x,double y,double z)
{
	a[k].x=x;
	a[k].y=y;
	a[k].z=z;
}

int tim=0,n;

double h[MAX];

int main()
{
	int i,j;
	double x,y,z,height;
	while(scanf("%d",&n),n)
	{
		tim++;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&x,&y,&z);
			give(i*6,x,y,z);
			give(i*6+1,x,z,y);
			give(i*6+2,y,x,z);
			give(i*6+3,y,z,x);
			give(i*6+4,z,x,y);
			give(i*6+5,z,y,x);
		}
		memset(h,0,sizeof(h));
		n*=6;
		sort(a,a+n,com);
		for(i=0;i<n;i++)
		{
			height=0;
			for(j=0;j<i;j++)
				if(h[j]>height&&a[i].x>a[j].x&&a[i].y>a[j].y)
					height=h[j];
			h[i]=height+a[i].z;
		}
		height=0;
		for(i=0;i<n;i++)
			if(h[i]>height)
				height=h[i];
		printf("Case %d: maximum height = %.0lf\n",tim,height);
	}
	return 0;
}


