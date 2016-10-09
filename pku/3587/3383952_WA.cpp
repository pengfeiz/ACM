#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;



struct poi
{
	int x,y;
}a[666];
int dist[666][666];
double distt[666][666];
int n;


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
	double l,l2;
	l=(dist[x][y]+dist[x][z]-dist[y][z]);
	l=4-l*l/(dist[x][y]*1.0*dist[x][z]);
	l=l/4.0;
	return dist[y][z]/l;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int t,i,j,k;
	double r,maxx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				dist[i][j]=dis(a[i],a[j]);
				distt[i][j]=sqrt(dist[i][j]*1.0);
			}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=j+1;k<n;k++)
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
