#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 80003

int n,t;
int a[MAX],b[MAX];

int main()
{
	int i,p;
	t=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	p=1;
	b[0]=n+1;
	b[1]=1;
	a[n+1]=0x7fffffff;
	for(i=2;i<=n+1;i++)
	{
		while(a[i]>=a[b[p]]&&p)
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