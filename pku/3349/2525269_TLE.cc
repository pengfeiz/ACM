#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1300001


int n;
struct gao
{
	int n;
	int b[6];
}a[MAX];


bool com(gao a,gao b)
{
	int i;
	for(i=0;i<6;i++)
		if(a.b[i]!=b.b[i])
			return a.b[i]<b.b[i];
	return a.n<b.n;
}

int main()
{
	int i,j,k;
	gao p,q,w[6];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
			scanf("%d",&p.b[j]);
		p.n=i;
		q.n=i;
		for(j=0;j<6;j++)
			q.b[j]=p.b[5-j];
		for(k=0;k<6;k++)
		{
			w[k].n=i;
			for(j=0;j<6;j++)
				w[k].b[j]=p.b[(j+k)%6];
		}
		sort(w,w+6,com);
		a[i*2].n=i;
		for(k=0;k<6;k++)
			a[i*2].b[k]=w[0].b[k];
		for(k=0;k<6;k++)
		{
			w[k].n=i;
			for(j=0;j<6;j++)
				w[k].b[j]=q.b[(j+k)%6];
		}
		sort(w,w+6,com);
		a[i*2+1].n=i;
		for(k=0;k<6;k++)
			a[i*2+1].b[k]=w[0].b[k];
	}
	n*=2;
	sort(a,a+n,com);
	for(i=0;i<n-1;i++)
	{
		if(a[i].n==a[i+1].n)
			continue;
		for(j=0;j<6;j++)
			if(a[i].b[j]!=a[i+1].b[j])
				break;
		if(j==6)
			break;
	}
	if(i<n-1)
		printf("Twin snowflakes found.\n");
	else
		printf("No two snowflakes are alike.\n");
	return 0;
}