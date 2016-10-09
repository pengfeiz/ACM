#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 20002

__int64 t,x;
int n,a[MAX];


bool com(int a,int b)
{
	return a>b;
}

int main()
{
	int i;
	x=t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		x+=a[i];
	}
	sort(a,a+n,com);
	for(i=0;i<n-1;i++)
	{
		t+=x;
		x-=a[i];
	}
	printf("%I64d\n",t);
	return 0;
}