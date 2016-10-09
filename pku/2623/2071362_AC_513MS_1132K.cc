#include <iostream>
#include <algorithm>
using namespace std;
unsigned int a[250000];

bool com(unsigned int a,unsigned int b)
{
	return a<b;
}

int main()
{
	unsigned int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n,com);
	if(n%2==1)
		printf("%d.0\n",a[n/2]);
	else
	{
		if((a[n/2]+a[n/2-1])%2)
			printf("%.1lf\n",(a[n/2]+a[n/2-1])/2.0);
		else
			printf("%d.0\n",(a[n/2]+a[n/2-1])/2);
	}
	return 0;
}
