#include <iostream>
#include <math.h>
using namespace std;
int prime(long n)
{
	long i;
	for(i=2;i<sqrt(double(n))+1;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	long n,i,j=1,l;
	while(cin>>n&&n!=0)
	{
		l=0;
		for(i=2;i<=n/2;i++)
			if(prime(i)==1&&prime(n-i)==1)
				l++;
		cout<<l<<endl;
	}
	return 0;
}