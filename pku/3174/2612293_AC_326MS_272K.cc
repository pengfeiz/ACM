#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxn=772;
const double esp=1e-7;

struct gao
{
	int x,y;
}a[maxn];

int n,m;
struct gao2
{
	int b[3];
}q[maxn*maxn];

bool cha(int x1,int y1,int x2,int y2)
{return x1*y2-x2*y1==0;}

int main()
{
	int i,j,k;
	scanf("%d",&n);
	m=0;
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			for(k=j+1;k<n;k++)
				if(cha(a[j].x-a[i].x,a[j].y-a[i].y,a[k].x-a[j].x,a[k].y-a[j].y))
				{
					q[m].b[0]=i+1;
					q[m].b[1]=j+1;
					q[m].b[2]=k+1;
					sort(q[m].b,q[m].b+3);
					m++;
				}
	printf("%d\n",m);
	for(i=0;i<m;i++)
		printf("%d %d %d\n",q[i].b[0],q[i].b[1],q[i].b[2]);
	return 0;
}
