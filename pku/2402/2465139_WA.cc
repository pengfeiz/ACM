#include <iostream>
using namespace std;

__int64 a[18]={9,9,90,90,900,900,9000,9000,90000,90000,900000,900000,9000000,9000000,90000000,90000000,900000000,900000000};

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

