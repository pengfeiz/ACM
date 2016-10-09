#include <iostream>
#include <math.h>
using namespace std;
bool prime(__int64 a)
{
	__int64 i;
	for(i=2;i<=sqrt(double(a));i++)
		if(a%i==0)
			return false;
	return true;
}
int main()
{
	__int64 a[1229],n,m,i,j,t;
	for(i=2,j=0;i<10000;i++)
		if(prime(i))
			a[j++]=i;
	scanf("%I64d%I64d",&n,&m);
	t=(__int64)pow(m*1.0,n*1.0);
	for(i=0;a[i]<=sqrt(m);i++)
		if(m%a[i]==0)
		{
			if(a[i]*a[i]!=m)
				t-=(__int64)pow(m/a[i]*1.0,n*1.0)+(__int64)pow(a[i]*1.0,n*1.0);
			else
				t-=(__int64)pow(m/a[i]*1.0,n*1.0);
		}
	printf("%I64d\n",t);
	return 0;
}


