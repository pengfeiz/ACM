#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	unsigned long n,i,t,nn,m;
	cin>>nn;
	while(nn-->0)
	{
		t=0;
		cin>>m>>n;
		cout<<m<<" ";
		for(i=2;i<=sqrt((double)2*n);i++)
			if(2*n%i==0&&(2*n/i+i)%2==1)
				t++;
		cout<<t<<endl;
	}
	return 0;
}
			