#include <iostream>
#include <math.h>
using namespace std;
#define MAX 2000
double max(double a,double b)
{
	return a>b?a:b;
}
int main()
{
	double a[MAX],b[MAX+1][MAX+1],c[MAX+1][MAX+1],x;
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%lf",&a[i]);
	memset(b,0,(MAX+1)*(MAX+1));
	memset(c,0,(MAX+1)*(MAX+1));
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			b[j][i]=max(b[j-1][i-1],c[i-j][i-1])+a[j-1]*i*(1.0);
			c[j][i]=max(c[j-1][i-1],b[i-j][i-1])+a[n-j]*i*(1.0);
		}
	for(i=1,x=0;i<=n;i++)
	{
		if(b[i][n]>x)
			x=b[i][n];
		if(c[i][n]>x)
			x=c[i][n];
	}
	cout<<x<<endl;
	return 0;
}
			
			

		
	

