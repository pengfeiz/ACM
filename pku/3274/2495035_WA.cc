#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

struct gao
{
	int n,a[31];
}a[MAX];

int n,k;

bool com(gao a,gao b)
{
	int i;
	for(i=1;i<k;i++)
		if(a.a[i]!=b.a[i])
			return a.a[i]<b.a[i];
	return a.n<b.n;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	int b[31],c[31],maxx=0,p,x;
	gao q;
	for(i=0;i<31;i++)
		c[i]=1<<i;
	scanf("%d%d",&n,&k);
	memset(b,0,sizeof(b));
	memset(a,0,sizeof(a));
	n++;
	for(i=1;i<n;i++)
	{
		scanf("%d",&x);
		for(j=0;j<k;j++)
			if(x&c[j])
				b[j]++;
		a[i].n=i;
		for(j=1;j<k;j++)
		{
			if(b[j])
				a[i].a[j]=b[j]-b[0];
			else
				a[i].a[j]=0;
		}
	}
	sort(a,a+n,com);
	for(i=1;i<n;i++)
	{
		for(j=1;j<k;j++)
			q.a[j]=a[i].a[j];
		p=lower_bound(a,a+i,q,com)-a;
		if(p==i)
			continue;
		if(a[i].n-a[p].n<maxx)
			continue;
		for(j=1;j<k;j++)
			if(q.a[j]!=a[p].a[j])
				break;
		if(j==k)
			if(a[i].n-a[p].n>maxx)
				maxx=a[i].n-a[p].n;
	}
	printf("%d\n",maxx);
	return 0;
}
