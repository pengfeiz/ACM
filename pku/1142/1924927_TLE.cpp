#include <iostream>
#include <math.h>
using namespace std;
int prime(long n)
{
	long i;
	for(i=2;i<=sqrt((double)n);i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	long n,num[100],i,j,m,tm,tn,t,nu[1335];
	for(i=2,j=0;i<11000;i++)
		if(prime(i)==1)
			nu[j++]=i;
	while(cin>>m&&m)
	{
		m++;
		t=0;
		while(t==0)
		{
			while(prime(m)==1)
				m++;
			n=m;
			i=j=0;
			while(prime(n)==0)
			{
				if(n%nu[i]==0)
				{
					num[j]=nu[i];
					j++;
					n/=nu[i];
				}
				else if(nu[i]>sqrt(double(n)))
					break;
				else
					i++;
			}
			num[j]=n;
			n=m;
			tm=tn=0;
			for(i=0;i<10;i++)
			{
				tm+=n%10;
				n/=10;
			}
			for(i=0;i<=j;i++)
			{
				for(n=0;n<10;n++)
				{
					tn+=num[i]%10;
					num[i]/=10;
				}
			}
			if(tm==tn)
				t=1;
			else
				m++;
		}
		cout<<m<<endl;
	}
	return 0;
}

