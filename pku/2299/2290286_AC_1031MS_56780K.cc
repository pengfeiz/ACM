#include <iostream>
using namespace std;
#define MAX 500002
int a[MAX];
__int64 t;
void merge(int p,int q,int r)
{
	int n1,n2,i,j,k;
	n1=q-p+1;
	n2=r-q+1;
	int *a1=new int[n1];
	int *a2=new int[n2];
	for(i=0;i<n1-1;i++)
		a1[i]=a[p+i];
	for(j=0;j<n2-1;j++)
		a2[j]=a[q+j];
	a1[n1-1]=a2[n2-1]=2000000000;
	i=j=0;
	for(k=p;k<r;k++)
	{
		if(a1[i]<a2[j])
		{
			a[k]=a1[i];
			i++;
		}
		else
		{
			if(a[i]!=2000000000)
				t+=q-p-i;  // 有这句成为求逆序数，只需要前面再加一个变量t
			a[k]=a2[j];
			j++;
		}
	}
}
void mergesort(int p,int r)
{
	int q;
	if(p<r-1)
	{
		q=(p+r)/2;
		mergesort(p,q);
		mergesort(q,r);
		merge(p,q,r);
	}
}
int main()
{
//	freopen("B.1.dat","r",stdin);
	int i,n;
	while(scanf("%d",&n),n)
	{
		t=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		mergesort(0,n);
		printf("%I64d\n",t);
	}
	return 0;
}
	  
