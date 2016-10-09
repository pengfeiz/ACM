#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 20002

__int64 t,x;
__int64 n,a[MAX];

bool com(__int64 a,__int64 b)
{
	return a>b;
}


int main()
{
	__int64 i,j;
	x=t=0;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		x+=a[i];
	}
	sort(a,a+n,com);
	i=1;
	j=0;
	while(2*i<n)
	{
		j++;
		i*=2;
	}
	t=x*j;
	i-=n-i;
	for(j=i;j<n;j++)
		t+=a[j];
	printf("%I64d\n",t);
	return 0;
}