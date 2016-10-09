#include <iostream>
using namespace std;

#define MAX 15001

int a[MAX];

int main()
{
	int i;
	a[0]=0;
	a[1]=1;
	for(i=2;i<MAX;i++)
		a[i]=(a[i-1]+a[i-2])%10000;
	while(scanf("%d",&i),i>=0)
		printf("%d\n",a[i%15000]);
	return 0;
}
