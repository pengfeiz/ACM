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
int distx[656][656];
int disty[656][656];
int n;


/*
cosA = (b^2+c^2-a^2)/(2bc) 
求出sinA 
则，根据正弦定理： 
外接圆半径 = a/(2*sinA) 
*/

inline double dis(poi a,poi b)
{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
inline double solve(poi a,poi b,poi c)
{return (a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);}
inline double cosquare(int x,int y,int z)
{
	double l;
	/*
	if(fabs(l-dist[x][y])<esp||fabs(l-dist[x][z])<esp||fabs(l-dist[y][z])<esp)
		return 0;*/
	return dist[x][y]*dist[x][z]*dist[y][z]/solve(a[x],a[y],a[z]);
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
			{
				distx[i][j]=a[i].x-a[j].x;
				disty[i][j]=a[i].y-a[j].y;
				dist[i][j]=dis(a[i],a[j]);
			}
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

