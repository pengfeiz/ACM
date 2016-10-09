#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 20005

__int64 t,x;
__int64 n,a[MAX];

bool com(__int64 a,__int64 b)
{return a>b;}

int main()
{
	__int64 i,p;
	x=t=0;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		x+=a[i];
	}
	sort(a,a+n,com);
	n--;
	while(n)
	{
		t+=a[n-1]+a[n];
		a[n-1]+=a[n];
		n--;
		p=a[n];
		for(i=n;i>0;i--)
		{
			if(a[i-1]<p)
				a[i]=a[i-1];
			else break;
		}
		a[i]=p;
	}
	printf("%I64d\n",t);
	return 0;
}