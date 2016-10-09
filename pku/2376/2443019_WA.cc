#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 25001

struct gao
{
	int x,y;
}a[MAX];
int n,t;

bool com(gao a,gao b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y>b.y;
}

int main()
{
	int i,y=1,tt=0,yy;
	scanf("%d%d",&n,&t);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y)
			swap(a[i].x,a[i].y);
	}
	sort(a,a+n,com);
	for(i=0;i<n;i++)
	{
		if(y>=t)
			break;
		if(a[i].x>y)
			break;
		tt++;
		yy=y;
		while(a[i].x<=yy&&i<n)
		{
			if(a[i].y>y)
				y=a[i].y;
			i++;
		}
		i--;
	}
	if(y<t)
		printf("-1\n");
	else
		printf("%d\n",tt);
	return 0;
}


