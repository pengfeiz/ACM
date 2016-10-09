#include <iostream>
#include <fstream>
using namespace std;
#define MAX 300
int a[MAX],b[MAX][MAX],c[MAX][MAX];
int main()
{
//	ifstream cin("input.txt");
	int n,m,i,j,l,k;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	memset(b,0,sizeof(b));
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			l=(i+j)/2;
			for(k=i;k<=j;k++)
				b[i][j]+=abs(a[l]-a[k]);
		}
	for(i=0;i<n;i++)
		c[i][0]=b[0][i];
	for(j=1;j<m;j++)
		for(i=0;i<n;i++)
		{
			c[i][j]=99999999;
			for(k=j;k<=i;k++)
				if(c[k-1][j-1]+b[k][i]<c[i][j])
					c[i][j]=c[k-1][j-1]+b[k][i];
		}
	cout<<c[n-1][m-1]<<endl;
	return 0;
}

