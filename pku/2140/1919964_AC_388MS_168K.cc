#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long n,i,t;
	cin>>n;
	if(n%2==1)
	{
		t=2;
		for(i=3;i<n;i++)
			if((n%i==0||n%i==(double)i/2)&&(double)n/(double)i>(double)i/2)
				t++;
	}
	else
	{
		t=1;
		for(i=3;i<n;i++)
			if(((n%i==0&&i%2==1)||n%i==(double)i/2)&&(double)n/(double)i>(double)i/2)
				t++;
	}
	cout<<t<<endl;
	return 0;
}
			