#include <iostream>
#include <algorithm>
using namespace std;
int a[10002];

int main()
{
	int nn,n,i,tt;
	tt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=n-1;i>2;i--)
	{
		if(a[i]+a[i-1]+2*a[0]<a[i]+a[0]+2*a[1])
			tt+=a[i]+a[0];
		else
		{
			tt+=a[i]+a[0]+2*a[1];
			i--;
		}
	}
	if(i==2)
		tt+=a[0]+a[1]+a[2];
	else if(i==1)
		tt+=a[1];
	if(n==1)
		tt=a[0];
	printf("%d\n",tt);
	return 0;
}