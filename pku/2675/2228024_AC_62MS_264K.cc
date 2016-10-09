#include <iostream>
#include <algorithm>
using namespace std;

struct gao
{
	int n;
	double a,b;
}a[1000000];

bool com(gao a,gao b)
{
	return a.a*b.b<b.a*a.b;
}

int n;

int main()
{
	int i,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d%lf%lf",&a[i].n,&a[i].a,&a[i].b);
		sort(a,a+n,com);
		scanf("%d",&m);
		printf("%d\n",a[m-1].n);
	}
	return 0;
}
