#include <iostream>
using namespace std;
int main()
{
	long n1,n2,max,tt,in,xn,n,i;
	while(cin>>n1>>n2)
	{
		if(n1>n2)
		{
			xn=n1;
			in=n2;
		}
		else
		{
			xn=n2;
			in=n1;
		}
		max=0;
		for(i=in;i<=xn;i++)
		{
			n=i;
			tt=1;
			while(n!=1)
			{
				if(n%2!=0)
					n=3*n+1;
				else
					n/=2;
				tt++;
			}
			if(tt>max)
				max=tt;
		}
		cout<<n1<<" "<<n2<<" "<<max<<endl;
	}
	return 0;
}

