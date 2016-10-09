#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a,b;
	long n1,n2,num;
	a=(sqrt(5)+1)/2;
	b=(sqrt(5)-1)/2;
      while(cin>>n1>>n2)
	{
		if(n1<n2)
			swap(n1,n2);
		num=ceil(n2*b);
		if(n1==(long)(num*a)+num||(n1==1&&n2==1))
			cout<<0<<endl;
		else cout<<1<<endl;
	}
      return 0;
}
