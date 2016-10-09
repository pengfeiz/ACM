#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;



struct poi
{
	int x,y;
}a[656];
struct poii 
{
	double x,y;
};
int dist[656][656];
int distx[656][656];
int disty[656][656];
int n;


/*
cosA = (b^2+c^2-a^2)/(2bc) 
求出sinA 
则，根据正弦定理： 
外接圆半径 = a/(2*sinA) 
*/

inline double dis(poi a,poii b)
{return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
inline bool cocircle(int x,int y,int z,double &r)
{
	poii q;
	int d=2*(distx[y][x]*(disty[z][y])-disty[y][x]*(distx[z][y]));
	if(!d)
		return false;
	q.x=disty[z][x]*(dist[y][x]*1.0)-disty[y][x]*1.0*dist[z][x];
	q.y=distx[y][x]*(dist[z][x]*1.0)-distx[z][x]*1.0*dist[y][x];
	q.x/=d;
	q.y/=d;
	r=dis(a[x],q);
	return true;
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
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				distx[i][j]=a[i].x-a[j].x;
				disty[i][j]=a[i].y-a[j].y;
				dist[i][j]=a[i].x*a[i].x+a[i].y*a[i].y-a[j].x*a[j].x-a[j].y*a[j].y;
			}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					if(cocircle(i,j,k,r))
						if(r>maxx)
							maxx=r;
				}
			}
		}
		printf("%.3lf\n",sqrt(maxx));
	}
	return 0;
}