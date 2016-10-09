#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100001

int n,a[MAX],c;

bool jud(int x)
{
	int i,t=1,q;
	for(i=0;i<n;)
	{
		q=a[i];
		while(i<n)
		{
			if(a[i]-q>=x)
				break;
			i++;
		}
		if(i==n)
			break;
		t++;
	}
	if(t<c)
		return false;
	return true;
}

int main()
{
	int i,aa,b,mid;
	scanf("%d%d",&n,&c);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	aa=0;
	b=999999;
	while(b>aa)
	{
		mid=(b+aa)/2;
		if(jud(mid))
			aa=mid;
		else
			b=mid-1;
	}
	printf("%d\n",b);
	return 0;
}
		
