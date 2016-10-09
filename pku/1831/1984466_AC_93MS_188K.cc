#include <iostream>
#include <math.h>
using namespace std;
long s,l;
long b[1000];
bool dosth(long n,long i,long h,double x,int p)
{
	if(n>100)
	{
		if(n%2==0)
		{
			dosth((n-2)/2,1,h+1,1.0,p*2);
			b[h]=2*p;
			return true;
		}
		else
		{
			dosth((n-9)/2,1,h+2,1.0,p*2);
			b[h]=6*p;
			b[h+1]=3*p;
			return true;
		}
	}
	if(n==0)
	{
		if(fabs(x)<5e-16)
		{
			l=h;
			cout<<h;
			return true;
		}
		return false;
	}
	if(n<i)
		return false;
	if(x<5e-16)
		return false;
	if(dosth(n-i,i,h+1,x-1/(i*1.0),p))
	{
		b[h]=i*p;
		return true;
	}
	if(dosth(n,i+1,h,x,p))
		return true;
	return false;
}
int main()
{
	int nn,i,j;
	cin>>nn;
//	nn=100;
	while(nn-->0)
//	while(nn++<1000)
	{
		l=0;
		cin>>s;
//		s=nn;
		if(!dosth(s,1,0,1.0,1))
			cout<<-1;
		else
		{
			for(i=0;i<l-1;i++)
				for(j=i+1;j<l;j++)
					if(b[i]>b[j])
						swap(b[i],b[j]);
			for(i=0;i<l;i++)
				cout<<" "<<b[i];
		}
		cout<<endl;
	}
	return 0;
}

