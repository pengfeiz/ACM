#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000
#define MAX2 20
double a[MAX];
double b[MAX2];
double c[MAX2],ma;
int n,m,t;

int main()
{
	int i,j;
	while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		for(i=0;i<n;i++)
			scanf("%lf",&b[i]);
		for(j=0;j<m;j++)
			scanf("%lf",&c[j]);
		t=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				a[t++]=b[i]/c[j];
		sort(a,a+t);
		ma=0;
		for(i=1;i<t;i++)
			if(ma<a[i]/a[i-1])
				ma=a[i]/a[i-1];
		printf("%.2lf\n",ma);
	}
	return 0;
}