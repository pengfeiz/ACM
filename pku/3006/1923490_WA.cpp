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
	long a,d,x,i,j=0,num[168];
	for(i=2;i<1000;i++)
		if(prime(i)==1)
			num[j++]=i;
	while(cin>>a>>d>>x&&(a||x||d))
	{
		i=0;
		while(1)
		{
			if(a==1)
			{
				i++;
				a+=d;
			}
			for(j=0;j<168;j++)
				if(a%num[j]==0&&a!=num[j])
					break;
			if(j==168)
				i++;
			if(i>=x)
				break;
			a+=d;
		}
		cout<<a<<endl;
	}
	return 0;
}
