#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000

struct gao
{
	int a,b;
}a[MAX];

bool com(gao a,gao b)
{
	return a.a>b.a;
}

int main()
{
	int n,i,s,x,y;
	while(scanf("%d",&n),n!=-1)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].a,&a[i].b);
		sort(a,a+n,com);
		s=a[0].a*a[0].b;
		x=a[0].a;
		y=a[0].b;
		for(i=1;i<n;i++)
		{
			if(x<y)
			{
				if(a[i].b>x)
				{
					s+=(a[i].b-x)*a[i].a;
					x=a[i].b;
				}
			}
			else
			{
				if(a[i].b>y)
				{
					s+=(a[i].b-y)*a[i].a;
					y=a[i].b;
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
					
