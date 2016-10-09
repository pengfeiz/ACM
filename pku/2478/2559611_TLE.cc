#include <iostream>
using namespace std;


int main()
{
    __int64 n,i,t,sum,j,nn;
    while(scanf("%I64d",&n),n)
	{
		t=0;
		for(j=2;j<=n;j++)
		{
			sum=nn=j;
			for(i=2;i*i<=nn;i++)
			{
				if(nn%i==0)
					sum-=sum/i;
				while(nn%i==0)
					nn/=i;
			}
			if(nn>1)
				sum-=sum/nn;
			t+=sum;
		}
		printf("%I64d\n",t);
	}
	return 0;
}

