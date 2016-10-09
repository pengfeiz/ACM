#include <iostream>
using namespace std;

double a[502][101];

int main()
{
	int c,n,m,i,j;
	while(scanf("%d",&c),c)
	{
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		if(m>c||m>n)
			printf("0.000\n");
		else
		{
			a[0][0]=1;
			if((n&1)&&n>500)
				n=501;
			else if(!(n&1)&&n>500)
				n=500;
			for(i=1;i<=n;i++)
			{
				a[i][1]+=a[i-1][0];
				for(j=1;j<c;j++)
				{
					a[i][j-1]+=a[i-1][j]*j/c;
					a[i][j+1]+=a[i-1][j]*(c-j)/c;
				}
				a[i][c-1]+=a[i-1][c];
			}
			printf("%.3lf\n",a[n][m]);
		}
	}
	return 0;
}