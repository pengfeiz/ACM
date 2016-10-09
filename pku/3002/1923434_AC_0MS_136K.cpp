#include <iostream>
#include <math.h>
using namespace std;
int prime(long n)
{
	long i;
	for(i=2;i<=sqrt(double(n));i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	long num[168],n,i,nn,j=0,m,t,s[168];
	double k;
	for(i=2;i<1000;i++)
		if(prime(i)==1)
			num[j++]=i;
	cin>>nn;
	while(nn-->0)
	{
		for(i=0;i<168;i++)
			s[i]=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>m;
			for(j=t=0;j<168;j++)
			{
				if(m%num[j]==0)
				{
					t++;
					m/=num[j];
					j--;
				}
				else
				{
					if(t>s[j])
						s[j]=t;
					t=0;
				}
			}
		}
		for(i=0,k=1;i<168;i++)
			k*=pow((double)num[i],(double)s[i]);
		if(k>1e9)
			cout<<"More than a billion.\n";
		else
			cout<<(long)k<<endl;
	}
	return 0;
}