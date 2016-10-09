#include <iostream>
#include <math.h>
using namespace std;
__int64 n,a[6542];
bool prime(__int64 num)
{
	__int64 i;
	for(i=0;a[i]<=sqrt(num);i++)
		if(num%a[i]==0)
			return false;
	return true;
}

int main()
{
	__int64 i,n1,n2,min,max,p1,p2,q1,q2,j;
	n=1;
	a[0]=2;
	for(i=3;i<65536;i++)
		if(prime(i))
			a[n++]=i;
	while(scanf("%I64d%I64d",&n1,&n2)!=EOF)
	{
		p1=q1=p2=q2=0;
		min=999999;
		max=j=0;
		while(n1<2)
			n1++;
		i=n1;
		while(!prime(i)&&i<n2)
			i++;
		j=i;
		for(i=j+1;i<=n2;i++)
		{
			if(prime(i))
			{
				if(i-j<min)
				{
					min=i-j;
					p1=j;
					p2=i;
				}
				if(i-j>max)
				{
					max=i-j;
					q1=j;
					q2=i;
				}
				j=i;
			}
		}
		if(p1)
			printf("%I64d,%I64d are closest, %I64d,%I64d are most distant.\n",p1,p2,q1,q2);
		else
			printf("There are no adjacent primes.\n");
	}
	return 0;
}
