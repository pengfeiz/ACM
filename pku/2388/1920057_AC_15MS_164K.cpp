#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
using namespace std;
int compare(const void *a,const void *b)
{
	return *(long *)a-*(long *)b;
}
int main()
{
	long num[10000],n,i;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%ld",&num[i]);
	qsort(num,n,sizeof(long),compare);
	cout<<num[n/2]<<endl;
	return 0;
}
