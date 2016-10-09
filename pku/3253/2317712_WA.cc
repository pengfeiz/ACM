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
	int i,j;
	x=t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
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
	i-=j;
	for(j=i;j<n;j++)
		t+=a[j];
	printf("%I64d\n",t);
	return 0;
}