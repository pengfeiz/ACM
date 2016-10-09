#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int he(long n)
{
	long i;
	for(i=2;i<=sqrt(double(n));i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	long n,i;
	while(scanf("%ld",&n)&&n!=0)
	{
		for(i=2;i<=n/2;i++)
			if(he(i)==1&&he(n-i)==1)
			{
				cout<<n<<" = "<<i<<" + "<<n-i<<endl;
				break;
			}
		if(i==n/2+1)
			cout<<"Goldbach's conjecture is wrong.\n";
	}
	return 0;
}