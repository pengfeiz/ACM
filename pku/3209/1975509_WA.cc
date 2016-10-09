#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	__int64 n,p,q,i;
	int nn;
	cin>>nn;
	while(nn-->0)
	{
		scanf("%I64d",&n);
		if(n<0)
		{
			printf("NO\n");
			continue;
		}
		p=(__int64)sqrt(n*1.0);
		q=(__int64)sqrt(n*0.5);
		for(i;q<=p&&i<100000;i++,q++,p--)
		{
			if(pow((__int64)sqrt(n*1.0-p*p*1.0),2)+p*p==n)
				break;
			if(pow((__int64)sqrt(n*1.0-q*q*1.0),2)+q*q==n)
				break;
		}
		if(q<=p&&i<100000)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

			