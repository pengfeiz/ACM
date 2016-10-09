#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
double n;
bool dosth(long i,double x,long t,long h)
{
	if((n-t)*1.0/(i*i*1.0)<(1-x-1e-10))
		return false;
	if(t>n)
		return false;
	if(fabs(x-1)<1e-10)
	{
		if(t<n)
			return false;	
		cout<<h;
		return true;
	}
	if(x>1.0)
		return false;
	if(i+t>n)
		return false;
	if(dosth(i+1,x,t,h))
		return true;
	if(dosth(i,x+1/double(i),t+i,h+1))
	{
		cout<<" "<<i;
		return true;
	}
	return false;
}
int main()
{
	n=0;
	long i;
	while(cin>>n)
//	while(n<500)
	{
	//	n++;
		if(sqrt(n*1.0)>15)
			i=(long)sqrt(n*1.0)-5;
		else
			i=0;
		if(!dosth(i,0.0,0,0))
			cout<<-1;
		cout<<endl;
	}
	return 0;
}

