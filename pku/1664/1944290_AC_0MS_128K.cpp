#include <iostream>
using namespace std;
long t;
long dosth(long m,long n)
{
	if(m<0||n==0)
		return 0;
	if(m==0)
		return 1;
	return dosth(m-n,n)+dosth(m,n-1);
}
int main()
{
	long m,n,nn;
	cin>>nn;
	while(nn-->0)
	{
		cin>>m>>n;
		t=dosth(m,n);
		cout<<t<<endl;
	}
	return 0;
}

