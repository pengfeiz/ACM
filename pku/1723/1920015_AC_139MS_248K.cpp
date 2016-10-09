#include <iostream>
#include <stdlib.h>
using namespace std;
long numx[12000],numy[12000];
int compare(const void *a,const void *b)
{
	if(*(long *)a>*(long *)b)
		return 1;
	if(*(long *)a<*(long *)b)
		return -1;
	return 0;
}
int main()
{
	long n,i,tx,ty,x[10000];
    cin>>n;
	for(i=0;i<n;i++)
		cin>>numx[i]>>numy[i];
	qsort(numx,n,sizeof(long),compare);
	qsort(numy,n,sizeof(long),compare);
	for(i=ty=0;i<n;i++)
		ty+=abs(numy[i]-numy[n/2]);
	for(i=0;i<n;i++)
		x[i]=numx[i]-i;
	qsort(x,n,sizeof(long),compare);
	for(i=tx=0;i<n;i++)
		tx+=abs(numx[i]-x[n/2]-i);
	cout<<tx+ty<<endl;
	return 0;
}
