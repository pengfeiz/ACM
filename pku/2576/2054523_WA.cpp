#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 450
int p1,p2;
void dosth(int a[],int n)
{
	int i;
	for(i=0;i<n;i+=2)
	{
		if(a[i]<a[i+1])
		{
			if(p1>p2)
			{
				p1+=a[i];
				p2+=a[i+1];
			}
			else
			{
				p1+=a[i+1];
				p2+=a[i];
			}
		}
		else
		{
			if(p1>p2)
			{
				p1+=a[i+1];
				p2+=a[i];
			}
			else
			{
				p1+=a[i];
				p2+=a[i+1];
			}
		}
	}
}
int main()
{	
	int n,i,j,k,a[MAX],b[MAX],l1,l2,min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(n%2)
	{
		min=99999999;
		for(i=0;i<n;i++)
		{
			for(k=j=0;k<n;k++)
			{
				if(k==i)
					continue;
				b[j++]=a[k];
			}
			p1=p2=0;
			dosth(b,j);
			if(p1>p2)
				p2+=a[i];
			else
				p1+=a[i];
			if(abs(p1-p2)<min)
			{
				min=abs(p1-p2);
				l1=p1;
				l2=p2;
			}
		}
	}
	else
	{
		dosth(a,n);
		l1=p1;
		l2=p2;
	}
	if(l1>l2)
		swap(l1,l2);
	printf("%d %d\n",l1,l2);
	return 0;
}




	