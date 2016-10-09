#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000000
__int64 tt;
int t,n,m;
struct gao
{
	int a;
	int b;
}a[MAX];
int a1[MAX],a2[MAX];
void merge(int p,int q,int r)
{
	int n1,n2,i,j,k;
	n1=q-p+1;
	n2=r-q+1;
	for(i=0;i<n1-1;i++)
		a1[i]=a[p+i].b;
	for(j=0;j<n2-1;j++)
		a2[j]=a[q+j].b;
	a1[n1-1]=a2[n2-1]=9999;
	i=j=0;
	for(k=p;k<r;k++)
	{
		if(a1[i]<=a2[j])
		{
			a[k].b=a1[i];
			i++;
		}
		else if(a1[i]>a2[j])
		{
			tt+=__int64(q+j-k);
			a[k].b=a2[j];
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
bool com(gao a,gao b)
{
	if(a.a>b.a)
		return false;
	if(a.a==b.a&&a.b>b.b)
		return false;
	return true;
}
int main()
{
	int nn,i,time=0;
	scanf("%d",&nn);
	while(nn-->0)
	{
		time++;
		memset(a,0,sizeof(a));
		scanf("%d%d%d",&n,&m,&t);
		for(i=0;i<t;i++)
			scanf("%d%d",&a[i].a,&a[i].b);
		tt=0;
		sort(a,a+t,com);
		for(i=0;i<t;i++)
			a[i].a=i;
		dosth(0,t);
		printf("Test case %d: %I64d\n",time,tt);
	}
	return 0;
}
				


