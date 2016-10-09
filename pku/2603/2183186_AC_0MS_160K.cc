#include <iostream>
#include <math.h>
using namespace std;

int a[10001];

void dosth(int n)
{
	int i;
	for(i=2;i<=n;i++)
		while(n%i==0)
		{
			a[i]++;
			n/=i;
		};
}

int main()
{
	int i,n;
	for(i=0;i<10;i++)
	{
		scanf("%d",&n);
		dosth(n);
	}
	n=1;
	for(i=0;i<=10000;i++)
	{
		n*=a[i]+1;
		n%=10;
	}
	printf("%d\n",n);
	return 0;
}