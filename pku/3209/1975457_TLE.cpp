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
		for(i=p;i>=q;i--)
		{
			if(pow((__int64)sqrt(n*1.0-i*i*1.0),2)+i*i==n)
				break;
		}
		if(i>=q)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

			