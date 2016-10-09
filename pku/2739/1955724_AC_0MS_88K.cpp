#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int a[1229];
long x;
int com(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int judge(int n)
{
	for(int i=2;i<=sqrt(double(n));i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main()
{
	int n,i,j=0;
	long tt;
	for(i=2;i<10000;i++)
		if(judge(i)==1)
		{
			a[j]=i;
			j++;
		}
	qsort(a,1229,sizeof(a[0]),com);
	while(cin>>n&&n)
	{
		i=x=0;
		while(a[i]>n)
			i++;
		for(i;i<1229;i++)
		{
			j=i;
			tt=n;
			while(tt>0&&j<1229)
			{
				if(a[j]==tt)
					x++;
				tt-=a[j];
				j++;
			}
		}
		cout<<x<<endl;
	}
	return 0;
}
