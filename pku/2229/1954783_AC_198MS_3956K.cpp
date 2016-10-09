#include <iostream.h>
#include <math.h>
#include <iomanip.h>
long x,t,a[1000001];
int main()
{
	long n,i;
	cin>>n;
	a[0]=1;
	a[1]=1;
	for(i=2;i<=1000000;i++)
	{
		if(i%2==0)
			a[i]=a[i-1]+a[i/2];
		else
			a[i]=a[i-1];
		if(a[i]>999999999)
			a[i]%=1000000000;
	}
	cout<<a[n]<<endl;
	return 0;
}