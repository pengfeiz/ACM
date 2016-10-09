#include <iostream>
#include <math.h>
using namespace std;

__int64 n,k;

void dosth()
{
	double y;
	__int64 x=0,i,p=k%n,z,q;
	do
	{
		q=k/n;
		y=(double)(n-p-0.01)/(double)(q+1);
		z=(__int64)floor(y);
		x+=(2*p+z*q)*(z+1)/2;
		p+=(z+1)*q;
		n-=z;
		n--;
		p=p%n;
	}while(z&&n);
	for(i=2;i<=n;i++)
		x+=k%i;
	printf("%I64d\n",x);
}

int main()
{
	scanf("%I64d%I64d",&n,&k);
	if(n==1)
		printf("0\n");
	else
		dosth();
	return 0;
}
