#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	__int64 k,n,i,m;
	double p,q,ans;
	scanf("%d",&k);
	while(k--)
	{
		ans=0;
		scanf("%I64d",&n);
		m=n*1.0;
		for(i=0;i<32;i++)
		{
			p=n/(__int64)pow(2,i*1.0+1)*(__int64)pow(2,i*1.0)+n%(__int64)pow(2,i*1.0);
			q=m-p;
			ans+=pow(2,i*1.0)*(1-(p*p+q*q)/(m*m));
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}

