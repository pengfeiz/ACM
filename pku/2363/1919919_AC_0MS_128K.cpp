#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long nn,n,i,j,t;
	cin>>nn;
	while(nn-->0)
	{
		t=9999999;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			if(n%i==0)
			{
				for(j=1;j<=n/i;j++)
				{
					if((n/i)%j==0)
					{
						if(t>2*i*j+2*n/i+2*n/j)
							t=2*i*j+2*n/i+2*n/j;
					}
				}
			}
		}
		cout<<t<<endl;
	}
	return 0;
}