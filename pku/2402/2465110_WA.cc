#include <iostream>
using namespace std;

int a[11]={9,9,90,90,900,900,9000,9000,90000,90000,900000};

void endd(int n)
{
	int i,b[20],m=0;
	while(n)
	{
		b[m]=n%10;
		m++;
		n/=10;
	}
	for(i=0;i<m;i++)
		printf("%d",b[i]);
	printf("\n");
}

int main()
{
	int i,n;
	while(scanf("%d",&n),n)
	{
		i=0;
		while(n>a[i])
		{
			n-=a[i];
			i++;
		}
		if(i==0)
			printf("%d\n",n);
		else if(i==1)
			printf("%d%d\n",n,n);
		else if(i%2==0)
		{
			printf("%d%d",a[i]/90+(n-1)/10,(n-1)%10);
			endd(a[i]/90+(n-1)/10);
		}
		else
		{
			printf("%d%d%d",a[i]/90+(n-1)/10,(n-1)%10,(n-1)%10);
			endd(a[i]/90+(n-1)/10);
		}
	}
	return 0;
}

