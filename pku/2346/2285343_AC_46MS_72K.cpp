#include <iostream>
#include <math.h>
using namespace std;
__int64 a[46];

__int64 judge(__int64 x)
{
	__int64 i,a=0;
	for(i=0;i<5;i++)
	{
		a+=x%10;
		x/=10;
	}
	return a;
}

int main()
{
	__int64 n,m,i;
	scanf("%I64d",&n);
	if(!n)
	{
		printf("0\n");
		return 0;
	}
	memset(a,0,sizeof(a));
	m=(__int64)pow(10,n/2);
	for(i=0;i<m;i++)
		a[judge(i)]++;
	m=0;
	for(i=0;i<46;i++)
		m+=a[i]*a[i];
	printf("%I64d\n",m);
	return 0;
}