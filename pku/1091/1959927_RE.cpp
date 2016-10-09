#include <iostream>
#include <math.h>
using namespace std;
__int64 a[1229],b[1229];
bool prime(__int64 x)
{
	__int64 i;
	for(i=0;a[i]<=sqrt(double(x));i++)
		if(x%a[i]==0)
			return false;
	return true;
}
int main()
{
	__int64 n,m,i,j,t,k;
	a[0]=2;
	for(i=3,j=1;i<10000;i++)
		if(prime(i))
			a[j++]=i;
	memset(b,0,1229);
	scanf("%I64d%I64d",&n,&m);
	k=m;
	for(i=0;a[i]<=m&&i<1229;i++)
		if(m%a[i]==0)
		{
			b[i]=1;			
			while(k%a[i]==0)
				k/=a[i];
		}
	if(prime(k)==0)
		k=1;
	k=m/k;
	for(i=0;a[i]<=sqrt(k);i++)
	{
		if(b[i]==1)
			k/=a[i];
	}
	t=(__int64)pow(k*1.0,n);
	for(i=0;a[i]<=sqrt(m);i++)
	{
		if(b[i]==1)
			t*=(__int64)pow(a[i]*1.0,n)-1;
	}
	printf("%I64d\n",t);
	return 0;
}


