#include <stdio.h>
long a[6]={0,10,670,55252,4816030,432457640};

int main()
{
	int n;
	scanf("%d",&n);
	printf("%ld",a[n/2]);
	return 0;
}