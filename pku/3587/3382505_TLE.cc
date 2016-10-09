
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const double esp=1e-6;



struct poi
{
	int x,y;
}a[1000];
int n,p;

inline double dis(poi a,poi b)
{
	int x1;
	int x2;
	x1=(a.x-b.x)*(a.x-b.x);
	x2=(a.y-b.y)*(a.y-b.y);
	return x1+x2;
}
inline double cosquare(poi p1,poi p2,poi p3)
{
	double l,l1,l2,l3;
	l1=sqrt(dis(p1,p2)*1.0);
	l2=sqrt(dis(p2,p3)*1.0);
	l3=sqrt(dis(p1,p3)*1.0);
	l=(l1+l2+l3)/2;
	if(fabs(l1-l)<esp||fabs(l2-l)<esp||fabs(l3-l)<esp)
		return 0;
	return l1*l2*l3/sqrt(l*(l-l1)*(l-l2)*(l-l3));
}

int main()
{
//	freopen("in.txt","r",stdin);

	poi p1,p2,p3;
	int t,i,j,k;
	double r,maxx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=0;
		for(i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(i=1;i<=n;i++)
		{
			p1.x=a[i].x;
			p1.y=a[i].y;
			for(j=i+1;j<=n;j++)
			{
				p2.x=a[j].x;
				p2.y=a[j].y;
				for(k=j+1;k<=n;k++)
				{
					p3.x=a[k].x;
					p3.y=a[k].y;
					r=cosquare(p1,p2,p3);
					if(r>maxx)
						maxx=r;
				}
			}
		}
		printf("%.3lf\n",maxx/4);
	}
	return 0;
}