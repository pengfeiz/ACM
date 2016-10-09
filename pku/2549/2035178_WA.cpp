#include <iostream>
#include <algorithm>
using namespace std;
int a[1000],n;
bool com(int a,int b)
{
	return a>b;
}
bool dosth(int x,int t,int p)
{
	int i;
	if(!p)
	{
		for(i=x;i<n;i++)
			if(a[i]==t)
				return true;
		return false;
	}
	for(i=x;i<n-p;i++)
	{	
		if(t>=(p+1)*a[i])
			return false;
		if(dosth(i+1,t-a[i],p-1))
			return true;
	}
	return false;
}

int main()
{
	int i;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n,com);
		for(i=0;i<n-3;i++)
		{
			if(a[i]>3*a[i+1])
				continue;
			if(dosth(i+1,a[i],2))
				break;
		}
		if(i==n-3||n<4)
			printf("no solution\n");
		else
			printf("%d\n",a[i]);
	}
	return 0;
}

