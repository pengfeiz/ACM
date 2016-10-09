#include <iostream>
#include <math.h>
using namespace std;
#define MAX 6543
__int64 aa[MAX];

bool primeh(__int64 a)
{
	__int64 i;
	for(i=2;i<=sqrt(a*1.0);i++)
		if(a%i==0)
			return false;
	return true;
}

int main()
{
	__int64 n,i,p;
	aa[0]=1;
	aa[1]=2;
	for(i=3;i<65536;i++)
		if(primeh(i))
			aa[++aa[0]]=i;
	while(scanf("%I64d",&n)!=EOF)
	{
		p=1;
		for(i=1;aa[i]<=n&&i<6543;i++)
		{
			if(n%aa[i]==0)
			{
				while(n%aa[i]==0)
				{
					n/=aa[i];
					p*=(2*aa[i]-1);
				}
			}
		}
		p*=(2*n-1);
		printf("%I64d\n",p);
	}
	return 0;
}
