#include <iostream>
#include <math.h>
using namespace std;
#define MAX 6543
int aa[MAX];

int primeh(int a)
{
	int i;
	for(i=2;i<=sqrt(a*1.0);i++)
		if(a%i==0)
			return 0;
	return 1;
}

__int64 dosth(int a)
{
	int i;
	for(i=1;aa[i]<=a/2;i++)
		if(a%aa[i]==0)
			return (__int64)(2*aa[i]-1)*dosth(a/aa[i]);
	return (__int64)a*2-1;
}

int main()
{
	int n,i;
	aa[0]=1;
	aa[1]=2;
	for(i=3;i<65536;i++)
		if(primeh(i))
			aa[++aa[0]]=i;
	while(scanf("%I64d",&n)!=EOF)
		printf("%I64d\n",dosth(n));
	return 0;
}
