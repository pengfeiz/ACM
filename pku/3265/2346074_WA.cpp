#include <iostream>
using namespace std;
#define MAX 1002

int n,m;

struct gao
{
	int a,b;
}a[MAX];

int main()
{
	int i,last,now,t=1;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i].a,&a[i].b);
	last=i=0;
	while(i<n)
	{
		t++;
		now=m-last;
		last=0;
		while(now>=a[i].a&&last+a[i].b<=m&&i<n)
		{
			now-=a[i].a;
			last+=a[i].b;
			i++;
		}
	}
	t++;
	printf("%d\n",t);
	return 0;
}