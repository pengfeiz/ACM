#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	__int64 n,t,i,p;
	int nn;
	cin>>nn;
//	nn=1000;
	while(nn-->0)
	{
		scanf("%I64d",&n);
//		n=nn;printf("%I64d ",n);
		p=0;
		for(i=2;i<=n&&i<500000;i++)
		{
			t=0;
			while(n%i==0)
			{
				n/=i;
				t++;
			}
			if(i%4==3&&t%2==1)
			{
				p=1;
				break;
			}
		}
		if(p||i==500000)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

			