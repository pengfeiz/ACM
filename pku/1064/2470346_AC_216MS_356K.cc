#include <iostream>
using namespace std;
#define MAX 10001

__int64 n;
__int64 a[MAX],k;

bool judge(__int64 mid)
{
	__int64 t=0,i;
	for(i=0;i<n;i++)
	{
		t+=a[i]/mid;
		if(t>=k)
			return true;
	}
	return false;
}


int main()
{
	__int64 i,aa,b,mid;
	double l;
	scanf("%I64d%I64d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&l);
		l*=100;
		l+=0.01;
		a[i]=(__int64)(l);
	}
	aa=1;
	b=(__int64)100000000000000.0;
	while(b>aa)
	{
		mid=(aa+b)/2;
		if(judge(mid))
			aa=mid+1;
		else
			b=mid;
	}
	printf("%.2lf\n",(b-1)/100.0);
	return 0;
}
