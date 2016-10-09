#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXX 200

bool b[MAXX];

struct gao
{
	double x,y;
}a[MAXX];

int n,tim;

void build()
{
	int i;
	for(i=0;i<n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
}


double ll(double x)
{return x*x;}


void dosth()
{
	int i,j,t;
	double s,minn,l;
	memset(b,0,sizeof(b));
	b[0]=true;
	minn=0;
	while(!b[1])
	{
		s=99999999;
		for(i=0;i<n;i++)
		{
			if(b[i])
			{
				for(j=0;j<n;j++)
				{
					if(!b[j])
					{
						l=sqrt(ll(a[i].x-a[j].x)+ll(a[i].y-a[j].y));
						if(l<s)
						{
							s=l;
							t=j;
						}
					}
				}
			}
		}
		b[t]=true;
		if(s>minn)
			minn=s;
	}
	printf("Scenario #%d\nFrog Distance = %.3lf\n",tim,minn);
}

int main()
{
	tim=0;
	while(scanf("%d",&n),n)
	{
		tim++;
		build();
		dosth();
		printf("\n");
	}
	return 0;
}
