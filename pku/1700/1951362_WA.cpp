#include <iostream>
#include <stdlib.h>
using namespace std;
int a[1000];
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int nn,n,i,tt;
	cin>>nn;
	while(nn-->0)
	{
		tt=0;
		cin>>n;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),compare);
		for(i=n-1;i>2;i--)
		{
			if(a[i]+a[i-1]+2*a[0]<a[i]+a[0]+3*a[1])
				tt+=a[i]+a[0];
			else
			{
				tt+=a[i]+a[0]+3*a[1];
				i--;
			}
		}
		if(i==2)
			tt+=a[0]+a[1]+a[2];
		if(n==2)
			tt=a[1];
		else if(n==1)
			tt=a[0];
		cout<<tt<<endl;
	}
	return 0;
}

