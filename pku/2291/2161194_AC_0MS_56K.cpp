#include <iostream>
#include <algorithm>
using namespace std;
int a[30000];
int main()
{
	int k,i,n,t;
	scanf("%d",&k);
	while(k--)
	{
		t=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=0;i<n;i++)
			if(a[i]*(n-i)>t)
				t=a[i]*(n-i);
		printf("%d\n",t);
	}
	return 0;
}