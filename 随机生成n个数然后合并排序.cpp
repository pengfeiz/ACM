#include <iostream>
using namespace std;
#define MAX 1000
int a[MAX];
//随机生成n个在[0,4*n)之间的数堆排 
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
	a1[n1-1]=a2[n2-1]=999999999;
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
		/*	if(a[i]!=999999999)
				t+=q-p-i;*/  // 有这句成为求逆序数，只需要前面再加一个变量t
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
	int i,n;
	cin>>n;
	
	//srand(time(NULL));
	for(i=0;i<n;i++)
	{
		if(i)
			cout<<" ";
		a[i]=rand()%(4*n);
		cout<<a[i];
	}
	cout<<endl;
	mergesort(0,n);
	for(i=0;i<n;i++)
	{
		if(i)
			cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	system("pause");
	return 0;
}
	  
