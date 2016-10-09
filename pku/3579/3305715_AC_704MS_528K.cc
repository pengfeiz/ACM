#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=100001;

int a[maxn],n,qq;


bool judge(int x)
{
	int i,p;
	int t=0;
	for(i=0;i<n-1;i++)
	{
		p=upper_bound(a+i,a+n,a[i]+x)-(a+i);
		t+=p-1;
	}
	if(2*t<qq)
		return false;
	return true;
}


int main()
{
	int i,l,r,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		qq=n*(n-1)/2;
		l=0;
		r=a[n-1]-a[0];
		while(l<r)
		{
			m=(l+r)/2;
			if(judge(m))
				r=m;
			else
				l=m+1;
		}
		printf("%d\n",l);
	}

	return 0;
}
