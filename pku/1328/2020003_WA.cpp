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
	double r,b;
	int n,i,k=0,q,j;
	while(scanf("%d%lf",&n,&r)&&(n||r))
	{
		b=1e10;
		k++;
		q=0;
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
			if(pow(b-a[i].x,2)+pow(a[i].y,2)>=0.999999*r*r)
			{
				b=1e10;
				q++;
				for(j=i;j<n;j++)				
					if(a[j].x+sqrt(r*r-pow(a[j].y,2))<b)
						b=a[j].x+sqrt(r*r-pow(a[j].y,2));
			}			
		}
		printf("Case %d: ",k);
		printf("%d\n",q);
	}
	return 0;
}

