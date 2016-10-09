#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000000

int b[MAX],k,t;

bool prime(int x)
{
	int i;
	for(i=2;i<=sqrt(x*1.0);i++)
		if(!(x%i))
			return false;
	return true;
}

int ouler(int n)
{
	int i,sum;	
	sum=n;
    for(i=0;b[i]*b[i]<=n&&i<k;i++)
	{
        if(n%b[i]==0)
            sum-=sum/b[i];
		while(n%b[i]==0)
			n/=b[i];
	}
	if(n>1)
		sum-=sum/n;
	return sum;
}

int main()
{
	int n,i;
	__int64 t;
	k=0;
	for(i=2;i<=sqrt(MAX);i++)
		if(prime(i))
			b[k++]=i;
	while(scanf("%d",&n),n)
	{
		t=0;
		for(i=2;i<=n;i++)
			t+=ouler(i);
		printf("%I64d\n",t);
	}
	return 0;
}