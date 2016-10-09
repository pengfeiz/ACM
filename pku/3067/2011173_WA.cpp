#include <iostream>
using namespace std;
#define MAX 1000000
int tt,t,n,m;
struct gao
{
	int a;
	int b;
}a[MAX],a1[MAX],a2[MAX];

void merge(int p,int q,int r)
{
	int n1,n2,i,j,k;
	n1=q-p+1;
	n2=r-q+1;
	for(i=0;i<n1-1;i++)
	{
		a1[i].a=a[p+i].a;
		a1[i].b=a[p+i].b;
	}
	for(j=0;j<n2-1;j++)
	{
		a2[j].a=a[q+j].a;
		a2[j].b=a[q+j].b;
	}
	a1[n1-1].a=a1[n1-1].b=a2[n2-1].a=a2[n2-1].b=9999999;
	i=j=0;
	for(k=p;k<r;k++)
	{
		if(a1[i].b<=a2[j].b)
		{
			a[k].b=a1[i].b;
			i++;
		}
		else if(a1[i].b>a2[j].b)
		{
			if(a1[i].a!=a2[j].a)
				tt+=q+j-k;
			a[k].b=a2[j].b;
			j++;
		}
	}
}

void dosth(int p,int r)
{
	int q;
	if(p<r-1)
	{
		q=(p+r)/2;
		dosth(p,q);
		dosth(q,r);
		merge(p,q,r);
	}
}
int main()
{
	int nn,i,time=0;
	scanf("%d",&nn);
	while(nn-->0)
	{
		time++;
		memset(a,0,sizeof(a));
		cin>>n>>m>>t;
		for(i=0;i<t;i++)
			scanf("%d %d",&a[i].a,&a[i].b);
		tt=0;
		dosth(0,t);
		printf("Test case %d: %d\n",time,tt);
	}
	return 0;
}
				


