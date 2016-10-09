#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100010

struct gao
{
	int n,a[32];
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
bool judge(gao a,gao b)
{
	int i;
	for(i=1;i<k;i++)
		if(a.a[i]!=b.a[i])
			return false;
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	int b[32],c[32],maxx=0,p;
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
			a[i].a[j]=b[j]-b[0];
	}
	sort(a,a+n,com);
	for(i=0;i<n;i++)
	{
		p=i+1;
		while(judge(a[i],a[p]))
			p++;
		p--;
		if(a[p].n-a[i].n>maxx)
			maxx=a[p].n-a[i].n;
	}
	printf("%d\n",maxx);
	return 0;
}
