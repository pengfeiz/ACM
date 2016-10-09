#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

__int64 a[MAX],n,m,k;

bool com(__int64 a,__int64 b)
{return a>b;}

bool judge(__int64 mid)
{
	__int64 i,z=m*mid;
	for(i=0;i<n;i++)
	{
		if(a[i]>mid)
		{
			if(a[i]-mid>(k-1)*mid)
				return false;
			else
				z-=(a[i]-mid+k-2)/(k-1);
			if(z<0)
				return false;
		}
		else if(a[i]<=mid)
			break;
	}
	return true;
}

int main()
{
	__int64 nn,i,x,y,mid;
	scanf("%I64d",&nn);
	while(nn--)
	{
		scanf("%I64d",&n);
		for(i=0;i<n;i++)
			scanf("%I64d",&a[i]);
		scanf("%I64d%I64d",&m,&k);
		y=99999999;
		x=0;
		sort(a,a+n,com);
		if(k==1)
		{
			printf("%d\n",a[0]);
			continue;
		}
		while(x!=y)
		{
			mid=(x+y)/2;
			if(judge(mid))
				y=mid;
			else
				x=mid+1;
		}
		printf("%I64d\n",x);
	}
	return 0;
}
