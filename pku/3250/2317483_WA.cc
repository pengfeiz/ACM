#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 80001

int n,t;
int a[MAX],b[MAX];

int main()
{
	int i,p;
	t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	p=0;
	b[p]=0;
	a[n]=1000000002;
	for(i=1;i<=n;i++)
	{
		while(a[i]>=a[b[p]]&&p>=0)
		{
			t+=i-b[p]-1;
			p--;
		}
		p++;
		b[p]=i;
	}
	printf("%d\n",t);
	return 0;
}