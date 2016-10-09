#include <iostream>
#include <math.h>
using namespace std;
long s;
bool dosth(long n,long i,long h,double x)
{
	if(h>10)
		return false;
	if(n==0)
	{
		if(fabs(x)<1e-10)
		{
			cout<<h;
			return true;
		}
		return false;
	}
	if(n<i)
		return false;
	if(x<1e-10)
		return false;
	if(dosth(n-i,i,h+1,x-1/(i*1.0)))
	{
		cout<<" "<<i;
		return true;
	}
	if(dosth(n,i+1,h,x))
		return true;
	return false;
}
int main()
{
	int nn;
	cin>>nn;
//	nn=1;
	while(nn-->0)
//	while(nn++<100)
	{
		cin>>s;
//		s=nn;
		if(!dosth(s,1,0,1.0))
			cout<<-1;
		cout<<endl;
	}
	return 0;
}

