#include <iostream>
#include <algorithm>
using namespace std;
int a[150000];
int main()
{
	int n,i,j,t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=j=0;i<n-1;i++)
	{
		if(j==0)
		{
			if(a[i]>a[i+1])
			{
				t+=a[i];
				j=1;
			}
		}
		else if(j==1)
		{
			if(a[i]<a[i+1])
			{
				t-=a[i];
				j=0;
			}
		}
	}
	if(j==0)
		t+=a[n-1];
	printf("%d\n",t);
	return 0;
}
