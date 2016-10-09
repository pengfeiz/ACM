
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


/*
cosA = (b^2+c^2-a^2)/(2bc) 
求出sinA 
则，根据正弦定理： 
外接圆半径 = a/(2*sinA) 
*/

inline int dis(poi a,poi b)
{return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
inline double cosquare(poi p1,poi p2,poi p3)
{
	int l1,l2,l3;
	double l;
	l1=dis(p1,p2);
	l2=dis(p2,p3);
	l3=dis(p1,p3);
	l=(l1+l2-l3)/(sqrt(l1*l2*4.0));
	l=sqrt(1-l*l);
	if(fabs(l)<esp)
		return 0;
	return 2*sqrt(l3)/l;
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