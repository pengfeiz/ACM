#include <iostream>
#include <math.h>
using namespace std;
#define MAX 2000
long max(long a,long b)
{
	return a>b?a:b;
}
int main()
{
	long a[MAX],n,i,b[MAX+1][MAX+1],c[MAX+1][MAX+1],j;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	memset(b,0,(MAX+1)*(MAX+1));
	memset(c,0,(MAX+1)*(MAX+1));
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			b[j][i]=max(b[j-1][i-1],c[i-j][i-1])+a[j-1]*i;
			c[j][i]=max(c[j-1][i-1],b[i-j][i-1])+a[n-j]*i;
		}
	for(i=1,j=0;i<=n;i++)
	{
		if(b[i][n]>j)
			j=b[i][n];
		if(c[i][n]>j)
			j=c[i][n];
	}
	cout<<j<<endl;
	return 0;
}
			
			

		
	

