#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 1048576

int a[MAX],n,b[MAX];

int dosth(int x,int m)
{
	int q;
	if(2*x>=a[0])
	{
		a[x]-=m;
		return m;
	}
	q=dosth(2*x,m);
	q=dosth(2*x+1,q+1);
	a[x]-=q;
	return q;
}

bool com(int a,int b)
{
	return a<b;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k,*num;
	scanf("%d",&n);
	a[0]=pow(2,n);
	for(j=0,i=1;j<n;j++)
		for(k=0;k<pow(2,j);k++)
			scanf("%d",&a[i++]);
	dosth(1,0);
	b[0]=a[1];
	for(i=2,k=0;i<a[0];i++)
	{
		if(a[i]>b[k])
		{
			k++;
			b[k]=a[i];
		}
		else
		{
			num=lower_bound(b,b+k,a[i],com);
			*num=a[i];
		}
	}
	printf("%d\n",a[0]-k-1);
	return 0;
}
	