#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const double esp=1e-6;



struct poi
{
	double x,y;
}a[657];
double dist[657][657];
int distt[657][657];
int n;


/*
cosA = (b^2+c^2-a^2)/(2bc) 
求出sinA 
则，根据正弦定理： 
外接圆半径 = a/(2*sinA) 
*/

inline double ll(double x)
{return x*x;}
inline double dis(poi a,poi b)
{return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
inline double solve(int x,int y,int z)
{
	double xx=distt[x][y]+distt[y][z]+distt[z][x];
	return ll(xx);
}
inline double cosquare(int x,int y,int z)
{
	/*
	if(fabs(l-dist[x][y])<esp||fabs(l-dist[x][z])<esp||fabs(l-dist[y][z])<esp)
		return 0;*/
	return dist[x][y]*dist[x][z]*dist[y][z]/solve(x,y,z);
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
				distt[i][j]=a[i].x*a[j].y-a[j].x*a[i].y;
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
		printf("%.3lf\n",sqrt(maxx)/2);
	}
	return 0;
}

