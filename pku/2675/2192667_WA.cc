#include <iostream>
#include <algorithm>
using namespace std;

struct gao
{
	int n;
	double a,b;
}a[100000];

bool com(gao a,gao b)
{
	return a.b/a.a>b.b/b.a;
}

int n;

int main()
{
	int i,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%lf%lf",&a[i].n,&a[i].a,&a[i].b);
	scanf("%d",&m);
	sort(a,a+n,com);
	printf("%d\n",a[m-1].n);
	return 0;
}
	