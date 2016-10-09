#include <stdio.h>
#define MAX 1000

double a[MAX+1][MAX+1];

int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	a[0][0]=0;
	for(y=1;y<=m;y++) 
		a[0][y]=a[0][y-1]+((double)m/y);
    for(x=1;x<=n;x++)
	{
		a[x][0]=a[x-1][0]+((double)n/x);
		for(y=1;y<=m;y++) 
				a[x][y]=(x*y*a[x-1][y-1]+(n-x)*y*a[x][y-1]+x*(m-y)*a[x-1][y]+m*n)/(x*m+y*n-x*y);
	}
	printf("%.4f\n",a[n][m]);
	return 0;
}
