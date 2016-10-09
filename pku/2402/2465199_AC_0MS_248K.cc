#include <iostream>
using namespace std;

__int64 a[20];
void endd(__int64 n)
{
	__int64 i,b[50],m=0;
	while(n)
	{
		b[m]=n%10;
		m++;
		n/=10;
	}
	for(i=0;i<m;i++)
		printf("%I64d",b[i]);
	printf("\n");
}

int main()
{
	__int64 i,n;
	a[0]=a[1]=9;
	for(i=2;i<20;i+=2)
		a[i]=a[i+1]=10*a[i-1];
	while(scanf("%I64d",&n),n)
	{
		i=0;
		while(n>a[i])
		{
			n-=a[i];
			i++;
		}
		if(i==0)
			printf("%I64d\n",n);
		else if(i==1)
			printf("%I64d%I64d\n",n,n);
		else if(i%2==0)
		{
			printf("%I64d%I64d",a[i]/90+(n-1)/10,(n-1)%10);
			endd(a[i]/90+(n-1)/10);
		}
		else
		{
			printf("%I64d%I64d%I64d",a[i]/90+(n-1)/10,(n-1)%10,(n-1)%10);
			endd(a[i]/90+(n-1)/10);
		}
	}
	return 0;
}