#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int gcd(int a,int b)
{
	int c;
	if(a>b)
		swap(a,b);
	while(a%b)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return b;
}
		
int main()
{
	int a[50],n,i,j,t;
	double x;
	while(scanf("%d",&n)&&n)
	{
		t=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(gcd(a[i],a[j])==1)
					t++;
		if(!t)
		{
			printf("No estimate for this data set.\n");
			continue;
		}
		n=n*(n-1)/2;
		x=6/(t*1.0)*(n*1.0);
		printf("%.6lf\n",sqrt(x));
	}
	return 0;
}


