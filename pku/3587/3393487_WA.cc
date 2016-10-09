#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const double esp=1e-6;



struct poi
{
	double x,y;
}a[656];
double dist[656][656];
int n;


/*
cosA = (b^2+c^2-a^2)/(2bc) 
求出sinA 
则，根据正弦定理： 
外接圆半径 = a/(2*sinA) 
*/

inline double dis(poi a,poi b)
{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
inline double cosquare(int x,int y,int z)
{
	double l;
	l=(dist[x][y]+dist[x][z]+dist[y][z])/2;
	/*
	if(fabs(l-dist[x][y])<esp||fabs(l-dist[x][z])<esp||fabs(l-dist[y][z])<esp)
		return 0;*/
	return dist[x][y]*dist[x][z]*dist[y][z]/sqrt(l*(l-dist[x][y])*(l-dist[x][z])*(l-dist[y][z]));
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
			scanf("%lf%lf",&a[i].x,&a[i].y);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
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
		printf("%.3lf\n",maxx/4);
	}
	return 0;
}
