#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10001

__int64 a[MAX],n;

int main()
{
	__int64 i,t=0,p,tt;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	sort(a,a+n);
	for(i=1;i<n;i++)
		t+=a[i]-a[0];
	tt=t;
	for(i=1;i<n;i++)
	{
		p=tt+(a[i]-a[i-1])*i;
		p-=(a[i]-a[i-1])*(n-i);
		t+=p;
		tt=p;
	}
	printf("%I64d\n",t);
	return 0;
}

