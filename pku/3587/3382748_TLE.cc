
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const double esp=1e-6;



struct poi
{
	int x,y;
}a[666];
int dist[666][666];
int n,p;


/*
cosA = (b^2+c^2-a^2)/(2bc) 
求出sinA 
则，根据正弦定理： 
外接圆半径 = a/(2*sinA) 
*/

inline int dis(poi a,poi b)
{return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
inline double cosquare(int x,int y,int z)
{
	int l1,l2,l3;
	double l;
	l1=dist[x][y];
	l2=dist[x][z];
	l3=dist[y][z];
	l=(l1+l2-l3)/(sqrt(l1*l2*4.0));
	l=sqrt(1-l*l);
	if(fabs(l)<esp)
		return 0;
	return sqrt(l3)/l;
}

int main()
{
	//freopen("in.txt","r",stdin);

	int t,i,j,k;
	double r,maxx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=0;
		for(i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				dist[i][j]=dis(a[i],a[j]);
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				for(k=j+1;k<=n;k++)
				{
					r=cosquare(i,j,k);
					if(r>maxx)
						maxx=r;
				}
			}
		}
		printf("%.3lf\n",maxx/2);
	}
	return 0;
}