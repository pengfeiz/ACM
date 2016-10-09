#include <iostream>
#include <math.h>
using namespace std;
long zhi[200];

int zs(long n)
{
	long i;
	for(i=2;i<=sqrt((double)n);i++)
		if(n%i==0)
			return 0;
	return 1;
}

long hz(long n)
{
	long i,p[200],m=n;
	p[0]=0;
	for(i=1;i<=zhi[0];i++)
	{
		if(n%zhi[i]==0)
			p[i]=1;
		else
			p[i]=0;
	}
	for(i=1;i<=zhi[0];i++)
		if(p[i]==1)
			m=m/zhi[i]*(zhi[i]-1);
	return m;
}
	
int main()
{
	long nn,i,n,num[1001];
	cin>>nn;
	zhi[0]=1;
	zhi[1]=2;
	for(i=3;i<=1000;i++)
		if(zs(i)==1)
		{
			zhi[zhi[0]+1]=i;
			zhi[0]++;
		}
	num[0]=0;
	num[1]=0;
	for(i=2;i<=1000;i++)
		num[i]=num[i-1]+hz(i);
	for(i=1;i<=nn;i++)
	{
		cin>>n;
		cout<<i<<" "<<n<<" ";
		if(n!=0)
			cout<<2*num[n]+3<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}





