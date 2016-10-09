#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 2001
struct gao
{
	int x;
	int y;
}a[MAX];
bool com(gao a,gao b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
int main()
{
	int n,t,i,j;
	gao he,ho,p,q;
	int x,y;
	while(scanf("%d",&n),n)
	{
		for(i=t=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,com);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				x=a[i].x-a[j].x;
				y=a[i].y-a[j].y;
				p.x=a[i].x+y;
				p.y=a[i].y-x;
				q.x=a[i].x-y;
				q.y=a[i].y+x;
				if((p.x+a[j].x)&1||(p.y+a[j].y)&1||(q.x+a[j].x)&1||(q.y+a[j].y)&1)
				    continue;
				he.x=(p.x+a[j].x)/2;
				he.y=(p.y+a[j].y)/2;
				ho.x=(q.x+a[j].x)/2;
				ho.y=(q.y+a[j].y)/2;
				if(binary_search(a,a+n,he,com)&&binary_search(a,a+n,ho,com))
						t++;
			}
		printf("%d\n",t/2);
	}
	return 0;
}

