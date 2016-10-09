#include <stdio.h>
#include <math.h>
#define MAX 6543
__int64 aa[MAX];

int primeh(__int64 a)
{
	__int64 i;
	for(i=2;i<=sqrt(a*1.0);i++)
		if(a%i==0)
			return 0;
	return 1;
}

__int64 dosth(__int64 a)
{
	if(a==1)
		return 1;
	for(int i=1;aa[i]<=a/2;i++)
		if(a%aa[i]==0)
			return (2*aa[i]-1)*dosth(a/aa[i]);
	return a*2-1;
}

int main()
{
	__int64 n,i;
	aa[0]=1;
	aa[1]=2;
	for(i=3;i<65536;i++)
		if(primeh(i))
			aa[++aa[0]]=i;
	while(scanf("%I64d",&n)!=EOF)
		printf("%I64d\n",dosth(n));
	return 0;
}
