#include <iostream>
using namespace std;
#define MAX 10001
int a[MAX];
int main()
{
	int i;
	a[0]=1;
	for(i=1;i<MAX;i++)
	{
		a[i]=a[i-1]*i;
		while(a[i]%10==0)
			a[i]/=10;
		a[i]=a[i]%100000;
	}
	while(cin>>i)
		printf("%5d -> %d\n",i,a[i]%10);
	return 0;
}

	