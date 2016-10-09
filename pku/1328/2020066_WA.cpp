#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX 1000

struct gao
{
	double x,y;
}a[MAX];

bool com(gao a,gao b)
{
	if(a.x<b.x)
		return true;
	else if(a.x==b.x&&a.y<b.y)
		return true;
	return false;
}

int main()
{
	double q,p,r,bb[MAX][2];
	int n,i,k=0,t;
	while(scanf("%d%lf",&n,&r)&&(n||r))
	{
		memset(bb,0,sizeof(bb));
		k++;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		sort(a,a+n,com);
		for(i=0;i<n;i++)
			if(a[i].y>r||a[i].y<0)
				break;
		if(i<n)
		{
			printf("Case %d: ",k);
			printf("-1\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			bb[i][1]=a[i].x+sqrt(r*r-a[i].y*a[i].y);
			bb[i][0]=a[i].x-sqrt(r*r-a[i].y*a[i].y);
		}
		t=1;
		p=bb[0][0];
		q=bb[0][1];
		for(i=1;i<n;i++)
		{
			if(q>bb[i][0])
			{
				if(p<bb[i][0])
					p=bb[i][0];
			}
			if(q<bb[i][0])
			{
				p=bb[i][0];
				q=bb[i][1];
				t++;
			}
		}
		printf("Case %d: %d\n",k,t);
	}
	return 0;
}

