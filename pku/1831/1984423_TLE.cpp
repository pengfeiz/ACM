#include <iostream>
#include <math.h>
using namespace std;
long s;

bool dosth(long n,long i,long h,double x,int p)
{
	if(n>100)
	{
		if(n%2==0)
		{
			dosth(n/2,1,h+1,1.0,p*2);
			cout<<" "<<2*p;
			return true;
		}
		else
		{
			dosth((n-9)/2,1,h+2,1.01,p*2);
			cout<<" "<<p*3<<" "<<p*2;
			return true;
		}
	}
	if(n==0)
	{
		if(fabs(x)<1e-15)
		{
			cout<<h;
			return true;
		}
		return false;
	}
	if(n<i)
		return false;
	if(x<1e-15)
		return false;
	if(dosth(n-i,i,h+1,x-1/(i*1.0),p))
	{
		cout<<" "<<i*p;
		return true;
	}
	if(dosth(n,i+1,h,x,p))
		return true;
	return false;
}
int main()
{
	int nn;
	cin>>nn;
//	nn=100;
	while(nn-->0)
//	while(nn++<1000)
	{
		cin>>s;
//		s=nn;
		if(!dosth(s,1,0,1.0,1))
			cout<<-1;
		cout<<endl;
	}
	return 0;
}

