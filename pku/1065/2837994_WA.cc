#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 5000

struct gao
{
	int a,b;
}a[MAX],b[MAX];

int n;

bool com(gao a,gao b)
{
	if(a.a>b.a)
		return true;
	if(a.a<b.a)
		return false;
	if(a.b>b.b)
		return true;
	return false;
}

void dosth()
{
	int t=0,i,j;
	for(i=0;i<n;i++)
	{
		for(j=t-1;j>=0;j--)
			if(a[i].a<=b[j].a&&a[i].b<=b[j].b)
			{
				b[j].a=a[i].a;
				b[j].b=a[i].b;
				break;
			}
		if(j<0)
		{
			b[t].a=a[i].a;
			b[t].b=a[i].b;
			t++;
		}
	}
	printf("%d\n",t);
}	

int main()
{
	int i,k;
	scanf("%d",&k);
	while(k-->0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].a,&a[i].b);
		sort(a,a+n,com);
		dosth();
	}
	return 0;
}
