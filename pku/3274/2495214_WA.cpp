#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100002

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
	int b[32],c[32],maxx=0,p;
	gao q;
	for(i=0;i<32;i++)
		c[i]=1<<i;
	scanf("%d%d",&n,&k);
	memset(b,0,sizeof(b));
	memset(a,0,sizeof(a));
	n++;
	for(i=1;i<n;i++)
	{
		scanf("%d",&p);
		for(j=0;j<k;j++)
			if(p&c[j])
				b[j]++;
		a[i].n=i;
		for(j=1;j<k;j++)
			a[i].a[j]=b[j]-b[j-1];
	}
	sort(a,a+n,com);
	for(i=1;i<n;i++)
	{
		for(j=1;j<k;j++)
			q.a[j]=a[i].a[j];
		p=lower_bound(a,a+n,q,com)-a;
		if(p==n)
			continue;
		if(abs(a[i].n-a[p].n)<=maxx)
			continue;
		for(j=1;j<k;j++)
			if(q.a[j]!=a[p].a[j])
				break;
		if(j==k)
			maxx=abs(a[i].n-a[p].n);
	}
	printf("%d\n",maxx);
	return 0;
}
