#include <iostream>
#include <math.h>
using namespace std;
#define MAX 6543
__int64 aa[MAX];

bool prime(__int64 a)
{
	__int64 i;
	for(i=2;i<=sqrt(a*1.0);i++)
		if(a%i==0)
			return false;
	return true;
}

__int64 dosth(int t,int k)
{
	int i,q;
	if(t==1)
		return 2*k-1;
	q=1;
	for(i=1;i<t;i++)
		q*=k;
	return k*dosth(t-1,k)+(k-1)*q;
}
int main()
{
	__int64 n,i,p,t;
	aa[0]=1;
	aa[1]=2;
	for(i=3;i<65536;i++)
		if(prime(i))
			aa[++aa[0]]=i;
	while(scanf("%I64d",&n)!=EOF)
	{
		p=1;
		for(i=1;aa[i]<=sqrt(n*1.0)&&i<6543;i++)
		{
			if(n%aa[i]==0)
			{
				t=0;
				while(!(n%aa[i]))
				{
					t++;
					n/=aa[i];
				}
				p*=dosth(t,aa[i]);
			}
		}
		p*=(2*n-1);
		printf("%I64d\n",p);
	}
	return 0;
}
