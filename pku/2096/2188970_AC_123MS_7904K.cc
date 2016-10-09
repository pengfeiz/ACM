#include <assert.h>
#include <stdio.h>

#define MAXN 1000

double E[MAXN+1][MAXN+1];

int main()
{
	int n, m, x, y;
	scanf("%d%d",&n,&m);
	E[0][0] = 0;
	for(y=1;y<=m;y++) 
		E[0][y]=E[0][y-1]+((double)m/y);
    for(x=1;x<=n;x++) 
	{
		E[x][0]=E[x-1][0]+(double)n/x;
		for(y=1;y<=m;y++) 
			E[x][y]=(x*y*E[x-1][y-1]+(n-x)*y*E[x][y-1]+x*(m-y)*E[x-1][y]+m*n)/(x*m+y*n-x*y);
	}
	printf ("%.4f\n", E[n][m]);
	return 0;
}
