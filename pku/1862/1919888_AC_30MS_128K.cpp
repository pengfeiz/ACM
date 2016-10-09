#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int compare(const void *a,const void *b)
{
	return *(double *)b-*(double *)a;
}
int main()
{
	double num[200],max;
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>num[i];
	qsort(num,n,sizeof(double),compare);
	max=0;
	for(i=1;i<n;i++)
		num[i]=2*sqrt(num[i]*num[i-1]);
	printf("%.3f\n",num[n-1]);
	return 0;
}