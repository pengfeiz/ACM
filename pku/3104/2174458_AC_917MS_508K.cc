#include <iostream>
using namespace std;
#define MAX 100000

int a,b,n,k,x[MAX],mid;

bool judge()
{
	int t,i;
	for(i=t=0;i<n;i++)
		if(x[i]>mid)
		{
			t+=(x[i]-mid+k-2)/(k-1);
			if(t>mid)
				return false;
		}
	return true;
}

int main()
{
	int i;
	scanf("%d",&n);
	b=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
		if(b<x[i])
			b=x[i];
	}
	scanf("%d",&k);
	a=0;
	if(k==1)
	{
		printf("%d\n",b);
		return 0;
	}
	while(1)
	{
		if(a==b-1)
			break;
		mid=(a+b)/2;
		if(judge())
			b=mid;
		else
			a=mid;
	}
	printf("%d\n",b);
	return 0;
}