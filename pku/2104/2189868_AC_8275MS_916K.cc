#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000

struct gao
{
	int a,n;
}a[MAX];

bool com(gao a,gao b)
{
	return a.a<b.a;
}

int n,m;

int main()
{
	int i,t,p,q,r;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i].a);
		a[i].n=i+1;
	}
	sort(a,a+n,com);
	while(m--)
	{
		scanf("%d%d%d",&p,&q,&r);
		t=0;
		for(i=0;;i++)
		{
			if(a[i].n<=q&&a[i].n>=p)
				t++;
			if(t-r==0)
				break;
		}
		printf("%d\n",a[i].a);
	}
	return 0;
}