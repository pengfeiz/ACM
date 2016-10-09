#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000000
int a[78499];
bool prime(int x)
{
	int i;
	for(i=1;a[i]<=sqrt(x);i++)
		if(!(x%a[i]))
			return false;
	return true;
}
int main()
{
	int i,n,p,q;
	a[0]=2;
	a[1]=2;
	for(i=3;i<MAX;i++)
		if(prime(i))
			a[a[0]++]=i;
	while(scanf("%d%d%d",&n,&p,&q)&&(n||p||q))
	{
		i=0;
		while(q-->0)
		{
			i++;
			while(n!=a[i])
			{
				if(n>a[i])
					i++;
				else if(n<a[i])
					n+=p;
			}
		}
		printf("%d\n",n);
	}			
	return 0;
}
