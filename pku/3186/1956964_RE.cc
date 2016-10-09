#include <iostream>
using namespace std;
#define MAX 5000
long maxx(long a,long b)
{
	return a>b?a:b;
}
int main()
{
	long a[MAX],b[MAX+1][MAX+1],c[MAX+1][MAX+1],x;
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	memset(b,0,(MAX+1)*(MAX+1));
	memset(c,0,(MAX+1)*(MAX+1));
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			b[j][i]=maxx(b[j-1][i-1],c[i-j][i-1])+a[j-1]*i;
			c[j][i]=maxx(c[j-1][i-1],b[i-j][i-1])+a[n-j]*i;
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
			
			

		
	

