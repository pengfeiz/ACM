#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100001

int n,a[MAX],c;

bool jud(int x)
{
	int i,t=0,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]-a[i]>x)
				break;
		}
		j--;
		i=j;
		t++;
		if(t>c)
			return false;
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
			aa=mid+1;
		else
			b=mid;
	}
	printf("%d\n",b);
	return 0;
}
		
