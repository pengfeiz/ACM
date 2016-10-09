#include <iostream>
using namespace std;
#define MAX 100000
//一般定义全局，不容易堆栈溢出
//随机生成[0,n)的n的数然后快排 
void quicksort(int a[],int low,int high) 
{
	if(low>=high)
		return;
	int i,j;
	i=low;
	j=high;
	a[0]=a[i];
	while(i<j)
	{
		while(i<j&&a[j]>a[0])
			j--;
		if(i<j)
			a[i++]=a[j];
		while(i<j&&a[i]<=a[0])
			i++;
		if(i<j)
			a[j--]=a[i];
	}
	a[i]=a[0];
	quicksort(a,low,i-1);
	quicksort(a,i+1,high);		
} 

void build(int a[],int &n)
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		a[i]=rand()%n;
}

void printff(int a[],int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main()
{
	int a[MAX],n;
	build(a,n);
	quicksort(a,1,n);
	printff(a,n);
	system("pause");
	return 0;
}

