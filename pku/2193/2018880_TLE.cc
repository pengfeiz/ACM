#include <iostream>
#include <math.h>
using namespace std;
__int64 m,t;
__int64 dosth(__int64 n,__int64 x)
{
	__int64 i,p=0;
	if(x==1)
		return m-2*n+1;
	for(i=2*n;;i++)
	{
		if(i*pow(2,x-1)<=m)
			p+=dosth(i,x-1);
		else
			break;
	}
	return p;
}
int main()
{
	__int64 n,l,i,k=0;
	scanf("%I64d",&l);
	while(l-->0)
	{
		t=0;
		k++;
		scanf("%I64d%I64d",&n,&m);
		if(n==1)
			t=m;
		else
		{
			for(i=1;;i++)
			{
				if(i*pow(2,n-1)<=m)
					t+=dosth(i,n-1);
				else
					break;
			}
		}
		printf("Case %I64d: n = %I64d, m = %I64d, # lists = %I64d\n",k,n,m,t);
	}
	return 0;
}
		