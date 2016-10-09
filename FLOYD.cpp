#include <iostream>
using namespace std;


#define n 3


int a[n][n];


int main()
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		for(k=0;k<n;k++)
			for(j=0;j<n;j++)
				if(a[i][j]>a[i][k]+a[k][j])
					a[i][j]=a[i][k]+a[k][j];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d",a[i][j]);
		printf("%\n");
	}
	return 0;
}
